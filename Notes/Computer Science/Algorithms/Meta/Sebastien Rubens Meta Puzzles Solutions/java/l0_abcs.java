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

class l0_abcs {

static class Solution {
	public int getSum(int A, int B, int C) {
		return A + B + C;
	}
}


static class Args implements test_all.Result<Integer> {
	int A;
	int B;
	int C;
	int res;

	Args(int A, int B, int C, Integer res)
	{
		this.A = A;
		this.B = B;
		this.C = C;
		this.res = res;
	}

	@Override
	public Integer getResult()
	{
		return res;
	}
}

public static int tests()
{
	var s = new Solution();

	Function<Args, Integer> wrapper = (p) -> s.getSum(p.A, p.B, p.C);

	var args_list = new Args[]{
		new Args(1, 2, 3, 6),
		new Args( 100, 100, 100, 300 ),
		new Args( 85, 16, 93, 194 ),
	};

	return test_all.run_all_tests("l0_abcs", args_list, wrapper);
}

}  // class l0_abcs
