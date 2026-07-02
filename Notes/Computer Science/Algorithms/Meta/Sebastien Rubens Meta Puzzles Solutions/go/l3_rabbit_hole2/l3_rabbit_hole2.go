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

package l3_rabbit_hole2

import (
	"math"
	"meta_puzzles/std"
	"meta_puzzles/test"
	"sort"
)

type index_t = uint32
type VertexPtr_t = *Vertex
type ListVertices_t = []VertexPtr_t

const index_not_set = math.MaxUint32

type Vertex struct {
	nb       index_t
	weight   index_t // 0 means unused
	children ListVertices_t

	// members for strongly connected components
	index    index_t
	low_link index_t
	on_stack bool

	// members for dag construction
	target VertexPtr_t

	// members for max length calculation
	inputs  index_t // number of inputs for a given node
	max_len index_t // used for memoization of max_len at node level
}

type Edge struct {
	v index_t
	w index_t
}

func (self *Edge) Less(rhs Edge) bool {
	if self.v < rhs.v {
		return true
	} else if self.v > rhs.v {
		return false
	}
	return self.w < rhs.w
}

func DefaultVertex(nb index_t) Vertex {
	v := Vertex{}
	v.nb = nb
	v.weight = 0 // 0 means unused
	v.children = ListVertices_t{}

	// members for strongly connected components
	v.index = index_not_set
	v.low_link = index_not_set
	v.on_stack = false

	// members for dag construction
	v.target = nil

	// members for max length calculation
	v.inputs = 0  // number of inputs for a given node
	v.max_len = 0 // used for memoization of max_len at node level
	return v
}

func keep_unique(edges []Edge) []Edge {
	if len(edges) <= 1 {
		return edges
	}
	sort.Slice(edges, func(i, j int) bool { return edges[i].Less(edges[j]) })
	fn := func(lhs, rhs Edge) bool { return lhs.v == rhs.v && lhs.w == rhs.w }
	edges = edges[0 : std.UniquePred(edges, fn)]
	return edges
}

func build_children(edges []Edge) ListVertices_t {
	// recalculate N as nb_vertices
	max_fn := func(e1 Edge, e2 Edge) bool { return std.Max(e1.v, e1.w) > std.Max(e2.v, e2.w) }
	max_elt_it := std.MaxMinElement(edges, max_fn)
	nb_vertices := std.Max(max_elt_it.v, max_elt_it.w)
	//
	vertices := make(ListVertices_t, 0, nb_vertices+1)
	for i := index_t(0); i < nb_vertices+1; i += 1 {
		v := DefaultVertex(i)
		vertices = append(vertices, &v)
	}
	for _, edge := range edges {
		vertices[edge.v].children = append(vertices[edge.v].children, vertices[edge.w])
		vertices[edge.v].weight = 1
		vertices[edge.w].weight = 1
	}
	return vertices
}

type Tarjan struct {
	sccs  []ListVertices_t
	stack ListVertices_t
	index index_t
}

func (self *Tarjan) init(v VertexPtr_t) {
	v.index = self.index
	v.low_link = self.index
	v.on_stack = true
	self.stack = append(self.stack, v)
	self.index += 1
}

func (self *Tarjan) end(v VertexPtr_t) {
	scc := make(ListVertices_t, 0)
	if v.low_link == v.index {
		for {
			w := self.stack[len(self.stack)-1]
			self.stack = self.stack[:len(self.stack)-1]
			w.low_link = v.low_link
			w.on_stack = false
			scc = append(scc, w)
			if w == v {
				break
			}
		}
	}
	if len(scc) > 1 {
		self.sccs = append(self.sccs, scc)
	}
}

func (self *Tarjan) recurse(v VertexPtr_t) {
	self.init(v) // set up Vertex in scc discovery
	// Go through all children of this Vertex
	for _, w := range v.children {
		if w.index == index_not_set {
			self.recurse(w)
			v.low_link = std.Min(v.low_link, w.low_link)
		} else if w.on_stack {
			v.low_link = std.Min(v.low_link, w.index)
		}
	}
	self.end(v) // found scc
}

func calculate_sccs(vertices ListVertices_t) []ListVertices_t {
	calc := Tarjan{make([]ListVertices_t, 0), make(ListVertices_t, 0), 0}
	for _, v := range vertices {
		if v.index == index_not_set {
			calc.recurse(v)
		}
	}
	return calc.sccs
}

func make_dag(vertices ListVertices_t, sccs []ListVertices_t) {
	// merge vertices in each scc
	for _, scc := range sccs { // O(V)
		v := scc[0]                         // target node (first node in scc)
		v.weight = index_t(len(scc))        // update the weight of the Vertex
		children := make(ListVertices_t, 0) // note: no reserve() here
		for _, w := range scc {
			for _, x := range w.children {
				if v.low_link != x.low_link {
					children = append(children, x)
				}
			}
		}
		v.children = children
		for _, w := range scc {
			if w != v {
				w.target = v // used for children remapping
				w.weight = 0 // indicates the Vertex is not used anymore
			}
		}
	}
	// remap children to the target node (if applicable)
	for _, v := range vertices {
		if len(v.children) > 0 {
			children := make(ListVertices_t, 0, len(v.children))
			for _, w := range v.children {
				tmp := w
				if w.target != nil {
					tmp = w.target
				}
				children = append(children, tmp)
			}
			// remove duplicates
			fn1 := func(i, j int) bool { return children[i].nb < children[j].nb }
			sort.Slice(children, fn1)
			fn2 := func(lhs, rhs *Vertex) bool { return lhs.nb == rhs.nb }
			children = children[0 : std.UniquePred(children, fn2)]
			v.children = children
		}
	}
}

func dag_max_len_recurse(v VertexPtr_t) index_t {
	max_len := index_t(0)
	for _, w := range v.children {
		curr_len := index_t(0)
		if w.max_len == 0 && v != w { // avoid self referencing
			curr_len = dag_max_len_recurse(w)
		} else {
			curr_len = w.max_len
		}
		max_len = std.Max(max_len, curr_len)
	}
	v.max_len = v.weight + max_len
	return v.max_len
}

func dag_max_len(vertices ListVertices_t) index_t {
	for _, v := range vertices {
		if v.weight > 0 {
			for _, w := range v.children {
				if v != w { // avoid self referencing
					w.inputs += 1
				}
			}
		}
	}
	ret := index_t(0)
	for _, v := range vertices {
		if v.weight > 0 && v.inputs == 0 {
			ret = std.Max(ret, dag_max_len_recurse(v))
		}
	}
	return ret
}

func getMaxVisitableWebpages(N int32, M int32, A []int32, B []int32) int32 {
	// just in case
	if len(A) == 0 || len(B) == 0 {
		return 0 // Write your code here
	}

	// calculate edges
	edges := make([]Edge, 0, M)
	for i := int32(0); i < M; i += 1 { // O(E)
		edges = append(edges, Edge{index_t(A[i]), index_t(B[i])})
	}

	//
	edges = keep_unique(edges)        // O(E * log(E))
	vertices := build_children(edges) // O(V + 2*E)
	sccs := calculate_sccs(vertices)  // O(V + E), calculate strongly connected components
	make_dag(vertices, sccs)          // O(V + E)
	res := dag_max_len(vertices)      // O(V + E)
	return int32(res)
}

type Args struct {
	A   []int32
	B   []int32
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 {
		max_len := std.Max(*std.MaxElement(p.A), *std.MaxElement(p.B))
		return getMaxVisitableWebpages(max_len, int32(len(p.A)), p.A, p.B)
	}

	args_lists := []Args{
		{[]int32{1, 2, 3, 4}, []int32{4, 1, 2, 1}, 4},
		{[]int32{3, 5, 3, 1, 3, 2}, []int32{2, 1, 2, 4, 5, 4}, 4},
		{[]int32{3, 2, 5, 9, 10, 3, 3, 9, 4}, []int32{9, 5, 7, 8, 6, 4, 5, 3, 9}, 5},
		// extra1
		{[]int32{3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 13, 14, 14}, []int32{9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 4, 4, 2}, 8},
		{[]int32{3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 14, 15, 15}, []int32{9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 2, 4, 9}, 8},
		{[]int32{3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 14, 13, 13, 13}, []int32{9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 2, 4, 5, 8}, 8},
		{[]int32{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6}, []int32{3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8}, 4},
		{[]int32{1, 3, 2}, []int32{3, 2, 3}, 3},
		{[]int32{2, 1}, []int32{1, 2}, 2},
		{[]int32{3, 5, 3, 1, 3, 2}, []int32{2, 2, 2, 4, 5, 4}, 4},
		{[]int32{3, 5, 3, 1, 3, 2}, []int32{2, 2, 5, 4, 5, 4}, 4}, // 3 is referencing 5 twice
		{[]int32{3, 5, 3, 1, 3, 2}, []int32{2, 2, 3, 4, 5, 4}, 4}, // 3 is self referencing
	}

	return test.RunAllTests("l3_rabbit_hole2", args_lists, wrapper)
}
