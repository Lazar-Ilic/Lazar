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

package l2_scoreboard_interference2

import "meta_puzzles/test"

func getMinProblemCount(N int32, S []int32) int32 {
	max_score := int32(0)
	second_max_score := int32(0)
	two_remainder := int32(0)
	one_remainder := int32(0)
	need_one := false

	for _, score := range S {
		score_mod_3 := score % 3
		two_remainder |= (score_mod_3 >> 1)
		one_remainder |= (score_mod_3 & 1)
		need_one = need_one || (score == 1)
		if max_score < score {
			second_max_score = max_score
			max_score = score
		} else if second_max_score < score {
			second_max_score = score
		}
	}

	// number of solutions, without any optimisation
	count := max_score/3 + two_remainder + one_remainder

	// not optimisation is possible if "two_remainder and one_remainder" is not true
	if two_remainder*one_remainder != 1 {
		return count
	}

	// replace "last +3" by "+1+2"
	if max_score%3 == 0 {
		count -= 1
	}

	// replace last "+3+1" by "+2+2"
	if need_one { // exit early because 1 is required but at least one sum(i.e.it cannot be replaced)
		return count
	}
	if max_score%3 != 1 { // max_score does not have a 1 (so it cannot be replaced)
		return count
	}
	tmp := max_score - second_max_score
	if !(tmp == 1 || tmp == 3) { // [ok, not ok(3), ok] || [not ok(1) | here | unimportant]
		count -= 1
	}
	return count
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
		{[]int32{1, 2, 3, 4, 5}, 3},
		{[]int32{4, 3, 3, 4}, 2},
		{[]int32{2, 4, 6, 8}, 4},
		{[]int32{8}, 3},
		// extra1
		{[]int32{4, 3, 3, 4}, 2},
		{[]int32{2, 4, 6, 8}, 4},
		{[]int32{8}, 3},
		{[]int32{1, 2, 3}, 2},
		{[]int32{5, 7}, 3},
		{[]int32{5, 9, 10}, 5},
		{[]int32{5, 9, 11}, 4},
		{[]int32{4, 5, 6}, 3},
		{[]int32{2, 4, 7}, 4},
		// extra2
		{[]int32{1, 2, 4}, 3},
		{[]int32{2, 4}, 2},
		{[]int32{4, 5}, 3},
		{[]int32{9, 12}, 4},
		{[]int32{11, 13}, 5},
	}

	return test.RunAllTests("l2_scoreboard_interference2", args_lists, wrapper)
}
