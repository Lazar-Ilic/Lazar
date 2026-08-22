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
#include <set>
#include <string>
#include <tuple>
#include <vector>

#if defined(HAS_SET_LOG_DISTANCE) && __has_include("ext/pb_ds/assoc_container.hpp") && __has_include("ext/pb_ds/tree_policy.hpp")

#include <ext/type_traits.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace l4_mathematical_art {

using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
int64_t distance(const T& container, typename T::value_type y0, typename T::value_type y1)
{
    // non std functions could be used to be more generic and stable complexity-wise (where the below could be logarithmic)
    // order_of_key() would be used
    // https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures_design.html#container.tree.interface)
    // https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree_order_statistics_node_update.html
    return container.order_of_key(y1) - container.order_of_key(y0 + 1);  // heights.lower_bound(y1) - heights.upper_bound(y0)
}

}  // namespace l4_mathematical_art

#else

namespace l4_mathematical_art {

template<typename T> using ordered_set = std::set<T>;

template<typename T>
int64_t distance(const T& container, typename T::value_type y0, typename T::value_type y1)
{
    // This is only using std (std::distance is linear on std::set, so it needs some special treatment)
    if (container.empty())
        return 0;
    const auto it_beg = std::cbegin(container);
    const auto it_last = --std::cend(container);
    const auto lo = *it_beg;
    const auto hi = *it_last;
    if (y1 < lo || y0 > hi)
        return 0;
    const auto it_end = std::cend(container);
    const auto it_i = y0 < lo ? it_beg : container.upper_bound(y0);
    const auto it_j = y1 > hi ? it_end : container.lower_bound(y1);
    const auto size = static_cast<int64_t>(container.size());
    if (it_i == it_beg && it_j == it_end)
        return size;
    // the following are std optimisation (keeping in mind std::distance is linear),
    if (it_i == it_beg)
        return std::distance(it_beg, it_j);
    else if (it_j == it_end)
        return size - std::distance(it_beg, it_i);
    else
        return std::distance(it_i, it_j);
}

}  // namespace l4_mathematical_art

#endif

namespace l4_mathematical_art {

using Stroke = std::tuple<int64_t, int64_t, int64_t>;
using StrokeEnd = std::tuple<int64_t, int64_t>;

static std::tuple<std::vector<Stroke>, std::vector<Stroke>> read_strokes(uint32_t N, const std::vector<int32_t>& L, const std::string& D)
{
    // Complexity: O(N)
    std::vector<Stroke> hor_strokes;
    std::vector<Stroke> ver_strokes;
    hor_strokes.reserve(2 * N);
    ver_strokes.reserve(2 * N);
    int64_t x0 = 0, y0 = 0;
    int64_t x1 = 0, y1 = 0;
    for (uint64_t i = 0; i < N; ++i)
    {
        const auto length = L[i];
        const auto direction = D[i];
        if (direction == 'R')
        {
            x1 = x0 + length;
            y1 = y0;
            hor_strokes.emplace_back(Stroke{ y0, x0, -1 });
            hor_strokes.emplace_back(Stroke{ y0, x1, +1 });
        }
        else if (direction == 'L')
        {
            x1 = x0 - length;
            y1 = y0;
            hor_strokes.emplace_back(Stroke{ y0, x1, -1 });
            hor_strokes.emplace_back(Stroke{ y0, x0, +1 });
        }
        else if (direction == 'U')
        {
            x1 = x0;
            y1 = y0 + length;
            ver_strokes.emplace_back(Stroke{ x0, y0, -1 });
            ver_strokes.emplace_back(Stroke{ x0, y1, +1 });
        }
        else if (direction == 'D')
        {
            x1 = x0;
            y1 = y0 - length;
            ver_strokes.emplace_back(Stroke{ x0, y1, -1 });
            ver_strokes.emplace_back(Stroke{ x0, y0, +1 });
        }
        x0 = x1;
        y0 = y1;
    }
    return { hor_strokes, ver_strokes };
}

static void merge_strokes(std::vector<Stroke>& strokes)
{
    // Complexity: O(N)
    if (strokes.empty())
        return;
    const auto strokes_end = std::cend(strokes);
    auto strokes_it = std::cbegin(strokes);
    auto strokes_out = std::begin(strokes);
    auto [x0, y0, total] = *strokes_it++;
    for (; strokes_it != strokes_end; ++strokes_it)
    {
        const auto [x1, y1, inc] = *strokes_it;
        if (x0 != x1)
        {
            x0 = x1;
            y0 = y1;
            total = inc;
            continue;
        }
        if (total == 0)
            y0 = y1;
        total += inc;
        if (total == 0)
            *strokes_out++ = { x0, y0, y1 };
    }
    const auto size = std::distance(std::begin(strokes), strokes_out);
    strokes.resize(static_cast<uint32_t>(size));
}

static int64_t count_crosses(std::vector<Stroke>& ver_strokes, std::vector<Stroke>& hor_strokes)
{
    // Complexity: O(N*log(N))

    // trivial optimisation
    if (ver_strokes.size() * hor_strokes.size() == 0)
        return 0;

    // ver_strokes is chosen to be the smallest container
    // the reason is we will iterate over ver_strokes, while we will use log - time operation on hor_strokes
    if (ver_strokes.size() > hor_strokes.size())
        ver_strokes.swap(hor_strokes);

    // we need to create a list of height to insert(we cannot have consecutive x's for a given height)
    // O(n * log(N))
    std::vector<StrokeEnd> hor_strokes_in, hor_strokes_out;
    hor_strokes_in.reserve(hor_strokes.size());
    hor_strokes_out.reserve(hor_strokes.size());
    for (const auto& [h, x0, x1] : hor_strokes)
    {
        hor_strokes_in.emplace_back(StrokeEnd{ x0, h });
        hor_strokes_out.emplace_back(StrokeEnd{ x1, h });
    }
    std::sort(std::begin(hor_strokes_in), std::end(hor_strokes_in));
    std::sort(std::begin(hor_strokes_out), std::end(hor_strokes_out));

    // count crosses
    int64_t nb = 0;
    ordered_set<int64_t> heights;
    auto it_in = std::cbegin(hor_strokes_in);
    const auto it_in_end = std::cend(hor_strokes_in);
    auto it_out = std::cbegin(hor_strokes_out);
    const auto it_out_end = std::cend(hor_strokes_out);
    for (const auto& [hpos, y0, y1] : ver_strokes)
    {
        // add input height
        while (it_in != it_in_end)
        {
            const auto& [x, vpos] = *it_in;
            if (hpos <= x)
                break;
            heights.insert(vpos);
            ++it_in;
        }
        // remove output heights
        while (it_out != it_out_end)
        {
            const auto& [x, vpos] = *it_out;
            if (hpos < x)
                break;
            heights.erase(vpos);
            ++it_out;
        }
        nb += distance(heights, y0, y1);
    }
    return nb;
}

int64_t getPlusSignCountCpp17(uint32_t N, const std::vector<int32_t>& L, const std::string& D)
{
    // https://www.metacareers.com/portal/coding_puzzles/?puzzle=587690079288608
    // Constraints:
    //   2 ≤ N ≤ 2,000
    //   1 ≤ Li ≤ 1,000,000,000
    //   Di ∈ {U, D, L, R}
    // Complexity: O(N*log(N))

    // O(N)
    auto [hor_strokes, ver_strokes] = read_strokes(N, L, D);
    if (hor_strokes.empty() || ver_strokes.empty())
        return 0;

    // O(N * log(N))
    std::sort(std::begin(hor_strokes), std::end(hor_strokes));
    std::sort(std::begin(ver_strokes), std::end(ver_strokes));

    // O(N)
    merge_strokes(hor_strokes);
    merge_strokes(ver_strokes);

    // O(N * log(N))
    const auto nb = count_crosses(ver_strokes, hor_strokes);
    return nb;
}

using namespace std;

long long getPlusSignCount(int N, vector<int> L, string D) {
    return getPlusSignCountCpp17(static_cast<uint32_t>(N), L, D);
}


struct Args
{
    std::vector<int> L;
    std::string D;
};

auto build_grid(uint32_t N, int32_t inc = 1)
{
    std::vector<int32_t> l;
    std::string d;
    const auto n = (N + 7) / 8;
    auto w = n * 2 + 1;
    if (inc == -1)
        //w = w + 2 * n + 1;
        w += n + 1;
    for (auto i = 0u; i < n; ++i)
    {
        d += "RULU";
        l.emplace_back(w);
        l.emplace_back(1);
        w += inc;
        l.emplace_back(w);
        l.emplace_back(1);
        w += inc;
    }
    for (auto i = 0u; i < n; ++i)
    {
        d += "RDRU";
        l.emplace_back(1);
        l.emplace_back(w);
        w += inc;
        l.emplace_back(1);
        l.emplace_back(w);
        w += inc;
    }
    if (inc == 1)
        l[n * 4] = static_cast<int32_t>(n + 1);
    const auto expected = 4 * n * n;
    return std::make_tuple(l, d, expected);
}

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getPlusSignCount(static_cast<int>(p.L.size()), p.L, p.D);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { { 6, 3, 4, 5, 1, 6, 3, 3, 4 }, "ULDRULURD" }, 4 },
                { { { 1, 1, 1, 1, 1, 1, 1, 1 }, "RDLUULDR" }, 1 },
                { { { 1, 2, 2, 1, 1, 2, 2, 1 }, "UDUDLRLR" }, 1 },
            }
        },
        { "extra1", {
                { { { 1, 1, 1, 1, 1, 1 }, "RDURLU" }, 1 },
            }
        },
    };

    //auto [L, D, e] = build_grid(2'000'000);
    //auto [L, D, e] = build_grid(100'000, -1);
    //auto n = getPlusSignCount((int)D.size(), L, D);

    return run_all_tests("l4_mathematical_art", tests, wrapper);
}

}  // namespace l4_mathematical_art
