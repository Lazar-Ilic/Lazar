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

namespace l1_stack_stabilization1
{

class Solution {

     public int getMinimumDeflatedDiscCount(int N, int[] R) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=183894130288005
        // Constraints
        //      1 ≤ N  ≤ 50                 N is the number of inflatable discs
        //      1 ≤ Ri ≤ 1,000,000,000      Ri is a disc radius
        // Complexity: O(N)

        // FIMXE: use iterators?
        int nb = 0;
        int it = R.Length - 1;
        var current_radius = R[it--];
        for (; it != -1; --it)
        {
            var next_radius = R[it];
            var target_radius = current_radius - 1;
            if (target_radius <= 0)
                return -1;
            nb += target_radius < next_radius ? 1 : 0;
            current_radius = Math.Min(next_radius, target_radius);
        }
        return nb;
    }

    class Args : test_all.Res<int>
    {
        public int[] S;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getMinimumDeflatedDiscCount(p.S.Length, p.S);

        var args_list = new List<Args> {
            new Args { S=new int[] { 2, 5, 3, 6, 5 }, res=3 },
            new Args { S=new int[] { 100, 100, 100 }, res=2 },
            new Args { S=new int[] { 6, 5, 4, 3 }, res=-1 },
        };

        return test_all.TestAll.run_all_tests("l1_stack_stabilization1", args_list, wrapper);
    }

}

}
