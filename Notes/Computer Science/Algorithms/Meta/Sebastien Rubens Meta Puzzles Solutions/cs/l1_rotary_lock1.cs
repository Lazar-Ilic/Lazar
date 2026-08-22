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

namespace l1_rotary_lock1
{

class Solution {

    public long getMinCodeEntryTime(int N, int M, int[] C) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=990060915068194
        // Constraints
        //      3 ≤ N ≤ 50,000,000      N is the number of integers
        //      1 ≤ M ≤ 1,000           M is the number of locks
        //      1 ≤ Ci ≤ N              Ci is the combination
        // Complexity: O(M)

        // The following is O(N)
        int pos = 1;
        long nb = 0;
        foreach (var target in C)
        {
            var positive_move = (target - pos) % N;  // positive move
            positive_move = positive_move < 0 ? positive_move + N : positive_move;  // modulo can be negative in C++
            var negative_move = N - positive_move;
            nb += Math.Min(positive_move, negative_move);
            pos = target;
        }
        return nb;
    }

    class Args : test_all.Res<long>
    {
        public int N;
        public int[] C;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, long> wrapper = (Args p) => s.getMinCodeEntryTime(p.N, p.C.Length, p.C);

        var args_list = new List<Args> {
            new Args { N=3, C=new int[] { 1, 2, 3 }, res=2 },
            new Args { N=10, C=new int[] { 9, 4, 4, 8 }, res=11 },
        };

        return test_all.TestAll.run_all_tests("l1_rotary_lock1", args_list, wrapper);
    }

}

}
