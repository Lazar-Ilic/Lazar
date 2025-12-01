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

namespace l4_mathematical_art
{

using Stroke = System.Tuple<long, long, long>;
using StrokeEnd = System.Tuple<long, long>;

class Solution {

    static (List<Stroke>, List<Stroke>) read_strokes(int N, List<int> L, String D)
    {
        // Complexity: O(N)
        var hor_strokes = new List<Stroke>(2 * N);
        var ver_strokes = new List<Stroke>(2 * N);
        long x0 = 0, y0 = 0;
        long x1 = 0, y1 = 0;
        for (int i = 0; i < N; ++i)
        {
            var length = L[i];
            var direction = D[i];
            if (direction == 'R')
            {
                x1 = x0 + length;
                y1 = y0;
                hor_strokes.Add(System.Tuple.Create( y0, x0, -1L ));
                hor_strokes.Add(System.Tuple.Create( y0, x1, +1L ));
            }
            else if (direction == 'L')
            {
                x1 = x0 - length;
                y1 = y0;
                hor_strokes.Add(System.Tuple.Create( y0, x1, -1L ));
                hor_strokes.Add(System.Tuple.Create( y0, x0, +1L ));
            }
            else if (direction == 'U')
            {
                x1 = x0;
                y1 = y0 + length;
                ver_strokes.Add(System.Tuple.Create( x0, y0, -1L ));
                ver_strokes.Add(System.Tuple.Create( x0, y1, +1L ));
            }
            else if (direction == 'D')
            {
                x1 = x0;
                y1 = y0 - length;
                ver_strokes.Add(System.Tuple.Create( x0, y1, -1L ));
                ver_strokes.Add(System.Tuple.Create( x0, y0, +1L ));
            }
            x0 = x1;
            y0 = y1;
        }
        return ( hor_strokes, ver_strokes );
    }

    static void merge_strokes(List<Stroke> strokes)
    {
        // Complexity: O(N)
        if (strokes.Count == 0)
            return;
        /*var strokes_end = strokes.Count;
        var strokes_it = 0;
        var strokes_out = 0;
        var (x0, y0, total) = strokes[strokes_it++];
        for (; strokes_it != strokes_end; ++strokes_it)
        {
            (x1, y1, inc) = *strokes_it;
            if (x0 != x1)
            {
                x0 = x1;
                y0 = y1;
                total = inc;
                continue;
            }
            if (total == 0)
                y0 = y1;
            total += inc;
            if (total == 0)
                *strokes_out++ = { x0, y0, y1 };
        }
        //const auto size = std::distance(std::begin(strokes), strokes_out);
        //strokes.resize(static_cast<uint32_t>(size));  // FIXME*/
    }

    public long getPlusSignCount(int N, int[] L, string D) {
        return 0;
    }

}

}
