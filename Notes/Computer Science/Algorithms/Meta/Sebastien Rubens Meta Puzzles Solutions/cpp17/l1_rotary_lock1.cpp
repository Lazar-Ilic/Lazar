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
#include <vector>

namespace l1_rotary_lock1 {

int64_t getMinCodeEntryTimeCpp17(int32_t N, uint32_t M, const std::vector<int32_t>& C)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=990060915068194
    // Constraints
    //      3 ≤ N ≤ 50,000,000      N is the number of integers
    //      1 ≤ M ≤ 1,000           M is the number of locks
    //      1 ≤ Ci ≤ N              Ci is the combination
    // Complexity: O(M)

    (void)M;

    int32_t pos = 1;
    int64_t nb = 0;
    for (const auto& target : C)
    {
        auto positive_move = (target - pos) % N;  // positive move
        positive_move = positive_move < 0 ? positive_move + N : positive_move;  // modulo can be negative in C++
        const auto negative_move = N - positive_move;
        nb += std::min(positive_move, negative_move);
        pos = target;
    }
    return nb;  // result should always be positive
}

using namespace std;

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
    return getMinCodeEntryTimeCpp17(N, static_cast<uint32_t>(M), C);
}


struct Args
{
    int N;
    std::vector<int> C;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMinCodeEntryTime(p.N, static_cast<int>(p.C.size()), p.C);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { 3, { 1, 2, 3 } }, 2 },
                { { 10, { 9, 4, 4, 8 } }, 11 },
            }
        },
    };

    return run_all_tests("l1_rotary_lock1", tests, wrapper);
}

}  // namespace l1_rotary_lock1
