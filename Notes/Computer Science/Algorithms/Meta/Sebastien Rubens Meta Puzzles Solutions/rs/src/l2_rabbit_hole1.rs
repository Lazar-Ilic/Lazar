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

use std::rc::Rc;
use std::cell::RefCell;

type VertexSP = Rc<RefCell<Vertex>>;
type ListVerticesT = Vec<VertexSP>;

#[derive(Clone)]
struct Vertex {
    _nb: usize,
    inputs: u32,
    level: u32,
    in_cycle: bool,
    cycle_len: u32,
    next: Option<VertexSP>,
}

impl Vertex {
    fn new(_nb: usize) -> Vertex {
        Vertex{ _nb, inputs: 0,  level: 1, in_cycle: true, cycle_len: 0, next: Option::None }
    }
}

fn get_next(v: &Vertex) -> VertexSP {
    return v.next.as_ref().unwrap().clone();
}

pub fn getMaxVisitableWebpages(N: i32, L: &Vec<i32>) -> i32 {
    use std::cmp;

    let _N = N as usize;

    let mut vertices: ListVerticesT = Vec::with_capacity(_N);
    for i in 0.._N {
        vertices.push(Rc::new(RefCell::new(Vertex::new(i + 1))));
    }

    // count the number of inputs for each vertex, and set next vertex: O(N)
    for i in 0.._N {
        let next_vertex = &vertices[L[i] as usize - 1];
        next_vertex.borrow_mut().inputs += 1;
        let vertex = &vertices[i];
        vertex.borrow_mut().next = Option::Some(next_vertex.clone());  // yes, we could use indices or raw pointers (as "vertices" is never resized)
    }

    // find the entrance vertices (could be []): O(N)
    let mut entrance_vertices = ListVerticesT::with_capacity(_N);
    for vertex in &vertices {
        if vertex.borrow().inputs == 0 {
            entrance_vertices.push(vertex.clone());
        }
    }

    // calculate "level" of each vertex that is not in a cycle: O(N)
    while !entrance_vertices.is_empty() {
        let curr_vertex = entrance_vertices.pop().unwrap();
        let mut _curr_vertex = curr_vertex.borrow_mut();
        _curr_vertex.in_cycle = false;
        //
        let next_vertex = get_next(&_curr_vertex);
        let mut _next_vertex = next_vertex.borrow_mut();
        _next_vertex.level = cmp::max(_next_vertex.level, _curr_vertex.level + 1);
        _next_vertex.inputs -= 1;
        if _next_vertex.inputs == 0 {
            entrance_vertices.push(next_vertex.clone());
        }
    }

    // calculate length of cycles of the different cycle: O(N)
    for vertex in &vertices {
        let mut _vertex = vertex.borrow_mut();
        if !_vertex.in_cycle || _vertex.cycle_len > 0 {
            continue;
        }
        // count length of cycle
        let mut cycle_len: u32 = 1;
        let mut curr = get_next(&_vertex);
        while curr.as_ptr() != vertex.as_ptr() {
            cycle_len += 1;
            curr = get_next(&curr.clone().borrow());
        }
        // assign length of cycle to vertices
        _vertex.cycle_len = cycle_len;
        let mut curr = get_next(&_vertex);
        while curr.as_ptr() != vertex.as_ptr() {
            curr.borrow_mut().cycle_len = cycle_len;
            curr = get_next(&curr.clone().borrow());
        }
    }
    
    // Now calculate the maximum length: O(N)
    let mut max_chain: u32 = 0;
    for vertex in &vertices {
        let _vertex = vertex.borrow();
        if _vertex.in_cycle { // Note: if the vertex is self-referencing, in_cycle will be true
            max_chain = cmp::max(max_chain, _vertex.cycle_len);
        } else {
            let next_vertex = get_next(&vertex.clone().borrow());
            let mut _next_vertex = next_vertex.borrow();
            if _next_vertex.in_cycle {
                max_chain = cmp::max(max_chain, _vertex.level + _next_vertex.cycle_len);
            }
        }
    }
    return max_chain as i32;
}


type RetType = i32;

struct Args
{
    L: Vec<i32>,
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
    let wrapper = |p: &Args| -> RetType { getMaxVisitableWebpages(p.L.len() as i32, &p.L) };

    let args_list : Vec<Args> = vec![
        Args{ L: vec![ 4, 1, 2, 1 ], res: 4 },
        Args{ L: vec![ 4, 3, 5, 1, 2 ], res: 3 },
        Args{ L: vec![ 2, 4, 2, 2, 3 ], res: 4 },
        // extra1
        Args{ L: vec![ 1 ], res: 1 },  // Link from page 1 to page 1 (not allowed)
        Args{ L: vec![ 1, 2 ], res: 1 },  // Link from page 2 to page 2 (not allowed)
        Args{ L: vec![ 2, 1 ], res: 2 },
        Args{ L: vec![ 3, 3, 4, 3 ], res: 3 },
        Args{ L: vec![ 4, 5, 6, 5, 6, 4 ], res: 4 },
        Args{ L: vec![ 6, 5, 4, 5, 6, 4 ], res: 4 },
        Args{ L: vec![ 3, 3, 4, 1 ], res: 4 },
        Args{ L: vec![ 2, 3, 2 ], res: 3 },
        Args{ L: vec![ 2, 4, 2, 2, 3 ], res: 4 },
        Args{ L: vec![ 6, 5, 4, 3, 2, 1 ], res: 2 },
        // extra2
        Args{ L: vec![ 4, 1, 2, 1 ], res: 4 },
        Args{ L: vec![ 4, 3, 5, 1, 2 ], res: 3 },
        Args{ L: vec![ 4, 1, 2, 1 ], res: 4 },
        Args{ L: vec![ 2, 1, 4, 3 ], res: 2 },
        Args{ L: vec![ 2, 4, 2, 2, 4, 5 ], res: 4 },
        Args{ L: vec![ 4, 1, 2, 1 ], res: 4 },
        Args{ L: vec![ 4, 3, 5, 1, 2 ], res: 3 },
        Args{ L: vec![ 2, 4, 2, 2, 4 ], res: 3 },
        Args{ L: vec![ 2, 3, 4, 2, 2, 3, 6, 9, 8 ], res: 5 },
        // extra3
        Args{ L: vec![ 2, 4, 2, 2, 3, 4, 8, 9, 10, 11, 12, 7 ], res: 6 },
        Args{ L: vec![ 2, 4, 2, 2, 4, 5, 8, 9, 10, 11, 12, 7 ], res: 6 },
    ];

    return super::run_all_tests("l2_rabbit_hole1", args_list, wrapper, Option::None);
}
