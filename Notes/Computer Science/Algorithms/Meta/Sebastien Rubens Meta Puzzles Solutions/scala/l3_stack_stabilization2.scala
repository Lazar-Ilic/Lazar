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

package l3_stack_stabilization2

import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._

object Solution {
    def getMinimumSecondsRequired(N: Int, R: Array[Int], A: Int, B: Int): Long = {
        val _A = A.toLong
        val _B = B.toLong

        if (N == 0 || R.isEmpty)
            return 0

        val U = R.clone()

        // Extend the range of input data
        var total_cost = 0L
        val costs = ArrayBuffer.fill(N)(0)

        val intervals = new ArrayBuffer[Int](N)
        intervals += 0
        for (i <- 1 until N)
        {
            val Uj = U(i - 1) + 1
            val Ui = U(i)
            // inflate first
            if (Uj > Ui) // if (min_inflate > 0)
            {
                val min_inflate = Uj - Ui // fits in 32bits
                total_cost += min_inflate * _A // fits in 64-bits
                U(i) += min_inflate // fits in 32bits by definition
                costs(i) = min_inflate // fits in 32bits by definition
            }
            // track continuous intervals (note: this is not a "else if"!)
            if (Uj < Ui) // if (min_inflate < 0)
            {
                intervals += i
                //break
            }
            else
            {
                // deflate eventually
                breakable {
                    while (true) {
                        val first = intervals.last
                        val nb_tot = 1 + i - first
                        //
                        var nb_pos = 0
                        var min_positive1 = 0
                        for (curr <- first until i + 1) {
                            val value = costs(curr)
                            if (value > 0) {
                                nb_pos += 1
                                min_positive1 = if (min_positive1 > 0) min_positive1.min(value) else value
                            }
                        }
                        //
                        val min_positive2 = if (first > 0) (U(first) - U(first - 1)) else U(0)
                        val min_positive = min_positive1.min(min_positive2 - 1)
                        val nb_neg = nb_tot - nb_pos
                        val cost_change = (nb_neg * _B - nb_pos * _A) * min_positive
                        if (cost_change >= 0)
                            break
                        total_cost += cost_change
                        for (j <- first to i) {
                            costs(j) -= min_positive
                            U(j) -= min_positive
                        }
                        if (first > 0) {
                            if (U(first) == U(first - 1) + 1)
                                //intervals.trimEnd(1) // FIXME: must use this on Meta's website
                                intervals.dropRightInPlace(1) // FIXME: >= 2.13.1 (does not work on Meta's website)
                        }
                        if (min_positive <= 0)
                            break
                    }
                }
            }
        }
        return total_cost
    }


    class Args(val R: Array[Int],
               val A: Int,
               val B: Int,
               val res: Long ) extends test.Result[Long] {
        override def get_result(): Long = res
    }

    def tests(): Int =
    {
        def _getSecondsElapsed(p: Args): Long = getMinimumSecondsRequired(p.R.size, p.R, p.A, p.B)

        val wrapper = (p: Args) => _getSecondsElapsed(p)

        val args_list = Array[Args](
            new Args(Array[Int](2, 5, 3, 6, 5), 1, 1, 5),
            new Args(Array[Int](100, 100, 100), 2, 3, 5),
            new Args(Array[Int](100, 100, 100), 7, 3, 9),
            new Args(Array[Int](6, 5, 4, 3), 10, 1, 19),
            new Args(Array[Int](100, 100, 1, 1), 2, 1, 207),
            new Args(Array[Int](6, 5, 2, 4, 4, 7), 1, 1, 10),
            // extra1
            new Args(Array[Int](10, 6, 2), 2, 1, 15),
            new Args(Array[Int](1, 2, 3, 4, 5, 6), 1, 1, 0),
            new Args(Array[Int](6, 5, 4, 3, 2, 1), 1, 1, 18),
            // extra2
            new Args(Array[Int](4, 6, 2), 2, 1, 9),
            new Args(Array[Int](6, 5, 2, 4, 4, 7), 1, 1, 10),
            new Args(Array[Int](2, 5, 3, 6, 5), 1, 1, 5),
            new Args(Array[Int](2, 3, 8, 1, 7, 6), 2, 1, 15),
            new Args(Array[Int](5, 4, 3, 6, 8, 1, 10, 11, 6, 1), 4, 1, 85),
            new Args(Array[Int](3, 4, 7, 8, 2), 4, 1, 24),
            new Args(Array[Int](1, 1, 1, 1, 1), 4, 1, 40),
            new Args(Array[Int](1, 1, 1, 1, 1), 1, 4, 10),
            new Args(Array[Int](8, 6, 4, 2), 1, 4, 18),
            new Args(Array[Int](1_000_000_000, 500_000_000, 200_000_000, 1_000_000), 1, 4, 2_299_000_006L)
        )

        return test.TestAll.run_all_tests("l3_stack_stabilization2", args_list, wrapper)
    }
}
