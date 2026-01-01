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
    let mut max_score = 0;
    let mut second_max_score = 0;
    let mut two_remainder = 0;
    let mut one_remainder = 0;
    let mut need_one: bool = false;

    for &score in S {
        let score_mod_3 = score % 3;
        two_remainder |= score_mod_3 >> 1;
        one_remainder |= score_mod_3 & 1;
        need_one = need_one || (score == 1);
        if max_score < score {
            second_max_score = max_score;
            max_score = score;
        }
        else if second_max_score < score {
            second_max_score = score;
        }
    }

    // number of solutions, without any optimisation
    let mut count = max_score / 3 + two_remainder + one_remainder;

    // not optimisation is possible if "two_remainder and one_remainder" is not true
    if two_remainder * one_remainder != 1 {
        return count;
    }

    // replace "last +3" by "+1+2"
    if max_score % 3 == 0 {
        count -= 1;
    }

    // replace last "+3+1" by "+2+2"
    if need_one {  // exit early because 1 is required but at least one sum(i.e.it cannot be replaced)
        return count;
    }
    if max_score % 3 != 1 {  // max_score does not have a 1 (so it cannot be replaced)
        return count;
    }
    let tmp =max_score - second_max_score;
    if !(tmp == 1 || tmp == 3) { // [ok, not ok(3), ok] || [not ok(1) | here | unimportant]
        count -= 1;
    }
    return count;
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
        Args{ S: vec![ 1, 2, 3, 4, 5 ], res: 3 },
        Args{ S: vec![ 4, 3, 3, 4 ], res: 2 },
        Args{ S: vec![ 2, 4, 6, 8 ], res: 4 },
        Args{ S: vec![ 8 ], res: 3 },
        // extra1
        Args{ S: vec![ 4, 3, 3, 4 ], res: 2 },
        Args{ S: vec![ 2, 4, 6, 8 ], res: 4 },
        Args{ S: vec![ 8 ], res: 3 },
        Args{ S: vec![ 1, 2, 3 ], res: 2 },
        Args{ S: vec![ 5, 7 ], res: 3 },
        Args{ S: vec![ 5, 9, 10 ], res: 5 },
        Args{ S: vec![ 5, 9, 11 ], res: 4 },
        Args{ S: vec![ 2, 4, 6 ], res: 3 },
        Args{ S: vec![ 2, 4, 7 ], res: 4 },
        // extra2
        Args{ S: vec![ 1, 2, 4 ], res: 3 },
        Args{ S: vec![ 2, 4 ], res: 2 },
        Args{ S: vec![ 4, 5 ], res: 3 },
        Args{ S: vec![ 9, 12 ], res: 4 },
        Args{ S: vec![ 11, 13 ], res: 5 },
    ];

    return super::run_all_tests("l2_scoreboard_interference2", args_list, wrapper, Option::None);
}
