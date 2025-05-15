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

package l1_kaitenzushi

object Solution {
    def getMaximumEatenDishCount(N: Int, D: Array[Int], K: Int): Int = {
        val eaten = Array.fill(1000001)(false)  // Meta does not 1_000_001

        // The following is O(K) (where K < N)
        val last_eaten = Array.fill(K)(0)  // circular buffer for last eaten value (0 is not used, as 1 <= Ki <= 1,000,000)
        var oldest_eaten = 0

        // The following is O(N)
        var nb = 0
        for (dish <- D) {
            if (!eaten(dish)) {
                oldest_eaten = (oldest_eaten + 1) % K
                val last_eaten_dish = last_eaten(oldest_eaten)
                eaten(last_eaten_dish) = false // we remove the oldest eaten dish
                eaten(dish) = true
                last_eaten(oldest_eaten) = dish // we add the newest eaten dish to our circular buffer
                nb += 1
            }
        }
        return nb
    }

    class Args(val D: Array[Int],
               val K: Int,
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMaximumEatenDishCount(p.D.size, p.D, p.K)

        val args_list = Array[Args](
            new Args( Array[Int](1, 2, 3, 3, 2, 1), 1, 5 ),
            new Args( Array[Int](1, 2, 3, 3, 2, 1), 2, 4 ),
            new Args( Array[Int](1, 2, 1, 2, 1, 2, 1), 2, 2 )
        )

        return test.TestAll.run_all_tests("l1_kaitenzushi", args_list, wrapper)
    }
}
