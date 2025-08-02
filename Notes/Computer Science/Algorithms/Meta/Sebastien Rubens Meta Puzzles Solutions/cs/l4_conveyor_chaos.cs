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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;

namespace l4_conveyor_chaos
{
#nullable enable annotations

class Solution {

    static private double x_min = 0;
    static private double x_max = 1_000_000;  // inclusive
    static private int h_min = 0;
    static private int h_max = 1_000_000;  // non inclusive

    class Drop
    {
        public double drop_point;
        public Interval? interval = null!;

        public Drop()
        {
            drop_point = 0.0;
            interval = null!;
        }

        public Drop(double _drop_point, Interval _interval)
        {
            drop_point = _drop_point;
            interval = _interval;
        }
    }

    class Interval : IComparable<Interval>
    {
        public int n = 0;
        public int h = 0;
        public double xmin = 0;
        public double xmax = 0;
        public Drop[] children;
        public double weight = 0.0;
        public double[] costs;

        public Interval()
        {
            children = new Drop[2];
            costs = new double[2] { 0.0, 0.0 };
        }

        public double width()
        {
            return xmax - xmin;
        }

        public double middle()
        {
            return (xmax + xmin) * 0.5;
        }

        public int CompareTo(Interval? other)
        {
            if (h < other!.h)
                return -1;
            if (h > other!.h)
                return 1;
            return 0;
        }
    }


    class Point : IComparable<Point>
    {
        public double   x;
        public Interval i;
        public int      op;

        public Point(double _x, Interval _i, int _op)
        {
            x = _x;
            i = _i;
            op = _op;
        }

        public int CompareTo(Point? other)
        {
            if (x < other!.x)
                return -1;
            if (x > other!.x)
                return 1;
            if (i.h < other!.i.h)
                return -1;
            if (i.h > other!.i.h)
                return 1;
            return 0;
        }
    }

    class Edge
    {
        public Interval parent;
        public Interval child;
        public int side;
        public double weight;

        public Edge(Interval _parent, Interval _child, int _side, double _weight)
        {
            parent = _parent;
            child = _child;
            side = _side;
            weight = _weight;
        }
    };

    class Result
    {
        public double base_cost = 0;
        public double min_delta = 0;
        public int side;
        public Interval? interval = null!;
    }

    static List<Interval> build_intervals(int N, in int[] H, in int[] A, in int[] B)  // O(N* log(N))
    {
        var G = N + 1;
        double mid = (h_max + h_min) * 0.5;
        var intervals = new List<Interval>(N + 2);

        // ground
        intervals.Add(new Interval() { n=0, h=h_min, xmin=x_min, xmax=x_max });
        var ground = intervals[^1];

        // user intervals: O(N)
        for (int i = 0; i < N; ++i)
            //intervals.Add(new Interval() { n=i + 1, h=H[i], xmin=A[i], xmax=B[i] });
            intervals.Add(new Interval() { n=i + 1, h=H[i], xmin=A[i], xmax=B[i], children=new Drop[2] { new Drop( mid, ground ), new Drop( mid, ground ) } });

        // sky
        intervals.Add(new Interval() { n=G, h=h_max, xmin=x_min, xmax=x_max, children=new Drop[2] { new Drop(mid, ground), new Drop() } });

        // O(N*log(N))
        intervals.OrderBy(obj => obj.h);

        return intervals;
    }

    static void add_entries(int N, List<Interval> intervals)
    {
        var sky = intervals.Last();
        var sky_h = intervals.Last().h;
        var mid = (intervals.First().xmax + intervals.Last().xmin) * 0.5;

        // O(N)
        var interval_size = intervals.Count;
        var points = new List<Point>(2 * interval_size - 4);
        for (int i = 1; i < interval_size - 1; ++i)
        {
            var interval = intervals[i];
            points.Add(new Point( interval.xmin, interval, +1 ));
            points.Add(new Point( interval.xmax, interval, -1 ));
        }

        // O(N*log(N))
        points.Sort();

        // build entry intervals (we do not save intervals dropping immediately to the ground)
        intervals.RemoveAt(intervals.Count - 1);

        //
        var ground = intervals[0];
        if (points[0].x > ground.xmin)
            intervals.Add(new Interval() { n=0, h=sky_h, xmin=ground.xmin, xmax=-1, children = new Drop[2] { new Drop(mid, ground), new Drop() } });

        var stack = new SortedSet<Interval>();
        stack.Add(ground);

        var first = 0;
        var end = points.Count;
        Interval last_p = null!;
        var comparator = new Interval();

        while (first != end)
        {
            // find the set next set of rows for the current x
            var x = points[first].x;
            var last = first + 1;
            while (last != end)
            {
                if (x != points[last].x)
                    break;
                ++last;
            }
            //
            var p = stack.Last();
            if (!Object.ReferenceEquals(last_p, p))
            {
                last_p = p;
                intervals.Add(new Interval());  // will reallocate platform
                }
            // First pass, we remove intervals, and deal with add/remove on left/right
            // C# note: GetViewBetween is not log(n) https://stackoverflow.com/questions/9850975/why-sortedsett-getviewbetween-isnt-olog-n
            for (var curr = first; curr != last; ++curr)
            {
                var i = points[curr].i;
                var op = points[curr].op;
                comparator.h = i.h - 1;
                //var view = stack.GetViewBetween(ground, comparator);
                //var min = stack.Min();
                var min = ground;
                var c = min.CompareTo(comparator);
                //var view = stack.GetViewBetween(min, comparator);
                var view = stack.GetViewBetween(null, comparator);
                var prev = view.Last();
                if (op == -1)
                {
                    i.children[1] = new Drop(i.xmax, prev);
                    stack.Remove(i);
                }
                else if (op == +1)
                    i.children[0] = new Drop(i.xmin, prev);
            }
            // Second pass, we add intervals
            for (var curr = first; curr != last; ++curr)
            {
                var i = points[curr].i;
                var op = points[curr].op;
                if (op == +1)
                    stack.Add(i);

            }
            //
            var last_n = stack.Last();
            intervals[^1] = new Interval() { n=0, h=sky_h, xmin=x, xmax=-1, children = new Drop[2] { new Drop(0, last_n), new Drop() } };  // we do not know xmax at that stage
            //
            first = last;
        }
        //
        if (intervals[^1].xmin == ground.xmax)
            intervals.RemoveAt(intervals.Count - 1);
        // stitching xmin and xmax
        for (int i = N + 1, n = intervals.Count - 1; i < n; ++i)
            intervals[i].xmax = intervals[i + 1].xmin;
        intervals[^1].xmax = ground.xmax;
        // fix children by adding drop_point
        for (int i = N + 1, n = intervals.Count; i < n; ++i)
        {
            var interval = intervals[i];
            interval.n = i - 1;
            interval.children[0].drop_point = interval.middle();
        }
    }

    static void populate_costs(int N, List<Interval> intervals)
    {
        // set up weight for entry interval from the sky: O(N)
        for (int i = N + 1; i < intervals.Count; ++i)
        {
            var p = intervals[i];
            p.weight = p.children[0].interval!.n > 0 ? p.width() : 0.0;
        }

        // Accumulate costs from top to bottom: O(E) where E is 2*N at most
        var edges = new List<Edge>(2 * N);
        for (int i = intervals.Count - 1; i >= 0; --i)
        {
            var parent = intervals[i];
            var weight = 0.5 * parent.weight;
            if (weight == 0)
                continue;
            for (int side = 0; side < 2; ++side)
            {
                var child = parent.children[side].interval;
                if (!Object.ReferenceEquals(child, null) && child.n > 0)
                {
                    var drop_point = parent.children[side].drop_point;
                    var cost_l = weight * (drop_point - child.xmin);
                    var cost_r = weight * (child.xmax - drop_point);
                    child.weight += weight;
                    child.costs[0] += cost_l;
                    child.costs[1] += cost_r;
                    edges.Add(new Edge( parent, child, side, weight ));
                }
            }
        }
    
        // Accumulate costs from bottom to top: O(E) where E is 2*N at most
        for (int i = edges.Count - 1; i >= 0; --i)
        {
            var curr = edges[i];
            var parent = curr.parent;
            var child = curr.child;
            parent.costs[curr.side] += (child.costs[0] + child.costs[1]) * curr.weight / child.weight;
        }
    }

    static Result calc_dist(int N, List<Interval> intervals)
    {
            // base_cost
        var res = new Result();
        for (int i = N + 1, size = intervals.Count; i < size; ++i)
            res.base_cost += intervals[i].costs[0];

        // calculate min_delta, min_dir, min_p: O(N)
        for (int i = 0, size = N + 1; i < size; ++i)
        {
            var interval = intervals[i];
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

    public double getMinExpectedHorizontalTravelDistance(int N, int[] H, int[] A, int[] B) {
            // https://www.metacareers.com/profile/coding_puzzles/?puzzle=280063030479374
            // Constraints :
            //    1 ≤ N ≤ 500, 000
            //    1 ≤ Hi ≤ 999, 999
            //    1 ≤ Ai < Bi ≤ 1, 000, 000
            // Complexity: O(N * log(N))
            var intervals = build_intervals(N, H, A, B);  // O(N)
            add_entries(N, intervals);  // O(N * log(N))
            populate_costs(N, intervals);  // O(N)
            var res = calc_dist(N, intervals);  // O(N)
            var smallest_cost = (res.base_cost + res.min_delta) / (x_max - x_min);
            return smallest_cost;
        }

    public static void tests()
    {
        var s = new Solution();

        var N = 10_000;
        //var H = new List<int>(N);
        //var A = new List<int>(N);
        //var B = new List<int>(N);
        var H = new int[N];
        var A = new int[N];
        var B = new int[N];
        for (int i = 1; i < N; ++i)
        {
            H[i - 1] = N + 1 - i;
            A[i - 1] = N - i;
            B[i - 1] = N + i;
        }
        var ret = s.getMinExpectedHorizontalTravelDistance(A.Length, H, A, B);
        Console.WriteLine(ret);  // 666766.67000000004
    }

}

}
