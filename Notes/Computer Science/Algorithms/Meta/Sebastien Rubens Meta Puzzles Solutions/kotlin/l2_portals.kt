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

package l2_portals

typealias dist_t = Int;

open class Coord(
    var row: Int,
    var col: Int, )

class NodeInfo(
    row: Int,
    col: Int,
    var node_type: Char, ) : Coord(row, col)
{
    var distance: dist_t = dist_t.MAX_VALUE;
    var is_inserted: Boolean = false;
}

class OurPriorityQueue<Priority: Comparable<Priority>, Item>
{
    // This is to have an "identical" implement to other languages who do not have std::multimap<dist_t, NodeInfoPtr_t>
    // Here, we are wrapping call to what could be the std::multimap<dist_t, NodeInfoPtr_t>

    //typealias value_type = Pair<Priority, Item>;  // Nested or local typealias are not supported in kotlin

    fun empty(): Boolean
    {
        return m.isEmpty();
    }

    fun insert(priority: Priority, item: Item)
    {
        m[Pair(priority, ++nb)] = item;
    }

    fun pop_front(): Pair<Priority, Item>
    {
        val k = m.firstKey();
        val v = m.remove(k)!!;
        return Pair<Priority, Item>(k.first, v);
    }

    var nb: ULong = 0UL;  // this could wrap at some point (if it was running forever), and makes it not really a multimap equivalent
    var m = sortedMapOf<Pair<Priority, ULong>, Item>(compareBy<Pair<Priority, ULong>> { it.first } then compareBy { it.second });
}

typealias GridNodeInfo_t = ArrayList<ArrayList<NodeInfo>>;
typealias PriorityQueue_t = OurPriorityQueue<dist_t, NodeInfo>;
typealias HeuristicFunc_t = (node: NodeInfo) -> dist_t;
typealias DistFunc_t = (n1: NodeInfo, n2: NodeInfo) -> dist_t;

fun add_neighbour(q: PriorityQueue_t, h: HeuristicFunc_t, d: DistFunc_t, node: NodeInfo, neighbour: NodeInfo)
{
    val neighbor_distance = d(node, neighbour);
    if (neighbor_distance >= neighbour.distance)
        return;
    neighbour.distance = neighbor_distance;
    if (!neighbour.is_inserted)
    {
        neighbour.is_inserted = true;
        q.insert(h(neighbour), neighbour);
    }
}

fun _getSecondsRequired(R: Int, C: Int, G: Array<Array<Char>>): Int {
    // set up grid and portal map
    val grid = GridNodeInfo_t(R);
    for (j in 0 until R)
    {
        val row = ArrayList<NodeInfo>(C);
        for (i in 0 until C)
            row.add(NodeInfo(j, i, G[j][i]));  // Meta used Array<Array<String>> instead of Array<Array<Char>>!
        grid.add(row);
    }

    var start = Coord(0, 0);
    val ends = ArrayList<Coord>(R * C);
    val portals = ArrayList<ArrayList<NodeInfo>>(256);
    repeat(256) { index -> portals.add(ArrayList<NodeInfo>()) }
    for (j in 0 until R)
    {
        val row = G[j];
        for (i in 0 until C)
        {
            val node_type = row[i];
            if (node_type == 'S')
                start = Coord( j, i );
            else if (node_type == 'E')
                ends.add(Coord( j, i ));  // Ends could be used for a heuristic
            else if ('a' <= node_type && node_type <= 'z')
                portals[node_type.code % 256].add(grid[j][i]);  // note: no reserve() here
        }
    }
    val start_node = grid[start.row][start.col];
    start_node.distance = 0;

    // set up the grid
    val q = PriorityQueue_t();  // contains (heuristic score, coordinates)
    val h = fun (node: NodeInfo): dist_t { return node.distance; };
    val d = fun (n1: NodeInfo, n2: NodeInfo): dist_t { return n1.distance + 1; };

    val neighbours_directions = arrayOf(Coord(-1, 0), Coord(1, 0), Coord(0, -1), Coord(0, 1));

    q.insert(h(start_node), start_node);
    while (!q.empty())
    {
        val (_, node) = q.pop_front();
        if (node.node_type == 'E')
            return node.distance;
        // add portal nodes to node
        if ('a' <= node.node_type && node.node_type <= 'z')
        {
            for (neighbour in portals[node.node_type.code % 256])
                if (neighbour !== node)
                    add_neighbour(q, h, d, node, neighbour);
        }
        // add neighbours to node
        for (coord in neighbours_directions)
        {
            val row = node.row + coord.row;
            val col = node.col + coord.col;
            if ((0 <= row && row < R) && (0 <= col && col < C))
            {
                val neighbour = grid[row][col];
                if (neighbour.node_type != '#')
                    add_neighbour(q, h, d, node, neighbour);
            }
        }
    }
    return -1;
}

fun getSecondsRequired(R: Int, C: Int, G: Array<Array<String>>): Int {
    val H = ArrayList<Array<Char>>(G.size);
    for (in_row in G)
    {
        val row = ArrayList<Char>(in_row.size);
        for (c in in_row)
            row.add(if (!c.isEmpty()) c[0] else '.');  // FIXME: Meta's website provide corrupted test data!
        H.add(row.toTypedArray());
    }
    return _getSecondsRequired(H.size, if (H.isEmpty()) 0 else H[0].size, H.toTypedArray());
}

fun _getSecondsRequiredTest(G: Array<String>): Int {
    val H = ArrayList<Array<String>>(G.size);
    for (in_row in G)
    {
        val row = ArrayList<String>(in_row.length);
        for (c in in_row)
            row.add(c.toString());
        H.add(row.toTypedArray());
    }
    return getSecondsRequired(H.size, if (H.isEmpty()) 0 else H[0].size, H.toTypedArray());
}

class Args(
    val G: Array<String>,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> _getSecondsRequiredTest(p.G) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(".E.", ".#E", ".S#"), 4 ),
        Args( arrayOf("a.Sa", "####", "Eb.b"), -1 ),
        Args( arrayOf("aS.b", "####", "Eb.a"), 4 ),
        Args( arrayOf("xS..x..Ex"), 3 ),
    );

    return test.run_all_tests("l2_portals", args_list, wrapper);
}
