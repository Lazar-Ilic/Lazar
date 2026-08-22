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

namespace l2_portals
{

#nullable enable annotations

class Solution {


    // Quick implementation of PriorityQueue as Meta does not seem to recognize it
    class OurPriorityQueue<TElement, TPriority>
        where TPriority : unmanaged
    {
        SortedDictionary<(TPriority, UInt64), TElement> queue;
        UInt64 nb;

        public OurPriorityQueue()
        {
            queue = new SortedDictionary<(TPriority, UInt64), TElement>();
            nb = 0;
        }

        public int Count { get { return queue.Count; } }

        public void Enqueue(TElement element, TPriority priority)
        {
            ++nb;
            queue[(priority, nb)] = element;
        }

        public TElement Dequeue()
        {
            var element = queue.First();
            queue.Remove(element.Key);
            return element.Value;
        }
    }

    class Coord
    {
        public int row;
        public int col;

        public Coord(int _row = 0, int _col = 0)
        {
            row = _row;
            col = _col;
        }
    }

    class NodeInfo : Coord
    {
        public char node_type;
        public int distance;
        public NodeInfo? source;

        public NodeInfo(int _row, int _col, char _node_type)
            : base(_row, _col)
        {
            node_type = _node_type;
            distance = int.MaxValue;
            source = null;
        }
    }

    static void add_neighbour(OurPriorityQueue<NodeInfo, int> q,
        Func<NodeInfo, int> h, Func<NodeInfo, NodeInfo, int> d,
        NodeInfo node, NodeInfo neighbour)
    {
        var neighbor_distance = d(node, neighbour);
        if (neighbor_distance >= neighbour.distance)
            return;
        if (Object.ReferenceEquals(neighbour.source, null))
            q.Enqueue(neighbour, h(neighbour));
        neighbour.source = node;
        neighbour.distance = neighbor_distance;
    }

    public int getSecondsRequired(int R, int C, char[,] G) {
        // https://www.metacareers.com/profile/coding_puzzles/?puzzle=544961100246576
        // Constraints:
        //      1 ≤ R,C ≤ 50
        //      Gi,j ∈ {".", "S", "E", "#", "a"..."z"}
        // Complexity: see A* search algorithm (https://en.wikipedia.org/wiki/A*_search_algorithm)

        // set up grid and portal map
        var grid = new List<List<NodeInfo>>(R);
        for (int j = 0; j < R; ++j)
        {
            var row = new List<NodeInfo>(C);
            grid.Add(row);
            for (int i = 0; i < C; ++i)
                row.Add(new NodeInfo(j, i, G[j, i]));
        }

        var start = new Coord(0, 0);
        var ends = new List<Coord>(R * C);
        var portals = new List<List<NodeInfo>>(256);
        for (int j = 0; j < 256; ++j)
            portals.Add(new List<NodeInfo>());  // note: no reserve() here
        for (int j = 0; j < R; ++j)
        {
            for (int i = 0; i < C; ++i)
            {
                var node_type = G[j, i];
                if (node_type == 'S')
                    start = new Coord( j, i );
                else if (node_type == 'E')
                    ends.Add(new Coord( j, i ));  // Ends could be used for a heuristic
                else if ('a' <= node_type && node_type <= 'z')
                    portals[node_type].Add(grid[j][i]);
            }
        }
        var start_node = grid[start.row][start.col];
        start_node.distance = 0;

        // set up the grid
        var q = new OurPriorityQueue<NodeInfo, int>();  // contains (heuristic score, coordinates)
        Func<NodeInfo, int> h = (NodeInfo node) => node.distance;
        Func<NodeInfo, NodeInfo, int> d = (NodeInfo n1, NodeInfo n2) => n1.distance + 1;  // distance is always one

        Coord[] neighbours_directions = { new Coord(-1, 0), new Coord(1, 0), new Coord(0, -1), new Coord(0, 1) };
        var x = h(start_node);
        q.Enqueue(start_node, x);
        while (q.Count > 0)
        {
            var node = q.Dequeue();
            if (node.node_type == 'E')
                return node.distance;
            // add portal nodes to node
            if ('a' <= node.node_type && node.node_type <= 'z')
            {
                foreach (var neighbour in portals[node.node_type])
                    if (!Object.ReferenceEquals(neighbour, node))
                        add_neighbour(q, h, d, node, neighbour);
            }
            // add neighbours to node
            foreach (var dcoord in neighbours_directions)
            {
                var row = node.row + dcoord.row;
                var col = node.col + dcoord.col;
                if ((0 <= row && row < R) && (0 <= col && col < C))
                {
                    var neighbour = grid[row][col];
                    if (neighbour.node_type != '#')
                        add_neighbour(q, h, d, node, neighbour);
                }
            }
        }
        return -1;
    }

    class Args : test_all.Res<int>
    {
        public char[,]? G;
    }

    public static int tests()
    {
        var s = new Solution();

        Func<Args, int> wrapper = (Args p) => s.getSecondsRequired(p.G!.GetLength(0), p.G!.GetLength(1), p.G!);

        var args_list = new List<Args> {
            new Args { G=new char[,] { { '.', 'E', '.' }, { '.', '#', 'E' }, { '.', 'S', '#' } }, res=4 },
            new Args { G=new char[,] { { 'a', '.', 'S', 'a' }, { '#', '#', '#', '#' }, { 'E', 'b', '.', 'b' } }, res=-1 },
            new Args { G=new char[,] { { 'a', 'S', '.', 'b' }, { '#', '#', '#', '#' }, { 'E', 'b', '.', 'a' } }, res=4 },
            new Args { G=new char[,] { { 'x', 'S', '.', '.', 'x', '.', '.', 'E', 'x' } }, res=3 },
        };

        return test_all.TestAll.run_all_tests("l2_portals", args_list, wrapper);
    }

}

}
