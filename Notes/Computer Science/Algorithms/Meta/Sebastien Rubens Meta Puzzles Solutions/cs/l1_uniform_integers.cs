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

namespace l1_uniform_integers
{

class Solution {

    static int len_str(long nb)
    {
        if (nb == 0)  // not necessary due to problem definition
            return 1;
        int ret = 0;
        for (; nb > 0; nb /= 10, ++ret);
        return ret;
    }

    static long ones(int log_value)
    {
        long ret = 0;
        for (int i = 0; i < log_value; ++i, ret = ret * 10 + 1);
        return ret;
    }

    public int getUniformIntegerCountInInterval(long A, long B) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=228269118726856
        // Constraints:
        //      1 ≤ A ≤ B ≤ 10^12
        // Complexity: O(log(max(A, B)))
        //      logarithmic on the number of digits to represent the integers
        //      The python version works using integer<->string conversion, which is not great

        // Each of the following lines is O(log(max(A, B)))
        var len_a = len_str(A);
        var len_b = len_str(B);
        var tmp_a = ones(len_a);
        var tmp_b = ones(len_b);

            // Everything else is O(1)
        var nb_a = (tmp_a * 10 - A) / tmp_a;
        var nb_b = B / tmp_b;
        var nb_m = len_b - len_a >= 2 ? 9 * (len_b - len_a - 1) : 0;
        var nb = nb_a + nb_m + nb_b;
        if (len_a == len_b)
            nb -= 9;
        return (int)(nb);
    }

    class Args : test_all.Res<int>
    {
        public long A;
        public long B;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getUniformIntegerCountInInterval(p.A, p.B);

        var args_list = new List<Args> {
            new Args { A=75, B=300, res=5 },
            new Args { A=1, B=9, res=9 },
            new Args { A=999999999999, B=999999999999, res=1 },
            // extra1
            new Args { A=1, B=1_000_000_000_000, res=108 },
            // extra2
            new Args { A=10, B=99, res=9 },
            new Args { A=11, B=98, res=8 },
            new Args { A=21, B=89, res=7 },
            new Args { A=22, B=88, res=7 },
            new Args { A=23, B=87, res=5 },
            // extra3
            new Args { A=11, B=88, res=8 },
            new Args { A=11, B=98, res=8 },
            new Args { A=11, B=99, res=9 },
        };

        return test_all.TestAll.run_all_tests("l1_uniform_integers", args_list, wrapper);
    }

}

}
