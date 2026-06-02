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

namespace l2_scoreboard_interference2
{

class Solution {

    public int getMinProblemCount(int N, int[] S) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=503122501113518
        // Constraints:
        //      1 ≤ N ≤ 500,000
        //      1 ≤ i ≤ 1,000,000,000
        // Complexity: O(N)

        int max_score = 0;
        int second_max_score = 0;
        int two_remainder = 0;
        int one_remainder = 0;
        bool need_one = false;

        foreach (int score in S)
{
            var score_mod_3 = score % 3;
            two_remainder |= (score_mod_3 >> 1);
            one_remainder |= (score_mod_3 & 1);
            need_one = need_one || (score == 1);
            if (max_score < score)
            {
                second_max_score = max_score;
                max_score = score;
            }
            else if (second_max_score < score)
                second_max_score = score;
        }

        // number of solutions, without any optimisation
        int count = max_score / 3 + two_remainder + one_remainder;

        // not optimisation is possible if "two_remainder and one_remainder" is not true
        if (two_remainder * one_remainder != 1)
            return count;

        // replace "last +3" by "+1+2"
        if (max_score % 3 == 0)
            count -= 1;

        // replace last "+3+1" by "+2+2"
        if (need_one)  // exit early because 1 is required but at least one sum(i.e.it cannot be replaced)
            return count;
        if (max_score % 3 != 1)  // max_score does not have a 1 (so it cannot be replaced)
            return count;
        int tmp = max_score - second_max_score;
        if (!(tmp == 1 || tmp == 3)) // [ok, not ok(3), ok] || [not ok(1) | here | unimportant]
            count -= 1;
        return count;
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
            new Args { S=new int[] { 1, 2, 3, 4, 5 }, res=3 },
            new Args { S=new int[] { 4, 3, 3, 4 }, res=2 },
            new Args { S=new int[] { 2, 4, 6, 8 }, res=4 },
            new Args { S=new int[] { 8 }, res=3 },
            // extra1
            new Args { S=new int[] { 4, 3, 3, 4 }, res=2 },
            new Args { S=new int[] { 2, 4, 6, 8 }, res=4 },
            new Args { S=new int[] { 8 }, res=3 },
            new Args { S=new int[] { 1, 2, 3 }, res=2 },
            new Args { S=new int[] { 5, 7 }, res=3 },
            new Args { S=new int[] { 5, 9, 10 }, res=5 },
            new Args { S=new int[] { 5, 9, 11 }, res=4 },
            new Args { S=new int[] { 2, 4, 6 }, res=3 },
            new Args { S=new int[] { 2, 4, 7 }, res=4 },
            // extra2
            new Args { S=new int[] { 1, 2, 4 }, res=3 },
            new Args { S=new int[] { 2, 4 }, res=2 },
            new Args { S=new int[] { 4, 5 }, res=3 },
            new Args { S=new int[] { 9, 12 }, res=4 },
            new Args { S=new int[] { 11, 13 }, res=5 },
        };

        return test_all.TestAll.run_all_tests("l2_scoreboard_interference2", args_list, wrapper);   
    }

}

}
