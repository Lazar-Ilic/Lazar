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
from dataclasses import dataclass, field


@dataclass
class Vertex:
    nb: int
    weight: int = 0  # 0 means unused
    children: List[object] = field(default_factory=lambda: [])

    # members for strongly connected components
    index: int = -1
    low_link: int = -1
    on_stack: bool = False

    # members for dag construction
    target: object = None  # target node

    # members for max length calculation
    inputs: int = 0  # number of inputs for a given node
    max_len: int = 0  # used for memoization of max_len at node level

    def __repr__(self):
        #return 'Vertex(nb=%d, weight=%d, inputs=%d, children=%s)' %\
        #       (self.nb, self.weight, self.inputs, [v.nb for v in self.children])
        return 'Vertex(nb=%d, weight=%d, inputs=%d, index=%d, low_link=%d, children=%s)' %\
               (self.nb, self.weight, self.inputs, self.index, self.low_link, [v.nb for v in self.children])


def keep_unique(edges):  # O(E*log(E))
    if len(edges) > 1:
        edges.sort()
        i = 1
        for e1, e2 in zip(edges, edges[1:]):
            if e1 != e2:
                edges[i] = e2
                i += 1
        edges = edges[:i]
    return edges


def build_children(edges):  # O(V + E)
    nb_vertices = max(max(v1 for v1, v2 in edges), max(v2 for v1, v2 in edges))  # O(2*E), we do not count it
    vertices = [Vertex(i) for i in range(nb_vertices + 1)]  # O(V)
    for v, w in edges:  # O(E)
        vertices[v].children.append(vertices[w])
        vertices[v].weight = 1
        vertices[w].weight = 1
    return vertices


class Tarjan:

    @dataclass
    class Frame1:
        v: Vertex
        child_nb: int = 0
        recurse_object: object = None

    def __init__(self, vertices):
        self.vertices = vertices
        self.sccs = []
        self.stack = []
        self.index = 0
        return

    def __init(self, v):
        v.index = self.index
        v.low_link = self.index
        v.on_stack = True
        self.stack.append(v)
        self.index += 1
        return

    def __end(self, v):
        scc = []
        if v.low_link == v.index:
            w = None
            while id(w) != id(v):
                w = self.stack.pop()
                w.low_link = v.low_link
                w.on_stack = False
                scc.append(w)
        if len(scc) > 1:
            self.sccs.append(scc)
        return

    def recurse(self, v):
        self.__init(v)  # set up vertex in scc discovery
        # Go through all children of this vertex
        for w in v.children:
            if w.index == -1:  # not visited
                self.recurse(w)
                v.low_link = min(v.low_link, w.low_link)
            elif w.on_stack:
                v.low_link = min(v.low_link, w.index)
        self.__end(v)  # found scc
        return

    def iterate(self, v):
        call_stack = [Tarjan.Frame1(v)]
        while call_stack:
            f = call_stack[-1]
            v = f.v
            # call __init only when we enter the node
            if v.index < 0:
                self.__init(v)
            # if we are at the end of the loop
            if f.child_nb >= len(v.children):
                self.__end(v)
                call_stack.pop()
                continue
            # we are in the loop
            w = v.children[f.child_nb]
            if id(f.recurse_object) == id(w):  # deal with return from recursion
                v.low_link = min(v.low_link, w.low_link)
            elif w.index == -1:
                f.recurse_object = w
                call_stack.append(Tarjan.Frame1(w))  # enter recursion
                continue
            elif w.on_stack:
                v.low_link = min(v.low_link, w.index)
            f.child_nb += 1
        return


def calculate_sccs(vertices, iterative):  # Tarjan's algorithm
    calc = Tarjan(vertices)
    fn = calc.iterate if iterative else calc.recurse
    for v in calc.vertices:
        if v.index == -1:
            fn(v)
    return calc.sccs


def make_dag(vertices, sccs):  # O(V + E)  ~ kind of (remapping not counted, will deal with it if necessary)
    # merge vertices in each scc
    for scc in sccs:  # O(V)
        v = scc[0]  # target node (first node in scc)
        v.weight = len(scc)  # update the weight of the vertex
        v.children = [x for w in scc for x in w.children if v.low_link != x.low_link]
        for w in scc:
            if id(w) != id(v):
                w.target = v  # used for children remapping
                w.weight = 0  # indicates the vertex is not used anymore

    # remap children to the target node (if applicable)
    for v in vertices:  # O(V + E)
        if v.children:
            v.children = [w.target or w for w in v.children]
            v.children = list(dict((id(w), w) for w in v.children).values())  # remove duplicates (could be more efficient)
    return


def dag_max_len(vertices, iterative):  # O(V + E)

    @dataclass
    class Frame2:
        v: Vertex
        child_nb: int = 0
        max_len: int = 0
        curr_len: int = 0
        recurse_object: object = None

    def recurse(v):
        max_len = 0
        for w in v.children:
            if w.max_len == 0 and id(v) != id(w):
                curr_len = recurse(w)
            else:
                curr_len = w.max_len
            max_len = max(max_len, curr_len)
        v.max_len = v.weight + max_len
        return v.max_len

    def iterate(v):
        call_stack = [Frame2(v)]
        while call_stack:
            f = call_stack[-1]
            v = f.v
            #
            if f.child_nb >= len(v.children):
                v.max_len = v.weight + f.max_len
                call_stack.pop()
                if not call_stack:
                    return v.max_len
                call_stack[-1].curr_len = max(call_stack[-1].curr_len, v.max_len)
                continue
            w = v.children[f.child_nb]
            if id(f.recurse_object) == id(w):  # deal with return from recursion
                pass
            elif w.max_len == 0 and id(v) != id(w):
                f.recurse_object = w
                call_stack.append(Frame2(w))  # enter recursion
                continue
            else:
                f.curr_len = w.max_len
            f.max_len = max(f.max_len, f.curr_len)
            f.child_nb += 1
        return v.max_len

    # calculate the number of inputs for each vertex
    for v in vertices:  # O(V + E)
        if v.weight > 0:
            for w in v.children:
                if id(v) != id(w):
                    w.inputs += 1

    fn = iterate if iterative else recurse
    return max(fn(v) for v in vertices if v.weight and v.inputs == 0)


def getMaxVisitableWebpages(N: int, M: int, A: List[int], B: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=254501763097320
    # Constraints:
    #   2 ≤ N ≤ 500,000   N different web pages
    #   1 ≤ M ≤ 500,000   M links present across the pages
    #   1 ≤ Ai, Bi ≤ N    ith of which is present on page Ai and links to a different page Bi
    #   Ai ≠ Bi           a page cannot link to itself
    # Complexity: O(V + E*log(E))  because of call to keep_unique()

    iterative = False  # iterative SCC is too slow to pass tests (almost expected and sad)
    if not iterative:
        import sys
        sys.setrecursionlimit(500_010)

    A, B = A[:M], B[:M]  # Just in case
    edges = list(zip(A, B))  # O(E)
    edges = keep_unique(edges)  # O(E*log(E))
    vertices = build_children(edges)  # O(V + 2*E)
    sccs = calculate_sccs(vertices, iterative)  # O(V + E), calculate strongly connected components
    make_dag(vertices, sccs)  # O(V + E)
    res = dag_max_len(vertices, iterative)  # O(V + E)
    return res


def tests():
    def fn(A, B): return max(max(A), max(B)), len(A), A, B

    meta_cases = "meta", [
        (([1, 2, 3, 4], [4, 1, 2, 1], ), 4),
        (([3, 5, 3, 1, 3, 2], [2, 1, 2, 4, 5, 4], ), 4),
        (([3, 2, 5, 9, 10, 3, 3, 9, 4], [9, 5, 7, 8, 6, 4, 5, 3, 9], ), 5),
    ]
    extra1_cases = "extra1", [
        # test
        (([3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14],
          [9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  4,  4,  2], ), 8),
        (([3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 15, 15],
          [9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  9], ), 8),
        (([3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 13, 13, 13],
          [9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  5,  8], ), 8),
        (([1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6], [3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8], ), 4),
        (([1, 3, 2], [3, 2, 3], ), 3),
        (([2, 1], [1, 2], ), 2),
        (([3, 5, 3, 1, 3, 2], [2, 2, 2, 4, 5, 4], ), 4),
        (([3, 5, 3, 1, 3, 2], [2, 2, 5, 4, 5, 4], ), 4),  # 3 is referencing 5 twice
        (([3, 5, 3, 1, 3, 2], [2, 2, 3, 4, 5, 4], ), 4),  # 3 is self referencing
    ]
    return getMaxVisitableWebpages, fn, [meta_cases, extra1_cases]


# End
