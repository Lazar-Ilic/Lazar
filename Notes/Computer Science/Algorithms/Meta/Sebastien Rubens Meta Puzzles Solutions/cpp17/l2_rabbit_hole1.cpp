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

#include <memory>
#include <vector>

namespace l2_rabbit_hole1 {

// C++ implementation note:
//   shared_ptr NodeInfoPtr_t is only used to keep the code close to the Python implementation.
//   in C++, we would probably use directly a (raw) pointer instead (once the grid is built,
//   there is not resize or anything raw preventing pointers to work)

struct Vertex;
using VertexPtr_t = std::shared_ptr<Vertex>;
using ListVertices_t = std::vector<VertexPtr_t>;

struct Vertex
{
    uint32_t nb;
    uint32_t inputs = 0;
    uint32_t level = 1;
    bool in_cycle = true;
    uint32_t cycle_len = 0;
    VertexPtr_t next = nullptr;
};

int32_t getMaxVisitableWebpagesCpp17(uint32_t N, const std::vector<int32_t>& L)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=316794079975021
    // Constraints:
    //      2 ≤ N ≤ 500,000
    //      1 ≤ Li ≤ N
    //      Li ≠ i
    //  Complexity: O(N)

    // Note: as a vertex is always followed by 1 vertex, we always end up in a cycle
    ListVertices_t vertices;
    vertices.reserve(N);
    for (uint32_t i = 0; i < N; ++i)
        vertices.emplace_back(std::make_shared<Vertex>(Vertex{ i + 1 }));

    // count the number of inputs for each vertex, and set next vertex: O(N)
    for (uint32_t i = 0; i < N; ++i)
    {
        auto& next_vertex = vertices[static_cast<uint32_t>(L[i] - 1)];
        next_vertex->inputs += 1;
        auto& vertex = vertices[i];
        vertex->next = next_vertex;  // yes, we could use indices or raw pointers (as "vertices" is never resized)
    }

    // find the entrance vertices (could be []): O(N)
    ListVertices_t entrance_vertices;
    entrance_vertices.reserve(vertices.size());
    for (const auto& vertex : vertices)
        if (vertex->inputs == 0)
            entrance_vertices.emplace_back(vertex);

    // calculate "level" of each vertex that is not in a cycle: O(N)
    while (!entrance_vertices.empty())
    {
        auto curr_vertex = entrance_vertices.back();
        curr_vertex->in_cycle = false;
        entrance_vertices.pop_back();
        auto next_vertex = curr_vertex->next;
        next_vertex->level = std::max(next_vertex->level, curr_vertex->level + 1);
        --next_vertex->inputs;
        if (next_vertex->inputs == 0)
            entrance_vertices.emplace_back(next_vertex);
    }

    // calculate length of cycles of the different cycle: O(N)
    for (const auto& vertex : vertices)
    {
        if (!vertex->in_cycle || vertex->cycle_len > 0)
            continue;
        // count length of cycle
        uint32_t cycle_len = 1;
        auto curr = vertex->next;
        while (curr.get() != vertex.get())
        {
            ++cycle_len;
            curr = curr->next;
        }
        // assign length of cycle to vertices
        vertex->cycle_len = cycle_len;
        curr = vertex->next;
        while (curr.get() != vertex.get())
        {
            curr->cycle_len = cycle_len;
            curr = curr->next;
        }
    }

    // Now calculate the maximum length: O(N)
    uint32_t max_chain = 0;
    for (const auto& vertex : vertices)
    {
        if (vertex->in_cycle)
            max_chain = std::max(max_chain, vertex->cycle_len);
        else if (vertex->next->in_cycle)
            max_chain = std::max(max_chain, vertex->level + vertex->next->cycle_len);
    }
    return static_cast<int32_t>(max_chain);
}

using namespace std;

int getMaxVisitableWebpages(int N, vector<int> L) {
    return getMaxVisitableWebpagesCpp17(static_cast<uint32_t>(N), L);
}


struct Args
{
    std::vector<int> L;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMaxVisitableWebpages(static_cast<int>(p.L.size()), p.L);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { 4, 1, 2, 1 } }, 4 },
                { { { 4, 3, 5, 1, 2 } }, 3 },
                { { { 2, 4, 2, 2, 3 } }, 4 },
            }
        },
        { "extra1", {
                { { { 1 } }, 1 },
                { { { 1, 2 } }, 1 },
                { { { 2, 1 } }, 2 },
                { { { 3, 3, 4, 3 } }, 3 },
                { { { 4, 5, 6, 5, 6, 4 } }, 4 },
                { { { 6, 5, 4, 5, 6, 4 } }, 4 },
                { { { 3, 3, 4, 1 } }, 4 },
                { { { 2, 3, 2 } }, 3 },
                { { { 2, 4, 2, 2, 3 } }, 4 },
                { { { 6, 5, 4, 3, 2, 1 } }, 2 },
            }
        },
        { "extra2", {
                { { { 4, 1, 2, 1 } }, 4 },
                { { { 4, 3, 5, 1, 2 } }, 3 },
                { { { 4, 1, 2, 1 } }, 4 },
                { { { 2, 1, 4, 3 } }, 2 },
                { { { 2, 4, 2, 2, 4, 5 } }, 4 },
                { { { 4, 1, 2, 1 } }, 4 },
                { { { 4, 3, 5, 1, 2 } }, 3 },
                { { { 2, 4, 2, 2, 4 } }, 3 },
                { { { 2, 3, 4, 2, 2, 3, 6, 9, 8 } }, 5 },
            }
        },
        { "extra3", {
                { { { 2, 4, 2, 2, 3, 4, 8, 9, 10, 11, 12, 7 } }, 6 },
                { { { 2, 4, 2, 2, 4, 5, 8, 9, 10, 11, 12, 7 } }, 6 },
            }
        },
    };

    return run_all_tests("l2_rabbit_hole1", tests, wrapper);
}

}  // namespace l2_rabbit_hole1
