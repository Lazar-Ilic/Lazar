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

#include <array>
#include <cstdint>  // int**_t
#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <vector>

namespace l2_portals {

// C++ implementation note:
//   shared_ptr NodeInfoPtr_t is only used to keep the code close to the Python implementation.
//   in C++, we would probably use directly a (raw) pointer instead (once the grid is built,
//   there is not resize or anything raw preventing pointers to work)

using dist_t = int32_t;

struct Coord
{
    uint32_t row = 0;
    uint32_t col = 0;
};

struct NodeInfo : Coord
{
    uint8_t node_type;
    dist_t distance = std::numeric_limits<dist_t>::max();
    bool is_inserted = false;
};

template<typename Priority, typename Item>
struct OurPriorityQueue
{
    // This is to have an "identical" implement to other languages who do not have std::multimap<dist_t, NodeInfoPtr_t>
    // Here, we are wrapping call to what could be the std::multimap<Priority, Item>

    bool empty() const
    {
        return m.empty();
    }

    void insert(const Priority& priority, Item& item)
    {
        m.insert({ { priority, ++nb }, item });
    }

    auto pop_front()
    {
        const auto node = m.extract(std::begin(m));
        return std::make_pair(node.key(), node.mapped());
    }

private:
    uint64_t nb = 0;  // this could wrap at some point (if it was running "near forever"), and makes it not really a multimap equivalent
    std::map<const std::pair<Priority, decltype(nb)>, Item> m;
};

using NodeInfoPtr_t = std::shared_ptr<NodeInfo>;
using VectorNodeInfo_t = std::vector<NodeInfoPtr_t>;
using GridNodeInfo_t = std::vector<VectorNodeInfo_t>;
using PriorityQueue_t = OurPriorityQueue<dist_t, NodeInfoPtr_t>;
using HeuristicFunc_t = std::function<dist_t(NodeInfoPtr_t)>;
using DistFunc_t = std::function<dist_t(NodeInfoPtr_t, NodeInfoPtr_t)>;

static void add_neighbour(PriorityQueue_t& q, HeuristicFunc_t& h, DistFunc_t& d,
    const NodeInfoPtr_t& node, NodeInfoPtr_t& neighbour)
{
    const auto neighbor_distance = d(node, neighbour);
    if (neighbor_distance >= neighbour->distance)
        return;
    neighbour->distance = neighbor_distance;
    if (!neighbour->is_inserted)
    {
        neighbour->is_inserted = true;
        q.insert(h(neighbour), neighbour);
    }
}

int getSecondsRequiredCpp17(uint32_t R, uint32_t C, const std::vector<std::vector<char>>& G)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=544961100246576
    // Constraints:
    //      1 ≤ R,C ≤ 50
    //      Gi,j ∈ {".", "S", "E", "#", "a"..."z"}
    // Complexity: see A* search algorithm (https://en.wikipedia.org/wiki/A*_search_algorithm)

    // set up grid and portal map
    GridNodeInfo_t grid;
    grid.reserve(R);
    for (uint32_t j = 0; j < R; ++j)
    {
        auto& row = grid.emplace_back();
        row.reserve(C);
        for (uint32_t i = 0; i < C; ++i)
            row.emplace_back(std::make_shared<NodeInfo>(NodeInfo{ { j, i }, static_cast<uint8_t>(G[j][i]) }));
    }

    Coord start{ 0, 0 };
    std::vector<Coord> ends;
    ends.reserve(R * C);
    std::array<VectorNodeInfo_t, 256> portals{};
    for (uint32_t j = 0; j < R; ++j)
    {
        const auto& row = G[j];
        for (uint32_t i = 0; i < C; ++i)
        {
            const auto& node_type = row[i];
            if (node_type == 'S')
                start = Coord{ j, i };
            else if (node_type == 'E')
                ends.emplace_back(Coord{ j, i });  // Ends could be used for a heuristic
            else if ('a' <= node_type && node_type <= 'z')
                portals[node_type & 255u].emplace_back(grid[j][i]);  // note: no reserve() here
        }
    }
    auto& start_node = grid[start.row][start.col];
    start_node->distance = 0;

    // set up the grid
    PriorityQueue_t q;  // contains (heuristic score, coordinates)
    HeuristicFunc_t h = [](const NodeInfoPtr_t& node) { return node->distance; };
    DistFunc_t d = [](const NodeInfoPtr_t& n1, const NodeInfoPtr_t&) { return n1->distance + 1; };  // distance is always one

    constexpr auto minus_1_row = static_cast<decltype(Coord::row)>(-1);
    constexpr auto minus_1_col = static_cast<decltype(Coord::col)>(-1);
    constexpr Coord neighbours_directions[] = { {minus_1_row, 0}, {1, 0}, {0, minus_1_col}, {0, 1}};

    q.insert(h(start_node), start_node);
    while (!q.empty())
    {
        const auto [_score, node] = q.pop_front();
        if (node->node_type == 'E')
            return node->distance;
        // add portal nodes to node
        if ('a' <= node->node_type && node->node_type <= 'z')
        {
            for (auto& neighbour : portals[node->node_type])
                if (neighbour.get() != node.get())
                    add_neighbour(q, h, d, node, neighbour);
        }
        // add neighbours to node
        for (const auto& [drow, dcol] : neighbours_directions)
        {
            const auto row = node->row + drow;
            const auto col = node->col + dcol;
            if ((row < R) && (col < C))
            {
                auto& neighbour = grid[row][col];
                if (neighbour->node_type != '#')
                    add_neighbour(q, h, d, node, neighbour);
            }
        }
    }
    return -1;
}

using namespace std;

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
    return getSecondsRequiredCpp17(static_cast<uint32_t>(R), static_cast<uint32_t>(C), G);
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
        return getSecondsRequired(static_cast<int>(H.size()), H.empty() ? 0 : static_cast<int>(H[0].size()), H);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { ".E.", ".#E", ".S#" } }, 4 },
                { { { "a.Sa", "####", "Eb.b" } }, -1 },
                { { { "aS.b", "####", "Eb.a" } }, 4 },
                { { { "xS..x..Ex" } }, 3 },
            }
        },
    };

    return run_all_tests("l2_portals", tests, wrapper);
}

}  // namespace l2_portals
