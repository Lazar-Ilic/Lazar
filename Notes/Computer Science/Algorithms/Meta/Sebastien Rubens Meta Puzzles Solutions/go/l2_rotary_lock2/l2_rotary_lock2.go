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

package l2_rotary_lock2

import (
	"math"
	"meta_puzzles/std"
	"meta_puzzles/test"
)

type Dials struct {
	dial1 int32
	dial2 int32
}

func get_distance(target int32, position int32, N int32) int32 {
	positive_move := (target - position) % N
	if positive_move < 0 { // modulo must be positive (must check that in C++)
		positive_move += N
	}
	negative_move := N - positive_move // positive number
	return std.Min(positive_move, negative_move)
}

type solutions_t map[Dials]int64

func insert_solution(new_solutions solutions_t, N int32, target int32, dial1 int32, dial2 int32, distance int64) {
	new_distance := distance + int64(get_distance(target, dial1, N))
	key := Dials{std.Min(dial2, target), std.Max(dial2, target)}
	value := int64(math.MaxInt64)
	if previous_value, found := new_solutions[key]; found {
		value = previous_value
	}
	new_solutions[key] = std.Min(value, new_distance)
}

func getMinCodeEntryTime(N int32, M int32, C []int32) int64 {
	if len(C) == 0 {
		return 0
	}
	solutions := solutions_t{Dials{1, 1}: 0}
	for _, target := range C {
		new_solutions := solutions_t{}
		for dials, distance := range solutions {
			// we turn dial1
			insert_solution(new_solutions, N, target, dials.dial1, dials.dial2, distance)
			// we turn dial2
			insert_solution(new_solutions, N, target, dials.dial2, dials.dial1, distance)
		}
		solutions = new_solutions
	}
	min_distance := int64(math.MaxInt64)
	for _, distance := range solutions {
		min_distance = std.Min(min_distance, distance)
	}
	return min_distance
}

type Args struct {
	N   int32
	C   []int32
	res int64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int64 { return getMinCodeEntryTime(p.N, int32(len(p.C)), p.C) }

	args_lists := []Args{
		{3, []int32{1, 2, 3}, 2},
		{10, []int32{9, 4, 4, 8}, 6},
		// extra1
		{0, []int32{}, 0},
		{3, []int32{}, 0},
		{10, []int32{}, 0},
		{10, []int32{4}, 3},
		{10, []int32{9}, 2},
		{10, []int32{9, 9, 9, 9}, 2},
		// extra2
		{10, []int32{6, 2, 4, 8}, 10},                   // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
		{10, []int32{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 9}, // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
		{4, []int32{4, 3, 2, 1, 2, 3, 4}, 5},            // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
	}

	return test.RunAllTests("l2_rotary_lock2", args_lists, wrapper)
}
