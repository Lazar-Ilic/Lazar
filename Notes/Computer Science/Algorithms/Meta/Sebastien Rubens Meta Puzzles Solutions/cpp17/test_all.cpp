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

// We are directly including the .cpp files here
#include "l0_abcs.cpp"
#include "l0_all_wrong.cpp"
#include "l0_battleship.cpp"
#include "l1_cafeteria.cpp"
#include "l1_director_photography1.cpp"
#include "l1_kaitenzushi.cpp"
#include "l1_rotary_lock1.cpp"
#include "l1_scoreboard_interference1.cpp"
#include "l1_stack_stabilization1.cpp"
#include "l1_uniform_integers.cpp"
#include "l2_director_photography2.cpp"
#include "l2_hops.cpp"
#include "l2_missing_mail.cpp"
#include "l2_portals.cpp"
#include "l2_rabbit_hole1.cpp"
#include "l2_rotary_lock2.cpp"
#include "l2_scoreboard_interference2.cpp"
#include "l2_tunnel_time.cpp"
#include "l3_boss_fight.cpp"
#include "l3_rabbit_hole2.cpp"
#include "l3_slippery_strip.cpp"
#include "l3_stack_stabilization2.cpp"
#include "l4_conveyor_chaos.cpp"
#include "l4_mathematical_art.cpp"

#include "test_all.h"


int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    uint32_t nb_errors = 0;
    nb_errors += l0_abcs::tests();
    nb_errors += l0_all_wrong::tests();
    nb_errors += l0_battleship::tests();
    nb_errors += l1_cafeteria::tests();
    nb_errors += l1_director_photography1::tests();
    nb_errors += l1_kaitenzushi::tests();
    nb_errors += l1_rotary_lock1::tests();
    nb_errors += l1_scoreboard_interference1::tests();
    nb_errors += l1_stack_stabilization1::tests();
    nb_errors += l1_uniform_integers::tests();
    nb_errors += l2_director_photography2::tests();
    nb_errors += l2_hops::tests();
    nb_errors += l2_missing_mail::tests();
    nb_errors += l2_portals::tests();
    nb_errors += l2_rabbit_hole1::tests();
    nb_errors += l2_rotary_lock2::tests();
    nb_errors += l2_scoreboard_interference2::tests();
    nb_errors += l2_tunnel_time::tests();
    nb_errors += l3_boss_fight::tests();
    nb_errors += l3_rabbit_hole2::tests();
    nb_errors += l3_slippery_strip::tests();
    nb_errors += l3_stack_stabilization2::tests();
    nb_errors += l4_conveyor_chaos::tests();
    nb_errors += l4_mathematical_art::tests();
    std::cout << std::endl << nb_errors << " errors found" << std::endl;
    return 0;
}


// End
