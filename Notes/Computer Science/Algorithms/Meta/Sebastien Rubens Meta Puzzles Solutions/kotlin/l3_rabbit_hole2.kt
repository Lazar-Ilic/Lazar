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

import java.util.LinkedList

typealias index_t = Int;
val index_not_set: index_t  = index_t.MAX_VALUE;

typealias ListVerticesT = ArrayList<Vertex>;

class Vertex(
    var nb: index_t = 0,
    var weight: index_t = 0,  // 0 means unused
    var children: ListVerticesT = ListVerticesT(),

    // members for strongly connected components
    var index: index_t = index_not_set,
    var low_link: index_t  = index_not_set,
    var on_stack: Boolean = false,

    // members for dag construction
    var target: Vertex? = null,

    // members for max length calculation
    var inputs: index_t  = 0,  // number of inputs for a given node
    var max_len: index_t = 0,  // used for memoization of max_len at node level
) : Comparable<Vertex> {
    override fun compareTo(other: Vertex) = compareValuesBy(this, other,
        { it.nb }
    )
}

data class Edge(
    var v: index_t,
    var w: index_t,
) : Comparable<Edge> {
    override fun compareTo(other: Edge) = compareValuesBy(this, other,
        { it.v },
        { it.w }
    )
}

fun <T: Comparable<T>> ArrayList<T>.unique(): Int {
    if (this.size <= 1)
        return this.size
    var last_elt = 0
    for (elt in this.slice(1 until this.size))
    {
        if (elt == this[last_elt])
            continue
        last_elt += 1
        this[last_elt] = elt
    }
    return last_elt + 1
}

fun <T: Comparable<T>> keep_unique(elements: ArrayList<T>): ArrayList<T>
{
    if (elements.size <= 1)
        return elements;
    elements.sort();
    val last = elements.unique();
    val ret = ArrayList<T>(elements.slice(0 until last));
    return ret
}

fun build_children(edges: ArrayList<Edge>): ListVerticesT
{
    // recalculate N as nb_vertices
    val max_elt = edges.maxByOrNull { maxOf(it.v, it.w) }!!;
    val nb_vertices = maxOf(max_elt.v, max_elt.w);
    //
    val vertices = ListVerticesT(nb_vertices.toInt() + 1);
    for (i in 0..nb_vertices)
        vertices.add(Vertex(i));
    for (edge in edges)
    {
        vertices[edge.v].children.add(vertices[edge.w]);
        vertices[edge.v].weight = 1;
        vertices[edge.w].weight = 1;
    }
    return vertices;
}

class Tarjan(var sccs: LinkedList<ListVerticesT> = LinkedList(),
             var stack: ListVerticesT = ListVerticesT(),
             var index: index_t = 0, )
{
    fun __init(v: Vertex)
    {
        v.index = index;
        v.low_link = index;
        v.on_stack = true;
        stack.add(v);
        ++index;
    }

    fun __end(v: Vertex)
    {
        val scc =  ListVerticesT();
        if (v.low_link == v.index)
        {
            while (true)
            {
                val w = stack.removeLast();
                w.low_link = v.low_link;
                w.on_stack = false;
                scc.add(w);
                if (w === v)
                    break;
            };
        }
        if (scc.size > 1)
            sccs.add(scc);
    }

    fun recurse(v: Vertex)
    {
        __init(v);  // set up Vertex in scc discovery
        // Go through all children of this Vertex
        for (w in v.children)
        {
            if (w.index == index_not_set)
            {
                recurse(w);
                v.low_link = minOf(v.low_link, w.low_link);
            }
            else if (w.on_stack)
                v.low_link = minOf(v.low_link, w.index);
        }
        __end(v);  // found scc
    }
};

fun calculate_sccs(vertices: ListVerticesT): LinkedList<ListVerticesT>
{
    val calc = Tarjan();
    for (v in vertices)
        if (v.index == index_not_set)
            calc.recurse(v);
    return calc.sccs;
}

fun make_dag(vertices: ListVerticesT, sccs: LinkedList<ListVerticesT>)
{
    // merge vertices in each scc
    for (scc in sccs)  // O(V)
    {
        val v = scc[0];  // target node (first node in scc)
        v.weight = scc.size;  // update the weight of the Vertex
        val children = ListVerticesT();  // note: no reserve() here
        for (w in scc)
            for (x in w.children)
                if (v.low_link != x.low_link)
                    children.add(x);
        v.children = children;
        for (w in scc)
            if (w !== v)
            {
                w.target = v;  // used for children remapping
                w.weight = 0;  // indicates the Vertex is not used anymore
            }
    }
    // remap children to the target node (if applicable)
    for (v in vertices)
        if (!v.children.isEmpty())
        {
            val children = ListVerticesT(v.children.size);
            for (w in v.children)
                children.add(w.target ?: w);
            // remove duplicates
            v.children = keep_unique(children);
        }
}

fun dag_max_len_recurse(v: Vertex): index_t
{
    var max_len: index_t  = 0;
    for (w in v.children)
    {
        var curr_len: index_t  = 0;
        if (w.max_len == 0 && v !== w)  // avoid self referencing
            curr_len = dag_max_len_recurse(w);
        else
            curr_len = w.max_len;
        max_len = maxOf(max_len, curr_len);
    }
    v.max_len = v.weight + max_len;
    return v.max_len;
}

fun dag_max_len(vertices: ListVerticesT): index_t
{
    for (v in vertices)
        if (v.weight > 0)
            for (w in v.children)
                if (v !== w)  // avoid self referencing
                    ++w.inputs;
    var ret: index_t = 0;
    for (v in vertices)
        if (v.weight > 0 && v.inputs == 0)
            ret = maxOf(ret, dag_max_len_recurse(v));
    return ret;
}

fun getMaxVisitableWebpages(N: Int, M: Int, A: Array<Int>, B: Array<Int>): Int {
    // just in case
    if (A.isEmpty() || B.isEmpty())
        return 0;

    // calculate edges
    var edges = ArrayList<Edge>(M);
    for (i in 0 until M)  // O(E)
        edges.add(Edge( A[i], B[i] ));
    //
    edges = keep_unique(edges);  // O(E * log(E))
    val vertices = build_children(edges);  // O(V + 2*E)
    val sccs = calculate_sccs(vertices);  // O(V + E), calculate strongly connected components
    make_dag(vertices, sccs);  // O(V + E)
    val res = dag_max_len(vertices);  // O(V + E)
    return res;
}

class Args(
    val A: Array<Int>,
    val B: Array<Int>,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun _getMaxVisitableWebpagesTest(A: Array<Int>, B: Array<Int>): Int {
    val max_elt_a = A.maxOrNull()!!;
    val max_elt_b = B.maxOrNull()!!;
    val max_len = maxOf(max_elt_a, max_elt_b);
    return getMaxVisitableWebpages(max_len, A.size, A, B);
}

fun tests(): UInt
{
    val wrapper = { p: Args -> _getMaxVisitableWebpagesTest(p.A, p.B) };

    val args_list: List<Args> = listOf(
        Args( arrayOf(1, 2, 3, 4), arrayOf(4, 1, 2, 1), 4 ),
        Args( arrayOf(3, 5, 3, 1, 3, 2), arrayOf(2, 1, 2, 4, 5, 4), 4 ),
        Args( arrayOf(3, 2, 5, 9, 10, 3, 3, 9, 4), arrayOf(9, 5, 7, 8, 6, 4, 5, 3, 9), 5 ),
        // extra1
        Args( arrayOf(3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14    ), arrayOf(9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  4,  4,  2    ), 8 ),
        Args( arrayOf(3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 15, 15    ), arrayOf(9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  9    ), 8 ),
        Args( arrayOf(3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 13, 13, 13), arrayOf(9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  5,  8), 8 ),
        Args( arrayOf(1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6), arrayOf(3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8), 4 ),
        Args( arrayOf(1, 3, 2), arrayOf(3, 2, 3), 3 ),
        Args( arrayOf(2, 1), arrayOf(1, 2), 2 ),
        Args( arrayOf(3, 5, 3, 1, 3, 2), arrayOf(2, 2, 2, 4, 5, 4), 4 ),
        Args( arrayOf(3, 5, 3, 1, 3, 2), arrayOf(2, 2, 5, 4, 5, 4), 4 ),  // 3 is referencing twice 5
        Args( arrayOf(3, 5, 3, 1, 3, 2), arrayOf(2, 2, 3, 4, 5, 4), 4 ),  // 3 is self referencing
    );

    return test.run_all_tests("l3_rabbit_hole2", args_list, wrapper);
}
