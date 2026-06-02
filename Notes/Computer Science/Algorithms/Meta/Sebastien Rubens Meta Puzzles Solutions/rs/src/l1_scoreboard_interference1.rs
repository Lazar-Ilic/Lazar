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

pub fn getMinProblemCount(_N: i32, S: &Vec<i32>) -> i32 {
    use std::cmp;

    let mut min_number_of_twos: i32 = 0;
    let mut min_number_of_ones: i32 = 0;
    for &score in S {
        let number_of_twos = score / 2;
        let number_of_ones = score % 2;
        min_number_of_twos = cmp::max(min_number_of_twos, number_of_twos);
        min_number_of_ones = cmp::max(min_number_of_ones, number_of_ones);
    }
    return min_number_of_twos + min_number_of_ones;
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
    let wrapper = |p: &Args| -> RetType { getMinProblemCount(p.S.len() as i32, &p.S) };

    let args_list : Vec<Args> = vec![
        Args{ S: vec![ 1, 2, 3, 4, 5, 6 ], res: 4 },
        Args{ S: vec![ 4, 3, 3, 4 ], res: 3 },
        Args{ S: vec![ 2, 4, 6, 8 ], res: 4 },
    ];

    return super::run_all_tests("l1_scoreboard_interference1", args_list, wrapper, Option::None);
}
