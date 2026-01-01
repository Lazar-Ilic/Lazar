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

import scala.collection.immutable.TreeMap
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.Map  // getOrElseUpdate not supported on mutable.HashMap on Meta's website

class Coord(var row: Int,
            var col: Int) {
}

class NodeInfo(var row: Int,
               var col: Int,
               var node_type: Char) {
    var distance = Int.MaxValue
    var is_inserted = false
}

class OurPriorityQueue[Priority: Numeric, Item] {
    // This is to have an "identical" implement to other languages who do not have std::multimap<dist_t, NodeInfoPtr_t>
    // Here, we are wrapping call to what could be the std::multimap<dist_t, NodeInfoPtr_t>
    type NbT = Long
    type KeyT = (Priority, NbT)

    def empty(): Boolean = m.isEmpty

    def insert(priority: Priority, item: Item) = {
        nb += 1L
        val key = (priority, nb)
        m = m.updated(key, item)
    }

    def pop_front(): (Priority, Item) = {
        val (key, value) = m.head
        m -= key
        return (key._1, value)
    }

    private var nb = 0L // this could wrap at some point (if it was running forever), and makes it not really a multimap equivalent
    private var m = new TreeMap[KeyT, Item]()
}

object Solution {
    def getSecondsRequired(R: Int, C: Int, G: Array[Array[String]]): Int = {
        type dist_t = Int
        type GridNodeInfo_t = ArrayBuffer[ArrayBuffer[NodeInfo]]
        type PriorityQueue_t = OurPriorityQueue[dist_t, NodeInfo]
        type HeuristicFunc_t = (NodeInfo) => dist_t
        type DistFunc_t = (NodeInfo, NodeInfo) => dist_t

        def add_neighbour(q: PriorityQueue_t, h: HeuristicFunc_t, d: DistFunc_t, node: NodeInfo, neighbour: NodeInfo) = {
            val neighbor_distance = d(node, neighbour)
            if (neighbor_distance < neighbour.distance) {
                neighbour.distance = neighbor_distance
                if (!neighbour.is_inserted) {
                    neighbour.is_inserted = true
                    q.insert(h(neighbour), neighbour)
                }
            }
        }

        def _getSecondsRequired(R: Int, C: Int, G: Array[Array[Char]]): Int = {
            // set up grid and portal map
            val grid = new GridNodeInfo_t(R)
            for (j <- 0 until R) {
                val row = new ArrayBuffer[NodeInfo](C)
                for (i <- 0 until C)
                    row += new NodeInfo(j, i, G(j)(i)) // Meta used Array<Array<String>> instead of Array<Array<Char>>!
                grid += row
            }

            var start = new Coord(0, 0)
            val ends = new ArrayBuffer[Coord](R * C)
            val portals = Map[Char, ArrayBuffer[NodeInfo]]()
            for (j <- 0 until R) {
                val row = G(j)
                for (i <- 0 until C) {
                    val node_type = row(i)
                    if (node_type == 'S')
                        start = new Coord(j, i)
                    else if (node_type == 'E')
                        ends += new Coord(j, i) // Ends could be used for a heuristic
                    else if ('a' <= node_type && node_type <= 'z') {
                        val values = portals.getOrElseUpdate(node_type, new ArrayBuffer[NodeInfo]()) // note: no reserve() here
                        values += grid(j)(i)
                    }
                }
            }
            val start_node = grid(start.row)(start.col)
            start_node.distance = 0

            // set up the grid
            val q = new PriorityQueue_t() // contains (heuristic score, coordinates)
            val h = (node: NodeInfo) => node.distance
            val d = (n1: NodeInfo, n2: NodeInfo) => n1.distance + 1

            val neighbours_directions = Array(new Coord(-1, 0), new Coord(1, 0), new Coord(0, -1), new Coord(0, 1))

            q.insert(h(start_node), start_node)
            while (!q.empty()) {
                val (_, node) = q.pop_front()
                if (node.node_type == 'E')
                    return node.distance
                // add portal nodes to node
                if ('a' <= node.node_type && node.node_type <= 'z') {
                    for (neighbour <- portals(node.node_type))
                        if (node ne neighbour)
                            add_neighbour(q, h, d, node, neighbour)
                }
                // add neighbours to node
                for (coord <- neighbours_directions) {
                    val row = node.row + coord.row
                    val col = node.col + coord.col
                    if ((0 <= row && row < R) && (0 <= col && col < C)) {
                        val neighbour = grid(row)(col)
                        if (neighbour.node_type != '#')
                            add_neighbour(q, h, d, node, neighbour)
                    }
                }
            }
            return -1
        }

        val H = new ArrayBuffer[Array[Char]](G.size)
        for (in_row <- G) {
            val row = new ArrayBuffer[Char](in_row.size)
            for (c <- in_row)
                row += c(0)
            H += row.toArray
        }
        return _getSecondsRequired(H.size, if (H.isEmpty) 0 else H(0).size, H.toArray)
    }


    class Args(val G: Array[String],
               val res: Int) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def _getSecondsRequiredTest (G: Array[String]): Int = {
        val H = new ArrayBuffer[Array[String]](G.size)
        for (in_row <- G) {
            val row = new ArrayBuffer[String](in_row.length)
            for (c <- in_row)
                row += c.toString
            H += row.toArray
        }
        return getSecondsRequired(H.size, if (H.isEmpty) 0 else H(0).size, H.toArray)
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => _getSecondsRequiredTest(p.G)

        val args_list = Array[Args](
            new Args(Array[String](".E.", ".#E", ".S#"), 4),
            new Args(Array[String]("a.Sa", "####", "Eb.b"), -1),
            new Args(Array[String]("aS.b", "####", "Eb.a"), 4),
            new Args(Array[String]("xS..x..Ex"), 3)
        )

        return test.TestAll.run_all_tests("l2_portals", args_list, wrapper)
    }
}

