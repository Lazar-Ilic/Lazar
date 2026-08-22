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

package test

trait Result[T] {
  def get_result(): T
}

object TestAll {

def run_all_tests[Args <: Result[Ret], Ret](name: String, args_list: Array[Args], fnc: (Args) => Ret): Int =
{
    var nb_errors: Int = 0
    printf("\n" + name + "\n")
    var nb: Int = 1
    for (args <- args_list)
    {
        val res = fnc(args)
        val expected = args.get_result()
        var is_same = false
        //if (res is Double && expected is Double)
        //    is_same = (res.toDouble() - expected.toDouble()).absoluteValue < (precision ?: 0.0)
        //else
        //    is_same = res == expected
        is_same = res == expected
        if (is_same) {
            println("  test #" + nb + ": res=" + res + " CORRECT")
        }
        else {
            println("  test #" + nb + ": res=" + res + " expected=" + expected + " ERROR <-----")
            nb_errors += 1
        }
        nb += 1
    }
    return nb_errors
}

}
