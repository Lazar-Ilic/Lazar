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

import scala.collection.mutable.ArrayBuffer
import scala.util.control.Breaks._
import util.Properties.versionNumberString

class Vertex(var _nb: Int,
             var inputs: Int = 0,
             var level: Int = 1,
             var in_cycle: Boolean = true,
             var cycle_len: Int = 0,
             var next: Option[Vertex] = null ) {
}

object Solution {
    def  getMaxVisitableWebpages(N: Int, L: Array[Int]): Int = {
        val vertices = new ArrayBuffer[Vertex](N)
        for (i <- 0 until N)
            vertices += new Vertex(i + 1)

        // count the number of inputs for each vertex, and set next vertex: O(N)
        for (i <- 0 until N) {
            val next_vertex = vertices(L(i)- 1)
            next_vertex.inputs += 1
            vertices(i).next = Option(next_vertex)
        }

        // find the entrance vertices (could be []): O(N)
        val entrance_vertices = new ArrayBuffer[Vertex](N)
        for (vertex <- vertices) {
            if (vertex.inputs == 0)
                entrance_vertices += vertex
        }

        // calculate "level" of each vertex that is not in a cycle: O(N)
        while (!entrance_vertices.isEmpty) {
            //val curr_vertex = entrance_vertices.removeLast()
            val curr_vertex = entrance_vertices.last
            //entrance_vertices.trimEnd(1) // FIXME: must use this on Meta's website
            entrance_vertices.dropRightInPlace(1)  // FIXME: >= 2.13.1 (does not work on Meta's website)
            curr_vertex.in_cycle = false
            //
            //val next_vertex = curr_vertex.next!!
            val next_vertex = curr_vertex.next.get
            next_vertex.level = next_vertex.level.max(curr_vertex.level + 1)
            next_vertex.inputs -= 1
            if (next_vertex.inputs == 0)
                entrance_vertices += next_vertex
        }

        // calculate length of cycles of the different cycle: O(N)
        for (vertex <- vertices) {
            breakable {
                if (!vertex.in_cycle || vertex.cycle_len > 0)
                    break
                // count length of cycle
                var cycle_len = 1
                var curr = vertex.next.get
                while (curr ne vertex) {
                    cycle_len += 1
                    curr = curr.next.get
                }
                // assign length of cycle to vertices
                vertex.cycle_len = cycle_len
                curr = vertex.next.get
                while (curr ne vertex) {
                    curr.cycle_len = cycle_len
                    curr = curr.next.get
                }
            }
        }

        // Now calculate the maximum length: O(N)
        var max_chain = 0
        for (vertex <- vertices) {
          if (vertex.in_cycle) // Note: if the vertex is self-referencing, in_cycle will be true
            max_chain = max_chain.max(vertex.cycle_len)
          else {
            val next_vertex = vertex.next.get
            if (next_vertex.in_cycle)
              max_chain = max_chain.max(vertex.level + next_vertex.cycle_len)
          }
        }
        return max_chain.toInt
    }


    class Args(val L: Array[Int],
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => getMaxVisitableWebpages(p.L.size, p.L)

        val args_list = Array[Args](
            new Args(Array[Int](4, 1, 2, 1), 4),
            new Args(Array[Int](4, 3, 5, 1, 2), 3),
            new Args(Array[Int](2, 4, 2, 2, 3), 4)
        )

        return test.TestAll.run_all_tests("l2_rabbit_hole1", args_list, wrapper)
    }
}
