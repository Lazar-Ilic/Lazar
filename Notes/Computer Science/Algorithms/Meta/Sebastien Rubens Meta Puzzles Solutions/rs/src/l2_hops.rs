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

pub fn getSecondsRequired(N: i64, _F: i32, P: &Vec<i64>) -> i64 {
    if P.is_empty() {
        return 0;
    }
    return N - (*P.iter().min().unwrap() as i64);
}


type RetType = i64;

struct Args
{
    N: i64,
    P: Vec<i64>,
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
    let wrapper = |p: &Args| -> RetType { getSecondsRequired(p.N, p.P.len() as i32, &p.P) };

    let args_list : Vec<Args> = vec![
        Args{ N: 3, P: vec![ 1 ], res: 2 },
        Args{ N: 6, P: vec![ 5, 2, 4 ], res: 4 },
    ];

    return super::run_all_tests("l2_hops", args_list, wrapper, Option::None);
}
