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

package l3_slippery_strip

import scala.collection.mutable.ArrayBuffer

class Counts(var star: Int,
             var right: Int,
             var down: Int) {
}

object Solution {
    def getMaxCollectableCoins(R: Int, C: Int, G: Array[Array[String]]): Int = {

        type char_counter_t = ArrayBuffer[Int]

        def get_counts(row: Array[Char], counts: char_counter_t): Counts = {
            counts('*') = 0
            counts('>') = 0
            counts('v') = 0
            for (c <- row) {
                var d = c
                if (d >= counts.size)
                    d = '.' // empty value (we do not use it)
                counts(d) += 1
            }
            return new Counts(counts('*'), counts('>'), counts('v'))
        }

        def get_nb_coins_right_then_down3(row: Array[Char], _count_down: Int, _count_right: Int): Int = {
            // complexity : O(C)
            if (_count_down == 0)
                return 0
            val k = row.indexOf('v')
            val j = if (k != -1) (k + 1) else 0
            val new_row = new ArrayBuffer[Char]()
            new_row.addAll(row.slice(j, row.size))
            new_row.addAll(row.slice(0, j))
            var count_down = _count_down
            var count_right = _count_right
            var nb_coins_right_then_down = 0
            val size = new_row.size
            var last = 0
            while (count_right * count_down != 0) {
                val first = new_row.slice(last, size).indexOf('>') + last
                last = new_row.slice(first, size).indexOf('v') + 1 + first
                nb_coins_right_then_down = nb_coins_right_then_down.max(new_row.slice(first, last).count((c: Char) => c == '*'))
                count_down -= 1
                count_right -= new_row.slice(first, last).count((c: Char) => c == '>')
            }
            return nb_coins_right_then_down
        }

        def _getMaxCollectableCoins(R: Int, C: Int, G: Array[Array[Char]]): Int = {
            val counts = ArrayBuffer.fill(256)(0)
            var res = 0
            for (i <- 0 until G.size) {
                val row = G(G.size - i - 1)
                val count = get_counts(row, counts)
                val nb_coins_immediately_down = count.star.min(1)
                if (count.right == C)
                    res = 0
                else if (count.right == 0)
                    res += nb_coins_immediately_down
                else {
                    val nb_coins_right_then_down = get_nb_coins_right_then_down3(row, count.down, count.right)
                    val nb_coins_right_forever = if (count.down == 0) count.star else 0
                    res = (nb_coins_immediately_down + res).max((nb_coins_right_then_down + res).max(nb_coins_right_forever))
                }
            }
            return res.toInt // result should always be positive
        }

        val H = new ArrayBuffer[Array[Char]](G.size)
        for (in_row <- G)
        {
            val row = new ArrayBuffer[Char](in_row.size)
            for (c <- in_row)
                row += c(0)
            H += row.toArray
        }
        return _getMaxCollectableCoins(H.size, if (H.isEmpty) 0 else H(0).size, H.toArray)
    }


    class Args(val G: Array[String],
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        def _getMaxCollectableCoinsTest(G: Array[String]): Int = {
            val H = new ArrayBuffer[Array[String]](G.size)
            for (in_row <- G)
            {
                val row = new ArrayBuffer[String](in_row.length)
                for (c <- in_row)
                    row += c.toString()
                H += row.toArray
            }
            return getMaxCollectableCoins(H.size, if (H.isEmpty) 0 else H(0).size, H.toArray)
        }


        val wrapper = (p: Args) => _getMaxCollectableCoinsTest(p.G)

        val args_list = Array[Args](
            new Args(Array[String](".***", "**v>", ".*.."), 4),
            new Args(Array[String](">**", "*>*", "**>"), 4),
            new Args(Array[String](">>", "**"), 0),
            new Args(Array[String](">*v*>*", "*v*v>*", ".*>..*", ".*..*v"), 6),
            // extra1
            new Args(Array[String](), 0),
            new Args(Array[String]("."), 0),
            new Args(Array[String]("v"), 0),
            new Args(Array[String](">"), 0),
            new Args(Array[String]("*"), 1),
            // extra2
            new Args(Array[String](".", ".", ">", "*"), 0),
            new Args(Array[String](".", "*", ">", "*"), 1),
            new Args(Array[String](".", "*", ">", "."), 1),
            new Args(Array[String]("*", ".", ">", "."), 1),
            new Args(Array[String]("***", "...", ">vv", "..."), 1),
            // extra3
            new Args(Array[String]("*....", ".*...", "..*..", "...*."), 4),
            new Args(Array[String]("....", "....", "....", "...."), 0),
            new Args(Array[String]("***>", "...."), 3),
            new Args(Array[String]("*"), 1),
            new Args(Array[String]("vvvv"), 0),
            new Args(Array[String]("vvvv", "....", ">>>>"), 0),
            // extra4
            new Args(Array[String]("******", "......", ">*>vvv", "......"), 2),
            new Args(Array[String]("*****", ".....", ">>vvv", "....."), 1)
        )

        return test.TestAll.run_all_tests("l3_slippery_strip", args_list, wrapper)
    }
}
