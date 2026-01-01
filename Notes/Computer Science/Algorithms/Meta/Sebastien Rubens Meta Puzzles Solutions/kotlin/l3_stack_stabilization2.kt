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

package l3_stack_stabilization2

fun getMinimumSecondsRequired(N: Int, R: Array<Int>, A: Int, B: Int): Long {
    val _A = A.toLong();
    val _B = B.toLong();

    if (N == 0 || R.isEmpty())
        return 0;

    val U = R.clone();

    // Extend the range of input data
    var total_cost = 0L;
    val costs = ArrayList<Int>(N);
    repeat(N) { index -> costs.add(0) }

    val intervals = ArrayList<Int>(N);
    intervals.add(0);
    for (i in 1 until N)
    {
        val Uj = U[i - 1] + 1;
        val Ui = U[i];
        // inflate first
        if (Uj > Ui)  // if (min_inflate > 0)
        {
            val min_inflate = Uj - Ui;  // fits in 32bits
            total_cost += min_inflate * _A;  // fits in 64-bits
            U[i] += min_inflate;  // fits in 32bits by definition
            costs[i] = min_inflate;  // fits in 32bits by definition
        }
        // track continous intervals (note: this is not a "else if"!)
        if (Uj < Ui)  // if (min_inflate < 0)
        {
            intervals.add(i);
            continue;
        }
        // deflate eventually
        while (true)
        {
            val first = intervals.last();
            val nb_tot = 1 + i - first;
            //
            var nb_pos = 0;
            var min_positive1 = 0;
            for (curr in first .. i)
            {
                val value = costs[curr];
                if (value > 0)
                {
                    ++nb_pos;
                    min_positive1 = if (min_positive1 > 0) minOf(min_positive1, value) else value;
                }
            }
            //
            val min_positive2 = if (first > 0) (U[first] - U[first - 1]) else U[0];
            val min_positive = minOf(min_positive1, min_positive2 - 1);
            val nb_neg = nb_tot - nb_pos;
            val cost_change = (nb_neg * _B - nb_pos * _A) * min_positive;
            if (cost_change >= 0)
                break;
            total_cost += cost_change;
            for (j in first..i)
            {
                costs[j] -= min_positive;
                U[j] -= min_positive;
            }
            if (first > 0)
            {
                if (U[first] == U[first - 1] + 1)
                    intervals.removeLast();
            }
            if (min_positive <= 0)
                break;
        }
    }
    return total_cost;
}

class Args(
    val R: Array<Int>,
    val A: Int,
    val B: Int,
    val res: Long, )  : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMinimumSecondsRequired(p.R.size, p.R, p.A, p.B) };

    val args_list: List<Args> = listOf(
        Args(arrayOf(2, 5, 3, 6, 5), 1, 1, 5),
        Args(arrayOf(100, 100, 100), 2, 3, 5),
        Args(arrayOf(100, 100, 100), 7, 3, 9),
        Args(arrayOf(6, 5, 4, 3), 10, 1, 19),
        Args(arrayOf(100, 100, 1, 1), 2, 1, 207),
        Args(arrayOf(6, 5, 2, 4, 4, 7), 1, 1, 10),
        // extra1
        Args(arrayOf(10, 6, 2), 2, 1, 15),
        Args(arrayOf(1, 2, 3, 4, 5, 6), 1, 1, 0),
        Args(arrayOf(6, 5, 4, 3, 2, 1), 1, 1, 18),
        // extra2
        Args(arrayOf(4, 6, 2), 2, 1, 9),
        Args(arrayOf(6, 5, 2, 4, 4, 7), 1, 1, 10 ),
        Args(arrayOf(2, 5, 3, 6, 5), 1, 1, 5),
        Args(arrayOf(2, 3, 8, 1, 7, 6), 2, 1, 15),
        Args(arrayOf(5, 4, 3, 6, 8, 1, 10, 11, 6, 1), 4, 1, 85),
        Args(arrayOf(3, 4, 7, 8, 2), 4, 1, 24),
        Args(arrayOf(1, 1, 1, 1, 1), 4, 1, 40),
        Args(arrayOf(1, 1, 1, 1, 1), 1, 4, 10),
        Args(arrayOf(8, 6, 4, 2), 1, 4, 18),
        Args(arrayOf(1_000_000_000, 500_000_000, 200_000_000, 1_000_000), 1, 4, 2_299_000_006),
    );

    return test.run_all_tests("l3_stack_stabilization2", args_list, wrapper);
}
