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

package l1_cafeteria

import (
	"meta_puzzles/test"
	"sort"
)

func getMaxAdditionalDinersCount(N int64, K int64, M int32, S []int64) int64 {
	d := K + 1
	taken := make([]int64, 0, len(S)+2)
	taken = append(taken, 0-K)
	taken = append(taken, S...)
	taken = append(taken, N+d)
	sort.Slice(taken, func(i, j int) bool { return taken[i] < taken[j] })

	var nb int64 = 0
	e := len(taken) - 1
	for i := 0; i < e; i += 1 {
		nb += (taken[i+1] - taken[i] - d) / d
	}
	return nb
}

type Args struct {
	N   int64
	K   int64
	S   []int64
	res int64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int64 { return getMaxAdditionalDinersCount(p.N, p.K, int32(len(p.S)), p.S) }

	args_lists := []Args{
		{10, 1, []int64{2, 6}, 3},
		{15, 2, []int64{11, 6, 14}, 1},
	}

	return test.RunAllTests("l1_cafetaria", args_lists, wrapper)
}
