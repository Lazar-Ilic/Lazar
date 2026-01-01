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

#include <algorithm>
#include <vector>

namespace l1_scoreboard_interference1 {

int32_t getMinProblemCountCpp17(uint32_t N, const std::vector<int32_t>& S)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=348371419980095
    // Constraints
    //      1 ≤ N ≤ 500,000             N is the number of scores
    //      1 ≤ Si ≤ 1,000,000,000      Si is a score
    // Complexity: O(N)

    (void)N;

    // Note: the way to solve this problem is to count and his fairly simple
    // - the minimum number of problems scored 2 to solve all solutions
    // - the minimum number of problems scored 1 to solve all solutions (0 or 1)

    int32_t min_number_of_twos = 0;
    int32_t min_number_of_ones = 0;
    for (const auto& score : S)
    {
        const auto number_of_twos = score / 2;
        const auto number_of_ones = score % 2;
        min_number_of_twos = std::max(min_number_of_twos, number_of_twos);
        min_number_of_ones = std::max(min_number_of_ones, number_of_ones);
    }
    return min_number_of_twos + min_number_of_ones;  // result should always be positive
}

using namespace std;

int getMinProblemCount(int N, vector<int> S) {
    return getMinProblemCountCpp17(static_cast<uint32_t>(N), S);
}


struct Args
{
    std::vector<int> S;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMinProblemCount(static_cast<int>(p.S.size()), p.S);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { 1, 2, 3, 4, 5, 6 } }, 4 },
                { { { 4, 3, 3, 4 } }, 3 },
                { { { 2, 4, 6, 8 } }, 4 },
            }
        },
    };

    return run_all_tests("l1_scoreboard_interference1", tests, wrapper);
}

}  // namespace l1_scoreboard_interference1
