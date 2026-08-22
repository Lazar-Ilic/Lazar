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

pub fn getMinCodeEntryTime(N: i32, _M: i32, C: &Vec<i32>) -> i64 {
    use std::cmp;

    let mut pos: i32 = 1;
    let mut nb: i64 = 0;
    for &target in C {
        let mut positive_move = (target - pos) % N;  // positive move
        positive_move = if positive_move < 0 { positive_move + N } else { positive_move};  // modulo can be negative in C++
        let negative_move = N - positive_move;
        nb += cmp::min(positive_move, negative_move) as i64;
        pos = target;
    }
    return nb;
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
        Args{ N: 10, C: vec![ 9, 4, 4, 8 ], res: 11 },
    ];

    return super::run_all_tests("l1_rotary_lock1", args_list, wrapper, Option::None);
}
