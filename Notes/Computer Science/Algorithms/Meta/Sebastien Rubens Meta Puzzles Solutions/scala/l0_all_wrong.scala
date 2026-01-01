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

package l0_all_wrong

object Solution {
    def getWrongAnswers(N: Int, C: String): String = {
        return C.map(c => if (c == 'A') 'B' else 'A')
    }


    class Args(val C: String,
               val res: String ) extends test.Result[String] {
      override def get_result(): String = res
    }

    def tests(): Int = {
        val wrapper = (p: Args) => getWrongAnswers(p.C.length, p.C)

        val args_list = Array[Args](
          new Args("ABA", "BAB"),
          new Args("BBBBB", "AAAAA")
        )

      return test.TestAll.run_all_tests("l0_all_wrong", args_list, wrapper)
  }
}
