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

namespace l2_rabbit_hole1
{

#nullable enable annotations

class Solution {

    class Vertex
    {
        public int nb;
        public int inputs;
        public int level;
        public bool in_cycle;
        public int cycle_len;
        public Vertex? next;

        public Vertex(int _nb)
        {
            nb = _nb;
            level = 1;
            in_cycle = true;
            cycle_len = 0;
            next = null;
        }
    }

    public int getMaxVisitableWebpages(int N, int[] L) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=316794079975021
        // Constraints:
        //      2 ≤ N ≤ 500,000
        //      1 ≤ Li ≤ N
        //      Li ≠ i
        //  Complexity: O(N)

        // Note: as a vertex is always followed by 1 vertex, we always end up in a cycle
        var vertices = new List<Vertex>(N);
        for (int i = 0; i < N; ++i)
            vertices.Add(new Vertex( i + 1 ));

        // count the number of inputs for each vertex, and set next vertex: O(N)
        for (int i = 0; i < N; ++i)
        {
            var vertex = vertices[i];
            var next_vertex = vertices[L[i] - 1];
            vertex.next = next_vertex;  // yes, we are using raw pointers, as vertices is never resized
            ++next_vertex.inputs;
        }

        // find the entrance vertices (could be []): O(N)
        var entrance_vertices = new List<Vertex>(vertices.Count);
        foreach (var vertex in vertices)
            if (vertex.inputs == 0)
                entrance_vertices.Add(vertex);

        // calculate "level" of each vertex that is not in a cycle: O(N)
        var visited_vertices = new List<Vertex>();
            visited_vertices.AddRange(entrance_vertices);
        while (visited_vertices.Count > 0)
        {
            var curr_vertex = visited_vertices[^1];
            visited_vertices.RemoveAt(visited_vertices.Count - 1);
            curr_vertex.in_cycle = false;
            var next_vertex = curr_vertex.next;
            next_vertex!.level = Math.Max(next_vertex.level, curr_vertex.level + 1);
            --next_vertex.inputs;
            if (next_vertex.inputs == 0)
                visited_vertices.Add(next_vertex);
        }

        // calculate length of cycles of the different cycle: O(N)
        foreach (var vertex in vertices)
        {
            if (!vertex.in_cycle || vertex.cycle_len > 0)
                continue;
            // count length of cycle
            int cycle_len = 1;
            var curr = vertex.next!;
            while (!Object.ReferenceEquals(curr, vertex))
            {
                ++cycle_len;
                curr = curr.next!;
            }
            // assign length of cycle to vertices
            vertex.cycle_len = cycle_len;
            curr = vertex.next!;
            while (curr != vertex)
            {
                curr.cycle_len = cycle_len;
                curr = curr.next!;
            }
        }

        // Now calculate the maximum length: O(N)
        int max_chain = 0;
        foreach (var vertex in vertices)
        {
            if (vertex.in_cycle)
                max_chain = Math.Max(max_chain, vertex.cycle_len);
            else if (vertex.next!.in_cycle)
                max_chain = Math.Max(max_chain, vertex.level + vertex.next.cycle_len);
        }
        return max_chain;
    }

    class Args : test_all.Res<int>
    {
        public int[]? L;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getMaxVisitableWebpages(p.L!.Length, p.L!);

        var args_list = new List<Args> {
            new Args { L=new int[] { 4, 1, 2, 1 }, res=4 },
            new Args { L=new int[] { 4, 3, 5, 1, 2 }, res=3 },
            new Args { L=new int[] { 2, 4, 2, 2, 3 }, res=4 },
            // extra1
            new Args { L=new int[] { 1 }, res=1 },
            new Args { L=new int[] { 1, 2 }, res=1 },
            new Args { L=new int[] { 2, 1 }, res=2 },
            new Args { L=new int[] { 3, 3, 4, 3 }, res=3 },
            new Args { L=new int[] { 4, 5, 6, 5, 6, 4 }, res=4 },
            new Args { L=new int[] { 6, 5, 4, 5, 6, 4 }, res=4 },
            new Args { L=new int[] { 3, 3, 4, 1 }, res=4 },
            new Args { L=new int[] { 2, 3, 2 }, res=3 },
            new Args { L=new int[] { 2, 4, 2, 2, 3 }, res=4 },
            new Args { L=new int[] { 6, 5, 4, 3, 2, 1 }, res=2 },
            // extra2
            new Args { L=new int[] { 4, 1, 2, 1 }, res=4 },
            new Args { L=new int[] { 4, 3, 5, 1, 2 }, res=3 },
            new Args { L=new int[] { 4, 1, 2, 1 }, res=4 },
            new Args { L=new int[] { 2, 1, 4, 3 }, res=2 },
            new Args { L=new int[] { 2, 4, 2, 2, 4, 5 }, res=4 },
            new Args { L=new int[] { 4, 1, 2, 1 }, res=4 },
            new Args { L=new int[] { 4, 3, 5, 1, 2 }, res=3 },
            new Args { L=new int[] { 2, 4, 2, 2, 4 }, res=3 },
            new Args { L=new int[] { 2, 3, 4, 2, 2, 3, 6, 9, 8 }, res=5 },
            // extra3
            new Args { L=new int[] { 2, 4, 2, 2, 3, 4, 8, 9, 10, 11, 12, 7 }, res=6 },
            new Args { L=new int[] { 2, 4, 2, 2, 4, 5, 8, 9, 10, 11, 12, 7 }, res=6 },
        };

        return test_all.TestAll.run_all_tests("l2_rabbit_hole1", args_list, wrapper);    
    }

}

}
