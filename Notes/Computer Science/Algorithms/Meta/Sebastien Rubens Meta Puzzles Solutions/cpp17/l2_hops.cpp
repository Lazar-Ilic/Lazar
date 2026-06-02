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

namespace l2_hops {

long long getSecondsRequiredCpp17(int64_t N, uint32_t F, const std::vector<long long>& P)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=977526253003069
    // Constraints:
    //      2 ≤ N ≤ 10^12
    //      1 ≤ F ≤ 500,000
    //      1 ≤ Pi ≤ N−1
    // Complexity: O(N), but could be O(1) if P was sorted

    (void)F;

    // When you think about it, the solution is very simple!
    if (P.empty())
        return 0;
    return N - *std::min_element(std::cbegin(P), std::cend(P));
}

using namespace std;

long long getSecondsRequired(long long N, int F, vector<long long> P) {
    return getSecondsRequiredCpp17(N, static_cast<uint32_t>(F), P);
}


struct Args
{
    long long N;
    std::vector<long long> P;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getSecondsRequired(p.N, static_cast<int>(p.P.size()), p.P);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { 3, { 1, }  }, 2 },
                { { 6, { 5, 2, 4, }  }, 4 },
            }
        },
    };

    return run_all_tests("l2_hops", tests, wrapper);
}

}  // namespace l2_hops
