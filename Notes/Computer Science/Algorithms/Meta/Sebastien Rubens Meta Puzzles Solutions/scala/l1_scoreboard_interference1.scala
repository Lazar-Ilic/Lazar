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

package l1_scoreboard_interference1

object Solution {
    def getMinProblemCount(N: Int, S: Array[Int]): Int = {
        var min_number_of_twos: Int = 0
        var min_number_of_ones: Int = 0
        for (score <- S) {
            val number_of_twos = score / 2
            val number_of_ones = score % 2
            min_number_of_twos = min_number_of_twos.max(number_of_twos)
            min_number_of_ones = min_number_of_ones.max(number_of_ones)
        }
        return min_number_of_twos + min_number_of_ones
    }

    class Args(val S: Array[Int],
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMinProblemCount(p.S.size, p.S)

        val args_list = Array[Args](
            new Args( Array[Int](1, 2, 3, 4, 5, 6), 4 ),
            new Args( Array[Int](4, 3, 3, 4), 3 ),
            new Args( Array[Int](2, 4, 6, 8), 4 )
        )

        return test.TestAll.run_all_tests("l1_scoreboard_interference1", args_list, wrapper)
    }
}
