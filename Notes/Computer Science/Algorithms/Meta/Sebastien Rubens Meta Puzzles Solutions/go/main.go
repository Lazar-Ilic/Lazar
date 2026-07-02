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

package main

import (
	"fmt"

	// l0
	"meta_puzzles/l0_abcs"
	"meta_puzzles/l0_all_wrong"
	"meta_puzzles/l0_battleship"

	// l1
	"meta_puzzles/l1_cafeteria"
	"meta_puzzles/l1_director_photography1"
	"meta_puzzles/l1_kaitenzushi"
	"meta_puzzles/l1_rotary_lock1"
	"meta_puzzles/l1_scoreboard_interference1"
	"meta_puzzles/l1_stack_stabilization1"
	"meta_puzzles/l1_uniform_integers"

	// l2
	"meta_puzzles/l2_director_photography2"
	"meta_puzzles/l2_hops"
	"meta_puzzles/l2_missing_mail"
	"meta_puzzles/l2_rabbit_hole1"
	"meta_puzzles/l2_rotary_lock2"
	"meta_puzzles/l2_scoreboard_interference2"
	"meta_puzzles/l2_tunnel_time"

	// l3
	"meta_puzzles/l3_boss_fight"
	"meta_puzzles/l3_rabbit_hole2"
	"meta_puzzles/l3_slippery_strip"
	"meta_puzzles/l3_stack_stabilization2"
)

func main() {
	nb_errors := uint(0)

	// l0
	nb_errors += l0_abcs.Tests()
	nb_errors += l0_all_wrong.Tests()
	nb_errors += l0_battleship.Tests()

	// l1
	nb_errors += l1_cafeteria.Tests()
	nb_errors += l1_director_photography1.Tests()
	nb_errors += l1_kaitenzushi.Tests()
	nb_errors += l1_rotary_lock1.Tests()
	nb_errors += l1_scoreboard_interference1.Tests()
	nb_errors += l1_stack_stabilization1.Tests()
	nb_errors += l1_uniform_integers.Tests()

	// l2
	nb_errors += l2_director_photography2.Tests()
	nb_errors += l2_hops.Tests()
	nb_errors += l2_missing_mail.Tests()
	//nb_errors += l2_portals.Tests()
	nb_errors += l2_rabbit_hole1.Tests()
	nb_errors += l2_rotary_lock2.Tests()
	nb_errors += l2_scoreboard_interference2.Tests()
	nb_errors += l2_tunnel_time.Tests()

	// l3
	nb_errors += l3_boss_fight.Tests()
	nb_errors += l3_rabbit_hole2.Tests()
	nb_errors += l3_slippery_strip.Tests()
	nb_errors += l3_stack_stabilization2.Tests()

	// l4
	//nb_errors += l4_conveyor_chaos.Tests()
	//nb_errors += l4_mathematical_art.Tests()

	fmt.Printf("\n%d errors\n", nb_errors)
}
