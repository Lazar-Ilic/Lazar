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

package l2_tunnel_time

import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._

class Tunnel(val a: Long,
             val b: Long) extends Ordered[Tunnel] {
    @`inline` def length = b - a
    def compare(that: Tunnel): Int = this.a compare that.a
}

object Solution {
    def getSecondsElapsed(C: Long, N: Int, A: Array[Long], B: Array[Long], K: Long): Long = {
        val tunnels = new ArrayBuffer[Tunnel](N)
        for ((a, b) <- A.zip(B))
            tunnels += new Tunnel(a, b)

        var tunnel_time_total: Long = 0L
        for (tunnel <- tunnels)
            tunnel_time_total += tunnel.length

        val number_of_complete_track: Long = K.toLong / tunnel_time_total // O(1)
        var total_time_left: Long = K - number_of_complete_track * tunnel_time_total // O(1)
        var travel_time: Long = number_of_complete_track * C // O(1)

        if (total_time_left == 0L)
            travel_time -= C - B.max // O(N)
        else {
            tunnels.sortInPlace()
            breakable {
                for (tunnel <- tunnels) {
                    val tunnel_length = tunnel.length
                    if (tunnel_length >= total_time_left) {
                        travel_time += tunnel.a + total_time_left
                        break
                    }
                    total_time_left -= tunnel_length
                }
            }
        }
        return travel_time
    }


    class Args(val C: Long,
               val A: Array[Long],
               val B: Array[Long],
               val K: Long,
               val res: Long ) extends test.Result[Long] {
        override def get_result(): Long = res
    }

    def tests(): Int =
    {
        def _getSecondsElapsed(p: Args): Long = {
            val min_len = p.A.size.min(p.B.size)
            return getSecondsElapsed (p.C, min_len, p.A, p.B, p.K)
        }

        val wrapper = (p: Args) => _getSecondsElapsed(p)

        val args_list = Array[Args](
            new Args(10, Array[Long](1, 6), Array[Long](3, 7), 7, 22),
            new Args(50, Array[Long](39, 19, 28), Array[Long](49, 27, 35), 15, 35),
            // extra 1
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 1, 20),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 8, 27),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 9, 29),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 15, 35),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 16, 40),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 25, 49),
            new Args(50, Array[Long](19, 28, 39), Array[Long](27, 35, 49), 26, 70)
        )

        return test.TestAll.run_all_tests("l2_tunnel_time", args_list, wrapper)
    }
}
