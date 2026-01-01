# meta_puzzles by Sebastien Rubens
#
# Please go to https://github.com/seb-pg/meta_puzzles/README.md
# for more information
#
# To the extent possible under law, the person who associated CC0 with
# meta_puzzles has waived all copyright and related or neighboring rights
# to meta_puzzles.
#
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

from typing import List
from dataclasses import dataclass
import collections
import queue
import sys


@dataclass
class NodeInfo:
    row: int
    col: int
    node_type: str
    distance: int = sys.maxsize  # cost of the cheapest path from start to n currently known
    source: object = None  # previous node with cheapest path

    def __lt__(self, other):
        return self.distance < other.distance

    def debug_reconstruct_path(self):
        node = self
        path = []
        while node:
            path.append(node)
            node = node.source
        return [(n.col, n.row, n.distance) for n in path[::-1]]


def add_neighbour(q, h, d, node, neighbour):
    neighbor_distance = d(node, neighbour)
    if neighbor_distance >= neighbour.distance:
        return
    if neighbour.source is None:
        q.put((h(neighbour), neighbour))
    neighbour.source = node
    neighbour.distance = neighbor_distance
    return


def getSecondsRequired(R: int, C: int, G: List[List[str]]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=544961100246576
    # Constraints:
    #   1 ≤ R,C ≤ 50
    #   Gi,j ∈ {".", "S", "E", "#", "a"..."z"}
    # Complexity: see A* search algorithm (https://en.wikipedia.org/wiki/A*_search_algorithm)

    # set up grid and portal map
    grid = [[NodeInfo(j, i, elt) for i, elt in enumerate(row)] for j, row in enumerate(G)]
    portals = collections.defaultdict(list)

    start, ends = (0, 0), []
    for j, row in enumerate(G):
        for i, node_type in enumerate(row):
            if node_type == 'S':
                start = (j, i)
            elif node_type == 'E':
                ends.append((j, i))  # Ends could be used for a heuristic
            elif 'a' <= node_type <= 'z':
                portals[node_type].append(grid[j][i])
    start_node = grid[start[0]][start[1]]
    start_node.distance = 0

    # set up the grid
    q = queue.PriorityQueue()  # contains (heuristic score, coordinates)
    h = lambda n: n.distance  # heuristic is the node distance (very basic)
    d = lambda n1, n2: n1.distance + 1  # distance is always one

    neighbours_directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    q.put((h(start_node), start_node))
    while q.qsize():
        score, node = q.get()
        if node.node_type == 'E':
            #print('path', node.debug_reconstruct_path())
            return node.distance
        # add portal nodes to node
        if 'a' <= node.node_type <= 'z':
            for neighbour in portals[node.node_type]:
                if id(neighbour) != id(node):
                    add_neighbour(q, h, d, node, neighbour)
        # add neighbours to node
        neighbours_coords = [(node.row + drow, node.col + dcol) for drow, dcol in neighbours_directions]
        neighbours = [grid[row][col] for row, col in neighbours_coords if (0 <= row < R) and (0 <= col < C)]
        for neighbour in neighbours:
            if neighbour.node_type != '#':
                add_neighbour(q, h, d, node, neighbour)
    return -1


def tests():
    def fn(G): return len(G), len(G[0]), G
    meta_cases = "meta", [
        (([".E.", ".#E", ".S#"], ), 4),
        ((["a.Sa", "####", "Eb.b"], ), -1),
        ((["aS.b", "####", "Eb.a"], ), 4),
        ((["xS..x..Ex"], ), 3),
    ]
    return getSecondsRequired, fn, [meta_cases]


# End
