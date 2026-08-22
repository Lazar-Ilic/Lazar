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

fun getMinProblemCount(N: Int, S: Array<Int>): Int {
    var min_number_of_twos: Int = 0;
    var min_number_of_ones: Int = 0;
    for (score in S) {
        val number_of_twos = score / 2;
        val number_of_ones = score % 2;
        min_number_of_twos = maxOf(min_number_of_twos, number_of_twos);
        min_number_of_ones = maxOf(min_number_of_ones, number_of_ones);
    }
    return min_number_of_twos + min_number_of_ones;
}

class Args(
    val S: Array<Int>,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMinProblemCount(p.S.size, p.S) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(1, 2, 3, 4, 5, 6), 4 ),
        Args( arrayOf(4, 3, 3, 4), 3 ),
        Args( arrayOf(2, 4, 6, 8), 4 ),
    );

    return test.run_all_tests("l1_scoreboard_interference1", args_list, wrapper);
}
