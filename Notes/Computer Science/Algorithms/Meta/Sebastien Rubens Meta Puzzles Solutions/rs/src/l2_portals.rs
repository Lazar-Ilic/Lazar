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

type DistT = i32;

pub struct OurPriorityQueue<P, I>
{
    nb: u64,
    m: std::collections::BTreeMap<(P, u64), I>,
}

impl<P, I> OurPriorityQueue<P, I>
    where I: Ord, P: Ord
{
    pub const fn new() -> OurPriorityQueue<P, I> {
        OurPriorityQueue{ nb: 0, m: std::collections::BTreeMap::<(P, u64), I>::new() }
    }

    pub fn is_empty(&self) -> bool {
        self.m.first_key_value().is_none()
    }

    pub fn insert(&mut self, priority: P, item: I) -> Option<I> {
        self.nb += 1;
        self.m.insert((priority, self.nb), item)
    }

    pub fn pop_first(&mut self) -> Option<((P, u64), I)> {
        self.m.pop_first()
    }
}

impl<P, I> Default for OurPriorityQueue<P, I>
    where I: Ord, P: Ord
{
    fn default() -> OurPriorityQueue<P, I> {
        OurPriorityQueue::<P, I>::new()
    }
}

struct Coord
{
    row: i32,
    col: i32,
}

#[derive(Eq)]
struct NodeInfo
{
    row: i32,
    col: i32,
    node_type: char,
    distance: DistT,
    is_inserted: bool,
}

impl NodeInfo {
    fn new(row: i32, col:i32, node_type: char) -> NodeInfo {
        NodeInfo{ row: row, col: col, node_type: node_type, distance: DistT::MAX, is_inserted: false }
    }
}

impl Ord for NodeInfo {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        return self.distance.cmp(&other.distance);
    }
}

impl PartialOrd for NodeInfo {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for NodeInfo {
    fn eq(&self, other: &Self) -> bool {
        return self.distance == other.distance;
    }
}

type NodeInfoSP = Rc<RefCell<NodeInfo>>;
type GridNodeInfoT = Vec<Vec<NodeInfoSP>>;
type PriorityQueueT = OurPriorityQueue<DistT, NodeInfoSP>;
type HeuristicFuncT = fn(&NodeInfoSP) -> DistT;
type DistFuncT = fn(&NodeInfoSP, &NodeInfoSP) -> DistT;
type PortalsT = Vec<Vec<NodeInfoSP>>;

fn add_neighbour(q: &mut PriorityQueueT, h: &HeuristicFuncT, d: &DistFuncT,
    node: &NodeInfoSP, neighbour: &mut NodeInfoSP)
{
    let neighbor_distance = d(node, neighbour);
    let mut n = neighbour.borrow_mut();
    if neighbor_distance >= n.distance {
        return;
    }
    n.distance = neighbor_distance;
    if !n.is_inserted {
        n.is_inserted = true;
        drop(n);  // because we used a temporary, we need to drop it, otherwise h() will complain
        q.insert(h(neighbour), neighbour.clone());
    }
}

pub fn getSecondsRequired(R: i32, C: i32, G: &Vec<Vec<char>>) -> i32 {
    // set up grid and portal map
    let mut grid: GridNodeInfoT = Vec::with_capacity(R as usize);
    for j in 0..R {
        let mut row = Vec::<NodeInfoSP>::with_capacity(C as usize);
        for i in 0..C {
            let node = NodeInfo::new(j, i, G[j as usize][i as usize]);
            let node_sp = Rc::new(RefCell::new(node));
            row.push(node_sp);
        }
        grid.push(row);
    }

    let mut start = Coord{ row: 0, col: 0 };
    let mut ends = Vec::<Coord>::with_capacity((R * C) as usize);
    let mut portals: PortalsT = PortalsT::with_capacity(256);
    for _ in 0..256 {
        portals.push(vec![]);
    }
    for j in 0..R {
        let row = &G[j as usize];
        for i in 0..C {
            let node_type = row[i as usize];
            if node_type == 'S' {
                start = Coord{ row: j, col: i };
            }
            else if node_type == 'E' {
                ends.push(Coord{ row: j, col: i });  // Ends could be used for a heuristic
            }
            else if 'a' <= node_type && node_type <= 'z' {
                portals[(node_type as usize) & 255].push(grid[j as usize][i as usize].clone());
            }
        }
    }
    let start_node = &grid[start.row as usize][start.col as usize];
    start_node.borrow_mut().distance = 0;

    // set up the grid
    let mut q: PriorityQueueT = PriorityQueueT::default();  // contains (heuristic score, coordinates)
    let h: HeuristicFuncT = |n: &NodeInfoSP| n.borrow().distance;
    let d: DistFuncT = |n1: &NodeInfoSP, _n2: &NodeInfoSP| return n1.borrow().distance + 1;  // distance is always one

    let neighbours_directions = [ Coord{ row: -1, col: 0 }, Coord{ row: 1, col: 0}, Coord{ row: 0, col: -1 }, Coord{ row: 0, col: 1} ];

    q.insert( h(start_node), start_node.clone() );
    while !q.is_empty() {
        let node_sp = q.pop_first().unwrap().1;
        let node = node_sp.borrow();
        if node.node_type == 'E' {
            return node.distance;
        }
        // add portal nodes to node
        if 'a' <= node.node_type && node.node_type <= 'z' {
            for neighbour_sp in &mut portals[(node.node_type as usize) & 255] {
                if neighbour_sp.as_ptr() != node_sp.as_ptr() {
                    add_neighbour(&mut q, &h, &d, &node_sp, neighbour_sp);
                }
            }
        }
        // add neighbours to node
        for c in &neighbours_directions {
            let drow = c.row;
            let dcol = c.col;
            let row = node.row + drow;
            let col = node.col + dcol;
            if (0 <= row && row < R) && (0 <= col && col < C) {
                let neighbour_sp = &mut grid[row as usize][col as usize];
                if neighbour_sp.borrow().node_type != '#' {
                    add_neighbour(&mut q, &h, &d, &node_sp, neighbour_sp);
                }
            }
        }
    }
    return -1;
}

pub fn _getSecondsRequired(G: &Vec<String>) -> i32 {
    let mut H: Vec<Vec<char>> = Vec::with_capacity(G.len());
    for row in G {
        H.push(row.chars().collect());
    }
    return getSecondsRequired(H.len() as i32, H[0].len() as i32, &H);
}


type RetType = i32;

struct Args
{
    V: Vec<&'static str>,
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
        let tmp = p.V.iter().map(|s| s.to_string()).collect();
        return _getSecondsRequired(&tmp);
    };

    let args_list : Vec<Args> = vec![
        Args{ V: vec![ ".E.", ".#E", ".S#" ], res: 4 },
        Args{ V: vec![ "a.Sa", "####", "Eb.b" ], res: -1 },
        Args{ V: vec![ "aS.b", "####", "Eb.a" ], res: 4 },
        Args{ V: vec![ "xS..x..Ex" ], res: 3 },
    ];

    return super::run_all_tests("l2_portals", args_list, wrapper, Option::None);
}
