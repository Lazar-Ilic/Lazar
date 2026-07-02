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

import (
	"math"
	"meta_puzzles/test"
)

type dist_t = int32

type Coord struct {
	row int32
	col int32
}

type NodeInfo struct {
	Coord
	node_type   byte
	distance    dist_t
	is_inserted bool
}

type OurPriorityQueue struct {
	m map[int32]([]NodeInfoPtr_t)
}

func (self *OurPriorityQueue) insert(dist dist_t, node NodeInfoPtr_t) {
	self.m[dist] = append(self.m[dist], node)
}

func (self *OurPriorityQueue) pop(dist dist_t, node NodeInfoPtr_t) {
	self.m[dist] = append(self.m[dist], node)
}

type NodeInfoPtr_t = *NodeInfo
type GridNodeInfo_t = [][]NodeInfoPtr_t
type PriorityQueue_t = OurPriorityQueue
type HeuristicFunc_t = func(NodeInfoPtr_t) dist_t
type DistFunc_t = func(NodeInfoPtr_t, NodeInfoPtr_t) dist_t

func add_neighbour(q PriorityQueue_t, h HeuristicFunc_t, d DistFunc_t, node NodeInfoPtr_t, neighbour NodeInfoPtr_t) {
	neighbor_distance := d(node, neighbour)
	if neighbor_distance >= neighbour.distance {
		return
	}
	neighbour.distance = neighbor_distance
	if !neighbour.is_inserted {
		neighbour.is_inserted = true
		q.insert(h(neighbour), neighbour)
	}
}

func getSecondsRequired(R int32, C int32, G [][]byte) int32 {
	grid := make(GridNodeInfo_t, 0, R)
	for j := int32(0); j < R; j += 1 {
		row := make([]NodeInfoPtr_t, 0, C)
		for i := int32(0); i < C; i += 1 {
			node := NodeInfo{Coord{j, i}, G[j][i], math.MaxInt32, false}
			row = append(row, &node)
		}
		grid = append(grid, row)
	}

	start := Coord{0, 0}
	ends := make([]Coord, 0, R*C)
	portals := map[byte]([]NodeInfoPtr_t){}
	for j := int32(0); j < R; j += 1 {
		row := G[j]
		for i := int32(0); i < C; i += 1 {
			node_type := row[i]
			if node_type == byte('S') {
				start = Coord{j, i}
			} else if node_type == byte('E') {
				ends = append(ends, Coord{j, i}) // Ends could be used for a heuristic
			} else if byte('a') <= node_type && node_type <= byte('z') {
				portals[node_type] = append(portals[node_type], grid[j][i]) // note: no reserve() here
			}
		}
	}
	start_node := grid[start.row][start.col]
	start_node.distance = 0

	minus_1_row := int32(-1)
	minus_1_col := int32(-1)
	neighbours_directions := []Coord{{minus_1_row, 0}, {1, 0}, {0, minus_1_col}, {0, 1}}

	/*q.insert(PriorityQueue_t::value_type(h(start_node), start_node));
	  while (!q.empty())
	  {
	      const auto itb = std::begin(q);
	      const auto [_score, node] = *itb;
	      q.erase(itb);
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
	          auto row = node->row + drow;
	          auto col = node->col + dcol;
	          if ((row < R) && (col < C))
	          {
	              auto& neighbour = grid[row][col];
	              if (neighbour->node_type != '#')
	                  add_neighbour(q, h, d, node, neighbour);
	          }
	      }
	  }
	  return -1;*/
}

type Args struct {
	G   []string
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 {
		H := make([][]byte, len(p.G))
		for idx, row := range p.G {
			H[idx] = []byte(string(row))
		}
		return getSecondsRequired(int32(len(H)), int32(len(H[0])), H)
	}

	args_lists := []Args{
		{[]string{".E.", ".#E", ".S#"}, 4},
		{[]string{"a.Sa", "####", "Eb.b"}, -1},
		{[]string{"aS.b", "####", "Eb.a"}, 4},
		{[]string{"xS..x..Ex"}, 3},
	}

	return test.RunAllTests("l2_portals", args_lists, wrapper)
}

// TODO: l2_portals
// TODO: implements have priority queue
// TODO: uses std::shared_ptr
// TODO: uses std::map
// TODO: uses std::unordered_map
