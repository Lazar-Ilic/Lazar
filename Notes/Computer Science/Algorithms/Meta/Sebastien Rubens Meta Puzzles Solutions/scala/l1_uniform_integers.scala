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

package l1_uniform_integers

object Solution {
    def getUniformIntegerCountInInterval(A: Long, B: Long): Int = {
        def len_str(_nb: Long): Int = {
            if (_nb == 0L) // not necessary due to problem definition
                return 1
            var nb = _nb
            var ret: Int = 0
            while (nb > 0) {
                nb /= 10
                ret += 1
            }
            return ret
        }

        def ones(log_value: Int): Long = {
            var ret: Long = 0
            var i = 0
            while (i < log_value) {
                i += 1
                ret = ret * 10 + 1
            }
            return ret
        }

        // Each of the following lines is O(log(max(A, B)))
        val len_a = len_str(A)
        val len_b = len_str(B)
        val tmp_a = ones(len_a)
        val tmp_b = ones(len_b)

        // Everything else is O(1)
        val nb_a = (tmp_a * 10 - A) / tmp_a
        val nb_b = B / tmp_b
        val nb_m = if (len_b - len_a >= 2) (9 * (len_b - len_a - 1)) else {
            0
        }
        var nb = nb_a + nb_m.toLong + nb_b
        if (len_a == len_b)
            nb -= 9
        return nb.toInt
    }


    class Args(val A: Long,
               val B: Long,
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getUniformIntegerCountInInterval(p.A, p.B)

        val args_list = Array[Args](
            new Args(75, 300, 5),
            new Args(1, 9, 9),
            // extra1
            new Args(1, 1_000_000_000_000L, 108),
            // extra2
            new Args(10, 99, 9),
            new Args(11, 98, 8),
            new Args(21, 89, 7),
            new Args(22, 88, 7),
            new Args(23, 87, 5),
            // extra3
            new Args(11, 88, 8),
            new Args(11, 98, 8),
            new Args(11, 99, 9)
        )

        return test.TestAll.run_all_tests("l1_uniform_integers", args_list, wrapper)
    }
}
