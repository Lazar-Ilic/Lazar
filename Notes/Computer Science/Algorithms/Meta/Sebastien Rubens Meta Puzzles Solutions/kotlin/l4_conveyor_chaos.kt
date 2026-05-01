// meta_puzzles by Sebastien Rubens
//
// Please go to https://github.com/seb-pg/meta_puzzles/README.md
// for more information
//
// To the extent possible under law, the person who associated CC0 with
// meta_puzzles has waived all copyright and related or neighboring rights
// to meta_puzzles.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

package l4_conveyor_chaos

class Params(
    val x_min: Double = 0.0,
    val x_max: Double = 1_000_000.0,
    val h_min: Int = 0,
    val h_max: Int = 1_000_000, )

class Drop(
    var drop_point: Double = 0.0,
    var interval: Interval? = null, )

class Interval(
    var n: Int = 0,
    var h: Int = 0,
    var xmin: Double = 0.0,
    var xmax: Double = 0.0,
    var children: ArrayList<Drop> = arrayListOf<Drop>(Drop(), Drop()),
    var weight: Double = 0.0,
    var costs: ArrayList<Double> = arrayListOf<Double>( .0, 0.0), )
: Comparable<Interval>
{
    fun width(): Double { return xmax - xmin; }
    fun middle(): Double { return (xmax + xmin) * 0.5; }

    override fun compareTo(other: Interval): Int = when {
        this.h != other.h -> this.h compareTo other.h
        this.xmin != other.xmin -> this.xmin compareTo other.xmin
        else -> 0
    }
}

class Point(
    var x: Double,
    var i: Interval,
    var op: Int, )

class Edge(
    var parent: Interval,
    var child: Interval,
    var side: Int,
    var weight: Double, )

class Result (
    var base_cost: Double,
    var min_delta: Double,
    var side: Int,
    var interval: Interval, )

typealias ListIntervals = ArrayList<Interval>;

fun build_intervals(N: Int, H: Array<Int>, A: Array<Int>, B: Array<Int>, params: Params): ListIntervals  // O(N* log(N))
{
    val G = N + 1;

    val mid = (params.h_max + params.h_min) * 0.5;
    val intervals = ListIntervals(N + 2);

    // ground
    val ground = Interval(0, params.h_min, params.x_min, params.x_max)
    intervals.add(ground);

    // user intervals: O(N)
    for (i in 0 until N)
        intervals.add(Interval(i + 1, H[i], A[i].toDouble(), B[i].toDouble(), arrayListOf(Drop(mid, ground), Drop(mid, ground)) ));

    // sky
    intervals.add(Interval( G, params.h_max, params.x_min, params.x_max, arrayListOf(Drop(mid, ground), Drop()) ));

    // O(N*log(N))
    intervals.sortWith(compareBy<Interval> { it.h });

    return intervals;
}

fun add_entries(N: Int, intervals: ListIntervals)
{
    val sky_h = intervals.last().h;
    val mid = (intervals.first().xmax + intervals.last().xmin) * 0.5;

    // O(N)
    val interval_size = intervals.size;
    val points = ArrayList<Point>(2 * interval_size - 4);
    for (i in 1 until interval_size - 1)
    {
        val interval = intervals[i];
        points.add(Point( interval.xmin, interval, +1 ));
        points.add(Point( interval.xmax, interval, -1 ));
    }

    // O(N*log(N))
    points.sortWith(compareBy<Point> { it.x }.thenBy { it.i.h });

    // build entry intervals (we do not save intervals dropping immediately to the ground)
    intervals.removeLast();
    intervals.ensureCapacity(intervals.size + points.size)

    //
    val ground = intervals.first();
    if (points[0].x > ground.xmin)
        intervals.add(Interval( 0, sky_h, ground.xmin, -1.0, arrayListOf(Drop(mid, ground), Drop()) ));

    val stack = sortedSetOf<Interval>(compareBy<Interval> { it.h });
    stack.add(ground);

    var first = 0;  // Iterators are a pain in Kotlin/Java, we are replacing them with integer
    val end = points.size;
    var last_p = Interval();

    while (first != end)
    {
        val x = points[first].x;
        var last = first + 1;
        while (last < end)
        {
            if (x != points[last].x)
                break;
            ++last;
        }
        //
        val p = stack.last();
        if (last_p !== p)
        {
            last_p = p;
            intervals.add(Interval());  // will reallocate platform
        }
        // First pass, we remove intervals, and deal with add/remove on left/right
        for (curr in first until last)
        {
            val i = points[curr].i;
            val op = points[curr].op;
            val prev = stack.lower(Interval(0, i.h, p.xmax + 1.0));
            if (op == -1)
            {
                i.children[1] = Drop( i.xmax, prev!! );
                stack.remove(i);
            }
            else if (op == +1)
                i.children[0] = Drop( i.xmin, prev!! );
        }
        // Second pass, we add intervals
        for (curr in first until last)
        {
            val i = points[curr].i;
            val op = points[curr].op;
            if (op == +1)
                stack.add(i);
        }
        //
        val last_n = stack.last();
        intervals[intervals.size - 1] = Interval( 0, sky_h, x, -1.0, arrayListOf(Drop(0.0, last_n), Drop()) );  // we do not know xmax at that stage
        //
        first = last;
    }
    //
    if (intervals.last().xmin == ground.xmax)
        intervals.removeLast();
    // stitching xmin and xmax
    for (i in N+1 until intervals.size - 1)
        intervals[i].xmax = intervals[i + 1].xmin;
    intervals.last().xmax = ground.xmax;
    // fix children by adding drop_point
    for (i in N+1 until intervals.size)
    {
        val interval = intervals[i];
        interval.n = i - 1;
        interval.children[0].drop_point = interval.middle();
    }
}

fun populate_costs(N: Int, intervals: ListIntervals)
{
    // set up weight for entry interval from the sky: O(N)
    for (p in intervals.slice(N+1 until intervals.size))
        p.weight = if (p.children[0].interval!!.n > 0) p.width() else 0.0;

    // Accumulate costs from top to bottom: O(E) where E is 2*N at most
    val edges = ArrayList<Edge>(2* N);
    for (parent in intervals.slice(intervals.size - 1 downTo 0))
    {
        val weight = 0.5 * parent.weight;
        if (weight == 0.0)
            continue;
        for (side in 0..1)
        {
            val drop_point = parent.children[side].drop_point;
            val _child = parent.children[side].interval;
            if (_child != null && _child!!.n > 0)
            {
                val child = _child!!;
                val cost_l = weight * (drop_point - child.xmin);
                val cost_r = weight * (child.xmax - drop_point);
                child.weight += weight;
                child.costs[0] += cost_l;
                child.costs[1] += cost_r;
                edges.add(Edge( parent, child, side, weight ));
            }
        }
    }

    // Accumulate costs from bottom to top: O(E) where E is 2*N at most
    for (curr in edges.slice(edges.size - 1 downTo 0))
    {
        val parent = curr.parent;
        val child = curr.child;
        parent.costs[curr.side] += (child.costs[0] + child.costs[1]) * curr.weight / child.weight;
    }
}

fun calc_dist(N: Int, intervals: ListIntervals): Result
{
    // base_cost
    val res = Result( 0.0, 0.0, 0, Interval() );
    for (i in N + 1 until intervals.size)
        res.base_cost += intervals[i].costs[0];

    // calculate min_delta, min_dir, min_p: O(N)
    for (i in 0..N)
    {
        val interval = intervals[i];
        var delta = interval.costs[0] - interval.costs[1];
        if (res.min_delta > delta)
        {
            res.min_delta = delta;
            res.side = 0;
            res.interval = interval;
            continue;
        }
        delta *= -1;
        if (res.min_delta > delta)
        {
            res.min_delta = delta;
            res.side = 1;
            res.interval = interval;
        }
    }
    return res;
}

fun getMinExpectedHorizontalTravelDistance(N: Int, H: Array<Int>, A: Array<Int>, B: Array<Int>): Double {
    val params = Params();
    val intervals = build_intervals(N, H, A, B, params);  // O(N)
    add_entries(N, intervals);  // O(N * log(N))
    populate_costs(N, intervals);  // O(N)
    val res = calc_dist(N, intervals);  // O(N)
    val smallest_cost = (res.base_cost + res.min_delta) / (params.x_max - params.x_min);
    return smallest_cost;
}

class Args(
    val H: Array<Int>,
    val A: Array<Int>,
    val B: Array<Int>,
    val res: Double, ) : test.Result<Double> {
    override fun get_result(): Double { return res; };
}

fun make_cases(N: Int): Args
{
    val params = Params();

    val H = ArrayList<Int>(N);
    val A = ArrayList<Int>(N);
    val B = ArrayList<Int>(N);
    for (i in 1..N)
    {
        H.add(N + 1 - i);
        A.add(N + 1 - i);
        B.add(N + i);
    }
    var base_cost = 0UL;
    var width = 2UL * N.toULong() - 1UL;
    var added_width = 0UL;
    for (i in 0 until N)
    {
        added_width += width;
        base_cost += added_width;
        width -= 2UL;
    }
    base_cost -= added_width / 2UL;
    val expected = base_cost.toDouble() / (params.x_max - params.x_min);
    return Args(H.toTypedArray(), A.toTypedArray(), B.toTypedArray(), expected);
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMinExpectedHorizontalTravelDistance(p.A.size, p.H, p.A, p.B) };

    val args_list = arrayListOf<Args>(
        Args( arrayOf(10, 20), arrayOf(100_000, 400_000), arrayOf(600_000, 800_000), 155_000.0 ),
        Args( arrayOf(2, 8, 5, 9, 4), arrayOf(5_000, 2_000, 7_000, 9_000, 0), arrayOf(7_000, 8_000, 11_000, 11_000, 4_000), 36.5 ),
        // extra1
        Args( arrayOf(2, 4, 5, 8, 9), arrayOf(5_000, 0, 7_000, 2_000, 9_000), arrayOf(7_000, 4_000, 11_000, 8_000, 11_000), 36.5 ),
        //
        Args( arrayOf(10), arrayOf(0), arrayOf(1_000_000), 500_000.0 ),
        Args( arrayOf(10), arrayOf(0), arrayOf(500_000), 125_000.0 ),
        Args( arrayOf(9), arrayOf(500_000), arrayOf(1_000_000), 125_000.0 ),
        Args( arrayOf(10, 9), arrayOf(0, 500_000), arrayOf(500_000, 1_000_000), 250_000.0 ),
        //
        Args( arrayOf(20, 10), arrayOf(200_000, 400_000), arrayOf(600_000, 800_000), 120_000.0 ),
        Args( arrayOf(20, 10), arrayOf(400_000, 200_000), arrayOf(800_000, 600_000), 120_000.0 ),
        Args( arrayOf(20, 20, 10), arrayOf(100_000, 500_000, 200_000), arrayOf(300_000, 700_000, 600_000), 100_000.0 ),
        //
        Args( arrayOf(1), arrayOf(0), arrayOf(1_000_000), 500_000.0 ),
        Args( arrayOf(1), arrayOf(250_000), arrayOf(750_000), 125_000.0 ),
        Args( arrayOf(1, 3, 3, 5), arrayOf(400_000, 200_000,  600_000, 400_000), arrayOf(700_000, 500_000, 1_000_000, 700_000), 213_750.0 ),
        Args( arrayOf(1, 3, 3, 5, 7), arrayOf(400_000, 200_000,  600_000, 400_000, 400_000), arrayOf(700_000, 500_000, 1000_000, 700_000, 600_000), 215_000.0 ),
    );
    //args_list.add(make_cases(2));
    args_list.add(make_cases(100_000));
    //args_list.add(make_cases(2_000_000));

    return test.run_all_tests("l4_conveyor_chaos", args_list, wrapper, 0.000_001);
}
