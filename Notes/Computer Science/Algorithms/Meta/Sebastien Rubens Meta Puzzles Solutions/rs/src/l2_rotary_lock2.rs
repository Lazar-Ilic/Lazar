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
use std::hash::{Hash, Hasher};

#[derive(Eq)]
struct Dials
{
    dial1: i32,
    dial2: i32,
}

impl Dials {
    const BUCKETS: usize = 1024;
}

impl PartialEq for Dials {
    fn eq(&self, other: &Self) -> bool {
        return self.dial1 == other.dial1 && self.dial2 == other.dial2;
    }
}

impl Hash for Dials {
    fn hash<H: Hasher>(&self, state: &mut H) {
        let value = self.dial1 + self.dial2;
        value.hash(state);
    }
}

type SolutionsT = std::collections::HashMap<Dials, i64>;  // A [hash map] implemented with quadratic probing and SIMD lookup.

fn get_distance(target: i32, position: i32, N: i32) -> i32 {
    let mut positive_move = (target - position) % N;
    if positive_move < 0 {
        positive_move += N;
    }
    let negative_move = N - positive_move;  // positive number
    return cmp::min(positive_move, negative_move);
}

fn insert_solution(new_solutions: &mut SolutionsT, N: i32, target: i32, dial1: i32, dial2: i32, distance: i64)
{
    let new_distance = distance + get_distance(target, dial1, N) as i64;
    let key = Dials{ dial1: cmp::min(dial2, target), dial2: cmp::max(dial2, target) };
    let it = new_solutions.get(&key);
    let value = it.unwrap_or(&i64::MAX);
    new_solutions.insert(key, cmp::min(*value, new_distance));
}

pub fn getMinCodeEntryTime(N: i32, _M: i32, C: &Vec<i32>) -> i64 {
    if C.is_empty() {
        return 0;
    }
    let max_value = i64::MAX;
    let mut solutions = SolutionsT::with_capacity(Dials::BUCKETS);
    solutions.insert(Dials{ dial1: 1, dial2: 1 }, 0);
    for &target in C {
        let mut new_solutions = SolutionsT::with_capacity(Dials::BUCKETS);
        for (dials, &distance) in &solutions {
            // we turn dial1
            insert_solution(&mut new_solutions, N, target, dials.dial1, dials.dial2, distance);
            // we turn dial2
            insert_solution(&mut new_solutions, N, target, dials.dial2, dials.dial1, distance);
        }
        solutions = new_solutions;
    }
    let mut min_distance = max_value;
    for (_, &distance) in &solutions {
        min_distance = cmp::min(min_distance, distance);
    }
    return min_distance;
}


type RetType = i64;

struct Args
{
    N: i32,
    C: Vec<i32>,
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
    let wrapper = |p: &Args| -> RetType { getMinCodeEntryTime(p.N, p.C.len() as i32, &p.C) };

    let args_list : Vec<Args> = vec![
        Args{ N: 3, C: vec![ 1, 2, 3 ], res: 2 },
        Args{ N: 10, C: vec![ 9, 4, 4, 8 ], res: 6 },
        // extra1
        Args{ N: 0, C: vec![], res: 0 },
        Args{ N: 3, C: vec![], res: 0 },
        Args{ N: 10, C: vec![], res: 0 },
        Args{ N: 10, C: vec![ 4 ], res: 3 },
        Args{ N: 10, C: vec![ 9 ], res: 2 },
        Args{ N: 10, C: vec![ 9, 9, 9, 9 ], res: 2 },
        // extra2
        Args{ N: 10, C: vec![ 6, 2, 4, 8 ], res: 10 },  // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
        Args{ N: 10, C: vec![ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ], res: 9 },  // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
        Args{ N: 4, C: vec![ 4, 3, 2, 1, 2, 3, 4 ], res: 5 },  // <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
    ];

    return super::run_all_tests("l2_rotary_lock2", args_list, wrapper, Option::None);
}
