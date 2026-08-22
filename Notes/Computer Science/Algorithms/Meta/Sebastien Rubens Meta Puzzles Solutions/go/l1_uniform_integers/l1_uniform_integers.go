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

package l1_uniform_integers

import (
	"meta_puzzles/test"
)

func len_str(nb int64) int {
	if nb == 0 { // not necessary due to problem definition
		return 1
	}
	ret := 0
	for ; nb > 0; nb /= 10 {
		ret += 1
	}
	return ret
}

func ones(log_value int) int64 {
	ret := int64(0)
	for i := 0; i < log_value; i += 1 {
		ret = ret*10 + 1
	}
	return ret
}

func getUniformIntegerCountInInterval(A int64, B int64) int32 {
	// Each of the following lines is O(log(max(A, B)))
	len_a := len_str(A)
	len_b := len_str(B)
	tmp_a := ones(len_a)
	tmp_b := ones(len_b)

	// Everything else is O(1)
	nb_a := (tmp_a*10 - A) / tmp_a
	nb_b := B / tmp_b
	nb_m := 0
	if len_b-len_a >= 2 {
		nb_m = 9 * (len_b - len_a - 1)
	}
	nb := nb_a + int64(nb_m) + nb_b
	if len_a == len_b {
		nb -= 9
	}
	return int32(nb)
}

type Args struct {
	A   int64
	B   int64
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 { return getUniformIntegerCountInInterval(p.A, p.B) }

	args_lists := []Args{
		{75, 300, 5},
		{1, 9, 9},
		{999999999999, 999999999999, 1},
		// extra1
		{1, 1_000_000_000_000, 108},
		// extra2
		{10, 99, 9},
		{11, 98, 8},
		{21, 89, 7},
		{22, 88, 7},
		{23, 87, 5},
		// extra3
		{11, 88, 8},
		{11, 98, 8},
		{11, 99, 9},
	}

	return test.RunAllTests("l1_uniform_integers", args_lists, wrapper)
}
