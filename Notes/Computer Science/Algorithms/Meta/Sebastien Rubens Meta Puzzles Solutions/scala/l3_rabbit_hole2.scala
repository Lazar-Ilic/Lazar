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

import scala.collection.mutable.ArrayBuffer
import scala.math.Ordered.orderingToOrdered
import scala.util.control.Breaks._

object Solution {
    def getMaxVisitableWebpages(N: Int, M: Int, A: Array[Int], B: Array[Int]): Int = {
        type index_t = Int
        val index_not_set: index_t = Int.MaxValue

        type ListVerticesT = ArrayBuffer[Vertex]

        class Vertex(
                      var nb: index_t = 0,
                      var weight: index_t = 0,  // 0 means unused
                      var children: ListVerticesT = ArrayBuffer[Vertex](),

                      // members for strongly connected components
                      var index: index_t = index_not_set,
                      var low_link: index_t  = index_not_set,
                      var on_stack: Boolean = false,

                      // members for dag construction
                      var target: Option[Vertex] = Option.empty,

                      // members for max length calculation
                      var inputs: index_t  = 0,  // number of inputs for a given node
                      var max_len: index_t = 0  // used for memoization of max_len at node level
                    ) extends Ordered[Vertex] {
            def compare(that: Vertex): Int = this.nb compare that.nb
        }

        class Edge(var v: index_t = 0,
                   var w: index_t = 0) extends Ordered[Edge] {
            def compare(that: Edge): Int = (this.v, this.w) compare (that.v, that.w)
        }

        def std_unique[T: Ordering](elements: ArrayBuffer[T]): Int =
        {
            if (elements.size <= 1)
                return elements.size
            var last_elt = 0
            for (elt_idx <- 1 until elements.size)
            {
                val elt = elements(elt_idx)
                //if (!elt.equals(elements(last_elt)))  //comparing values of types T and T using `equals` unsafely bypasses cooperative equality; use `==` instead
                if (elt != elements(last_elt))  //comparing values of types T and T using `equals` unsafely bypasses cooperative equality; use `==` instead
                {
                    last_elt += 1
                    elements(last_elt) = elt
                }
            }
            return last_elt + 1
        }

        def keep_unique[T: Ordering](elements: ArrayBuffer[T]): ArrayBuffer[T] =
        {
            if (elements.size <= 1)
                return elements
            //elements.sortInPlace()
            val elements2 = elements.sorted
            val last = std_unique(elements2);
            val ret = elements2.slice(0, last);
            return ret
        }

        def build_children(edges: ArrayBuffer[Edge]): ListVerticesT =
        {
            // recalculate N as nb_vertices
            val max_elt = edges.maxBy(it => it.v.max(it.w))
            val nb_vertices = max_elt.v.max(max_elt.w)
            //
            val vertices = new ListVerticesT(nb_vertices.toInt + 1)
            for (i <- 0 to nb_vertices)
                vertices += new Vertex(i)
            for (edge <- edges)
            {
                vertices(edge.v).children += vertices(edge.w)
                vertices(edge.v).weight = 1
                vertices(edge.w).weight = 1
            }
            return vertices
        }

        class Tarjan(var sccs: ArrayBuffer[ListVerticesT] = new ArrayBuffer[ListVerticesT](),
                     var stack: ListVerticesT = new ListVerticesT(),
                     var index: index_t = 0)
        {
            def __init(v: Vertex) =
            {
                v.index = index
                v.low_link = index
                v.on_stack = true
                stack += v
                index += 1
            }

            def __end(v: Vertex) =
            {
                val scc = new ListVerticesT()
                if (v.low_link == v.index) {
                    breakable {
                    while (true) {
                        val w = stack.last
                        //stack.dropRightInPlace(1)  // does not work in Meta's website
                        stack = stack.dropRight(1)
                        w.low_link = v.low_link
                        w.on_stack = false
                        scc += w
                        if (w eq v)
                            break
                    }
                    }
                }
                if (scc.size > 1)
                    sccs += scc
            }

            def recurse(v: Vertex): Unit =
            {
                __init(v) // set up Vertex in scc discovery
                // Go through all children of this Vertex
                for (w <- v.children) {
                    if (w.index == index_not_set) {
                        recurse(w)
                        v.low_link = v.low_link.min(w.low_link)
                    }
                    else if (w.on_stack)
                        v.low_link = v.low_link.min(w.index)
                }
                __end(v) // found scc
            }
        }

        def calculate_sccs(vertices: ListVerticesT): ArrayBuffer[ListVerticesT] =
        {
            val calc = new Tarjan()
            for (v <- vertices)
                if (v.index == index_not_set)
                    calc.recurse (v)
            return calc.sccs
        }

        def make_dag(vertices: ListVerticesT, sccs: ArrayBuffer[ListVerticesT]) = {
            // merge vertices in each scc
            for (scc <- sccs) // O(V)
            {
                val v: Vertex = scc(0) // target node (first node in scc)
                v.weight = scc.size // update the weight of the Vertex
                val children = new ListVerticesT() // note: no reserve() here
                for (w <- scc)
                    for (x <- w.children)
                        if (v.low_link != x.low_link)
                            children += x
                v.children = children
                for (w <- scc)
                    if (w ne v) {
                        w.target = Option(v) // used for children remapping
                        w.weight = 0 // indicates the Vertex is not used anymore
                    }
            }
            // remap children to the target node (if applicable)
            for (v <- vertices)
                if (v.children.nonEmpty) {
                    val children = new ListVerticesT(v.children.size)
                    for (w <- v.children)
                        children += w.target.getOrElse(w)
                    // remove duplicates
                    v.children = keep_unique(children)
                }
        }

        def dag_max_len_recurse(v: Vertex): index_t = {
            var max_len: index_t = 0
            for (w <- v.children)
            {
                var curr_len: index_t = 0
                if ((w.max_len == 0) && (v ne w)) // avoid self referencing
                    curr_len = dag_max_len_recurse(w)
                else
                    curr_len = w.max_len
                max_len = max_len.max(curr_len)
            }
            v.max_len = v.weight + max_len
            return v.max_len
        }

        def dag_max_len(vertices: ListVerticesT): index_t =
        {
            for (v <- vertices)
                if (v.weight > 0)
                    for (w <- v.children)
                        if (v ne w) // avoid self referencing
                            w.inputs += 1
            var ret: index_t = 0
            for (v <- vertices)
                if (v.weight > 0 && v.inputs == 0)
                    ret = ret.max(dag_max_len_recurse(v))
            return ret
        }

        // just in case
        if (A.isEmpty || B.isEmpty)
            return 0

        // calculate edges
        var edges = new ArrayBuffer[Edge](M)
        for (i <- 0 until M)  // O(E)
            edges += new Edge( A(i), B(i) )
        //
        edges = keep_unique(edges)  // O(E * log(E))
        val vertices = build_children(edges)  // O(V + 2*E)
        val sccs = calculate_sccs(vertices)  // O(V + E), calculate strongly connected components
        make_dag(vertices, sccs)  // O(V + E)
        val res = dag_max_len(vertices)  // O(V + E)
        return res
    }


    class Args(val A: Array[Int],
               val B: Array[Int],
               val res: Int ) extends test.Result[Int] {
        override def get_result(): Int = res
    }

    def _getMaxVisitableWebpagesTest(A: Array[Int], B: Array[Int]): Int = {
        val max_len = A.max.max(B.max)
        return getMaxVisitableWebpages (max_len, A.size, A, B)
    }

    def tests(): Int =
    {
        val wrapper = (p: Args) => _getMaxVisitableWebpagesTest(p.A, p.B)

        val args_list = Array[Args](
            new Args(Array[Int](1, 2, 3, 4), Array[Int](4, 1, 2, 1), 4),
            new Args(Array[Int](3, 5, 3, 1, 3, 2), Array[Int](2, 1, 2, 4, 5, 4), 4),
            new Args(Array[Int](3, 2, 5, 9, 10, 3, 3, 9, 4), Array[Int](9, 5, 7, 8, 6, 4, 5, 3, 9), 5),
            // extra1
            new Args(Array[Int](3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 13, 14, 14), Array[Int](9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 4, 4, 2), 8),
            new Args(Array[Int](3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 14, 15, 15), Array[Int](9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 2, 4, 9), 8),
            new Args(Array[Int](3, 2, 5, 9, 10, 3, 3, 9, 4, 9, 11, 12, 14, 13, 13, 13), Array[Int](9, 5, 7, 8, 6, 4, 5, 3, 9, 11, 12, 9, 2, 4, 5, 8), 8),
            new Args(Array[Int](1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6), Array[Int](3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8), 4),
            new Args(Array[Int](1, 3, 2), Array[Int](3, 2, 3), 3),
            new Args(Array[Int](2, 1), Array[Int](1, 2), 2),
            new Args(Array[Int](3, 5, 3, 1, 3, 2), Array[Int](2, 2, 2, 4, 5, 4), 4),
            new Args(Array[Int](3, 5, 3, 1, 3, 2), Array[Int](2, 2, 5, 4, 5, 4), 4), // 3 is referencing twice 5
            new Args(Array[Int](3, 5, 3, 1, 3, 2), Array[Int](2, 2, 3, 4, 5, 4), 4), // 3 is self referencing
            //
        )

        return test.TestAll.run_all_tests("l3_rabbit_hole2", args_list, wrapper)
    }
}
