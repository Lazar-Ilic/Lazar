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

#include "test_all.h"

#include <numeric>
#include <vector>

namespace l0_battleship {

double getHitProbabilityCpp17(uint32_t R, uint32_t C, const std::vector<std::vector<int32_t>>& G)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=3641006936004915
    // Constraints
    //      1 ≤ R,C ≤ 100       R,C is the number of rows,columns
    //      0 ≤ Gi,j ≤ 1
    // Complexity: O(N), where N=R*C

    uint32_t ret = 0;
    for (const auto& row : G)
        for (const auto& elt : row)
            ret += elt;
    return ret / static_cast<double>(R * C);

    // one could do the following, but here, C++ won't be beating Python in term of concision
    //return std::transform_reduce(std::cbegin(G), std::cend(G), 0, std::plus{},
    //        [](const auto& row) { return std::accumulate(std::cbegin(row), std::cend(row), 0); });
}

using namespace std;

double getHitProbability(int R, int C, vector<vector<int>> G) {
    return getHitProbabilityCpp17(static_cast<uint32_t>(R), static_cast<uint32_t>(C), G);
}


struct Args
{
    std::vector<vector<int>> G;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getHitProbability(static_cast<int>(p.G.size()), p.G.empty() ? 0 : static_cast<int>(p.G[0].size()), p.G);
    };

    std::vector<NamedTests<Args, double>> tests = {
        { "Meta", {
                { { { { 0, 0, 1 }, { 1, 0, 1 } } }, 0.5 },
                { { { { 1, 1 }, { 1, 1 } } }, 1.0 },
            }
        },
        { "extra1", {
                { { { { 0, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 0, 0 } } }, 0.25 },
            }
        },
    };

    return run_all_tests("l0_battleship", tests, wrapper, 0.000'001);
}

}  // namespace l0_battleship
