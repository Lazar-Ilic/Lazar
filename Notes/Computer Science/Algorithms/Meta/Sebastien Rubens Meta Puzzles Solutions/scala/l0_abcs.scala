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

package l0_abcs

object Solution {
    def getSum(A: Int, B: Int, C: Int): Int = {
        return A + B + C
    }


    class Args(val A: Int,
               val B: Int,
               val C: Int,
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int = {
        val wrapper = (p: Args) => getSum(p.A, p.B, p.C)

        val args_list = Array[Args](
            new Args(1, 2, 3, 6),
            new Args(100, 100, 100, 300),
            new Args(85, 16, 93, 194)
        )

        return test.TestAll.run_all_tests("l0_abcs", args_list, wrapper)
    }
}
