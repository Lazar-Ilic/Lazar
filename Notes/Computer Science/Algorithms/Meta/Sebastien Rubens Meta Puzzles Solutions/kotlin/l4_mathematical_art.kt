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

package l4_mathematical_art

fun getPlusSignCount(N: Int, L: Array<Int>, D: String): Long {
    return 0L;
}

class Args(
    val L: Array<Int>,
    val D: String,
    val res: Long, ) : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getPlusSignCount(p.L.size, p.L, p.D) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(6, 3, 4, 5, 1, 6, 3, 3, 4), "ULDRULURD", 4 ),
        Args( arrayOf(1, 1, 1, 1, 1, 1, 1, 1), "RDLUULDR", 1 ),
        Args( arrayOf(1, 2, 2, 1, 1, 2, 2, 1), "UDUDLRLR", 1 ),
        // extra1
        Args( arrayOf(1, 1, 1, 1, 1, 1), "RDURLU", 1 ),
    );

    return test.run_all_tests("l4_mathematical_art", args_list, wrapper);
}

// TODO
