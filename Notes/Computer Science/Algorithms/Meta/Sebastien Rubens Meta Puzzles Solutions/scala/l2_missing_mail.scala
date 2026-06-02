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

import scala.collection.mutable.ArrayBuffer

class Result(var mail_room_value: Double,
             var total_value: Double) {
    @`inline` def both = mail_room_value + total_value
}

object Solution {
    def getMaxExpectedProfit(N: Int, V: Array[Int], C: Int, S: Double): Float = {
        if (S == 0.0) {
            var ret: Double = 0.0
            for (Vi <- V)
                ret += Vi.toDouble
            ret -= C.toDouble
            return ret.toFloat
        }

        // Initial result
        val results = new ArrayBuffer[Result](V.size)
        results += new Result(0.0, 0.0)
        for (Vi <- V) {
            // Update the best results for the new day, considering the packages could've stolen in previous round
            for (result <- results)
                result.mail_room_value *= 1.0 - S

            // Possibility #1 : pick up packages on this day
            // We need to add the best(max) possible total_value among all saved so far
            val pickup_value = (Vi - C).toDouble + results.foldLeft(Double.MinValue) ((acc, elt) => acc.max(elt.both))

            // Possibility #2 : do not pick up packages on this day
            for (result <- results)
                result.mail_room_value += Vi.toDouble

            results += new Result(0.0, pickup_value)
        }

        val res = results.foldLeft(Double.MinValue) ((acc, elt) => acc.max(elt.total_value))
        return res.toFloat
    }


    class Args(val V: Array[Int],
               val C: Int,
               val S: Double,
               val res: Float ) extends test.Result[Float] {
        override def get_result(): Float = res
    }

    def tests(): Int =
    {
        val wrapper = ((p: Args) => getMaxExpectedProfit(p.V.size, p.V, p.C, p.S))

        val args_list = Array[Args](
            new Args(Array[Int](10, 2, 8, 6, 4), 5, 0.0, 25.0f),
            new Args(Array[Int](10, 2, 8, 6, 4), 5, 1.0, 9.0f),
            new Args(Array[Int](10, 2, 8, 6, 4), 3, 0.5, 17.0f),
            new Args(Array[Int](10, 2, 8, 6, 4), 3, 0.15, 20.10825f)
        )

        return test.TestAll.run_all_tests("l2_missing_mail", args_list, wrapper)
    }
}
