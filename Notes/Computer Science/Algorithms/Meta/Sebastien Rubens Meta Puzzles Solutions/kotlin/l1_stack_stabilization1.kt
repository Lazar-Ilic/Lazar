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

package l1_stack_stabilization1

fun getMinimumDeflatedDiscCount(N: Int, R: Array<Int>): Int {
    var nb = 0;
    val iter = R.reversed().iterator();
    iter.hasNext();
    var current_radius = iter.next();
    while (iter.hasNext()) {
        val next_radius = iter.next();
        val target_radius = current_radius - 1;
        if (target_radius <= 0) {
            return -1;
        }
        nb += if (target_radius < next_radius) 1 else 0;
        current_radius = minOf(next_radius, target_radius);
        iter.hasNext();
    }
    return nb;
}

class Args(
    val R: Array<Int>,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMinimumDeflatedDiscCount(p.R.size, p.R) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(2, 5, 3, 6, 5), 3 ),
        Args( arrayOf(100, 100, 10), 2 ),
        Args( arrayOf(6, 5, 4, 3), -1 ),
    );

    return test.run_all_tests("l1_stack_stabilization1", args_list, wrapper);
}
