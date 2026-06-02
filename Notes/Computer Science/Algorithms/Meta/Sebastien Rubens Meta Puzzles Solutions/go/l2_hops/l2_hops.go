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

package l2_hops

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

func getSecondsRequired(N int64, F int32, P []int64) int64 {
	// When you think about it, the solution is very simple!
	if len(P) == 0 {
		return 0
	}
	return N - *std.MinElement(P)
}

type Args struct {
	N   int64
	P   []int64
	res int64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int64 { return getSecondsRequired(p.N, int32(len(p.P)), p.P) }

	args_lists := []Args{
		{3, []int64{1}, 2},
		{6, []int64{5, 2, 4}, 4},
	}

	return test.RunAllTests("l2_hops", args_lists, wrapper)
}
