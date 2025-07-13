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

namespace l2_hops
{

class Solution {

    public long getSecondsRequired(long N, int F, long[] P) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=977526253003069
        // Constraints:
        //      2 ≤ N ≤ 10^12
        //      1 ≤ F ≤ 500,000
        //      1 ≤ Pi ≤ N−1
        // Complexity: O(N), but could be O(1) if P was sorted

        // When you think about it, the solution is very simple!
        if (P.Length == 0)
            return 0;
        return N - P.Min();
    }

    class Args : test_all.Res<long>
    {
        public int F;
        public long[] P;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, long> wrapper = (Args p) => s.getSecondsRequired(p.F, p.P.Length, p.P);

        var args_list = new List<Args> {
            new Args { F=3, P=new long[] { 1 }, res=2 },
            new Args { F=6, P=new long[] { 5, 2, 4 }, res=4 },
        };

        return test_all.TestAll.run_all_tests("l2_hops", args_list, wrapper);
    }

}

}
