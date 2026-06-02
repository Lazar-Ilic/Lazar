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

package l0_battleship

object Solution {
    def getHitProbability(R: Int, C: Int, G: Array[Array[Int]]): Float = {
        val sum = G.foldLeft(0) ((acc, row) => acc + row.foldLeft(0) ((acc_row, elt) => acc_row + elt))
        return sum.toFloat / (R * C).toFloat
    }


    class Args(val G: Array[Array[Int]],
               val res: Float ) extends test.Result[Float] {
        override def get_result(): Float = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getHitProbability(p.G.size, p.G(0).size, p.G)

        val args_list = Array[Args](
            new Args( Array[Array[Int]]( Array[Int](0, 0, 1), Array[Int](1, 0, 1) ), 0.5f ),
            new Args( Array[Array[Int]]( Array[Int](1, 1), Array[Int](1, 1) ), 1.0f ),
            // extra1
            new Args( Array[Array[Int]]( Array[Int](0, 1, 0, 0), Array[Int](1, 1, 0, 0), Array[Int](0, 0, 0, 0) ), 0.25f )
        )

        return test.TestAll.run_all_tests("l0_battleship", args_list, wrapper)
    }
}
