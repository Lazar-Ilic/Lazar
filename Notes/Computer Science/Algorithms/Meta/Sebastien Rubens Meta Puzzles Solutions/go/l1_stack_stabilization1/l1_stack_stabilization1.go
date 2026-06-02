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

package l1_stack_stabilization1

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

func getMinimumDeflatedDiscCount(N int32, R []int32) int32 {
	nb := int32(0)
	it := len(R) - 1
	current_radius := R[it]
	it -= 1
	for ; it > -1; it -= 1 {
		next_radius := R[it]
		target_radius := current_radius - 1
		if target_radius <= 0 {
			return -1
		}
		if target_radius < next_radius {
			nb += 1
		}
		current_radius = std.Min(next_radius, target_radius)
	}
	return nb
}

type Args struct {
	S   []int32
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 { return getMinimumDeflatedDiscCount(int32(len(p.S)), p.S) }

	args_lists := []Args{
		{[]int32{2, 5, 3, 6, 5}, 3},
		{[]int32{100, 100, 100}, 2},
		{[]int32{6, 5, 4, 3}, -1},
	}

	return test.RunAllTests("l1_stack_stabilization1", args_lists, wrapper)
}
