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

class l0_battleship {

static class Solution {
	public double getHitProbability(int R, int C, int[][] G) {
		int ret = 0;
		for (var row : G)
			for (var elt : row)
				ret += elt;
		return ret / (double) (R * C);
	}
}


static class Args implements test_all.Result<Double> {
	int[][] G;
	double res;

	Args(int[][] G, double res)
	{
		this.G = G;
		this.res = res;
	}

	@Override
	public Double getResult()
	{
		return res;
	}
}

public static int tests()
{
	var s = new Solution();

	Function<Args, Double> wrapper = (p) -> s.getHitProbability(p.G.length, p.G[0].length, p.G);

	var args_list = new Args[]{
		new Args( new int[][]{ {0, 0, 1}, {1, 0, 1} }, 0.5 ),
		new Args( new int[][]{ {0, 0, 1}, {1, 0, 1} }, 0.5 ),
		new Args( new int[][]{ {1, 1}, {1, 1} }, 1.0 ),
		// extra1
		new Args( new int[][]{ {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0} }, 0.25 ),
	};

	return test_all.run_all_tests("l0_battleship", args_list, wrapper, 0.000_001);
}

}  // class l0_battleship
