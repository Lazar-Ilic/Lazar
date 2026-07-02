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

namespace l1_scoreboard_interference1
{

class Solution {

    public int getMinProblemCount(int N, int[] S) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=348371419980095
        // Constraints
        //      1 ≤ N ≤ 500,000             N is the number of scores
        //      1 ≤ Si ≤ 1,000,000,000      Si is a score
        // Complexity: O(N)

        // Note: the way to solve this problem is to count and his fairly simple
        // - the minimum number of problems scored 2 to solve all solutions
        // - the minimum number of problems scored 1 to solve all solutions (0 or 1)

        int min_number_of_twos = 0;
        int min_number_of_ones = 0;
        foreach (var score in S)
        {
            var number_of_twos = score / 2;
            var number_of_ones = score % 2;
            min_number_of_twos = Math.Max(min_number_of_twos, number_of_twos);
            min_number_of_ones = Math.Max(min_number_of_ones, number_of_ones);
        }
        return min_number_of_twos + min_number_of_ones;
    }

    class Args : test_all.Res<int>
    {
        public int[] S;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getMinProblemCount(p.S.Length, p.S);

        var args_list = new List<Args> {
            new Args { S=new int[] { 1, 2, 3, 4, 5, 6 }, res=4 },
            new Args { S=new int[] { 4, 3, 3, 4 }, res=3 },
            new Args { S=new int[] { 2, 4, 6, 8 }, res=4 },
        };

        return test_all.TestAll.run_all_tests("l1_scoreboard_interference1", args_list, wrapper);
    }

}

}
