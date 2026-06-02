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

package l1_cafeteria

fun getMaxAdditionalDinersCount(N: Long, K: Long, _M: Int, S: Array<Long>): Long {
    val d: Long = K + 1;

    val taken = ArrayList<Long>(S.size + 1);
    taken.add(-K);  // we are adding "fake" seats at the beginning
    taken.addAll(S);
    taken.add(N + d);  // we are adding "fake" seats at the end

    // we sort elements of S: O(M * log(M))
    taken.sort();

    // we are calculating the extra seats available between each consecutive seats: O(M)
    var nb: Long = 0;
    val e = taken.size - 1;
    for (i in 0 until e)
        nb += (taken[i + 1] - taken[i] - d) / d;
    return nb;
}

class Args(
    val N: Long,
    val K: Long,
    val S: Array<Long>,
    val res: Long, ) : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMaxAdditionalDinersCount(p.N, p.K, p.S.size, p.S) };

    val args_list: List<Args> = listOf(
        Args( 10, 1, arrayOf(2, 6), 3),
        Args( 15, 2, arrayOf(11, 6, 14), 1),
    );

    return test.run_all_tests("l1_cafeteria", args_list, wrapper);
}
