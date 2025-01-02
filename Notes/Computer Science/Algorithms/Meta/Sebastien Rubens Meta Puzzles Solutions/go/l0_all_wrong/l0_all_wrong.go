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

package l0_all_wrong

import "meta_puzzles/test"

func getWrongAnswers(N int32, C string) string {
	var ret string
	for _, ch := range C {
		if ch == 'A' {
			ret += "B"
		} else {
			ret += "A"
		}
	}
	return ret
}

type Args struct {
	C   string
	res string
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) string { return getWrongAnswers(int32(len(p.C)), p.C) }

	args_lists := []Args{
		{"ABA", "BAB"},
		{"BBBBB", "AAAAA"},
	}

	return test.RunAllTests("l0_all_wrong", args_lists, wrapper)
}
