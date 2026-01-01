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

namespace l3_stack_stabilization2
{

class Solution {

    public long getMinimumSecondsRequired(int N, int[] R, int A, int B) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=290955626029019
        // Constraints :
        //      1 ≤ N    ≤ 50
        //      1 ≤ Ri   ≤ 1,000,000,000
        //      1 ≤ A, B ≤ 100
        // Complexity: O(N ^ 2)

        if (N == 0 || R.Length == 0)
            return 0;

        var U = new List<int>(R);  // copy

        // Extend the range of input data
        long _A = A;
        long _B = B;

        //
        long total_cost = 0;
        var costs = new List<int>(N);
        for (int i = 0; i < N; ++i)
            costs.Add(0);
        var intervals = new List<int>(N);
        intervals.Add(0);
        for (int i = 1; i < N; ++i)
        {
            int min_inflate = U[i - 1] - U[i] + 1;  // fits in 32bits
            // inflate first
            if (min_inflate > 0)
            {
                total_cost += min_inflate * _A;  // fits in 64-bits
                U[i] += min_inflate;  // fits in 32bits by definition
                costs[i] = min_inflate;  // fits in 32bits by definition
            }
            // track continuous intervals
            if (min_inflate < 0)
            {
                intervals.Add(i);
                continue;
            }
            // deflate eventually
            while (true)
            {
                var first = intervals[intervals.Count - 1];
                var nb_tot = 1 + i - first;
                //
                int nb_pos = 0;
                int min_positive1 = 0;
                for (int curr = first, last = i + 1; curr < last; ++curr)
                {
                    var value = costs[curr];
                    if (value > 0)
                    {
                        ++nb_pos;
                        min_positive1 = min_positive1 > 0 ? Math.Min(min_positive1, value) : value;
                    }
                }
                //
                int min_positive2 = first > 0 ? (U[first] - U[first - 1]) : U[0];
                int min_positive = Math.Min(min_positive1, min_positive2 - 1);
                int nb_neg = nb_tot - nb_pos;
                long cost_change = (nb_neg * _B - nb_pos * _A) * min_positive;
                if (cost_change >= 0)
                    break;
                total_cost += cost_change;
                for (int j = first; j <= i; ++j)
                {
                    costs[j] -= min_positive;
                    U[j] -= min_positive;
                }
                if (first > 0)
                {
                    if (U[first] == U[first - 1] + 1)
                        intervals.RemoveAt(intervals.Count - 1);
                }
                if (min_positive <= 0)
                    break;
            }
        }
        return total_cost;
    }

    class Args : test_all.Res<long>
    {
        public int[] R;
        public int A;
        public int B;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, long> wrapper = (Args p) => s.getMinimumSecondsRequired(p.R.Length, p.R, p.A, p.B);

        var args_list = new List<Args> {
            new Args { R=new int[] { 2, 5, 3, 6, 5 }, A=1, B=1, res=5 },
            new Args { R=new int[] { 100, 100, 100 }, A=2, B=3, res=5 },
            new Args { R=new int[] { 100, 100, 100 }, A=7, B=3, res=9 },
            new Args { R=new int[] { 6, 5, 4, 3 }, A=10, B=1, res=19 },
            new Args { R=new int[] { 100, 100, 1, 1 }, A=2, B=1, res=207 },
            new Args { R=new int[] { 6, 5, 2, 4, 4, 7 }, A=1, B=1, res=10 },
            // extra1
            new Args { R=new int[] { 10, 6, 2 }, A=2, B=1, res=15 },
            new Args { R=new int[] { 1, 2, 3, 4, 5, 6 }, A=1, B=1, res=0 },
            new Args { R=new int[] { 6, 5, 4, 3, 2, 1 }, A=1, B=1, res=18 },
            // extra2
            new Args { R=new int[] { 4, 6, 2 }, A=2, B=1, res=9 },
            new Args { R=new int[] { 6, 5, 2, 4, 4, 7 }, A=1, B=1, res=10 },
            new Args { R=new int[] { 2, 5, 3, 6, 5 }, A=1, B=1, res=5 },
            new Args { R=new int[] { 2, 3, 8, 1, 7, 6 }, A=2, B=1, res=15 },
            new Args { R=new int[] { 5, 4, 3, 6, 8, 1, 10, 11, 6, 1 }, A=4, B=1, res=85 },
            new Args { R=new int[] { 3, 4, 7, 8, 2 }, A=4, B=1, res=24 },
            new Args { R=new int[] { 1, 1, 1, 1, 1 }, A=4, B=1, res=40 },
            new Args { R=new int[] { 1, 1, 1, 1, 1 }, A=1, B=4, res=10 },
            new Args { R=new int[] { 8, 6, 4, 2 }, A=1, B=4, res=18 },
            new Args { R=new int[] { 1_000_000_000, 500_000_000, 200_000_000, 1_000_000 }, A=1, B=4, res=2_299_000_006 },
        };

        return test_all.TestAll.run_all_tests("l3_rabbit_hole2", args_list, wrapper);
    }

}

}
