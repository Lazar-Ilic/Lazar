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

package l2_tunnel_time

class Tunnel(
    val a: Long,
    val b: Long, ) {

    fun length(): Long {
        return b - a;
    }
}

fun getSecondsElapsed(C: Long, N: Int, A: Array<Long>, B: Array<Long>, K: Long): Long {
    val tunnels = ArrayList<Tunnel>(N);
    for ((a, b) in A.zip(B))
        tunnels.add(Tunnel(a, b));

    var tunnel_time_total: Long = 0L;
    for (tunnel in tunnels)
        tunnel_time_total += tunnel.length();

    val number_of_complete_track: Long = K.toLong() / tunnel_time_total;  // O(1)
    var total_time_left: Long = K - number_of_complete_track * tunnel_time_total;  // O(1)
    var travel_time: Long = number_of_complete_track * C;  // O(1)

    if (total_time_left == 0L)
        travel_time -= C - B.maxOrNull()!!;  // O(N)
    else
    {
        tunnels.sortWith(compareBy<Tunnel> { it.a }.thenBy { it.b });
        for (tunnel in tunnels) {
            val tunnel_length = tunnel.length();
            if (tunnel_length >= total_time_left) {
                travel_time += tunnel.a + total_time_left;
                break;
            }
            total_time_left -= tunnel_length;
        }
    }
    return travel_time;
}

class Args(
    val C: Long,
    val A: Array<Long>,
    val B: Array<Long>,
    val K: Long,
    val res: Long, ) : test.Result<Long> {
    override fun get_result(): Long { return res; };
}

fun tests(): UInt
{
    fun _getSecondsElapsed(p: Args): Long {
        val min_len = minOf(p.A.size, p.B.size);
        return getSecondsElapsed(p.C, min_len, p.A, p.B, p.K);
    }
    val wrapper = { p: Args -> _getSecondsElapsed(p) };

    val args_list: List<Args> = listOf(
        Args( 10, arrayOf(1, 6), arrayOf(3, 7), 7, 22 ),
        Args( 50, arrayOf(39, 19, 28), arrayOf(49, 27, 35), 15, 35 ),
        // extra 1
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 1, 20 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 8, 27 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 9, 29 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 15, 35 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 16, 40 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 25, 49 ),
        Args( 50, arrayOf(19, 28, 39), arrayOf(27, 35, 49), 26, 70 ),
    );

    return test.run_all_tests("l2_tunnel_time", args_list, wrapper);
}
