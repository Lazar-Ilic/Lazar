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
#include <cstdint>  // int**_t
#include <string>
#include <set>
#include <vector>

namespace l4_conveyor_chaos {

struct Params
{
    double x_min = 0, x_max = 1'000'000;  // inclusive
    int32_t h_min = 0, h_max = 1'000'000;  // non inclusive
};

struct Interval;
using IntervalPtr_t = std::shared_ptr<Interval>;  // Would probably not use std::shared_ptr in C++, but it keeps the code close to Python

struct Drop
{
    double drop_point = 0.;
    IntervalPtr_t interval;
};

struct Interval
{
    uint32_t n = 0;
    int32_t h = 0;
    double xmin = 0;
    double xmax = 0;
    std::array<Drop, 2> children = {};
    double weight = 0.;
    std::array<double, 2> costs = {};

    double width() const
    {
        return xmax - xmin;
    }

    double middle() const
    {
        return (xmax + xmin) * 0.5;
    }

    bool operator<(const Interval& rhs) const
    {
        return h < rhs.h;
    }
};

using ListIntervals_t = std::vector<IntervalPtr_t>;

struct Point
{
    double        x;
    IntervalPtr_t i;
    int32_t       op;

    bool operator<(const Point& rhs) const
    {
        return std::tie(x, i->h) < std::tie(rhs.x, rhs.i->h);
    }
};

struct Edge
{
    IntervalPtr_t parent;
    IntervalPtr_t child;
    uint32_t side;
    double weight;
};

struct Result
{
    double base_cost;
    double min_delta;
    uint32_t side;
    IntervalPtr_t interval;
};

static ListIntervals_t build_intervals(uint32_t N, const std::vector<int32_t>& H, const std::vector<int32_t>& A, const std::vector<int32_t>& B, const Params& params)  // O(N* log(N))
{
    const auto G = N + 1;

    const double mid = (params.h_max + params.h_min) * 0.5;
    ListIntervals_t intervals;
    intervals.reserve(static_cast<uint32_t>(N) + 2);

    // ground
    auto ground = intervals.emplace_back(std::make_shared<Interval>(Interval{ 0, params.h_min, params.x_min, params.x_max }));

    // user intervals: O(N)
    for (uint32_t i = 0; i < N; ++i)
        intervals.emplace_back(std::make_shared<Interval>(Interval{ i + 1, H[i], static_cast<double>(A[i]), static_cast<double>(B[i]), {{ {mid, ground}, {mid, ground} }} }));

    // sky
    intervals.emplace_back(std::make_shared<Interval>(Interval{ G, params.h_max, params.x_min, params.x_max, {{ {mid, ground} }} }));

    // O(N*log(N))
    std::sort(std::begin(intervals), std::end(intervals), [](const auto& a, const auto& b) { return *a < *b; });

    return intervals;
}

static void add_entries(uint32_t N, ListIntervals_t& intervals)
{
    const auto sky_h = intervals.back()->h;
    const auto mid = (intervals.front()->xmax + intervals.back()->xmin) * 0.5;

    // O(N)
    const auto interval_size = intervals.size();
    std::vector<Point> points;
    points.reserve(2 * interval_size - 4);
    for (uint32_t i = 1; i < interval_size - 1; ++i)
    {
        const auto& interval = intervals[i];
        points.emplace_back(Point{ interval->xmin, interval, +1 });
        points.emplace_back(Point{ interval->xmax, interval, -1 });
    }

    // O(N*log(N))
    std::sort(std::begin(points), std::end(points));

    // build entry intervals (we do not save intervals dropping immediately to the ground)
    intervals.pop_back();
    intervals.reserve(intervals.size() + points.size());

    //
    const auto ground = intervals.front();
    if (points[0].x > ground->xmin)
        intervals.emplace_back(std::make_shared<Interval>(Interval{ 0, sky_h, ground->xmin, -1, {{ {mid, ground} }} }));

    struct IntervalCmp
    {
        bool operator() (const IntervalPtr_t& lhs, const IntervalPtr_t& rhs) const
        {
            return *lhs < *rhs;
        }
    };

    std::set<IntervalPtr_t, IntervalCmp> stack;
    stack.insert(ground);

    auto first = std::cbegin(points);
    const auto end = std::cend(points);
    IntervalPtr_t last_p;

    while (first != end)
    {
        // find the set next set of rows for the current x
        auto x = first->x;
        auto last = first + 1;
        while (last != end)
        {
            if (x != last->x)
                break;
            ++last;
        }
        //
        const auto& p = *(--std::cend(stack));
        if (last_p != p)
        {
            last_p = p;
            intervals.emplace_back(std::make_shared<Interval>());  // will reallocate platform
        }
        // First pass, we remove intervals, and deal with add/remove on left/right
        for (auto curr = first; curr != last; ++curr)
        {
            const auto& [_x, i, op] = *curr;
            const auto prev = --stack.lower_bound(i);  // Note: multiple platform can be at the same height, we are looking for the "rightmost" interval whose height lower that i
            if (op == -1)
            {
                i->children[1] = { i->xmax, *prev };
                stack.erase(i);
            }
            else if (op == +1)
                i->children[0] = { i->xmin, *prev };
        }
        // Second pass, we add intervals
        for (auto curr = first; curr != last; ++curr)
        {
            const auto& [_x, i, op] = *curr;
            if (op == +1)
                stack.emplace(i);

        }
        //
        const auto& last_n = *(--std::cend(stack));
        *intervals.back() = Interval{ 0, sky_h, x, -1,  {{ {0, last_n} }} };  // we do not know xmax at that stage
        //
        first = last;
    }
    //
    if (intervals.back()->xmin == ground->xmax)
        intervals.pop_back();
    // stitching xmin and xmax
    for (uint32_t i = N + 1, n = static_cast<uint32_t>(intervals.size() - 1); i < n; ++i)
        intervals[i]->xmax = intervals[i + 1]->xmin;
    intervals.back()->xmax = ground->xmax;
    // fix children by adding drop_point
    for (uint32_t i = N + 1, n = static_cast<uint32_t>(intervals.size()); i < n; ++i)
    {
        auto& interval = intervals[i];
        interval->n = i - 1;
        interval->children[0].drop_point = interval->middle();
    }
}

static void populate_costs(uint32_t N, ListIntervals_t& intervals)
{
    // set up weight for entry interval from the sky: O(N)
    for (auto p = std::cbegin(intervals) + (N + 1), end = std::cend(intervals); p != end; ++p)
        (*p)->weight = (*p)->children[0].interval->n > 0 ? (*p)->width() : 0.;

    // Accumulate costs from top to bottom: O(E) where E is 2*N at most
    std::vector<Edge> edges;
    edges.reserve(2 * N);
    for (auto curr = std::crbegin(intervals), end = std::crend(intervals); curr != end; ++curr)
    {
        const auto& parent = *curr;
        const auto weight = 0.5 * parent->weight;
        if (weight == 0)
            continue;
        for (uint32_t side = 0; side < 2; ++side)
        {
            const auto& [drop_point, child] = parent->children[side];
            if (child && child->n > 0)
            {
                const auto cost_l = weight * (drop_point - child->xmin);
                const auto cost_r = weight * (child->xmax - drop_point);
                child->weight += weight;
                child->costs[0] += cost_l;
                child->costs[1] += cost_r;
                edges.emplace_back(Edge{ parent, child, side, weight });
            }
        }
    }
    
    // Accumulate costs from bottom to top: O(E) where E is 2*N at most
    for (auto curr = edges.crbegin(), end = edges.crend(); curr != end; ++curr)
    {
        auto& parent = *curr->parent;
        const auto& child = *curr->child;
        parent.costs[curr->side] += (child.costs[0] + child.costs[1]) * curr->weight / child.weight;
    }
}

static Result calc_dist(uint32_t N, const ListIntervals_t& intervals)
{
    // base_cost
    Result res{ 0, 0, 0, {} };
    for (uint32_t i = N + 1, e = static_cast<uint32_t>(intervals.size()); i < e; ++i)
        res.base_cost += intervals[i]->costs[0];

    // calculate min_delta, min_dir, min_p: O(N)
    for (uint32_t i = 0, size = N + 1; i < size; ++i)
    {
        const auto& interval = intervals[i];
        auto delta = interval->costs[0] - interval->costs[1];
        if (res.min_delta > delta)
        {
            res.min_delta = delta;
            res.side = 0;
            res.interval = interval;
            continue;
        }
        delta *= -1;
        if (res.min_delta > delta)
        {
            res.min_delta = delta;
            res.side = 1;
            res.interval = interval;
        }
    }
    return res;
}

double getMinExpectedHorizontalTravelDistanceCpp17(uint32_t N, const std::vector<int32_t>& H, const std::vector<int32_t>& A, const std::vector<int32_t>& B)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=280063030479374
    // Constraints :
    //    1 ≤ N ≤ 500, 000
    //    1 ≤ Hi ≤ 999, 999
    //    1 ≤ Ai < Bi ≤ 1, 000, 000
    // Complexity: O(N * log(N))

    const Params params;
    auto intervals = build_intervals(N, H, A, B, params);  // O(N)
    add_entries(N, intervals);  // O(N * log(N))
    populate_costs(N, intervals);  // O(N)
    const auto res = calc_dist(N, intervals);  // O(N)
    const auto smallest_cost = (res.base_cost + res.min_delta) / (params.x_max - params.x_min);
    return smallest_cost;
}

using namespace std;

double getMinExpectedHorizontalTravelDistance(int N, vector<int32_t> H, vector<int32_t> A, vector<int32_t> B) {
    return getMinExpectedHorizontalTravelDistanceCpp17(static_cast<uint32_t>(N), H, A, B);
}


struct Args
{
    std::vector<int> H;
    std::vector<int> A;
    std::vector<int> B;
};

NamedTests<Args, double> make_cases(const std::string& name, uint32_t N)
{
    const Params params;
    const auto _N = static_cast<int32_t>(N);
    NamedTests<Args, double> res;
    res.name = name;
    auto& test = res.tests.emplace_back();
    auto& args = test.first;
    args.H.reserve(N);
    args.A.reserve(N);
    args.B.reserve(N);
    for (int i = 1; i <= _N; ++i)
    {
        args.H.push_back(_N + 1 - i);
        args.A.push_back(_N + 1 - i);
        args.B.push_back(_N + i);
    }
    uint64_t base_cost = 0;
    uint64_t width = 2 * static_cast<uint64_t>(_N) - 1;
    uint64_t added_width = 0;
    for (int i = 0; i < _N; ++i)
    {
        added_width += width;
        base_cost += added_width;
        width -= 2;
    }
    base_cost -= added_width / 2;
    test.second = static_cast<double>(base_cost) / (params.x_max - params.x_min);
    return res;
}

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMinExpectedHorizontalTravelDistance(static_cast<int>(p.A.size()), p.H, p.A, p.B);
    };

    std::vector<NamedTests<Args, double>> tests = {
        {"Meta", {
                { { { 10, 20 }, { 100'000, 400'000 }, { 600'000, 800'000 } }, 155'000.0 },
                { { { 2, 8, 5, 9, 4 }, { 5'000, 2'000, 7'000, 9'000, 0 }, { 7'000, 8'000, 11'000, 11'000, 4'000 } }, 36.5 },
            }
        },
        {"extra1", {
                { { { 2, 4, 5, 8, 9 }, { 5'000, 0, 7'000, 2'000, 9'000 }, { 7'000, 4'000, 11'000, 8'000, 11'000 } }, 36.5 },
                //
                { { { 10 }, { 0 }, { 1'000'000 } }, 500'000.0 },
                { { { 10 }, { 0 }, { 500'000 } }, 125'000.0 },
                { { { 9 }, { 500'000 }, { 1'000'000 } }, 125'000.0 },
                { { { 10, 9 }, { 0, 500'000 }, { 500'000, 1'000'000 } }, 250'000.0 },
                //
                { { { 20, 10 }, { 200'000, 400'000 }, { 600'000, 800'000 } }, 120'000.0 },
                { { { 20, 10 }, { 400'000, 200'000 }, { 800'000, 600'000 } }, 120'000.0 },
                { { { 20, 20, 10 }, { 100'000, 500'000, 200'000 }, { 300'000, 700'000, 600'000 } }, 100'000.0 },
                //
                { { { 1 }, { 0 }, { 1'000'000 } }, 500'000.0 },
                { { { 1 }, { 250'000 }, { 750'000 } }, 125'000.0 },
                { { { 1, 3, 3, 5 }, { 400'000, 200'000,  600'000, 400'000 }, { 700'000, 500'000, 1'000'000, 700'000 } }, 213'750.0 },
                { { { 1, 3, 3, 5, 7 }, { 400'000, 200'000,  600'000, 400'000, 400'000 }, { 700'000, 500'000, 1000'000, 700'000, 600'000 } }, 215'000.0 },
            }
        },
    };
    //tests.emplace_back(make_cases("generated", 2));
    //tests.emplace_back(make_cases("generated", 100'000));  // Precision is ok for this value
    //tests.emplace_back(make_cases("generated", 2'000'000));  // Do not forget to run this in release, and the precision goes wrong

    return run_all_tests("l4_conveyor_chaos", tests, wrapper, 0.000'001);
}

}  // namespace l4_conveyor_chaos
