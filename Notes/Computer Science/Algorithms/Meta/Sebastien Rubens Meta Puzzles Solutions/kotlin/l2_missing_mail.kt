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

package l2_missing_mail

class Result(
    var mail_room_value: Double,
    var total_value: Double, ) {

    fun both(): Double {
        return mail_room_value + total_value;
    }
}

fun getMaxExpectedProfit(N: Int, V: Array<Int>, C: Int, S: Double): Double {
    if (S == 0.0)
    {
        var ret: Double = 0.0;
        for (Vi in V)
            ret += Vi.toDouble();
        return ret - C.toDouble();
    }

    // Initial result
    var results = ArrayList<Result>(V.size);
    results.add(Result(0.0, 0.0));
    for (Vi in V) {
        // Update the best results for the new day, considering the packages could've stolen in previous round
        for (result in results)
            result.mail_room_value *= 1.0 - S;

        // Possibility #1 : pick up packages on this day
        // We need to add the best(max) possible total_value among all saved so far
        val pickup_value = (Vi - C).toDouble() + results.fold(Double.MIN_VALUE, { a, b -> maxOf(a, b.both()) } );

        // Possibility #2 : do not pick up packages on this day
        for (result in results)
            result.mail_room_value += Vi.toDouble();

        results.add(Result(0.0, pickup_value));

    }

    return results.fold(Double.MIN_VALUE, { a, b -> maxOf(a, b.total_value) });
}

class Args(
    val V: Array<Int>,
    val C: Int,
    val S: Double,
    val res: Double, ) : test.Result<Double> {
    override fun get_result(): Double { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMaxExpectedProfit(p.V.size, p.V, p.C, p.S) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(10, 2, 8, 6, 4), 5, 0.0, 25.0 ),
        Args( arrayOf(10, 2, 8, 6, 4), 5, 1.0, 9.0 ),
        Args( arrayOf(10, 2, 8, 6, 4), 3, 0.5, 17.0 ),
        Args( arrayOf(10, 2, 8, 6, 4), 3, 0.15, 20.10825 ),
    );

    return test.run_all_tests("l2_missing_mail", args_list, wrapper, 0.000_001);
}
