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

package l1_rotary_lock1

fun getMinCodeEntryTime(N: Int, M: Int, C: Array<Int>): Long {
    var pos = 1;
    var nb: Long = 0;
    for (target in C) {
        var positive_move = (target - pos) % N;  // positive move
        positive_move = if (positive_move < 0) (positive_move + N) else positive_move;  // modulo can be negative in C++
        val negative_move = N - positive_move;
        nb += minOf(positive_move, negative_move).toLong();
        pos = target;
    }
    return nb;
}

class Args(
    val N: Int,
    val C: Array<Int>,
    val res: Long, ) : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMinCodeEntryTime(p.N, p.C.size, p.C) };

    val args_list: List<Args> = listOf(
        Args( 3, arrayOf(1, 2, 3), 2 ),
        Args( 10, arrayOf(9, 4, 4, 8), 11 ),
    );

    return test.run_all_tests("l1_rotary_lock1", args_list, wrapper);
}
