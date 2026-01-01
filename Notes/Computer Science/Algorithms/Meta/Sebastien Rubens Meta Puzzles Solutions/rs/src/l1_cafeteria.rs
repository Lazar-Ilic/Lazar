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

pub fn getMaxAdditionalDinersCount(N: i64, K: i64, _M: i32, S: &Vec<i64>) -> i64 {
    let d: i64 = K + 1;

    let mut taken: Vec<i64> = Vec::with_capacity(S.len() + 1);
    taken.push(-K);  // we are adding "fake" seats at the beginning
    taken.extend_from_slice(&S);
    taken.push(N + d);  // we are adding "fake" seats at the end

    // we sort elements of S: O(M * log(M))
    taken.sort();

    // we are calculating the extra seats available between each consecutive seats: O(M)
    let mut nb: i64 = 0;
    let e = taken.len() - 1;
    for i in 0..e {
        nb += (taken[i + 1] - taken[i] - d) / d;
    }
    return nb;
}


type RetType = i64;

struct Args
{
    N: i64,
    K: i64,
    S: Vec<i64>,
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
    let wrapper = |p: &Args| -> RetType { getMaxAdditionalDinersCount(p.N, p.K, p.S.len() as i32, &p.S) };

    let args_list : Vec<Args> = vec![
        Args{ N: 10, K: 1, S: vec![ 2, 6 ], res: 3 },
        Args{ N: 15, K: 2, S: vec![ 11, 6, 14 ], res: 1 },
    ];

    return super::run_all_tests("l1_cafeteria", args_list, wrapper, Option::None);
}
