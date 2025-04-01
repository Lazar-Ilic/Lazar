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

package l2_director_photography2

import scala.collection.mutable.ArrayBuffer

object Solution {
    def getArtisticPhotographCount(N: Int, C: String, X: Int, Y: Int): Long = {

        def _getArtisticPhotographCount(N: Int, C: String, X: Int, Y: Int): Long =
        {
            val _X = X
            val _Y = Y

            class Counts(var p: Int, var b: Int) {}

            // count the number of Ps or Bs till a position i: O(N)
            val w = _Y + 1
            val count = new Counts(0, 0)
            val counts = new ArrayBuffer[Counts](C.length + w.toInt * 2)
            for (i <- 0 until w) // add space at the beginning to avoid special treatment of indices later
                counts += new Counts(0, 0)
            for (ci <- C) {
                if (ci == 'P')
                    count.p += 1
                else if (ci == 'B')
                    count.b += 1
                counts += new Counts(count.b, count.p)
            }
            val last = counts.last
            for (i <- 0 until w) // add space at the end to avoid special treatment of indices later
                counts += last

            // To make things more readable, we are finding first the point where 'A' is found: O(N)
            val possible = new ArrayBuffer[Int](C.length)
            var j = w
            for (ci <- C) {
                if (ci == 'A')
                    possible += j
                j += 1
            }

            // Count PABs : O(N)
            val X1 = _X - 1
            val Y1 = _Y + 1
            var nb: Long = 0
            for (i <- possible) {
                val a = counts(i - _X).p - counts(i - Y1).p
                val b = counts(i + _Y).b - counts(i + X1).b
                nb += a.toLong * b.toLong
            }

            // Count BAPs : O(N)
            for (i <- possible) {
                val a = counts(i - _X).b - counts(i - Y1).b
                val b = counts(i + _Y).p - counts(i + X1).p
                nb += a.toLong * b.toLong
            }

            return nb
        }

        return _getArtisticPhotographCount(N, C, X, Y).toLong
    }

    class Args(val C: String,
               val X: Int,
               val Y: Int,
               val res: Long ) extends test.Result[Long] {
        override def get_result(): Long = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getArtisticPhotographCount(p.C.length, p.C, p.X, p.Y)

        val args_list = Array[Args](
            new Args( "APABA", 1, 2, 1 ),
            new Args( "APABA", 2, 3, 0 ),
            new Args( ".PBAAP.B", 1, 3, 3 ),
            // extra1
            new Args( "PP.A.BB.B", 1, 3, 4 )
        )

        return test.TestAll.run_all_tests("l2_director_photography2", args_list, wrapper)
    }
}
