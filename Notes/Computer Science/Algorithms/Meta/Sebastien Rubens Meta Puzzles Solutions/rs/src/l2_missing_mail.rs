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

trait Both {
    fn both(&self) -> f64;
}

struct Result {
    mail_room_value: f64,
    total_value: f64,
}

impl Both for Result {
    fn both(&self) -> f64 {
        return self.mail_room_value + self.total_value;
    }
}

pub fn getMaxExpectedProfit(_N: i32, V: &Vec<i32>, C: i32, S: f64) -> f64 {
    if S == 0.0 {
        let mut ret: f64 = 0.0;
        for &Vi in V {
            ret += Vi as f64;
        }
        return ret - C as f64;
    }

    // Initial result
    let mut results = Vec::<Result>::with_capacity(V.len());
    results.push(Result{ mail_room_value: 0.0, total_value: 0.0 });
    for &Vi in V {
        // Update the best results for the new day, considering the packages could've stolen in previous round
        for result in &mut results {
            result.mail_room_value *= 1.0 - S;
        }

        // Possibility #1 : pick up packages on this day
        // We need to add the best(max) possible total_value among all saved so far
        let pickup_value = (Vi - C) as f64 + results.iter().fold(f64::MIN, |a, b| a.max(b.both()));

        // Possibility #2 : do not pick up packages on this day
        for result in &mut results {
            result.mail_room_value += Vi as f64;
        }

        results.push(Result{ mail_room_value: 0.0, total_value: pickup_value });

    }

    return results.iter().fold(f64::MIN, |a, b| a.max(b.total_value));
}


type RetType = f64;

struct Args
{
    V: Vec<i32>,
    C: i32,
    S: f64,
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
    let wrapper = |p: &Args| -> RetType { getMaxExpectedProfit(p.V.len() as i32, &p.V, p.C, p.S) };

    let args_list : Vec<Args> = vec![
        Args{ V: vec![ 10, 2, 8, 6, 4 ], C: 5, S: 0.0, res: 25.0 },
        Args{ V: vec![ 10, 2, 8, 6, 4 ], C: 5, S: 1.0, res: 9.0 },
        Args{ V: vec![ 10, 2, 8, 6, 4 ], C: 3, S: 0.5, res: 17.0 },
        Args{ V: vec![ 10, 2, 8, 6, 4 ], C: 3, S: 0.15, res: 20.10825 },
    ];

    return super::run_all_tests("l2_missing_mail", args_list, wrapper, Option::Some(0.000_001));
}
