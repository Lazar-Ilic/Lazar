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

package l2_scoreboard_interference2

fun getMinProblemCount(N: Int, S: Array<Int>): Int {
    var max_score = 0;
    var second_max_score = 0;
    var two_remainder = 0;
    var one_remainder = 0;
    var need_one = false;

    for (score in S) {
        val score_mod_3 = score % 3;
        two_remainder = two_remainder or (score_mod_3 shr 1);
        one_remainder = one_remainder or (score_mod_3 and 1);
        need_one = need_one || (score == 1);
        if (max_score < score) {
            second_max_score = max_score;
            max_score = score;
        } else if (second_max_score < score)
            second_max_score = score;
    }

    // number of solutions, without any optimisation
    var count = max_score / 3 + two_remainder + one_remainder;

    // not optimisation is possible if "two_remainder and one_remainder" is not true
    if (two_remainder * one_remainder != 1)
        return count;

    // replace "last +3" by "+1+2"
    if (max_score % 3 == 0)
        count -= 1;

    // replace last "+3+1" by "+2+2"
    if (need_one)  // exit early because 1 is required but at least one sum(i.e.it cannot be replaced)
        return count;
    if (max_score % 3 != 1)  // max_score does not have a 1 (so it cannot be replaced)
        return count;
    val tmp =max_score - second_max_score;
    if (!(tmp == 1 || tmp == 3)) // [ok, not ok(3), ok] || [not ok(1) | here | unimportant]
        count -= 1;
    return count;
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
        Args( arrayOf(1, 2, 3, 4, 5), 3 ),
        Args( arrayOf(4, 3, 3, 4), 2 ),
        Args( arrayOf(2, 4, 6, 8), 4 ),
        Args( arrayOf(8), 3 ),
        // extra1
        Args( arrayOf(4, 3, 3, 4), 2 ),
        Args( arrayOf(2, 4, 6, 8), 4 ),
        Args( arrayOf(8), 3 ),
        Args( arrayOf(1, 2, 3), 2 ),
        Args( arrayOf(5, 7), 3 ),
        Args( arrayOf(5, 9, 10), 5 ),
        Args( arrayOf(5, 9, 11), 4 ),
        Args( arrayOf(2, 4, 6), 3 ),
        Args( arrayOf(2, 4, 7), 4 ),
        // extra2
        Args( arrayOf(1, 2, 4), 3 ),
        Args( arrayOf(2, 4), 2 ),
        Args( arrayOf(4, 5), 3 ),
        Args( arrayOf(9, 12), 4 ),
        Args( arrayOf(11, 13), 5 ),
    );

    return test.run_all_tests("l2_scoreboard_interference2", args_list, wrapper);
}
