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

object Main {
    def main(args: Array[String]): Unit = {
        var nb_errors: Int = 0
        // l0
        nb_errors += l0_abcs.Solution.tests()
        nb_errors += l0_all_wrong.Solution.tests()
        nb_errors += l0_battleship.Solution.tests()
        // l1
        nb_errors += l1_cafeteria.Solution.tests()
        nb_errors += l1_director_photography1.Solution.tests()
        nb_errors += l1_kaitenzushi.Solution.tests()
        nb_errors += l1_rotary_lock1.Solution.tests()
        nb_errors += l1_scoreboard_interference1.Solution.tests()
        nb_errors += l1_stack_stabilization1.Solution.tests()
        nb_errors += l1_uniform_integers.Solution.tests()
        // l2
        nb_errors += l2_director_photography2.Solution.tests()
        nb_errors += l2_hops.Solution.tests()
        nb_errors += l2_missing_mail.Solution.tests()
        nb_errors += l2_portals.Solution.tests()
        nb_errors += l2_rabbit_hole1.Solution.tests()
        nb_errors += l2_rotary_lock2.Solution.tests() // You solved 28 / 32 test cases., Time Limit Exceeded on 4 test cases
        nb_errors += l2_scoreboard_interference2.Solution.tests()
        nb_errors += l2_tunnel_time.Solution.tests()
        // l3
        nb_errors += l3_boss_fight.Solution.tests()
        nb_errors += l3_rabbit_hole2.Solution.tests() // You solved 15 / 22 test cases., Runtime Error on 7 test cases
        nb_errors += l3_slippery_strip.Solution.tests()
        nb_errors += l3_stack_stabilization2.Solution.tests()
        // l4
        //nb_errors += l4_conveyor_chaos.Solution.tests()
        //nb_errors += l4_mathematical_art.Solution.tests()

        println("\n" + nb_errors + " errors found")
    }
}