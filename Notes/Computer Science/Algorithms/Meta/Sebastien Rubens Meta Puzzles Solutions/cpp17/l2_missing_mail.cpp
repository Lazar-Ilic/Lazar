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
#include <cstdint>  // int**_t
#include <numeric>
#include <vector>

namespace l2_missing_mail {

struct Result
{
    double mail_room_value;
    double total_value;

    double both() const
    {
        return mail_room_value + total_value;
    }
};

double getMaxExpectedProfitCpp17(uint32_t N, const std::vector<int32_t>& V, int32_t C, double S)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=401886137594615
    // Constraints:
    //      1   ≤ N  ≤ 4,000    N is the number of parcels
    //      0   ≤ Vi ≤ 1,000    Vi is the value of a parcel
    //      1   ≤ C  ≤ 1,000    C is the cost the enter a room
    //      0.0 ≤ S   ≤ 1.0     S is the probability the content of the mailroom is stolen
    // Complexity: O(N^2)

    (void)N;

    // Optimisation when packages are never stolen (O(N))
    if (S == 0)
        return std::accumulate(std::cbegin(V), std::cend(V), 0.) - C;

    // Initial result
    std::vector<Result> results = { {0, 0} };
    results.reserve(V.size());
    for (const auto& Vi : V)
    {
        // Update the best results for the new day, considering the packages could've stolen in previous round
        for (auto& [mail_room_value, total_value] : results)
            mail_room_value *= (1 - S);

        // Possibility #1 : pick up packages on this day
        // We need to add the best(max) possible total_value among all saved so far
        const auto max_fn1 = [](const auto& a, const auto& b) { return a.both() < b.both(); };
        const auto pickup_value = (Vi - C) + std::max_element(std::cbegin(results), std::cend(results), max_fn1)->both();

        // Possibility #2 : do not pick up packages on this day
        for (auto& [mail_room_value, total_value] : results)
            mail_room_value += Vi;

        results.emplace_back(Result{ 0, pickup_value });
    }

    const auto max_fn2 = [](const auto& a, const auto& b) { return a.total_value < b.total_value; };
    return std::max_element(std::cbegin(results), std::cend(results), max_fn2)->total_value;
}

using namespace std;

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
    return getMaxExpectedProfitCpp17(static_cast<uint32_t>(N), V, C, S);
}


struct Args
{
    std::vector<int> V;
    int C;
    double S;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMaxExpectedProfit(static_cast<int>(p.V.size()), p.V, p.C, p.S);
    };

    std::vector<NamedTests<Args, double>> tests = {
        { "Meta", {
                { { { 10, 2, 8, 6, 4 }, 5, 0.0 }, 25.0 },
                { { { 10, 2, 8, 6, 4 }, 5, 1.0 }, 9.0 },
                { { { 10, 2, 8, 6, 4 }, 3, 0.5 }, 17.0 },
                { { { 10, 2, 8, 6, 4 }, 3, 0.15 }, 20.10825 },
            }
        },
    };

    return run_all_tests("l2_missing_mail", tests, wrapper, 0.000'001);
}

}  // namespace l2_missing_mail
