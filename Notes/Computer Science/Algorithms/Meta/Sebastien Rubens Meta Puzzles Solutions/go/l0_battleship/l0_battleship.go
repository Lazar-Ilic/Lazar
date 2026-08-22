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

package l0_battleship

import (
	"math"
	"meta_puzzles/test"
)

func getHitProbability(R int32, C int32, G [][]int32) float64 {
	var ret int32 = 0
	for _, row := range G {
		for _, elt := range row {
			ret += elt
		}
	}
	return float64(ret) / float64(R*C)
}

type Args struct {
	G   [][]int32
	res float64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) float64 { return getHitProbability(int32(len(p.G)), int32(len(p.G[0])), p.G) }

	args_lists := []Args{
		{[][]int32{{0, 0, 1}, {1, 0, 1}}, 0.5},
		{[][]int32{{1, 1}, {1, 1}}, 1.0},
		// extra1
		{[][]int32{{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}}, 0.25},
	}

	pred := func(lhs float64, rhs float64) bool { return math.Abs(lhs-rhs) < 0.000_001 }
	return test.RunAllTests("l0_battleship", args_lists, wrapper, pred)
}
