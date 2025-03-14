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

package l1_stack_stabilization1

object Solution {
    def getMinimumDeflatedDiscCount(N: Int, R: Array[Int]): Int = {
        var nb: Int = 0
        val iter = R.reverseIterator
        iter.hasNext
        var current_radius = iter.next()
        while (iter.hasNext) {
            val next_radius = iter.next
            val target_radius = current_radius - 1
            if (target_radius <= 0) {
                return -1
            }
            //nb += if (target_radius < next_radius) 1 else 0
            if (target_radius < next_radius)
                nb += 1
            current_radius = next_radius.min(target_radius)
            iter.hasNext
        }
        return nb
    }

    class Args(val S: Array[Int],
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMinimumDeflatedDiscCount(p.S.size, p.S)

        val args_list = Array[Args](
            new Args( Array[Int](2, 5, 3, 6, 5), 3 ),
            new Args( Array[Int](100, 100, 100), 2 ),
            new Args( Array[Int](6, 5, 4, 3), -1 )
        )

        return test.TestAll.run_all_tests("l1_stack_stabilization1", args_list, wrapper)
    }
}
