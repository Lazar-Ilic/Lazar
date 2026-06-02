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

package l1_kaitenzushi

import "meta_puzzles/test"

func getMaximumEatenDishCount(N int32, D []int32, K int32) int32 {
	eaten := make([]bool, 1_000_001)
	last_eaten := make([]uint, K, K)
	oldest_eaten := int32(0)
	nb := int32(0)
	for _, _dish := range D {
		dish := uint(_dish)
		if !eaten[dish] {
			oldest_eaten = (oldest_eaten + 1) % K
			last_eaten_dish := last_eaten[oldest_eaten]
			eaten[last_eaten_dish] = false // we remove the oldest eaten dish
			eaten[dish] = true
			last_eaten[oldest_eaten] = dish // we add the newest eaten dish to our circular buffer
			nb += 1
		}
	}
	return nb
}

type Args struct {
	D   []int32
	K   int32
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 { return getMaximumEatenDishCount(int32(len(p.D)), p.D, p.K) }

	args_lists := []Args{
		{[]int32{1, 2, 3, 3, 2, 1}, 1, 5},
		{[]int32{1, 2, 3, 3, 2, 1}, 2, 4},
		{[]int32{1, 2, 1, 2, 1, 2, 1}, 2, 2},
	}

	return test.RunAllTests("l1_kaitenzushi", args_lists, wrapper)
}
