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

import kotlin.math.absoluteValue

interface Result<T> {
    fun get_result(): T;
}

fun <Args, Ret> run_all_tests(name: String, args_list: List<Args>, fnc: (Args) -> Ret, precision: Double? = 0.0): UInt
    where Args: Result<Ret>
{
    var nb_errors: UInt = 0u;
    println("\n$name");
    var nb: UInt = 1u;
    for (args in args_list)
    {
        val res = fnc(args);
        val expected = args.get_result();
        var is_same = false;
        if (res is Double && expected is Double) {
            //println("res=${res.toDouble()}");
            //println("exp=${expected.toDouble()}");
            //println("abs=${(res.toDouble() - expected.toDouble()).absoluteValue}");
            //println("precision=${precision}");
            is_same = (res.toDouble() - expected.toDouble()).absoluteValue < (precision ?: 0.0);
        }
        else
            is_same = res == expected;
        if (is_same) {
            println("  test #$nb: res=$res CORRECT");
        }
        else {
            println("  test #$nb: res=$res expected=$expected ERROR <-----");
            ++nb_errors;
        }
        ++nb;
    }
    return nb_errors;
}
