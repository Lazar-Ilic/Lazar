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

#include <vector>

namespace l0_abcs {

int32_t getSumCpp17(int32_t A, int32_t B, int32_t C)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=513411323351554
    // Constraints
    //   1 ≤ A,B,C ≤ 100
    // Complexity: O(1)

    return A + B + C;
}

using namespace std;

int getSum(int A, int B, int C) {
    return getSumCpp17(A, B, C);
}


struct Args
{
    int A;
    int B;
    int C;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getSum(p.A, p.B, p.C);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { 1, 2, 3 }, 6 },
                { { 100, 100, 100 }, 300 },
                { { 85, 16, 93 }, 194 },
            }
        },
    };

    return run_all_tests("l0_abcs", tests, wrapper);
}

} // namespace l0_abcs
