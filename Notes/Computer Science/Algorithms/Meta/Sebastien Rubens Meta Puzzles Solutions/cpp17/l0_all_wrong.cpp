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
#include <string>
#include <vector>

namespace l0_all_wrong {

std::string getWrongAnswersCpp17(uint32_t N, const std::string& C)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=1082217288848574
    // Constraints
    //   1 ≤ N ≤ 100         N is the number of characters of string C
    //   Ci ∈ { "A", "B" }
    // Complexity: O(N)

    (void)N;

    std::string ret(C);
    //for (auto& c : ret)
    //    c = c == 'A' ? 'B' : 'A';
    std::transform(std::cbegin(ret), std::cend(ret), std::begin(ret),
        [](auto c) { return c == 'A' ? 'B' : 'A'; });
    return ret;
}

using namespace std;

std::string getWrongAnswers(int N, string C) {
    return getWrongAnswersCpp17(static_cast<uint32_t>(N), C);
}


struct Args
{
    std::string C;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getWrongAnswers(static_cast<int>(p.C.size()), p.C);
    };

    std::vector<NamedTests<Args, std::string>> tests = {
        { "Meta", {
                { { "ABA" }, "BAB" },
                { { "BBBBB" }, "AAAAA" },
            }
        },
    };

    return run_all_tests("l0_all_wrong", tests, wrapper);
}

}  // namespace l0_all_wrong
