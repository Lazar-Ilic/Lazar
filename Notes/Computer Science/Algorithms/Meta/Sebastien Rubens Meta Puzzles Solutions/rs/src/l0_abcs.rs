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

pub fn getSum(A: i32, B: i32, C: i32) -> i32 {
    return A + B + C;
}


type RetType = i32;

struct Args
{
    A: i32,
    B: i32,
    C: i32,
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
    let wrapper = |p: &Args| -> RetType { getSum(p.A, p.B, p.C) };

    let args_list : Vec<Args> = vec![
        Args{ A: 1, B: 2, C: 3, res: 6 },
        Args{ A: 100, B: 100, C: 100, res: 300 },
        Args{ A: 85, B: 16, C: 93, res: 194 },
    ];

    return super::run_all_tests("l0_abcs", args_list, wrapper, Option::None);
}
