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

pub fn getMinimumSecondsRequired(N: i32, R: &Vec<i32>, A: i32, B: i32) -> i64 {
    use std::cmp;

    if N == 0 || R.is_empty() {
        return 0;
    }

    let mut U = R.clone();

    // Extend the range of input data
    type TotalCostT = i64;
    type UnitCostT = i32;
    let _A = A as TotalCostT;
    let _B = B as TotalCostT;
    let _N = N as usize;

    //
    let mut total_cost: TotalCostT = 0;
    let mut costs = Vec::<UnitCostT>::with_capacity(_N);
    for _ in 0..N {
        costs.push(0);
    }
    let mut intervals = Vec::<usize>::with_capacity(_N);
    intervals.push(0);
    for i in 1.._N {
        let Uj = U[i - 1] + 1;
        let Ui = U[i];
        // inflate first
        if Uj > Ui {  // min_inflate > 0
            let min_inflate = Uj - Ui;  // fits in 32bits
            total_cost += (min_inflate as TotalCostT) * _A;  // fits in 64-bits
            U[i] += min_inflate;  // fits in 32bits by definition
            costs[i] = min_inflate;  // fits in 32bits by definition
        }
        // track continuous intervals
        if Uj < Ui {  // min_inflate < 0
            intervals.push(i);
            continue;
        }
        // deflate eventually
        loop {
            let first = *intervals.last().unwrap();
            let nb_tot = 1 + i - first;
            //
            let mut nb_pos = 0;
            let mut min_positive1 = 0;
            for &value in &costs[first..i + 1] {
                if value > 0 {
                    nb_pos += 1;
                    min_positive1 = if min_positive1 > 0 { cmp::min(min_positive1, value) } else { value };
                }
            }
            //
            let min_positive2 = if first > 0  {U[first] - U[first - 1] } else { U[0] };
            let min_positive = cmp::min(min_positive1, min_positive2 - 1);
            let nb_neg = nb_tot - nb_pos;
            let cost_change = ((nb_neg as TotalCostT) * _B - (nb_pos as TotalCostT) * _A) * (min_positive as TotalCostT);
            if cost_change >= 0 {
                break;
            }
            total_cost += cost_change;
            for j in first..i + 1 {
                costs[j] -= min_positive;
                U[j] -= min_positive;
            }
            if first > 0 {
                if U[first] == U[first - 1] + 1 {
                    intervals.pop();
                }
            }
            if min_positive <= 0 {
                break;
            }
        }
    }
    return total_cost;
}


type RetType = i64;

struct Args
{
    R: Vec<i32>,
    A: i32,
    B: i32,
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
    let wrapper = |p: &Args| -> RetType { getMinimumSecondsRequired(p.R.len() as i32, &p.R, p.A, p.B) };

    let args_list : Vec<Args> = vec![
        Args{ R: vec![ 2, 5, 3, 6, 5 ], A: 1, B: 1, res: 5 },
        Args{ R: vec![ 100, 100, 100 ], A: 2, B: 3, res: 5 },
        Args{ R: vec![ 100, 100, 100 ], A: 7, B: 3, res: 9 },
        Args{ R: vec![ 6, 5, 4, 3 ], A: 10, B: 1, res: 19 },
        Args{ R: vec![ 100, 100, 1, 1 ], A: 2, B: 1, res: 207 },
        Args{ R: vec![ 6, 5, 2, 4, 4, 7 ], A: 1, B: 1, res: 10 },
        // extra1
        Args{ R: vec![ 10, 6, 2 ], A: 2, B: 1, res: 15 },
        Args{ R: vec![ 1, 2, 3, 4, 5, 6 ], A: 1, B: 1, res: 0 },
        Args{ R: vec![ 6, 5, 4, 3, 2, 1 ], A: 1, B: 1, res: 18 },
        // extra2
        Args{ R: vec![ 4, 6, 2 ], A: 2, B: 1, res: 9 },
        Args{ R: vec![ 6, 5, 2, 4, 4, 7 ], A: 1, B: 1, res: 10 },
        Args{ R: vec![ 2, 5, 3, 6, 5 ], A: 1, B: 1, res: 5 },
        Args{ R: vec![ 2, 3, 8, 1, 7, 6  ], A: 2, B: 1, res: 15 },
        Args{ R: vec![ 5, 4, 3, 6, 8, 1, 10, 11, 6, 1 ], A: 4, B: 1, res: 85 },
        Args{ R: vec![ 3, 4, 7, 8, 2 ], A: 4, B: 1, res: 24 },
        Args{ R: vec![ 1, 1, 1, 1, 1 ], A: 4, B: 1, res: 40 },
        Args{ R: vec![ 1, 1, 1, 1, 1 ], A: 1, B: 4, res: 10 },
        Args{ R: vec![ 8, 6, 4, 2 ], A: 1, B: 4, res: 18 },
        Args{ R: vec![ 1_000_000_000, 500_000_000, 200_000_000, 1_000_000 ], A: 1, B: 4, res: 2_299_000_006 },
    ];

    return super::run_all_tests("l3_stack_stabilization2", args_list, wrapper, Option::None);
}
