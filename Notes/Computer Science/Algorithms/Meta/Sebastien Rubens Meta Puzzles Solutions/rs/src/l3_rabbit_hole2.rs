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

#![allow(non_snake_case)]

use std::cmp;
use std::rc::Rc;
use std::cell::RefCell;
use std::hash::{Hash, Hasher};

type IndexT = usize;
type VertexSP = Rc<RefCell<Vertex>>;
type ListVerticesT = Vec<VertexSP>;

const INDEX_NOT_SET: IndexT = IndexT::MAX;

#[derive(Clone, Eq)]
struct Vertex {
    nb: IndexT,
    weight: IndexT,  // 0 means unused
    children: ListVerticesT,

    // members for strongly connected components
    index: IndexT,
    low_link: IndexT,
    on_stack: bool,

    // members for dag construction
    target: Option<VertexSP>,

    // members for max length calculation
    inputs: IndexT,  // number of inputs for a given node
    max_len: IndexT,  // used for memoization of max_len at node level
}

impl Vertex {
    fn new(_nb: IndexT) -> Vertex {
        Vertex{nb: _nb, weight: 0, children: Vec::<VertexSP>::new(),
                index: INDEX_NOT_SET, low_link: INDEX_NOT_SET, on_stack: false,
                target: Option::<VertexSP>::None,
                inputs: 0, max_len: 0}
    }
}

impl PartialEq for Vertex {
    fn eq(&self, other: &Self) -> bool {
        self.nb == other.nb
    }
}

impl Ord for Vertex {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        if self.nb < other.nb {
            return std::cmp::Ordering::Less;
        }
        else if self.nb > other.nb {
            return std::cmp::Ordering::Greater;
        }
        return  std::cmp::Ordering::Equal;
    }
}

impl PartialOrd for Vertex {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl std::fmt::Debug for Vertex {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        let mut children: Vec<IndexT> = vec![];
        for c in &self.children {
            children.push(c.as_ref().borrow().nb)
        }
        let mut target = 0;
        if self.target.is_some() {
            target = self.target.as_ref().unwrap().borrow().nb;
        }
        return write!(f, "Vertex{{ nb: {}, weight: {}, index: {}, low_link: {}, on_stack: {}, target: {}, inputs: {}, max_len: {}, children: {:?} }}",
            self.nb, self.weight, self.index, self.low_link, self.on_stack, target, self.inputs, self.max_len, children);
    }
}

#[derive(Copy, Clone, Eq)]
struct Edge
{
    v: IndexT,
    w: IndexT,
}

impl Ord for Edge {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        if self.v < other.v {
            return std::cmp::Ordering::Less;
        }
        else if self.v > other.v {
            return std::cmp::Ordering::Greater;
        }
        if self.w < other.w {
            return std::cmp::Ordering::Less;
        }
        else if self.w > other.w {
            return std::cmp::Ordering::Greater;
        }
        return  std::cmp::Ordering::Equal;
    }
}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Edge {
    fn eq(&self, other: &Self) -> bool {
        return self.v == other.v && self.w == other.w;
    }
}

impl Hash for Edge {
    fn hash<H: Hasher>(&self, state: &mut H) {
        self.v.hash(state);
        self.w.hash(state);
    }
}

fn keep_unique<T>(elements: &mut Vec<T>) where T: PartialEq + std::cmp::Ord {
    if elements.len() <= 1 {
        return
    }
    elements.sort();
    elements.dedup();
}

fn build_children(edges: &Vec<Edge>) -> ListVerticesT {
    // recalculate N as nb_vertices
    let max_elt = *edges.iter().max_by_key(|&x| cmp::max(x.v, x.w)).unwrap_or(&Edge{v: 0, w: 0});
    let nb_vertices = cmp::max(max_elt.v, max_elt.w);

    //
    let mut vertices = ListVerticesT::with_capacity(nb_vertices + 1);
    for i in 0..nb_vertices + 1 {
        vertices.push(Rc::new(RefCell::new(Vertex::new(i as IndexT))));
    }
    for edge in edges {
        let w = &vertices[edge.w];
        let mut _v = vertices[edge.v].borrow_mut();
        _v.weight = 1;
        if vertices[edge.v].as_ptr() == w.as_ptr() { // avoid self referencing
            continue;
        }
        let mut _w = w.borrow_mut();
        _v.children.push(w.clone());
        _w.weight = 1;
    }
    return vertices;
}

struct Tarjan {
    sccs: Vec<ListVerticesT>,
    stack: ListVerticesT,
    index: IndexT,
}

impl Tarjan {
    fn new() -> Tarjan {
        Tarjan{sccs: Vec::<ListVerticesT>::default(), stack: ListVerticesT::default(), index: 0}
    }

    fn __init(&mut self, v: &VertexSP) {
        let mut _v = v.borrow_mut();
        _v.index = self.index;
        _v.low_link = self.index;
        _v.on_stack = true;
        drop(_v);  // because we used a temporary, we need to drop it, otherwise we are pushing a borrowed v to the stack
        self.stack.push(v.clone());
        self.index += 1;
    }

    fn __end(&mut self, v: &VertexSP) {
        let mut scc = ListVerticesT::new();
        let _v = v.as_ref().borrow();
        let low_link = _v.low_link;
        let index = _v.index;
        drop(_v);
        if low_link == index {
            loop {
                let w = self.stack.pop().unwrap();
                let mut _w = w.borrow_mut();
                _w.low_link = low_link;
                _w.on_stack = false;
                drop(_w);
                scc.push(w.clone());
                if w.as_ptr() == v.as_ptr() {
                    break;
                }
        }
        }
        if scc.len() > 1 {
            self.sccs.push(scc);
        }
    }

    pub fn recurse(&mut self, v: &VertexSP) {
        self.__init(&v.clone());  // set up Vertex in scc discovery
        // Go through all children of this Vertex
        //for w in &v.borrow().children {
        let children = v.borrow().children.to_vec();  // FIXME: We copy because of Rust borrowing checks
        for w in &children {
            if w.borrow().index == INDEX_NOT_SET {
                self.recurse(&w.clone());
                let mut _v = v.borrow_mut();
                let low_link = _v.low_link;
                _v.low_link = cmp::min(low_link, w.borrow().low_link);
            }
            else if w.borrow().on_stack {
                let mut _v = v.borrow_mut();
                let low_link = _v.low_link;
                _v.low_link = cmp::min(low_link, w.borrow().index);
            }
        }
        self.__end(&v.clone());  // found scc
    }
}

fn calculate_sccs(vertices: &ListVerticesT) -> Vec<ListVerticesT> {
    let mut calc = Tarjan::new();
    for v in vertices {
        if v.borrow().index == INDEX_NOT_SET {
            calc.recurse(v);
        }
    }
    return calc.sccs
}

fn make_dag(vertices: &mut ListVerticesT, sccs: &Vec<ListVerticesT>) {
    // merge vertices in each scc
    for scc in sccs {  // O(V)
        let v = &scc[0];  // target node (first node in scc)
        v.borrow_mut().weight = scc.len() as IndexT;  // update the weight of the Vertex
        let mut children = ListVerticesT::with_capacity(0);  // note: no reserve() here
        for w in scc {
            for x in &w.borrow().children {
                if v.borrow().low_link != x.borrow().low_link {
                    children.push(x.clone());
                }
           }
        }
        v.borrow_mut().children = children;
        for w in scc {
            if w.as_ptr() != v.as_ptr() {
                w.borrow_mut().target = Option::Some(v.clone());  // used for children remapping
                w.borrow_mut().weight = 0;  // indicates the Vertex is not used anymore
            }
        }
    }
    // remap children to the target node (if applicable)
    for v in vertices {
        if !v.borrow_mut().children.is_empty() {
            let mut children = ListVerticesT::with_capacity(v.borrow_mut().children.len());
            for w in &v.borrow_mut().children {
                children.push(w.borrow().target.as_ref().unwrap_or(w).clone());
            }
            // remove duplicates
            keep_unique(&mut children);
            v.borrow_mut().children = children;
        }

    }
}

fn dag_max_len_recurse(v: &VertexSP) -> IndexT {
    let mut max_len: IndexT  = 0;
    for w in &v.borrow().children {
        let curr_len: IndexT = if w.borrow().max_len == 0 && v.as_ptr() != w.as_ptr() {  // avoid self referencing
            dag_max_len_recurse(&w.clone())
        } else {
            w.borrow().max_len
        };
        max_len = cmp::max(max_len, curr_len);
    }
    let mut _v = v.borrow_mut();
    _v.max_len = _v.weight + max_len;
    return _v.max_len;
}

fn dag_max_len(vertices: &ListVerticesT) -> IndexT {
    for v in vertices {
        if v.borrow().weight > 0 {
            for w in &v.borrow().children {
                if v.as_ptr() != w.as_ptr() {  // avoid self referencing
                    w.borrow_mut().inputs += 1;
                }
            }
        }
    }
    let mut ret: IndexT = 0;
    for v in vertices {
        if v.borrow().weight > 0 && v.borrow().inputs == 0 {
            ret = cmp::max(ret, dag_max_len_recurse(v));
        }
    }
    return ret;
}

pub fn getMaxVisitableWebpages(_N: i32, M: i32, A: &Vec<i32>, B: &Vec<i32>) -> i32 {
    if A.is_empty() || B.is_empty() {
        return 0;
    }

    // calculate edges
    let mut edges = Vec::<Edge>::with_capacity(M as usize);
    for i in 0..M as usize {
        edges.push(Edge{ v: A[i] as IndexT, w: B[i] as IndexT });  // O(E)
    }

    //
    keep_unique(&mut edges);  // O(E * log(E))
    let mut vertices = build_children(&edges);  // O(V + 2*E)
    let sccs = calculate_sccs(&vertices);  // O(V + E), calculate strongly connected components
    make_dag(&mut vertices, &sccs);  // O(V + E)
    let res = dag_max_len(&vertices);  // O(V + E)
    return res as i32;
}


type RetType = i32;

struct Args
{
    A: Vec<i32>,
    B: Vec<i32>,
    res: RetType,
}

impl super::Result<RetType> for Args {
    fn get_result(&self) -> RetType
    {
        return self.res;
    }
}

pub fn tests() -> u32
{
    let wrapper = |p: &Args| -> RetType {
        let max_len = cmp::max(*p.A.iter().max().unwrap(), *p.B.iter().max().unwrap());
        return getMaxVisitableWebpages(max_len, p.A.len() as i32, &p.A, &p.B);
    };

    let args_list : Vec<Args> = vec![
        /*Args{ A: vec![ 1, 2, 3, 4 ], B: vec![ 4, 1, 2, 1 ], res: 4 },
        Args{ A: vec![ 3, 5, 3, 1, 3, 2 ], B: vec![ 2, 1, 2, 4, 5, 4 ], res: 4 },
        Args{ A: vec![ 3, 2, 5, 9, 10, 3, 3, 9, 4 ], B: vec![ 9, 5, 7, 8, 6, 4, 5, 3, 9 ], res: 5 },
        // extra1
        Args{ A: vec![ 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 13, 14, 14     ], B: vec![ 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  4,  4,  2     ], res: 8 },
        Args{ A: vec![ 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 15, 15     ], B: vec![ 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  9     ], res: 8 },
        Args{ A: vec![ 3, 2, 5, 9, 10, 3, 3, 9, 4,  9, 11, 12, 14, 13, 13, 13 ], B: vec![ 9, 5, 7, 8,  6, 4, 5, 3, 9, 11, 12,  9,  2,  4,  5,  8 ], res: 8 },
        Args{ A: vec![ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6 ], B: vec![ 3, 4, 3, 4, 5, 6, 5, 6, 7, 8, 7, 8 ], res: 4 },
        Args{ A: vec![ 1, 3, 2 ], B: vec![ 3, 2, 3 ], res: 3 },
        Args{ A: vec![ 2, 1 ], B: vec![ 1, 2 ], res: 2 },
        Args{ A: vec![ 3, 5, 3, 1, 3, 2 ], B: vec![ 2, 2, 2, 4, 5, 4 ], res: 4 },*/
        Args{ A: vec![ 3, 5, 3, 1, 3, 2 ], B: vec![ 2, 2, 5, 4, 5, 4 ], res: 4 },  // 3 is referencing twice 5
        //Args{ A: vec![ 3, 5, 3, 1, 3, 2 ], B: vec![ 2, 2, 3, 4, 5, 4 ], res: 4 },  // 3 is self referencing
    ];

    return super::run_all_tests("l2_rabbit_hole1", args_list, wrapper, Option::None);
}
