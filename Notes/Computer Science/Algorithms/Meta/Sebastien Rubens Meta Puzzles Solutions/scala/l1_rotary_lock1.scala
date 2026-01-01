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

package l1_rotary_lock1

object Solution {
    def getMinCodeEntryTime(N: Int, M: Int, C: Array[Int]): Long = {
        var pos = 1
        var nb = 0L
        for (target <- C) {
            var positive_move = (target - pos) % N // positive move
            positive_move = if (positive_move < 0) (positive_move + N) else positive_move // modulo can be negative in C++
            val negative_move = N - positive_move
            nb += positive_move.min(negative_move)
            pos = target
        }
        return nb  // result should always be positive
    }

    class Args(val N: Int,
               val C: Array[Int],
               val res: Long ) extends test.Result[Long] {
        override def get_result(): Long = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMinCodeEntryTime(p.N, p.C.size, p.C)

        val args_list = Array[Args](
            new Args( 3, Array[Int](1, 2, 3), 2 ),
            new Args( 10, Array[Int](9, 4, 4, 8), 11 )
        )

        return test.TestAll.run_all_tests("l1_rotary_lock1", args_list, wrapper)
    }
}
