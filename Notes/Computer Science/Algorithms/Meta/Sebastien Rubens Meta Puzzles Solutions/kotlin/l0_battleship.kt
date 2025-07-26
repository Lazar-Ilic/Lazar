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

package l0_battleship

fun getHitProbability(R: Int, C: Int, G: Array<Array<Int>>): Double {
    val numerator: Double = G.fold(0.0) {sum, row -> sum + row.fold(0.0) {sum, elt -> sum + elt } };
    return numerator / (R * C).toDouble();
}

class Args(
    val G: Array<Array<Int>>,
    val res: Double, ) : test.Result<Double> {
    override fun get_result(): Double { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getHitProbability(p.G.size, p.G[0].size, p.G) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(arrayOf(0, 0, 1), arrayOf(1, 0, 1) ), 0.5 ),
        Args( arrayOf(arrayOf(1, 1), arrayOf(1, 1) ), 1.0 ),
        // extra1
        Args( arrayOf(arrayOf(0, 1, 0, 0), arrayOf(1, 1, 0, 0), arrayOf(0, 0, 0, 0) ), 0.25 ),
    );

    return test.run_all_tests("l0_battleship", args_list, wrapper, 0.000_001);
}
