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

use std::cmp;

#[derive(Eq)]
struct Tunnel
{
    a: i64,
    b: i64,
}

impl Tunnel {
    fn length(&self) -> i64 {
        return self.b - self.a;
    }
}

impl Ord for Tunnel {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        if self.a < other.a {
            return std::cmp::Ordering::Less;
        }
        else if self.a > other.a {
            return std::cmp::Ordering::Greater;
        }
        if self.b < other.b {
            return std::cmp::Ordering::Less;
        }
        else if self.b > other.b {
            return std::cmp::Ordering::Greater;
        }
        return  std::cmp::Ordering::Equal;
    }
}

impl PartialOrd for Tunnel {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Tunnel {
    fn eq(&self, other: &Self) -> bool {
        return self.a == other.a && self.b == other.b;
    }
}

pub fn getSecondsElapsed(C: i64, N: i32, A: &Vec<i64>, B: &Vec<i64>, K: i64) -> i64 {
    let mut tunnels = Vec::<Tunnel>::with_capacity(N as usize);
    for (&a, &b) in A.iter().zip(B.iter()) {
        tunnels.push(Tunnel{ a: a, b: b });
    }

    let mut tunnel_time_total: i64 = 0;
    for tunnel in &tunnels {
        tunnel_time_total += tunnel.length();
    }

    let number_of_complete_track: i64 = K as i64 / tunnel_time_total;  // O(1)
    let mut total_time_left: i64 = K - number_of_complete_track * tunnel_time_total;  // O(1)
    let mut travel_time: i64 = number_of_complete_track * C;  // O(1)

    if total_time_left == 0 {
        travel_time -= C - i64::from(*B.iter().max().unwrap());  // O(N)
    }
    else
    {
        tunnels.sort();
        for tunnel in &tunnels {
            let tunnel_length = tunnel.length();
            if tunnel_length >= total_time_left {
                travel_time += tunnel.a + total_time_left;
                break;
            }
            total_time_left -= tunnel_length;
        }
    }
    return travel_time;
}


type RetType = i64;

struct Args
{
    C: i64,
    A: Vec<i64>,
    B: Vec<i64>,
    K: i64,
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
    let wrapper = |p: &Args| -> RetType {
        let min_len = cmp::min(p.A.len() as i32, p.B.len() as i32);
        return getSecondsElapsed(p.C, min_len, &p.A, &p.B, p.K);
    };

    let args_list : Vec<Args> = vec![
        Args{ C: 10, A: vec![ 1, 6 ], B: vec![ 3, 7 ], K: 7, res: 22 },
        Args{ C: 50, A: vec![ 39, 19, 28 ], B: vec![ 49, 27, 35 ], K: 15, res: 35 },
        // extra1
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 1, res: 20 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 8, res: 27 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 9, res: 29 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 15, res: 35 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 16, res: 40 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 25, res: 49 },
        Args{ C: 50, A: vec![ 19, 28, 39 ], B: vec![ 27, 35, 49 ], K: 26, res: 70 },
    ];

    return super::run_all_tests("l2_tunnel_time", args_list, wrapper, Option::None);
}
