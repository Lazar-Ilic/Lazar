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

package l1_cafeteria

import scala.collection.mutable.ArrayBuffer

object Solution {
    def getMaxAdditionalDinersCount(N: Long, K: Long, M: Int, S: Array[Long]): Long = {
        val d: Long = K + 1

        var taken = new ArrayBuffer[Long](S.size + 1)
        taken += -K  // we are adding "fake" seats at the beginning
        taken = taken ++ S
        taken += N + d // we are adding "fake" seats at the end

        // we sort elements of S: O(M * log(M))
        taken = taken.sorted

        // we are calculating the extra seats available between each consecutive seats: O(M)
        var nb = 0L
        val e = taken.size - 1
        for ((a, b) <- taken.slice(0, taken.size - 1).zip(taken.slice(1, taken.size)))
            nb += (b - a - d) / d
        return nb
    }

    class Args(val N: Long,
               val K: Long,
               val S: Array[Long],
               val res: Long ) extends test.Result[Long] {
        override def get_result(): Long = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMaxAdditionalDinersCount(p.N, p.K, p.S.size, p.S)

        val args_list = Array[Args](
            new Args( 10, 1, Array[Long](2, 6), 3 ),
            new Args( 15, 2, Array[Long](11, 6, 14), 1 )
        )

        return test.TestAll.run_all_tests("l1_cafeteria", args_list, wrapper)
    }
}
