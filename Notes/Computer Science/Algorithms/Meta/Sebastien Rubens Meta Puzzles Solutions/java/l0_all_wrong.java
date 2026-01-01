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

import java.util.function.Function;

class l0_all_wrong {

static class Solution {
	public String getWrongAnswers(int N, String C) {
		var res = new StringBuilder();
		for(int i = 0, n = C.length() ; i < n ; i++)
			res.append(C.charAt(i) == 'A' ? 'B' : 'A');
		return res.toString();
	}
}


static class Args implements test_all.Result<String> {
	String C;
	String res;

	Args(String C, String res)
	{
		this.C = C;
		this.res = res;
	}

	@Override
	public String getResult()
	{
		return res;
	}
}

public static int tests()
{
	var s = new Solution();

	Function<Args, String> wrapper = (p) -> s.getWrongAnswers(p.C.length(), p.C);

	var args_list = new Args[]{
		new Args( "ABA", "BAB" ),
		new Args( "BBBBB", "AAAAA" ),
	};

	return test_all.run_all_tests("l0_all_wrong", args_list, wrapper);
}

}  // class l0_all_wrong
