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

typealias damage_t = ULong;

class DamageInfo(
    var order: Int,
    var indices: Array<Int> = arrayOf( 0, 1 ),
    var damage: damage_t = 0UL, )

fun maximize_damage(N: Int, H: Array<Int>, D: Array<Int>, info: DamageInfo): Boolean
{
    // this maximizes damage for a fixed index(max_i if order is True, otherwise max_j)
    // and also returns the value of max_i and max_j
    var has_same_damage: Boolean = true;
    for (i in 0 until N)
    {
        val j = info.indices[info.order];
        if (j == i)
            continue;
        val Hi = H[i].toULong();  // TODO: Kotlin is not great with casting directly to damage_t
        val Hj = H[j].toULong();
        val Di = D[i].toULong();
        val Dj = D[j].toULong();
        var new_damage: damage_t;
        if (info.order == 0)
            new_damage = Hj * Dj + Hj * Di + Hi * Di;
        else
            new_damage = Hi * Di + Hi * Dj + Hj * Dj;
        if (info.damage < new_damage)
        {
            has_same_damage = false;
            info.damage = new_damage;
            info.indices[1 - info.order] = i;
        }
    }
    return has_same_damage;
}

fun getMaxDamageDealt(N: Int, H: Array<Int>, D: Array<Int>, B: Int): Double {
    val damage_infos = arrayListOf<DamageInfo>();  // note: no reserve() here
    for (order in arrayOf<Int>( 0, 1 ))
    {
        val damage_info = DamageInfo(order);
        while (true)
        {
            val has_same_damage = maximize_damage(N, H, D, damage_info);
            if (has_same_damage)
                break;
            damage_info.order = 1 - damage_info.order;
            damage_infos.add(damage_info);
        }
    }
    if (damage_infos.isEmpty())
        return 0.0;

    val max_elt = damage_infos.maxByOrNull { it.damage }!!;
    return max_elt.damage.toDouble() / B.toDouble();
}

class Args(
    val H: Array<Int>,
    val D: Array<Int>,
    val B: Int,
    val res: Double, ) : test.Result<Double> {
    override fun get_result(): Double { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMaxDamageDealt(p.H.size, p.H, p.D, p.B) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(2, 1, 4), arrayOf(3, 1, 2), 4, 6.5 ),
        Args( arrayOf(1, 1, 2, 100), arrayOf(1, 2, 1, 3), 8, 62.75 ),
        Args( arrayOf(1, 1, 2, 3), arrayOf(1, 2, 1, 100), 8, 62.75 ),
        // extra1
        Args( arrayOf(1, 1, 2, 100, 3), arrayOf(1, 2, 1, 4, 100), 8, 1337.5 ),
        Args( arrayOf(9, 1, 3, 4), arrayOf(0, 10, 4, 3), 1, 100.0 ),
    );

    return test.run_all_tests("l3_boss_fight", args_list, wrapper, 0.000_001);
}
