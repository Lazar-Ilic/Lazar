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

namespace l0_battleship
{
class Solution {

    public double getHitProbability(int R, int C, int[,] G)
    {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=3641006936004915
        // Constraints
        //      1 ≤ R,C ≤ 100       R,C is the number of rows,columns
        //      0 ≤ Gi,j ≤ 1
        // Complexity: O(N), where N=R*C

        // Note: the solution prevents over/undersized rows/columns and assumes missing elements are 0
        int ret = 0;
        foreach (int elt in G)
                ret += elt;

        return ret / (double)(R * C);
    }

    class Args : test_all.Res<double>
    {
        public int[,] G;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, double> wrapper = (Args p) => s.getHitProbability(p.G.GetLength(0), p.G.GetLength(1), p.G);

        var args_list = new List<Args> {
            new Args { G=new int[,] {{ 0, 0, 1 }, { 1, 0, 1 } }, res=0.5 },
            new Args { G=new int[,] {{ 1, 1 }, { 1, 1 } }, res=1.0 },
            // extra1
            new Args { G=new int[,] {{ 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 } }, res=0.25 },
        };

        return test_all.TestAll.run_all_tests("l0_battleship", args_list, wrapper, 0.000_001);
    }

}

}
