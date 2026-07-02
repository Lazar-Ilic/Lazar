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

package l3_boss_fight

import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._

class DamageInfo(var order: Int,
                 var indices: Array[Int] = Array[Int](0, 1),
                 var damage: Long = 0L ) {
}

object Solution {
    def getMaxDamageDealt(N: Int, H: Array[Int], D: Array[Int], B: Int): Float = {

        def maximize_damage(N: Int, H: Array[Int], D: Array[Int], info: DamageInfo): Boolean = {
            // this maximizes damage for a fixed index(max_i if order is True, otherwise max_j)
            // and also returns the value of max_i and max_j
            var has_same_damage: Boolean = true
            for (i <- 0 until N) {
                var j = info.indices(info.order)
                breakable {
                    if (j == i)
                        break
                    val Hi = H(i).toLong
                    val Hj = H(j).toLong
                    val Di = D(i).toLong
                    val Dj = D(j).toLong
                    var new_damage: Long = 0
                    if (info.order == 0)
                        new_damage = Hj * Dj + Hj * Di + Hi * Di
                    else
                        new_damage = Hi * Di + Hi * Dj + Hj * Dj
                    if (info.damage < new_damage) {
                        has_same_damage = false
                        info.damage = new_damage
                        info.indices(1 - info.order) = i
                    }
                }
            }
            return has_same_damage
        }

        val damage_infos = new ArrayBuffer[DamageInfo]() // note: no reserve() here
        val orders = Array[Int](0, 1)
        for (order <- orders) {
            val damage_info = new DamageInfo(order)
            breakable {
                while (true) {
                    val has_same_damage = maximize_damage(N, H, D, damage_info)
                    if (has_same_damage)
                        break
                    damage_info.order = 1 - damage_info.order
                    damage_infos += damage_info
                }
            }

        }
        if (damage_infos.isEmpty)
            return (0.0).toFloat

        val max_elt = damage_infos.maxBy(x =>x.damage)
        val ret = max_elt.damage.toDouble / B.toDouble
        return ret.toFloat
    }


    class Args(val H: Array[Int],
               val D: Array[Int],
               val B: Int,
               val res: Float ) extends test.Result[Float] {
        override def get_result(): Float = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMaxDamageDealt(p.H.size, p.H, p.D, p.B)

        val args_list = Array[Args](
            new Args( Array[Int](2, 1, 4), Array[Int](3, 1, 2), 4, 6.5f ),
            new Args( Array[Int](1, 1, 2, 100), Array[Int](1, 2, 1, 3), 8, 62.75f ),
            new Args( Array[Int](1, 1, 2, 3), Array[Int](1, 2, 1, 100), 8, 62.75f ),
            // extra1
            new Args( Array[Int](1, 1, 2, 100, 3), Array[Int](1, 2, 1, 4, 100), 8, 1337.5f ),
            new Args( Array[Int](9, 1, 3, 4), Array[Int](0, 10, 4, 3), 1, 100.0f )
        )

        return test.TestAll.run_all_tests("l3_boss_fight", args_list, wrapper)
    }
}
