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

@dataclass
class Vertex:
    nb: int
    inputs: int = 0
    level: int = 1
    in_cycle: bool = True
    cycle_len: int = 0
    next: object = None

    def __repr__(self):
        return 'Vertex(i=%d, inputs=%d, in_cycle=%s, cycle_len=%d, level=%d, next=%d)' %\
               (self.nb, self.inputs, self.in_cycle, self.cycle_len, self.level, self.next.nb if self.next else -1)

def getMaxVisitableWebpages(N: int, L: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=316794079975021
    # Constraints:
    #   2 ≤ N ≤ 500,000
    #   1 ≤ Li ≤ N
    #   Li ≠ i
    # Complexity: O(N)

    # Note: as a vertex is always followed by 1 vertex, we always end up in a cycle: O(N)
    vertices = [Vertex(i + 1) for i in range(N)]  # O(N)

    # count the number of inputs for each vertex, and set next vertex: O(N)
    for i, (vertex, n) in enumerate(zip(vertices, L)):
        vertex.next = next_vertex = vertices[n - 1]
        next_vertex.inputs += 1

    # find the entrance vertices (could be []): O(N)
    entrance_vertices = [vertex for vertex in vertices if vertex.inputs == 0]

    # calculate "level" of each vertex that is not in a cycle: O(N)
    visited_vertices = list(entrance_vertices)
    while visited_vertices:
        curr_vertex = visited_vertices.pop()
        curr_vertex.in_cycle = False
        next_vertex = curr_vertex.next
        next_vertex.level = max(next_vertex.level, curr_vertex.level + 1)
        next_vertex.inputs -= 1
        if next_vertex.inputs == 0:
            visited_vertices.append(next_vertex)

    # calculate length of cycles of the different cycle: O(N)
    for vertex in vertices:
        if vertex.in_cycle is False or vertex.cycle_len > 0:
            continue
        # count length of cycle
        cycle_len = 1
        curr = vertex.next
        while curr != vertex:
            cycle_len += 1
            curr = curr.next
        # assign length of cycle to vertices
        vertex.cycle_len = cycle_len
        curr = vertex.next
        while curr != vertex:
            curr.cycle_len = cycle_len
            curr = curr.next

    # Now calculate the maximum length: O(N)
    max_chain = 0
    for vertex in vertices:
        if vertex.in_cycle:
            max_chain = max(max_chain, vertex.cycle_len)
        elif vertex.next.in_cycle:
            max_chain = max(max_chain, vertex.level + vertex.next.cycle_len)
    return max_chain


def tests():
    def fn(L): return len(L), L
    meta_cases = "meta", [
        (([4, 1, 2, 1], ), 4),
        (([4, 3, 5, 1, 2], ), 3),
        (([2, 4, 2, 2, 3], ), 4),
    ]
    extra1_cases = "extra1", [
        (([1], ), 1),
        (([1, 2], ), 1),
        (([2, 1], ), 2),
        (([3, 3, 4, 3], ), 3),
        (([4, 5, 6, 5, 6, 4], ), 4),
        (([6, 5, 4, 5, 6, 4], ), 4),
        (([3, 3, 4, 1], ), 4),
        (([2, 3, 2], ), 3),
        (([2, 4, 2, 2, 3], ), 4),
        (([6, 5, 4, 3, 2, 1], ), 2),
    ]
    extra2_cases = "extra2", [
        (([4, 1, 2, 1], ), 4),
        (([4, 3, 5, 1, 2], ), 3),
        (([4, 1, 2, 1], ), 4),
        (([2, 1, 4, 3], ), 2),
        (([2, 4, 2, 2, 4, 5], ), 4),
        (([4, 1, 2, 1], ), 4),
        (([4, 3, 5, 1, 2], ), 3),
        (([2, 4, 2, 2, 4], ), 3),
        (([2, 3, 4, 2, 2, 3, 6, 9, 8], ), 5),
    ]
    cycles = [8, 9, 10, 11, 12, 7]
    extra3_cases = "extra3", [
        (([2, 4, 2, 2, 3, 4] + cycles, ), 6),
        (([2, 4, 2, 2, 4, 5] + cycles, ), 6),
    ]
    return getMaxVisitableWebpages, fn, [meta_cases, extra1_cases, extra2_cases, extra3_cases]


# End
