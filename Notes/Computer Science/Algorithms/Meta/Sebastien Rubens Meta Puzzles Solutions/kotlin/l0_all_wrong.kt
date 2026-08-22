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

fun getWrongAnswers(N: Int, C: String): String {
    val ret = StringBuilder();
    for (c in C)
        ret.append(if (c == 'A') 'B' else 'A');
    return ret.toString();
}

class Args(
    val C: String,
    val res: String, ) : test.Result<String> {
    override fun get_result(): String { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getWrongAnswers(p.C.length, p.C) };

    val args_list: List<Args> = listOf(
        Args( "ABA", "BAB" ),
        Args( "BBBBB", "AAAAA" ),
    );

    return test.run_all_tests("l0_all_wrong", args_list, wrapper);
}
