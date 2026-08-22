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

namespace l1_kaitenzushi {

int32_t getMaximumEatenDishCountCpp17(uint32_t N, const std::vector<int32_t>& D, int32_t K)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=958513514962507
    // Constraints
    //      1 ≤ N ≤ 500,000         N is the number of dishes
    //      1 ≤ K ≤ N               K is the number of previous dishes needed to be different
    //      1 ≤ Di ≤ 1,000,000      Di is a dish
    // Complexity: O(N) ~ O(max(N, 1_000_001))   (as asymptotically, N -> +inf)

    (void)N;

    // The following is O(1_000_001)
    std::vector<bool> eaten(1'000'001, false);

    // The following is O(K) (where K < N)
    std::vector<uint32_t> last_eaten(static_cast<size_t>(K), 0);  // circular buffer for last eaten value (0 is not used, as 1 <= Ki <= 1,000,000)
    uint32_t oldest_eaten = 0;

    // The following is O(N)
    int32_t nb = 0;
    for (const auto& _dish : D)
    {
        const auto dish = static_cast<uint32_t>(_dish);
        if (!eaten[dish])
        {
            oldest_eaten = (oldest_eaten + 1) % K;
            const auto last_eaten_dish = last_eaten[oldest_eaten];
            eaten[last_eaten_dish] = false;  // we remove the oldest eaten dish
            eaten[dish] = true;
            last_eaten[oldest_eaten] = dish;  // we add the newest eaten dish to our circular buffer
            ++nb;
        }
    }
    return nb;  // result should always be positive
}

using namespace std;

int32_t getMaximumEatenDishCount(int N, vector<int> D, int K) {
    return getMaximumEatenDishCountCpp17(static_cast<uint32_t>(N), D, K);
}


struct Args
{
    std::vector<int> D;
    int K;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMaximumEatenDishCount(static_cast<int>(p.D.size()), p.D, static_cast<int>(p.K));
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { 1, 2, 3, 3, 2, 1 }, 1 }, 5 },
                { { { 1, 2, 3, 3, 2, 1 }, 2 }, 4 },
                { { { 1, 2, 1, 2, 1, 2, 1 }, 2 }, 2 },
            }
        },
    };

    return run_all_tests("l1_kaitenzushi", tests, wrapper);
}

}  // namespace l1_kaitenzushi
