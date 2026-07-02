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

namespace l1_stack_stabilization1 {

int32_t getMinimumDeflatedDiscCountCpp17(uint32_t N, const std::vector<int32_t>& R)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=183894130288005
    // Constraints
    //      1 ≤ N  ≤ 50                 N is the number of inflatable discs
    //      1 ≤ Ri ≤ 1,000,000,000      Ri is a disc radius
    // Complexity: O(N)

    (void)N;

    int32_t nb = 0;
    auto it = std::crbegin(R);
    auto current_radius = *it++;
    for (auto ite = std::crend(R); it != ite; ++it)
    {
        const auto next_radius = *it;
        const auto target_radius = current_radius - 1;
        if (target_radius <= 0)
            return -1;
        nb += target_radius < next_radius ? 1 : 0;
        current_radius = std::min(next_radius, target_radius);
    }
    return nb;  // result should always be positive
}

using namespace std;

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
    return getMinimumDeflatedDiscCountCpp17(static_cast<uint32_t>(N), R);
}


struct Args
{
    std::vector<int> S;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMinimumDeflatedDiscCount(static_cast<int>(p.S.size()), p.S);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { 2, 5, 3, 6, 5 } }, 3 },
                { { { 100, 100, 100 } }, 2 },
                { { { 6, 5, 4, 3 } }, -1 },
            }
        },
    };

    return run_all_tests("l1_stack_stabilization1", tests, wrapper);
}

}  // namespace l1_stack_stabilization1
