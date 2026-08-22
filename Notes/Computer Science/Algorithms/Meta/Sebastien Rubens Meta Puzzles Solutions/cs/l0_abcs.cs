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

namespace l0_abcs
{
class Solution {
  
    public int getSum(int A, int B, int C) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=513411323351554
        // Constraints
        //   1 ≤ A,B,C ≤ 100
        // Complexity: O(1)

        return A + B + C;
    }

    class Args : test_all.Res<int>
    {
        public int A, B, C;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getSum(p.A, p.B, p.C);

        var args_list = new List<Args> {
            new Args { A=1, B=2, C=3, res=6 },
            new Args { A=100, B=100, C=100, res=300 },
            new Args { A=85, B=16, C=93, res=194 },
        };

        return test_all.TestAll.run_all_tests("l0_abcs", args_list, wrapper);
    }

}

}
