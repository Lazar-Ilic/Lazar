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

namespace l3_slippery_strip
{

class Solution {

    struct Counts
    {
        public int empty;
        public int star;
        public int right;
        public int down;

        public Counts(int _empty = 0, int _star = 0, int _right = 0, int _down = 0)
        {
            empty = _empty;
            star = _star;
            right = _right;
            down = _down;
        }
    }

    static Counts get_counts(List<char> row, int[] counts)
    {
        counts['.'] = 0;
        counts['*'] = 0;
        counts['>'] = 0;
        counts['v'] = 0;
        foreach (var c in row)
        {
            int d = c;
            if (d >= counts.Length)
                d = '.';
            ++counts[d];
        }
        return new Counts( counts['.'], counts['*'], counts['>'], counts['v'] );
    }

    static int get_nb_coins_right_then_down3(List<char> row, long count_down, long count_right)
    {
        // complexity : O(C)
        if (count_down == 0)
            return 0;
        var k = row.FindIndex(obj => obj == 'v');
        var j = k != -1 ? k + 1 : 0;
        var new_row = new List<char>();
        new_row.InsertRange(new_row.Count, row.GetRange(j, row.Count - j));  // A bit lame
        new_row.InsertRange(new_row.Count, row.GetRange(0, j));
        int nb_coins_right_then_down = 0;
        int last = 0;
        while (count_right * count_down != 0)
        {
            var first = new_row.FindIndex(last, obj => obj == '>');
            last = new_row.FindIndex(first, obj => obj == 'v');
            var tmp = new_row.GetRange(first, last - first).Where(obj => obj == '*').Count();
            nb_coins_right_then_down = Math.Max(nb_coins_right_then_down, tmp);
            --count_down;
            count_right -= new_row.GetRange(first, last - first).Where(obj => obj == '>').Count();
        }
        return nb_coins_right_then_down;
    }


    public int getMaxCollectableCoins(int R, int C, char[,] G) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=2881982598796847
        // Constraints
        //      2 ≤ R, C ≤ 400, 000
        //      R∗C ≤ 800, 000
        //      Gi, j ∈{ ".' }, { '*", ">", "v" }
        //      Complexity: O(N), where N = R * C

        var H = new List<List<char>>(R);
        for (int j = 0; j < R; ++j)
        {
            var col = new List<char>(C);
            H.Add(col);
            for (int i = 0; i < C; ++i)
                col.Add(G[j, i]);
        }

        var counts = new int[256];
        for (int i = 0; i < counts.Length; ++i)
            counts[i] = 0;
        int res = 0;
        for (int i = 0; i < H.Count; ++i)
        {
            var row = H[H.Count - i - 1];
            var count = get_counts(row, counts);
            var nb_coins_immediately_down = Math.Min(count.star, 1);
            if (count.right == C)
                res = 0;
            else if (count.right == 0)
                res += nb_coins_immediately_down;
            else
            {
                var nb_coins_right_then_down = get_nb_coins_right_then_down3(row, count.down, count.right);
                var nb_coins_right_forever = count.down == 0 ? count.star : 0;
                res = Math.Max(nb_coins_immediately_down + res, Math.Max(nb_coins_right_then_down + res, nb_coins_right_forever));
            }
        }
        return res;
    }

    class Args : test_all.Res<int>
    {
        public char[,] G;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getMaxCollectableCoins(p.G.GetLength(0), p.G.GetLength(1), p.G);

        var args_list = new List<Args> {
            new Args { G=new char[,] { { '.', '*', '*', '*' }, { '*', '*', 'v', '>', }, { '.', '*', '.', '.' } }, res=4 },
            new Args { G=new char[,] { { '>', '*', '*' }, { '*', '>', '*' } , { '*', '*', '>' } }, res=4 },
            new Args { G=new char[,] { { '>', '>' }, { '*', '*' } }, res=0 },
            new Args { G=new char[,] { { '>', '*', 'v', '*', '>', '*' }, { '*', 'v', '*', 'v', '>', '*' }, { '.', '*', '>', '.', '.', '*' }, { '.', '*', '.', '.', '*', 'v' } }, res=6 },
            // extra1
            new Args { G=new char[,] { { } }, res=0 },
            new Args { G=new char[,] { { '.'  } }, res=0 },
            new Args { G=new char[,] { { 'v' } }, res=0 },
            new Args { G=new char[,] { { '>' } }, res=0 },
            new Args { G=new char[,] { { '*' } }, res=1 },
            // extra2
            new Args { G=new char[,] { { '.' }, { '.' }, { '>' }, { '*' } }, res=0 },
            new Args { G=new char[,] { { '.' }, { '*' }, { '>' }, { '*' } }, res=1 },
            new Args { G=new char[,] { { '.' }, { '*' }, { '>' }, { '.' } }, res=1 },
            new Args { G=new char[,] { { '*' }, { '.' }, { '>' }, { '.' } }, res=1 },
            new Args { G=new char[,] { { '*', '*', '*' }, { '.', '.', '.' }, { '>', 'v', 'v' }, { '.', '.', '.' } }, res=1 },
            // extra3
            new Args { G=new char[,] { { '*', '.', '.', '.', '.' }, { '.', '*', '.', '.', '.' }, { '.', '.', '*', '.', '.' }, { '.', '.', '.', '*', '.' } }, res=4 },
            new Args { G=new char[,] { { '.', '.', '.', '.' }, { '.', '.', '.', '.' }, { '.', '.', '.', '.' }, { '.', '.', '.', '.' } }, res=0 },
            new Args { G=new char[,] { { '*', '*', '*', '>' }, { '.', '.', '.', '.' } }, res=3 },
            new Args { G=new char[,] { { '.', '.', '.', '.' } }, res=0 },
            new Args { G=new char[,] { { 'v', 'v', 'v', 'v' } }, res=0 },
            new Args { G=new char[,] { { 'v', 'v', 'v', 'v' }, { '.', '.', '.', '.' }, { '>', '>', '>', '>' } }, res=0 },
            // extra4
            new Args { G=new char[,] { { '*', '*', '*', '*', '*', '*' }, { '.', '.', '.', '.', '.', '.' }, { '>', '*', '>', 'v', 'v', 'v' }, { '.', '.', '.', '.', '.', '.' } }, res=2 },
            new Args { G=new char[,] { { '*', '*', '*', '*', '*' }, { '.', '.', '.', '.', '.' }, { '>', '>', 'v', 'v', 'v' }, { '.', '.', '.', '.', '.' } }, res=1 },
        };

        return test_all.TestAll.run_all_tests("l3_slippery_strip", args_list, wrapper);
    }

}

}
