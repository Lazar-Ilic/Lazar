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

package l2_rabbit_hole1

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
)

type ListVertices_t = [](*Vertex)

type Vertex struct {
	nb        uint32
	inputs    uint32
	level     uint32
	in_cycle  bool
	cycle_len uint32
	next      *Vertex
}

func getMaxVisitableWebpages(N int32, L []int32) int32 {
	// Note: as a vertex is always followed by 1 vertex, we always end up in a cycle
	vertices := make(ListVertices_t, 0, N)
	for i := uint32(0); i < uint32(N); i += 1 {
		vertices = append(vertices, &Vertex{i + 1, 0, 1, true, 0, nil})
	}

	// count the number of inputs for each vertex, and set next vertex: O(N)
	for i := uint32(0); i < uint32(N); i += 1 {
		next_vertex := vertices[L[i]-1]
		next_vertex.inputs += 1
		vertex := vertices[i]
		vertex.next = next_vertex // yes, we could use indices or raw pointers (as "vertices" is never resized)
	}

	// find the entrance vertices (could be []): O(N)
	entrance_vertices := make(ListVertices_t, 0, len(vertices))
	for _, vertex := range vertices {
		if vertex.inputs == 0 {
			entrance_vertices = append(entrance_vertices, vertex)
		}
	}

	// calculate "level" of each vertex that is not in a cycle: O(N)
	for len(entrance_vertices) > 0 {
		last_index := len(entrance_vertices) - 1
		curr_vertex := entrance_vertices[last_index]
		curr_vertex.in_cycle = false
		entrance_vertices = entrance_vertices[:last_index]
		next_vertex := curr_vertex.next
		next_vertex.level = std.Max(next_vertex.level, curr_vertex.level+1)
		next_vertex.inputs -= 1
		if next_vertex.inputs == 0 {
			entrance_vertices = append(entrance_vertices, next_vertex)
		}
	}

	// calculate length of cycles of the different cycle: O(N)
	for _, vertex := range vertices {
		if !vertex.in_cycle || vertex.cycle_len > 0 {
			continue
		}
		// count length of cycle
		cycle_len := uint32(1)
		curr := vertex.next
		for curr != vertex {
			cycle_len += 1
			curr = curr.next
		}
		// assign length of cycle to vertices
		vertex.cycle_len = cycle_len
		curr = vertex.next
		for curr != vertex {
			curr.cycle_len = cycle_len
			curr = curr.next
		}
	}

	// Now calculate the maximum length: O(N)
	max_chain := uint32(0)
	for _, vertex := range vertices {
		if vertex.in_cycle {
			max_chain = std.Max(max_chain, vertex.cycle_len)
		} else if vertex.next.in_cycle {
			max_chain = std.Max(max_chain, vertex.level+vertex.next.cycle_len)
		}
	}
	return int32(max_chain)
}

type Args struct {
	L   []int32
	res int32
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int32 { return getMaxVisitableWebpages(int32(len(p.L)), p.L) }

	args_lists := []Args{
		{[]int32{4, 1, 2, 1}, 4},
		{[]int32{4, 3, 5, 1, 2}, 3},
		{[]int32{2, 4, 2, 2, 3}, 4},
		// extra1
		{[]int32{1}, 1},
		{[]int32{1, 2}, 1},
		{[]int32{2, 1}, 2},
		{[]int32{3, 3, 4, 3}, 3},
		{[]int32{4, 5, 6, 5, 6, 4}, 4},
		{[]int32{6, 5, 4, 5, 6, 4}, 4},
		{[]int32{3, 3, 4, 1}, 4},
		{[]int32{2, 3, 2}, 3},
		{[]int32{2, 4, 2, 2, 3}, 4},
		{[]int32{6, 5, 4, 3, 2, 1}, 2},
		// extra2
		{[]int32{4, 1, 2, 1}, 4},
		{[]int32{4, 3, 5, 1, 2}, 3},
		{[]int32{4, 1, 2, 1}, 4},
		{[]int32{2, 1, 4, 3}, 2},
		{[]int32{2, 4, 2, 2, 4, 5}, 4},
		{[]int32{4, 1, 2, 1}, 4},
		{[]int32{4, 3, 5, 1, 2}, 3},
		{[]int32{2, 4, 2, 2, 4}, 3},
		{[]int32{2, 3, 4, 2, 2, 3, 6, 9, 8}, 5},
		// extra3
		{[]int32{2, 4, 2, 2, 3, 4, 8, 9, 10, 11, 12, 7}, 6},
		{[]int32{2, 4, 2, 2, 4, 5, 8, 9, 10, 11, 12, 7}, 6},
	}

	return test.RunAllTests("l2_rabbit_hole1", args_lists, wrapper)
}
