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
#include <array>
#include <vector>

namespace l3_slippery_strip {

struct Counts
{
    uint32_t star;
    uint32_t right;
    uint32_t down;
};

using row_t = std::vector<char>;
using char_counter_t = std::array<uint32_t, 256>;

static Counts get_counts(const row_t& row, char_counter_t& counts)
{
    counts['*'] = 0;
    counts['>'] = 0;
    counts['v'] = 0;
    for (auto c : row)
    {
        auto d = static_cast<size_t>(c);
        if (d >= std::size(counts))
            d = '.';  // empty value (we do not use it)
        ++counts[d];
    }
    return { counts['*'], counts['>'], counts['v'] };
}

static uint32_t get_nb_coins_right_then_down3(const row_t& row, uint32_t count_down, uint32_t count_right)
{
    // complexity : O(C)
    if (count_down == 0)
        return 0;
    const auto k = std::find(std::cbegin(row), std::cend(row), 'v');
    const auto j = k != std::cend(row) ? k + 1 : std::cbegin(row);
    row_t new_row;
    new_row.insert(std::end(new_row), j, std::cend(row));
    new_row.insert(std::end(new_row), std::cbegin(row), j);
    uint32_t nb_coins_right_then_down = 0;
    auto last = std::cbegin(new_row);
    while (count_right * count_down != 0)
    {
        const auto first = std::find(last, std::cend(new_row), '>');
        last = std::find(first, std::cend(new_row), 'v');
        nb_coins_right_then_down = std::max(nb_coins_right_then_down, static_cast<uint32_t>(std::count(first, last, '*')));
        --count_down;
        count_right -= static_cast<int32_t>(std::count(first, last, '>'));
    }
    return nb_coins_right_then_down;
}

int32_t getMaxCollectableCoinsCpp17(uint32_t R, uint32_t C, const std::vector<std::vector<char>>& G)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=2881982598796847
    // Constraints
    //      2 ≤ R, C ≤ 400, 000
    //      R∗C ≤ 800, 000
    //      Gi, j ∈{ ".", "*", ">", "v" }
    //      Complexity: O(N), where N = R * C

    (void)R;

    char_counter_t counts;
    std::fill(std::begin(counts), std::end(counts), 0);
    uint32_t res = 0;
    for (size_t i = 0, e = G.size(); i < e; ++i)
    {
        const auto& row = G[G.size() - i - 1];
        const auto count = get_counts(row, counts);
        const auto nb_coins_immediately_down = std::min(count.star, 1u);
        if (count.right == C)
            res = 0;
        else if (count.right == 0)
            res += nb_coins_immediately_down;
        else
        {
            const auto nb_coins_right_then_down = get_nb_coins_right_then_down3(row, count.down, count.right);
            const auto nb_coins_right_forever = count.down == 0 ? count.star : 0;
            res = std::max(nb_coins_immediately_down + res, std::max(nb_coins_right_then_down + res, nb_coins_right_forever));
        }
    }
    return static_cast<int32_t>(res);  // result should always be positive
}

using namespace std;

int getMaxCollectableCoins(int R, int C, vector<vector<char>> G) {
    return getMaxCollectableCoinsCpp17(static_cast<uint32_t>(R), static_cast<uint32_t>(C), G);
}


struct Args
{
    std::vector<std::string> G;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        std::vector<std::vector<char>> H;
        H.reserve(p.G.size());
        for (const auto& row : p.G)
        {
            auto& last = H.emplace_back();
            last.insert(last.end(), std::cbegin(row), std::cend(row));
        }
        return getMaxCollectableCoins(static_cast<int>(H.size()), H.empty() ? 0 : static_cast<int>(H[0].size()), H);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { ".***", "**v>", ".*.." } }, 4 },
                { { { ">**", "*>*", "**>" } }, 4 },
                { { { ">>", "**" } }, 0 },
                { { { ">*v*>*", "*v*v>*", ".*>..*", ".*..*v" } }, 6 },
            }
        },
        {"extra1", {
                { { { } }, 0 },
                { { { "." } }, 0 },
                { { { "v" } }, 0 },
                { { { ">" } }, 0 },
                { { { "*" } }, 1 },
            }
        },
        { "extra2", {
                { { { ".", ".", ">", "*" } }, 0 },
                { { { ".", "*", ">", "*" } }, 1 },
                { { { ".", "*", ">", "." } }, 1 },
                { { { "*", ".", ">", "." } }, 1 },
                { { { "***", "...", ">vv", "..." } }, 1 },
            }
        },
        { "extra3", {
                { { { "*....", ".*...", "..*..", "...*." } }, 4 },
                { { { "....", "....", "....", "...." } }, 0 },
                { { { "***>", "...." } }, 3 },
                { { { "...." } }, 0 },
                { { { "vvvv" } }, 0 },
                { { { "vvvv", "....", ">>>>" } }, 0 },
            }
        },
        { "extra4", {
                { { { "******", "......", ">*>vvv", "......" } }, 2 },
                { { { "*****", ".....", ">>vvv", "....." } }, 1 },
            }
        },
    };

    return run_all_tests("l3_slippery_strip", tests, wrapper);
}

}  // namespace l3_slippery_strip
