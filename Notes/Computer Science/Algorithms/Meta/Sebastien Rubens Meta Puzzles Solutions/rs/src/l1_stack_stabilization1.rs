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

pub fn getMinimumDeflatedDiscCount(_N: i32, R: &Vec<i32>) -> i32 {
    use std::cmp;

    let mut nb: i32 = 0;
    let mut iter = R.iter().rev();
    let mut current_radius = *iter.next().unwrap();
    for next_radius in iter {
        let target_radius = current_radius - 1;
        if target_radius <= 0 {
            return -1;
        }
        nb += if target_radius < *next_radius { 1 } else { 0 };
        current_radius = cmp::min(*next_radius, target_radius);
    }
    return nb;
}


type RetType = i32;

struct Args
{
    S: Vec<i32>,
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
    let wrapper = |p: &Args| -> RetType { getMinimumDeflatedDiscCount(p.S.len() as i32, &p.S) };

    let args_list : Vec<Args> = vec![
        Args{ S: vec![ 2, 5, 3, 6, 5 ], res: 3 },
        Args{ S: vec![ 100, 100, 10 ], res: 2 },
        Args{ S: vec![ 6, 5, 4, 3 ], res: -1 },
    ];

    return super::run_all_tests("l1_stack_stabilization1", args_list, wrapper, Option::None);
}
