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

package l3_stack_stabilization2

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

func getMinimumSecondsRequired(N int32, R []int32, A int32, B int32) int64 {
	type total_cost_t = int64
	type unit_cost_t = int32
	_A := total_cost_t(A)
	_B := total_cost_t(B)

	if N == 0 || len(R) == 0 {
		return 0
	}

	U := make([]int32, len(R))
	copy(U, R)

	// Extend the range of input data
	total_cost := total_cost_t(0)
	costs := make([]unit_cost_t, N)
	intervals := make([]int32, 0, N)
	intervals = append(intervals, 0)
	for i := int32(1); i < N; i += 1 {
		Uj := U[i-1] + 1
		Ui := U[i]
		// inflate first
		if Uj > Ui { // if (min_inflate > 0)
			min_inflate := Uj - Ui                       // fits in 32bits
			total_cost += total_cost_t(min_inflate) * _A // fits in 64-bits
			U[i] += min_inflate                          // fits in 32bits by definition
			costs[i] = min_inflate                       // fits in 32bits by definition
		}
		// track continuous intervals (note: this is not a "else if"!)
		if Uj < Ui { // if (min_inflate < 0)
			intervals = append(intervals, i)
			continue
		}
		// deflate eventually
		for {
			first := intervals[len(intervals)-1]
			nb_tot := 1 + i - first
			//
			nb_pos := int32(0)
			min_positive1 := int32(0)
			last := +i + 1
			for curr := first; curr != last; curr += 1 {
				value := costs[curr]
				if value > 0 {
					nb_pos += 1
					if min_positive1 > 0 {
						min_positive1 = std.Min(min_positive1, value)
					} else {
						min_positive1 = value
					}
				}
			}
			//
			min_positive2 := U[0]
			if first > 0 {
				min_positive2 = U[first] - U[first-1]
			}
			min_positive := std.Min(min_positive1, min_positive2-1)
			nb_neg := nb_tot - nb_pos
			cost_change := (total_cost_t(nb_neg)*_B - total_cost_t(nb_pos)*_A) * total_cost_t(min_positive)
			if cost_change >= 0 {
				break
			}
			total_cost += cost_change
			for j := first; j < i+1; j += 1 {
				costs[j] -= min_positive
				U[j] -= min_positive
			}
			if first > 0 {
				if U[first] == U[first-1]+1 {
					intervals = intervals[:len(intervals)-1]
				}
			}
			if min_positive <= 0 {
				break
			}
		}
	}
	return total_cost
}

type Args struct {
	R   []int32
	A   int32
	B   int32
	res int64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int64 { return getMinimumSecondsRequired(int32(len(p.R)), p.R, p.A, p.B) }

	args_lists := []Args{
		{[]int32{2, 5, 3, 6, 5}, 1, 1, 5},
		{[]int32{100, 100, 100}, 2, 3, 5},
		{[]int32{100, 100, 100}, 7, 3, 9},
		{[]int32{6, 5, 4, 3}, 10, 1, 19},
		{[]int32{100, 100, 1, 1}, 2, 1, 207},
		{[]int32{6, 5, 2, 4, 4, 7}, 1, 1, 10},
		// extra1
		{[]int32{10, 6, 2}, 2, 1, 15},
		{[]int32{1, 2, 3, 4, 5, 6}, 1, 1, 0},
		{[]int32{6, 5, 4, 3, 2, 1}, 1, 1, 18},
		// extra2
		{[]int32{4, 6, 2}, 2, 1, 9},
		{[]int32{6, 5, 2, 4, 4, 7}, 1, 1, 10},
		{[]int32{2, 5, 3, 6, 5}, 1, 1, 5},
		{[]int32{2, 3, 8, 1, 7, 6}, 2, 1, 15},
		{[]int32{5, 4, 3, 6, 8, 1, 10, 11, 6, 1}, 4, 1, 85},
		{[]int32{3, 4, 7, 8, 2}, 4, 1, 24},
		{[]int32{1, 1, 1, 1, 1}, 4, 1, 40},
		{[]int32{1, 1, 1, 1, 1}, 1, 4, 10},
		{[]int32{8, 6, 4, 2}, 1, 4, 18},
		{[]int32{1_000_000_000, 500_000_000, 200_000_000, 1_000_000}, 1, 4, 2_299_000_006},
	}

	return test.RunAllTests("l3_stack_stabilization2", args_lists, wrapper)
}
