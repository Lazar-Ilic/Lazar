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

#include <cstdint>  // int**_t
#include <string>
#include <type_traits>
#include <vector>

namespace l2_director_photography2 {

template<typename T>
static inline T _getArtisticPhotographCountCpp17(uint32_t N, const std::string& C, int32_t X, int32_t Y)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=870874083549040
    // Constraints
    //      1 ≤ N ≤ 200         N is the number of cells in a row
    //      1 ≤ X ≤ Y ≤ N       X,Y are the distance between a photograph and an actor
    // Complexity: O(N) ~ O(N * (Y-X+1)) because Y-X << N

    static_assert(std::disjunction_v<std::is_same<T, int32_t>, std::is_same<T, int64_t>>);  // Because there is not concept in C++17
    const auto _X = static_cast<uint32_t>(X);
    const auto _Y = static_cast<uint32_t>(Y);

    (void)N;

    struct Counts
    {
        uint32_t p;
        uint32_t b;
    };

    // count the number of Ps or Bs till a position i: O(N)
    const auto w = _Y + 1;
    Counts count{ 0, 0 };
    std::vector<Counts> counts;
    counts.reserve(C.size() + w * 2);
    for (uint32_t i = 0; i < w; ++i)  // add space at the beginning to avoid special treatment of indices later
        counts.emplace_back(Counts{ 0, 0 });
    for (const auto& ci : C)
    {
        if (ci == 'P')
            ++count.p;
        else if (ci == 'B')
            ++count.b;
        counts.emplace_back(count);
    }
    const auto& last = counts.back();
    for (uint32_t i = 0; i < w; ++i)  // add space at the end to avoid special treatment of indices later
        counts.emplace_back(last);

    // To make things more readable, we are finding first the point where 'A' is found: O(N)
    std::vector<uint32_t> possible;
    possible.reserve(C.size());
    uint32_t j = w;
    for (const auto& ci : C)
    {
        if (ci == 'A')
            possible.emplace_back(j);
        ++j;
    }

    // Count PABs : O(N)
    const auto X1 = _X - 1;
    const auto Y1 = _Y + 1;
    T nb = 0;
    for (const auto i : possible)
        nb += static_cast<T>(counts[i - _X].p - counts[i - Y1].p) * static_cast<T>(counts[i + _Y].b - counts[i + X1].b);

    // Count BAPs : O(N)
    for (const auto i : possible)
        nb += static_cast<T>(counts[i - _X].b - counts[i - Y1].b) * static_cast<T>(counts[i + _Y].p - counts[i + X1].p);

    return nb;  // result should always be positive
}

using namespace std;

long long getArtisticPhotographCount(int N, string C, int X, int Y) {
    return _getArtisticPhotographCountCpp17<int64_t>(static_cast<uint32_t>(N), C, X, Y);
}


struct Args
{
    std::string C;
    int X;
    int Y;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getArtisticPhotographCount(static_cast<int>(p.C.size()), p.C, p.X, p.Y);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { "APABA", 1, 2 }, 1 },
                { { "APABA", 2, 3 }, 0 },
                { { ".PBAAP.B", 1, 3 }, 3 },
            }
        },
        { "extra1", {
                { { "PP.A.BB.B", 1, 3 }, 4 },
            }
        },
    };

    return run_all_tests("l2_director_photography2", tests, wrapper);
}

}  // namespace l2_director_photography2
