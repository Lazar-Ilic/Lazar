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

namespace l2_director_photography2
{
class Solution {

    struct Counts
    {
        public int p;
        public int b;

        public Counts(int _p = 0, int _b = 0)
        {
            p = _p;
            b = _b;
        }

        public Counts(Counts other)
        {
            p = other.p;
            b = other.b;
        }
    }

    public static T _getArtisticPhotographCount<T>(int N, string C, int X, int Y) where T : unmanaged
    {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=870874083549040
        // Constraints
        //      1 ≤ N ≤ 200         N is the number of cells in a row
        //      1 ≤ X ≤ Y ≤ N       X,Y are the distance between a photograph and an actor
        // Complexity: O(N) ~ O(N * (Y-X+1)) because Y-X << N

        // Note: the solution is not really elegant speed-wise, but focuses on the algorithm
        // The solution calculates the pairs of sub string (of width w), surrounding 'A' characters, this is O(N)
        var w = Y + 1;  // w = width of the interval
        var count = new Counts();
        var counts = new List<Counts>(C.Length + w * 2);
        for (int i = 0; i < w; ++i)
            counts.Add(new Counts());
        foreach (char ci in C)
        {
            if (ci == 'P')
                ++count.p;
            else if (ci == 'B')
                ++count.b;
            counts.Add(new Counts(count));
        }
        var last = counts[^1];
        for (int i = 0; i < w; ++i)
            counts.Add(last);

        // To make things more readable, we are finding first the point where 'A' is found: O(N)
        var possible = new List<int>(C.Length);
        int j = w;
        foreach (var ci in C)
        {
            if (ci == 'A')
                possible.Add(j);
            ++j;
        }

        // Count PABs : O(N)
        long nb = 0;
        foreach (int i in possible)
        {
            var a = counts[i - X].p - counts[i - Y - 1].p;
            var b = counts[i + Y].b - counts[i + X - 1].b;
            nb += (long)a * (long)b;
        }

        // Count BAPs : O(N)
        foreach (int i in possible)
        {
            var a = counts[i - X].b - counts[i - Y - 1].b;
            var b = counts[i + Y].p - counts[i + X - 1].p;
            nb += (long)a * (long)b;
        }

        return (T)Convert.ChangeType(nb, typeof(T));
    }

    public long getArtisticPhotographCount(int N, string C, int X, int Y) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=156565259776376
        // Constraints
        //      1 ≤ N ≤ 300,000     N is the number of cells in a row
        //      1 ≤ X ≤ Y ≤ N       X,Y are the distance between a photograph and an actor
        // Complexity: O(N) ~ O(N * (Y-X+1)) because Y-X << N

        return _getArtisticPhotographCount<long>(N, C, X, Y);
    }

    class Args : test_all.Res<long>
    {
        public string C;
        public int X;
        public int Y;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, long> wrapper = (Args p) => s.getArtisticPhotographCount(p.C.Length, p.C, p.X, p.Y);

        var args_list = new List<Args> {
            new Args { C="APABA", X=1, Y=2, res=1 },
            new Args { C="APABA", X=2, Y=3, res=0 },
            new Args { C=".PBAAP.B", X=1, Y=3, res=3 },
            // extra1
            new Args { C="PP.A.BB.B", X=1, Y=3, res=4 },
        };

        return test_all.TestAll.run_all_tests("l2_director_photography2", args_list, wrapper);
    }

}

}
