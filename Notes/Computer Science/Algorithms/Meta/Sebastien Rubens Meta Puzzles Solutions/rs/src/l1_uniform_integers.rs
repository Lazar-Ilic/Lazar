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

fn len_str(_nb: i64) -> i32 {
    if _nb == 0 {  // not necessary due to problem definition
        return 1;
    }
    let mut nb = _nb;
    let mut ret: i32 = 0;
    while nb > 0 {
        nb /= 10;
        ret += 1;
    }
    return ret;
}

fn ones(log_value: i32) -> i64 {
    let mut ret: i64 = 0;
    let mut i = 0;
    while i < log_value {
        i += 1;
        ret = ret * 10 + 1;
    }
    return ret;
}

pub fn getMinimumDeflatedDiscCount(A: i64, B: i64) -> i32 {
    // Each of the following lines is O(log(max(A, B)))
    let len_a = len_str(A);
    let len_b = len_str(B);
    let tmp_a = ones(len_a);
    let tmp_b = ones(len_b);
    
    // Everything else is O(1)
    let nb_a = (tmp_a * 10 - A) / tmp_a;
    let nb_b = B / tmp_b;
    let nb_m = if len_b - len_a >= 2 { 9 * (len_b - len_a - 1) } else { 0 } as i64;
    let mut nb = nb_a + nb_m + nb_b;
    if len_a == len_b {
        nb -= 9;
    }
    return nb as i32;
}


type RetType = i32;

struct Args
{
    A: i64,
    B: i64,
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
    let wrapper = |p: &Args| -> RetType { getMinimumDeflatedDiscCount(p.A, p.B) };

    let args_list : Vec<Args> = vec![
        Args{ A: 75, B: 300, res: 5 },
        Args{ A: 1, B: 9, res: 9 },
        Args{ A: 999999999999, B: 999999999999, res: 1 },
        // extra1
        Args{ A: 1, B: 1_000_000_000_000, res: 108 },
        // extra2
        Args{ A: 10, B: 99, res: 9 },
        Args{ A: 11, B: 98, res: 8 },
        Args{ A: 21, B: 89, res: 7 },
        Args{ A: 22, B: 88, res: 7 },
        Args{ A: 23, B: 87, res: 5 },
        // extra3
        Args{ A: 11, B: 88, res: 8 },
        Args{ A: 11, B: 98, res: 8 },
        Args{ A: 11, B: 99, res: 9 },
    ];

    return super::run_all_tests("l1_uniform_integers", args_list, wrapper, Option::None);
}
