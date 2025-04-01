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

package l1_scoreboard_interference1

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

func getMinProblemCount(N int32, S []int32) int32 {
	min_number_of_twos := int32(0)
	min_number_of_ones := int32(0)
	for _, score := range S {
		number_of_twos := score / 2
		number_of_ones := score % 2
		min_number_of_twos = std.Max(min_number_of_twos, number_of_twos)
		min_number_of_ones = std.Max(min_number_of_ones, number_of_ones)
	}
	return min_number_of_twos + min_number_of_ones // result should always be positive
}

type Args struct {
	S   []int32
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 { return getMinProblemCount(int32(len(p.S)), p.S) }

	args_lists := []Args{
		{[]int32{1, 2, 3, 4, 5, 6}, 4},
		{[]int32{4, 3, 3, 4}, 3},
		{[]int32{2, 4, 6, 8}, 4},
	}

	return test.RunAllTests("l1_scoreboard_interference1", args_lists, wrapper)
}
