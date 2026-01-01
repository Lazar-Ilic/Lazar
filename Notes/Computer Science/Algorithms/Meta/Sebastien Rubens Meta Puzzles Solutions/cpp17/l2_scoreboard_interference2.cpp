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
#include <vector>

namespace l2_scoreboard_interference2 {

int32_t getMinProblemCountCpp17(uint32_t N, const std::vector<int32_t>& S)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=503122501113518
    // Constraints:
    //      1 ≤ N ≤ 500,000
    //      1 ≤ i ≤ 1,000,000,000
    // Complexity: O(N)

    (void)N;

    int32_t max_score = 0;
    int32_t second_max_score = 0;
    int32_t two_remainder = 0;
    int32_t one_remainder = 0;
    bool need_one = false;

    for (const auto score : S)
    {
        const auto score_mod_3 = score % 3;
        two_remainder |= (score_mod_3 >> 1);
        one_remainder |= (score_mod_3 & 1);
        need_one = need_one || (score == 1);
        if (max_score < score)
        {
            second_max_score = max_score;
            max_score = score;
        }
        else if (second_max_score < score)
            second_max_score = score;
    }

    // number of solutions, without any optimisation
    auto count = max_score / 3 + two_remainder + one_remainder;

    // not optimisation is possible if "two_remainder and one_remainder" is not true
    if (two_remainder * one_remainder != 1)
        return count;

    // replace "last +3" by "+1+2"
    if (max_score % 3 == 0)
        count -= 1;

    // replace last "+3+1" by "+2+2"
    if (need_one)  // exit early because 1 is required but at least one sum(i.e.it cannot be replaced)
        return count;
    if (max_score % 3 != 1)  // max_score does not have a 1 (so it cannot be replaced)
        return count;
    const auto tmp = max_score - second_max_score;
    if (!(tmp == 1 || tmp == 3)) // [ok, not ok(3), ok] || [not ok(1) | here | unimportant]
        count -= 1;
    return count;
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
                { { { 1, 2, 3, 4, 5 } }, 3 },
                { { { 4, 3, 3, 4 } }, 2 },
                { { { 2, 4, 6, 8 } }, 4 },
                { { { 8 } }, 3 },
            }
        },
        { "extra1", {
                { { { 4, 3, 3, 4 } }, 2 },
                { { { 2, 4, 6, 8 } }, 4 },
                { { { 8 } }, 3 },
                { { { 1, 2, 3 } }, 2 },
                { { { 5, 7 } }, 3 },
                { { { 5, 9, 10 } }, 5 },
                { { { 5, 9, 11 } }, 4 },
                { { { 2, 4, 6 } }, 3 },
                { { { 2, 4, 7 } }, 4 },
            }
        },
        { "extra2", {
                { { { 1, 2, 4 } }, 3 },
                { { { 2, 4 } }, 2 },
                { { { 4, 5 } }, 3 },
                { { { 9, 12 } }, 4 },
                { { { 11, 13 } }, 5 },
            }
        },
    };

    return run_all_tests("l2_scoreboard_interference2", tests, wrapper);
}

}  // namespace l2_scoreboard_interference2
