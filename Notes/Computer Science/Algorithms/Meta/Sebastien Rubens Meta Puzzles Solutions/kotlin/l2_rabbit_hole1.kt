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

class Vertex(
    var _nb: Int,
    var inputs: UInt = 0U,
    var level: UInt = 1U,
    var in_cycle: Boolean = true,
    var cycle_len: UInt = 0U,
    var next: Vertex? = null, )

typealias ListVerticesT = ArrayList<Vertex>;

fun getMaxVisitableWebpages(N: Int, L: Array<Int>): Int {
    val vertices = ListVerticesT(N);
    for (i in 0 until N) {
        vertices.add(Vertex(i + 1));
    }

    // count the number of inputs for each vertex, and set next vertex: O(N)
    for (i in 0 until N) {
        val next_vertex = vertices[L[i] - 1];
        next_vertex.inputs += 1U;
        vertices[i].next = next_vertex;
    }

    // find the entrance vertices (could be []): O(N)
    val entrance_vertices = ListVerticesT(N);
    for (vertex in vertices) {
        if (vertex.inputs == 0U)
            entrance_vertices.add(vertex);
    }

    // calculate "level" of each vertex that is not in a cycle: O(N)
    while (!entrance_vertices.isEmpty()) {
        val curr_vertex = entrance_vertices.removeLast();
        curr_vertex.in_cycle = false;
        //
        val next_vertex = curr_vertex.next!!;
        next_vertex.level = maxOf(next_vertex.level, curr_vertex.level + 1U);
        next_vertex.inputs -= 1U;
        if (next_vertex.inputs == 0U)
            entrance_vertices.add(next_vertex);
    }

    // calculate length of cycles of the different cycle: O(N)
    for (vertex in vertices) {
        if (!vertex.in_cycle || vertex.cycle_len > 0U)
            continue;
        // count length of cycle
        var cycle_len = 1U;
        var curr = vertex.next!!;
        while (curr !== vertex) {
            cycle_len += 1U;
            curr = curr.next!!;
        }
        // assign length of cycle to vertices
        vertex.cycle_len = cycle_len;
        curr = vertex.next!!;
        while (curr !== vertex) {
            curr.cycle_len = cycle_len;
            curr = curr.next!!;
        }
    }

    // Now calculate the maximum length: O(N)
    var max_chain = 0U;
    for (vertex in vertices) {
        if (vertex.in_cycle) // Note: if the vertex is self-referencing, in_cycle will be true
            max_chain = maxOf(max_chain, vertex.cycle_len);
        else {
            val next_vertex = vertex.next!!;
            if (next_vertex.in_cycle)
                max_chain = maxOf(max_chain, vertex.level + next_vertex.cycle_len);
        }
    }
    return max_chain.toInt();
}

class Args(
    val L: Array<Int>,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getMaxVisitableWebpages(p.L.size, p.L) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(4, 1, 2, 1), 4 ),
        Args( arrayOf(4, 3, 5, 1, 2), 3 ),
        Args( arrayOf(2, 4, 2, 2, 3), 4 ),
        // extra1
        Args( arrayOf(1), 1 ),  // Link from page 1 to page 1 (not allowed)
        Args( arrayOf(1, 2), 1 ),  // Link from page 2 to page 2 (not allowed)
        Args( arrayOf(2, 1), 2 ),
        Args( arrayOf(3, 3, 4, 3), 3 ),
        Args( arrayOf(4, 5, 6, 5, 6, 4), 4 ),
        Args( arrayOf(6, 5, 4, 5, 6, 4), 4 ),
        Args( arrayOf(3, 3, 4, 1), 4 ),
        Args( arrayOf(2, 3, 2), 3 ),
        Args( arrayOf(2, 4, 2, 2, 3), 4 ),
        Args( arrayOf(6, 5, 4, 3, 2, 1), 2 ),
        // extra2
        Args( arrayOf(4, 1, 2, 1), 4 ),
        Args( arrayOf(4, 3, 5, 1, 2), 3 ),
        Args( arrayOf(4, 1, 2, 1), 4 ),
        Args( arrayOf(2, 1, 4, 3), 2 ),
        Args( arrayOf(2, 4, 2, 2, 4, 5), 4 ),
        Args( arrayOf(4, 1, 2, 1), 4 ),
        Args( arrayOf(4, 3, 5, 1, 2), 3 ),
        Args( arrayOf(2, 4, 2, 2, 4), 3 ),
        Args( arrayOf(2, 3, 4, 2, 2, 3, 6, 9, 8), 5 ),
        // extra3
        Args( arrayOf(2, 4, 2, 2, 3, 4, 8, 9, 10, 11, 12, 7), 6 ),
        Args( arrayOf(2, 4, 2, 2, 4, 5, 8, 9, 10, 11, 12, 7), 6 ),
    );

    return test.run_all_tests("l2_rabbit_hole1", args_list, wrapper);
}
