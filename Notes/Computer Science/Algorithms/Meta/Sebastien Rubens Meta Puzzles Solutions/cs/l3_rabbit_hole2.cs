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

using System;
using System.Collections.Generic;
using System.Linq;

namespace l3_rabbit_hole2
{

#nullable enable annotations

class Solution {

    class Vertex : IComparable<Vertex>
    {
        public int nb = 0;
        public int weight = 0;  // 0 means unused
        public List<Vertex> children;

        // members for strongly connected components
        public int index = -1;
        public int low_link = -1;
        public bool on_stack = false;

        // members for dag construction
        public Vertex? target = null!;

        // members for max length calculation
        public int inputs = 0;  // number of inputs for a given node
        public int max_len = 0;  // used for memoization of max_len at node level

        public Vertex(int _nb)
        {
            nb = _nb;
            children = new List<Vertex>();
        }

        public Vertex(Vertex other)
        {
            nb = other.nb;
            weight = other.weight;
            children = other.children;
            index = other.index;
            low_link = other.low_link;
            on_stack = other.on_stack;
            target = other.target;
            inputs = other.inputs;
            max_len = other.max_len;
        }

        public int CompareTo(Vertex? other)
        {
            if (nb < other!.nb)
                return -1;
            if (nb > other!.nb)
                return 1;
            return 0;
        }

    };

    struct Edge : IComparable<Edge>
    {
        public int v;
        public int w;

        public int MaxEdge()
        {
            return Math.Max(v, w);
        }

        public Edge(int _v, int _w)
        {
            v = _v;
            w = _w;
        }

        public int CompareTo(Edge other)
        {
            if (v < other.v)
                return -1;
            if (v > other.v)
                return 1;
            if (w < other.w)
                return -1;
            if (w > other.w)
                return 1;
            return 0;
        }

    }

    static List<T> keep_unique<T>(List<T> edges)
    {
        if (edges.Count <= 1)
            return edges;
        edges.Sort();
        edges = edges.Distinct().ToList();
        return edges;
    }

    static List<Vertex> build_children(List<Edge> edges)
    {
        // recalculate N as nb_vertices
        var nb_vertices = edges.Max(obj => Math.Max(obj.v, obj.w));
        //
        var vertices = new List<Vertex>(nb_vertices + 1);
        for (int i = 0; i <= nb_vertices; ++i)
            vertices.Add(new Vertex(i));
        foreach (var edge in edges)
        {
            vertices[edge.v].children.Add(vertices[edge.w]);
            vertices[edge.v].weight = 1;
            vertices[edge.w].weight = 1;
        }
        return vertices;
    }

    class Tarjan
    {
        class Frame1
        {
            public Vertex? v = null!;
            public int child_nb = 0;
            public Vertex? recurse_object = null!;

            public Frame1(Vertex _v)
            {
                v = _v;
                recurse_object = null!;
            }
        };

        public LinkedList<List<Vertex>> sccs;
        public List<Vertex> stack;
        public int index = 0;

        public Tarjan()
        {
            sccs = new LinkedList<List<Vertex>>();
            stack = new List<Vertex>();
            index = 0;
        }

        void __init(Vertex v)
        {
            v.index = index;
            v.low_link = index;
            v.on_stack = true;
            stack.Add(v);
            ++index;
        }

        void __end(Vertex v)
        {
            var scc = new List<Vertex>();
            if (v.low_link == v.index)
            {
                Vertex w = null!;
                while (!Object.ReferenceEquals(w, v))
                {
                    w = stack[^1];
                    stack.RemoveAt(stack.Count - 1);
                    w.low_link = v.low_link;
                    w.on_stack = false;
                    scc.Add(w);
                }
            }
            if (scc.Count > 1)
                sccs.AddLast(scc);
        }

        public void recurse(Vertex v)
        {
            __init(v);  // set up Vertex in scc discovery
            // Go through all children of this Vertex
            foreach (var w in v.children)
            {
                if (w.index == -1)
                {
                    recurse(w);
                    v.low_link = Math.Min(v.low_link, w.low_link);
                }
                else if (w.on_stack)
                    v.low_link = Math.Min(v.low_link, w.index);

            }
            __end(v);  // found scc
        }
    };

    static LinkedList<List<Vertex>> calculate_sccs(List<Vertex> vertices, bool iterative = false)
    {
        var calc = new Tarjan();
        foreach (var v in vertices)
            if (v.index == -1)
            {
                //if (iterative)
                //    calc.iterate(v);
                //else
                    calc.recurse(v);
            }
        return calc.sccs;
    }

    static void make_dag(List<Vertex> vertices, LinkedList<List<Vertex>> sccs)
    {
        // merge vertices in each scc
        foreach (var scc in sccs)  // O(V)
        {
            var v = scc[0];  // target node (first node in scc)
            v.weight = scc.Count;  // update the weight of the Vertex
            var children = new List<Vertex>();  // note: no reserve() here
            foreach (var w in scc)
                foreach (var x in w.children)
                    if (v.low_link != x.low_link)
                        children.Add(x);
            v.children = children;
            foreach (var w in scc)
                if (!Object.ReferenceEquals(w, v))
                {
                    w.target = v;  // used for children remapping
                    w.weight = 0;  // indicates the Vertex is not used anymore
                }
        }
        // remap children to the target node (if applicable)
        foreach (var v in vertices)
            if (v.children.Count > 0)
            {
                var children = new List<Vertex>(v.children.Count);
                foreach (var w in v.children)
                children.Add(!Object.ReferenceEquals(w.target, null) ? w.target : w);
                // remove duplicates
                children = keep_unique(children);
                v.children = children;
            }
    }

    static int dag_max_len_recurse(Vertex v)
    {
        int max_len = 0;
        foreach (var w in v.children)
        {
            int curr_len = 0;
            if (w.max_len == 0 && !Object.ReferenceEquals(v, w))  // avoid self referencing
                curr_len = dag_max_len_recurse(w);
            else
                curr_len = w.max_len;
            max_len = Math.Max(max_len, curr_len);
        }
        v.max_len = v.weight + max_len;
        return v.max_len;
    }

    static int dag_max_len(List<Vertex> vertices, bool iterative = false)
    {
        foreach (var v in vertices)
            if (v.weight > 0)
                foreach (var w in v.children)
                    if (!Object.ReferenceEquals(v, w))  // avoid self referencing
                        ++w.inputs;
        int ret = 0;
        foreach (var v in vertices)
        {
            if (v.weight > 0 && v.inputs == 0)
                ret = Math.Max(ret, dag_max_len_recurse(v));
        }
        return ret;
    }

    public int getMaxVisitableWebpages(int N, int M, int[] A, int[] B) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=254501763097320
        // Constraints :
        //      2 ≤ N ≤ 500,000   N different web pages
        //      1 ≤ M ≤ 500,000   M links present across the pages
        //      1 ≤ Ai, Bi ≤ N    ith of which is present on page Aiand links to a different page Bi
        //      Ai ≠ Bi           a page cannot link to itself
        //      Complexity: O(V + E * log(E))  because of call to keep_unique()

        const bool iterative = false;

        // just in case
        if (A.Length == 0 || B.Length == 0)
            return 0;

        // calculate edges
        var edges = new List<Edge>(M);
        for (int i = 0; i < M; ++i)
            edges.Add(new Edge( A[i], B[i] ));  // O(E)
                                                        //
        edges = keep_unique(edges);  // O(E * log(E))
        var vertices = build_children(edges);  // O(V + 2*E)
        var sccs = calculate_sccs(vertices, iterative);  // O(V + E), calculate strongly connected components
        make_dag(vertices, sccs);  // O(V + E)
        var res = dag_max_len(vertices, iterative);  // O(V + E)
        return res;
    }

    class Args : test_all.Res<int>
    {
        public int[]? A;
        public int[]? B;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) =>
        {
            var max_len = Math.Max(p.A!.Max(), p.B!.Max());
            return s.getMaxVisitableWebpages(max_len, p.A!.Length, p.A!, p.B!);
        };

        var args_list = new List<Args> {
            new Args { A=new int[] { 1, 2, 3, 4 }, B=new int[] { 4, 1, 2, 1 }, res=4 },
            new Args { A=new int[] { 3, 5, 3, 1, 3, 2 }, B=new int[] { 2, 1, 2, 4, 5, 4 }, res=4 },
            new Args { A=new int[] { 3, 2, 5, 9, 10, 3, 3, 9, 4 }, B=new int[] { 9, 5, 7, 8, 6, 4, 5, 3, 9 }, res=5 },
            //
            new Args { A=new int[] { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14     }, B=new int[] { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  4,  4,  2     }, res=8 },
            new Args { A=new int[] { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14     }, B=new int[] { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  9     }, res=8 },
            new Args { A=new int[] { 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 13, 13, 13 }, B=new int[] { 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  5,  8 }, res=8 },
            new Args { A=new int[] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 }, B=new int[] { 3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8 }, res=4 },
            new Args { A=new int[] { 1, 3, 2 }, B=new int[] { 3, 2, 3 }, res=3 },
            new Args { A=new int[] { 2, 1 }, B=new int[] { 1, 2 }, res=2 },
            new Args { A=new int[] { 3, 5, 3, 1, 3, 2 }, B=new int[] { 2, 2, 2, 4, 5, 4 }, res=4 },
            new Args { A=new int[] { 3, 5, 3, 1, 3, 2 }, B=new int[] { 2, 2, 5, 4, 5, 4 }, res=4 },  // 3 is referencing 5 twice
            new Args { A=new int[] { 3, 5, 3, 1, 3, 2 }, B=new int[] { 2, 2, 3, 4, 5, 4 }, res=4 },  // 3 is self referencing
        };

        return test_all.TestAll.run_all_tests("l3_rabbit_hole2", args_list, wrapper);
    }

}

}
