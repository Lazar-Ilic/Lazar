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

package l2_hops

fun getSecondsRequired(N: Long, _F: Int, P: Array<Long>): Long {
    if (P.isEmpty())
        return 0;
    return N - P.minOrNull()!!;
}

class Args(
    val N: Long,
    val P: Array<Long>,
    val res: Long, ) : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getSecondsRequired(p.N, p.P.size, p.P) };

    val args_list: List<Args> = listOf(
        Args( 3, arrayOf(1), 2 ),
        Args( 6, arrayOf(5, 2, 4), 4 ),
    );

    return test.run_all_tests("l2_hops", args_list, wrapper);
}
