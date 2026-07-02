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

namespace l3_stack_stabilization2 {

int64_t getMinimumSecondsRequiredCpp17(uint32_t N, const std::vector<int32_t>& R, int32_t A, int32_t B)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=290955626029019
    // Constraints :
    //      1 ≤ N    ≤ 50
    //      1 ≤ Ri   ≤ 1,000,000,000
    //      1 ≤ A, B ≤ 100
    // Complexity: O(N ^ 2)

    using total_cost_t = int64_t;
    using unit_cost_t = int32_t;
    const auto _A = static_cast<total_cost_t>(A);
    const auto _B = static_cast<total_cost_t>(B);

    if (N == 0 || R.empty())
        return 0;

    auto U = R;

    // Extend the range of input data
    total_cost_t total_cost = 0;
    std::vector<unit_cost_t> costs(N, 0);
    std::vector<uint32_t> intervals;
    intervals.reserve(N);
    intervals.emplace_back(0);
    for (uint32_t i = 1; i < N; ++i)
    {
        const auto Uj = U[i - 1] + 1;
        const auto Ui = U[i];
        // inflate first
        if (Uj > Ui)  // if (min_inflate > 0)
        {
            const auto min_inflate = Uj - Ui;  // fits in 32bits
            total_cost += min_inflate * _A;  // fits in 64-bits
            U[i] += min_inflate;  // fits in 32bits by definition
            costs[i] = min_inflate;  // fits in 32bits by definition
        }
        // track continuous intervals (note: this is not a "else if"!)
        if (Uj < Ui)  // if (min_inflate < 0)
        {
            intervals.emplace_back(i);
            continue;
        }
        // deflate eventually
        while (true)
        {
            const auto first = intervals.back();
            const auto nb_tot = 1 + i - first;
            //
            int32_t nb_pos = 0;
            int32_t min_positive1 = 0;
            for (auto curr = std::cbegin(costs) + first, last = std::cbegin(costs) + i + 1; curr != last; ++curr)
            {
                const auto value = *curr;
                if (value > 0)
                {
                    ++nb_pos;
                    min_positive1 = min_positive1 > 0 ? std::min(min_positive1, value) : value;
                }
            }
            //
            const auto min_positive2 = first > 0 ? (U[first] - U[first - 1]) : U[0];
            const auto min_positive = std::min(min_positive1, min_positive2 - 1);
            const auto nb_neg = nb_tot - nb_pos;
            const auto cost_change = (nb_neg * _B - nb_pos * _A) * min_positive;
            if (cost_change >= 0)
                break;
            total_cost += cost_change;
            for (auto j = first; j <= i; ++j)
            {
                costs[j] -= min_positive;
                U[j] -= min_positive;
            }
            if (first > 0)
            {
                if (U[first] == U[first - 1] + 1)
                    intervals.pop_back();
            }
            if (min_positive <= 0)
                break;
        }
    }
    return total_cost;
}

using namespace std;

long long getMinimumSecondsRequired(int N, vector<int> R, int A, int B) {
    return getMinimumSecondsRequiredCpp17(static_cast<uint32_t>(N), R, A, B);
}


struct Args
{
    std::vector<int> R;
    int A;
    int B;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMinimumSecondsRequired(static_cast<int>(p.R.size()), p.R, p.A, p.B);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { { 2, 5, 3, 6, 5 }, 1, 1 }, 5 },
                { { { 100, 100, 100 }, 2, 3 }, 5 },
                { { { 100, 100, 100 }, 7, 3 }, 9 },
                { { { 6, 5, 4, 3 }, 10, 1 }, 19 },
                { { { 100, 100, 1, 1 }, 2, 1 }, 207 },
                { { { 6, 5, 2, 4, 4, 7 }, 1, 1 }, 10 },
            }
        },
        { "extra1", {
                { { { 10, 6, 2 }, 2, 1 }, 15 },
                { { { 1, 2, 3, 4, 5, 6 }, 1, 1 }, 0 },
                { { { 6, 5, 4, 3, 2, 1 }, 1, 1 }, 18 },
            }
        },
        { "extra2", {
                { { { 4, 6, 2 }, 2, 1 }, 9 },
                { { { 6, 5, 2, 4, 4, 7 }, 1, 1 }, 10 },
                { { { 2, 5, 3, 6, 5 }, 1, 1 }, 5 },
                { { { 2, 3, 8, 1, 7, 6 }, 2, 1 }, 15 },
                { { { 5, 4, 3, 6, 8, 1, 10, 11, 6, 1 }, 4, 1 }, 85 },
                { { { 3, 4, 7, 8, 2 }, 4, 1 }, 24 },
                { { { 1, 1, 1, 1, 1 }, 4, 1 }, 40 },
                { { { 1, 1, 1, 1, 1 }, 1, 4 }, 10 },
                { { { 8, 6, 4, 2 }, 1, 4 }, 18 },
                { { { 1'000'000'000, 500'000'000, 200'000'000, 1'000'000 }, 1, 4}, 2'299'000'006 },
            }
        },
    };

    return run_all_tests("l3_stack_stabilization2", tests, wrapper);
}

}  // namespace l3_stack_stabilization2
