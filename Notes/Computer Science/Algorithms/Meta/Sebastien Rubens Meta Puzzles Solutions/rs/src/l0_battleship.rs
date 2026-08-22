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

pub fn getHitProbability(R: i32, C: i32, G: &Vec<Vec<i32>>) -> f64 {
    let sum = G.iter().fold(0, |acc, row| acc + row.iter().sum::<i32>());
    let div = R * C;
    return (sum as f64) / (div as f64);
}


type RetType = f64;

struct Args
{
    G: Vec<Vec<i32>>,
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
    let wrapper = |p: &Args| -> RetType { getHitProbability(p.G.len() as i32, p.G[1].len() as i32, &p.G) };

    let args_list : Vec<Args> = vec![
        Args{ G: vec![ vec![ 0, 0, 1 ], vec![ 1, 0, 1 ] ], res: 0.5 },
        Args{ G: vec![ vec![ 1, 1 ], vec![ 1, 1 ] ], res: 1.0 },
        // extra1
        Args{ G: vec![ vec![ 0, 1, 0, 0 ], vec![ 1, 1, 0, 0 ], vec![ 0, 0, 0, 0 ] ], res: 0.25 },
    ];

    return super::run_all_tests("l0_battleship", args_list, wrapper, Option::Some(0.000_001));
}
