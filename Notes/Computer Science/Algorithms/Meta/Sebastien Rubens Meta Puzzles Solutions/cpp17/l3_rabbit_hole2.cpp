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
#include <limits>
#include <list>
#include <memory>
#include <utility>
#include <vector>

namespace l3_rabbit_hole2 {

struct Vertex;
using VertexPtr_t = std::shared_ptr<Vertex>;  // Would probably not use std::shared_ptr in C++, but it keeps the code close to Python
using ListVertices_t = std::vector<VertexPtr_t>;

using index_t = uint32_t;
static constexpr index_t index_not_set = std::numeric_limits<index_t>::max();

struct Vertex
{
    index_t nb = 0;
    index_t weight = 0;  // 0 means unused
    ListVertices_t children = {};

    // members for strongly connected components
    index_t index = index_not_set;
    index_t low_link = index_not_set;
    bool on_stack = false;

    // members for dag construction
    VertexPtr_t target = {};

    // members for max length calculation
    index_t inputs = 0;  // number of inputs for a given node
    index_t max_len = 0;  // used for memoization of max_len at node level

    inline bool operator<(const Vertex& rhs) const
    {
        return nb < rhs.nb;
    }
};

struct Edge
{
    index_t v;
    index_t w;
    inline bool operator<(const Edge& rhs) const
    {
        return std::tie(v, w) < std::tie(rhs.v, rhs.w);
    }
    inline bool operator==(const Edge& rhs) const
    {
        return std::tie(v, w) == std::tie(rhs.v, rhs.w);
    }
};

template<typename T>
static inline bool operator<(const std::shared_ptr<T>& rhs, const std::shared_ptr<T>& lhs)
{
    return *rhs < *lhs;
}

template<typename T>
static void keep_unique(std::vector<T>& elements)
{
    if (elements.size() <= 1)
        return;
    std::sort(std::begin(elements), std::end(elements));
    const auto last = std::unique(std::begin(elements), std::end(elements));
    elements.erase(last, std::end(elements));
}

static ListVertices_t build_children(std::vector<Edge>& edges)
{
    // recalculate N as nb_vertices
    const auto max_fn = [](const auto& e1, const auto& e2) { return std::max(e1.v, e1.w) < std::max(e2.v, e2.w); };
    const auto max_elt_it = std::max_element(std::cbegin(edges), std::cend(edges), max_fn);
    const auto nb_vertices = std::max(max_elt_it->v, max_elt_it->w);
    //
    ListVertices_t vertices;
    vertices.reserve(nb_vertices + 1);
    for (index_t i = 0; i <= nb_vertices; ++i)
        vertices.emplace_back(std::make_shared<Vertex>(Vertex{ i }));
    for (const auto& [v, w] : edges)
    {
        vertices[v]->children.emplace_back(vertices[w]);
        vertices[v]->weight = 1;
        vertices[w]->weight = 1;
    }
    return vertices;
}

struct Tarjan
{
    Tarjan(const Tarjan&) = delete;
    Tarjan(Tarjan&&) = delete;
    Tarjan& operator=(const Tarjan&) = delete;
    Tarjan& operator=(Tarjan&&) = delete;

    struct Frame1
    {
        VertexPtr_t v;
        index_t child_nb = 0;
        VertexPtr_t recurse_object = {};
    };

    std::list<ListVertices_t> sccs;
    ListVertices_t stack;
    index_t index = 0;

    Tarjan()
    {
    }

    void __init(VertexPtr_t& v)
    {
        v->index = index;
        v->low_link = index;
        v->on_stack = true;
        stack.emplace_back(v);
        ++index;
    }

    void __end(const VertexPtr_t& v)
    {
        ListVertices_t scc;
        if (v->low_link == v->index)
        {
            while (true)
            {
                auto w = stack.back();
                stack.pop_back();
                w->low_link = v->low_link;
                w->on_stack = false;
                scc.emplace_back(w);
                if (w.get() == v.get())
                    break;
            };
        }
        if (scc.size() > 1)
            sccs.emplace_back(scc);
    }

    void recurse(VertexPtr_t& v)
    {
        __init(v);  // set up Vertex in scc discovery
        // Go through all children of this Vertex
        for (auto& w : v->children)
        {
            if (w->index == index_not_set)
            {
                recurse(w);
                v->low_link = std::min(v->low_link, w->low_link);
            }
            else if (w->on_stack)
                v->low_link = std::min(v->low_link, w->index);

        }
        __end(v);  // found scc
    }

    void iterate(VertexPtr_t& v)
    {
        std::vector<Frame1> call_stack{ Frame1{ v } };
        while (!call_stack.empty())
        {
            auto& f = call_stack.back();
            v = f.v;
            // call __init only when we enter the node
            if (v->index == index_not_set)
                __init(v);
            // if we are at the end of the loop
            if (f.child_nb >= v->children.size())
            {
                __end(v);
                call_stack.pop_back();
                continue;
            }
            // we are in the loop
            auto w = v->children[f.child_nb];
            if (f.recurse_object.get() == w.get())
                v->low_link = std::min(v->low_link, w->low_link);
            else if (w->index == index_not_set)
            {
                f.recurse_object = w;
                call_stack.emplace_back(Frame1{ w });  // enter recursion
                continue;
            }
            else if (w->on_stack)
                v->low_link = std::min(v->low_link, w->index);
            ++f.child_nb;
        }
    }
};

static auto calculate_sccs(ListVertices_t& vertices, bool iterative = false)
{
    auto calc = Tarjan();
    for (auto& v : vertices)
        if (v->index == index_not_set)
        {
            if (iterative)
                calc.iterate(v);
            else
                calc.recurse(v);
        }
    return calc.sccs;
}

static void make_dag(ListVertices_t& vertices, const std::list<ListVertices_t>& sccs)
{
    // merge vertices in each scc
    for (const auto& scc : sccs)  // O(V)
    {
        const auto& v = scc[0];  // target node (first node in scc)
        v->weight = static_cast<index_t>(scc.size());  // update the weight of the Vertex
        ListVertices_t children;  // note: no reserve() here
        for (const auto& w : scc)
            for (const auto& x : w->children)
                if (v->low_link != x->low_link)
                    children.emplace_back(x);
        v->children = std::move(children);
        for (const auto& w : scc)
            if (w.get() != v.get())
            {
                w->target = v;  // used for children remapping
                w->weight = 0;  // indicates the Vertex is not used anymore
            }
    }
    // remap children to the target node (if applicable)
    for (const auto& v : vertices)
        if (!v->children.empty())
        {
            ListVertices_t children;
            children.reserve(v->children.size());
            for (const auto& w : v->children)
                children.emplace_back(w->target.get() ? w->target : w);
            // remove duplicates
            keep_unique(children);
            v->children = std::move(children);
        }
}

static index_t dag_max_len_recurse(VertexPtr_t& v)
{
    index_t max_len = 0;
    for (auto& w : v->children)
    {
        index_t curr_len = 0;
        if (w->max_len == 0 && v.get() != w.get())  // avoid self referencing
            curr_len = dag_max_len_recurse(w);
        else
            curr_len = w->max_len;
        max_len = std::max(max_len, curr_len);
    }
    v->max_len = v->weight + max_len;
    return v->max_len;
}

static index_t dag_max_len_iterate(VertexPtr_t v)
{
    struct Frame2
    {
        VertexPtr_t v;
        index_t child_nb = 0;
        uint32_t max_len = 0;
        uint32_t curr_len = 0;
        VertexPtr_t recurse_object = {};
    };

    std::vector<Frame2> call_stack{ Frame2{ v } };
    while (!call_stack.empty())
    {
        auto& f = call_stack.back();
        v = f.v;
        //
        if (f.child_nb >= v->children.size())
        {
            v->max_len = v->weight + f.max_len;
            call_stack.pop_back();
            if (call_stack.empty())
                return v->max_len;
            call_stack.back().curr_len = std::max(call_stack.back().curr_len, v->max_len);
            continue;
        }
        const auto w = v->children[f.child_nb];
        if (f.recurse_object.get() == w.get())
        {
        }
        else if (w->max_len == 0 && v.get() != w.get())  // avoid self referencing
        {
            f.recurse_object = w;
            call_stack.emplace_back(Frame2{ w });
            continue;
        }
        else
        {
            f.curr_len = w->max_len;
        }
        f.max_len = std::max(f.max_len, f.curr_len);
        ++f.child_nb;
    }
    return v->max_len;
}

static index_t dag_max_len(ListVertices_t& vertices, bool iterative = false)
{
    for (const auto& v : vertices)
        if (v->weight > 0)
            for (const auto& w : v->children)
                if (v.get() != w.get())  // avoid self referencing
                    ++w->inputs;
    index_t ret = 0;
    for (auto& v : vertices)
    {
        if (v->weight > 0 && v->inputs == 0)
        {
            if (iterative)
                ret = std::max(ret, dag_max_len_iterate(v));
            else
                ret = std::max(ret, dag_max_len_recurse(v));
        }
    }
    return ret;
}

int32_t getMaxVisitableWebpagesCpp17(uint32_t N, uint32_t M, const std::vector<int32_t>& A, const std::vector<int32_t> B)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=254501763097320
    // Constraints :
    //      2 ≤ N ≤ 500,000   N different web pages
    //      1 ≤ M ≤ 500,000   M links present across the pages
    //      1 ≤ Ai, Bi ≤ N    ith of which is present on page Aiand links to a different page Bi
    //      Ai ≠ Bi           a page cannot link to itself
    //      Complexity: O(V + E * log(E))  because of call to keep_unique()

    (void)N;
    constexpr bool iterative = false;

    // just in case
    if (A.empty() || B.empty())
        return 0;

    // calculate edges
    std::vector<Edge> edges;
    edges.reserve(M);
    for (size_t i = 0; i < M; ++i)  // O(E)
        edges.emplace_back(Edge{ static_cast<index_t>(A[i]), static_cast<index_t>(B[i]) });

    //
    keep_unique(edges);  // O(E * log(E))
    auto vertices = build_children(edges);  // O(V + 2*E)
    const auto sccs = calculate_sccs(vertices, iterative);  // O(V + E), calculate strongly connected components
    make_dag(vertices, sccs);  // O(V + E)
    const auto res = dag_max_len(vertices, iterative);  // O(V + E)
    return static_cast<int>(res);
}

using namespace std;

int getMaxVisitableWebpages(int N, int M, vector<int> A, vector<int> B) {
    return getMaxVisitableWebpagesCpp17(static_cast<uint32_t>(N), static_cast<uint32_t>(M), A, B);
}


struct Args
{
    std::vector<int> A;
    std::vector<int> B;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        const auto max_elt_a = std::max_element(std::cbegin(p.A), std::cend(p.A));
        const auto max_elt_b = std::max_element(std::cbegin(p.B), std::cend(p.B));
        const auto max_len = static_cast<int32_t>(std::max(*max_elt_a, *max_elt_b));
        return getMaxVisitableWebpages(max_len, static_cast<int>(p.A.size()), p.A, p.B);
    };

    std::vector<NamedTests<Args, int>> tests = {
        { "Meta", {
                { { { 1, 2, 3, 4 }, { 4, 1, 2, 1 } }, 4 },
                { { { 3, 5, 3, 1, 3, 2 }, { 2, 1, 2, 4, 5, 4 } }, 4 },
                { { { 3, 2, 5, 9, 10, 3, 3, 9, 4 }, { 9, 5, 7, 8, 6, 4, 5, 3, 9 } }, 5 },
            }
        },
        { "extra1", {
                { { { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14     }, { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  4,  4,  2     } }, 8 },
                { { { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 15, 15     }, { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  9     } }, 8 },
                { { { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 13, 13, 13 }, { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  5,  8 } }, 8 },
                { { { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 }, { 3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8 } }, 4 },
                { { { 1, 3, 2 }, { 3, 2, 3 } }, 3 },
                { { { 2, 1 }, { 1, 2 } }, 2 },
                { { { 3, 5, 3, 1, 3, 2 }, { 2, 2, 2, 4, 5, 4 } }, 4 },
                { { { 3, 5, 3, 1, 3, 2 }, { 2, 2, 5, 4, 5, 4 } }, 4 },  // 3 is referencing 5 twice
                { { { 3, 5, 3, 1, 3, 2 }, { 2, 2, 3, 4, 5, 4 } }, 4 },  // 3 is self referencing
            }
        },
    };

    return run_all_tests("l3_rabbit_hole2", tests, wrapper);
}

}  // namespace l3_rabbit_hole2
