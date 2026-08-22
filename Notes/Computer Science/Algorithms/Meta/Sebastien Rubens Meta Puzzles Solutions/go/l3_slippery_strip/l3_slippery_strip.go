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

package l3_slippery_strip

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

type row_t = []byte
type char_counter_t = [256]int

type Counts struct {
	star  int
	right int
	down  int
}

type predicate_t[T any] func(x T) bool

func Count[T std.Comparable](elements []T, value T) int {
	// similar to C++ std::count
	nb := 0
	for _, elt := range elements {
		if elt == value {
			nb += 1
		}
	}
	return nb
}

func _find_element[T any](elements []T, pred predicate_t[T]) int {
	for pos, elt := range elements {
		if pred(elt) {
			return pos
		}
	}
	return len(elements)
}

func Find[T std.Comparable](elements []T, value T) int {
	// similar to C++ std::find
	fn := func(x T) bool { return x == value }
	return _find_element(elements, fn)
}

func get_counts(row row_t, counts *char_counter_t) Counts {
	counts['*'] = 0
	counts['>'] = 0
	counts['v'] = 0
	for _, c := range row {
		d := int(c)
		if d >= len(counts) {
			d = '.' // empty value (we do not use it)
		}
		counts[d] += 1
	}
	return Counts{counts['*'], counts['>'], counts['v']}
}

func get_nb_coins_right_then_down3(row row_t, count_down int, count_right int) int {
	// complexity : O(C)
	if count_down == 0 {
		return 0
	}
	k := Find(row, 'v')
	j := 0
	if k != len(row) {
		j = k + 1
	}
	new_row := make(row_t, 0, len(row))
	new_row = append(new_row, row[j:]...)
	new_row = append(new_row, row[:j]...)
	nb_coins_right_then_down := 0
	last := 0
	for count_right*count_down != 0 {
		first := last + Find(new_row[last:], '>')
		last := first + Find(new_row[first:], 'v')
		nb_coins_right_then_down = std.Max(nb_coins_right_then_down, Count(new_row[first:last], '*'))
		count_down -= 1
		count_right -= Count(new_row[first:last], '>')
	}
	return nb_coins_right_then_down
}

func getMaxCollectableCoins(R int32, C int32, G [][]byte) int32 {
	counts := char_counter_t{}
	res := 0
	for i, _ := range G {
		row := G[len(G)-i-1]
		count := get_counts(row, &counts)
		nb_coins_immediately_down := std.Min(count.star, 1)
		if count.right == int(C) {
			res = 0
		} else if count.right == 0 {
			res += nb_coins_immediately_down
		} else {
			nb_coins_right_then_down := get_nb_coins_right_then_down3(row, count.down, count.right)
			nb_coins_right_forever := 0
			if count.down == 0 {
				nb_coins_right_forever = count.star
			}
			res = std.Max(nb_coins_immediately_down+res, std.Max(nb_coins_right_then_down+res, nb_coins_right_forever))
		}
	}
	return int32(res) // result should always be positive
}

type Args struct {
	G   []string
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 {
		H := make([][]byte, len(p.G))
		for idx, row := range p.G {
			H[idx] = []byte(string(row))
		}
		C := 0
		if len(H) > 0 {
			C = len(H[0])
		}
		return getMaxCollectableCoins(int32(len(H)), int32(C), H)
	}

	args_lists := []Args{
		{[]string{".***", "**v>", ".*.."}, 4},
		{[]string{">**", "*>*", "**>"}, 4},
		{[]string{">>", "**"}, 0},
		{[]string{">*v*>*", "*v*v>*", ".*>..*", ".*..*v"}, 6},
		// extra1
		{[]string{}, 0},
		{[]string{"."}, 0},
		{[]string{"v"}, 0},
		{[]string{">"}, 0},
		{[]string{"*"}, 1},
		// extra2
		{[]string{".", ".", ">", "*"}, 0},
		{[]string{".", "*", ">", "*"}, 1},
		{[]string{".", "*", ">", "."}, 1},
		{[]string{"*", ".", ">", "."}, 1},
		{[]string{"***", "...", ">vv", "..."}, 1},
		// extra3
		{[]string{"*....", ".*...", "..*..", "...*."}, 4},
		{[]string{"....", "....", "....", "...."}, 0},
		{[]string{"***>", "...."}, 3},
		{[]string{"...."}, 0},
		{[]string{"vvvv"}, 0},
		{[]string{"vvvv", "....", ">>>>"}, 0},
		// extra4
		{[]string{"******", "......", ">*>vvv", "......"}, 2},
		{[]string{"*****", ".....", ">>vvv", "....."}, 1},
	}

	return test.RunAllTests("l3_slippery_strip", args_lists, wrapper)
}
