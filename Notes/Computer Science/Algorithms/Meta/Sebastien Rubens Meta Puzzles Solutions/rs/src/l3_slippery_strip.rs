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

struct Counts
{
    star: i32,
    right: i32,
    down: i32,
}

type CharCounterT = [i32; 256];

fn std_count(row: &Vec<char>, first: usize, last: usize, value: char) -> i32 {
    let mut count: i32 = 0;
    for &c in &row[first..last] {
        if c == value {
            count += 1;
        }
    }
    return count;
}

fn std_find_index(row: &Vec<char>, value: char, first: usize) -> usize {
    let mut index: usize = first;
    for &c in &row[first..row.len()] {
        if c == value {
            break;
        }
        index += 1;
    }
    return index;
}

fn get_counts(row: &Vec<char>, counts: &mut CharCounterT) -> Counts {
    counts['*' as usize] = 0;
    counts['>' as usize] = 0;
    counts['v' as usize] = 0;
    for &c in row {
        let mut d = c as usize;
        if d >= counts.len() {
            d = '.'  as usize;
        }
        counts[d] += 1;
    }
    return Counts{ star: counts['*' as usize], right: counts['>' as usize], down: counts['v' as usize] };
}

fn get_nb_coins_right_then_down3(row: &Vec<char>, _count_down: i32, _count_right: i32) -> i32 {
    // complexity : O(C)
    if _count_down == 0 {
        return 0;
    }
    let mut count_down = _count_down;
    let mut count_right = _count_right;
    let k = std_find_index(row, 'v', 0);
    let j = if k != row.len() { k + 1 } else { 0 };
    let mut new_row = Vec::<char>::with_capacity(row.len());
    new_row.extend_from_slice(&row[j..row.len()]);
    new_row.extend_from_slice(&row[0..j]);

    let mut nb_coins_right_then_down = 0;
    let mut last = 0;
    while count_right * count_down != 0 {
        let first = std_find_index(&new_row, '>', last);
        last = std_find_index(&new_row, 'v', first) + 1;
        nb_coins_right_then_down = cmp::max(nb_coins_right_then_down, std_count(&new_row, first, last, '*'));
        count_down -= 1;
        count_right -= std_count(&new_row, first, last, '>');
    }
    return nb_coins_right_then_down;
}

pub fn getMaxCollectableCoins(_R: i32, C: i32, G: &Vec<Vec<char>>) -> i32 {
    let mut counts: CharCounterT = [0; 256];
    let mut res = 0;
    for i in 0..G.len() {
        let row = &G[G.len() - i - 1];
        let count = get_counts(&row, &mut counts);
        let nb_coins_immediately_down = cmp::min(count.star, 1);
        if count.right == C {
            res = 0;
        }
        else if  count.right == 0 {
            res += nb_coins_immediately_down;
        }
        else {
            let nb_coins_right_then_down = get_nb_coins_right_then_down3(row, count.down, count.right);
            let nb_coins_right_forever = if count.down == 0 { count.star } else { 0 };
            res = cmp::max(nb_coins_immediately_down + res, cmp::max(nb_coins_right_then_down + res, nb_coins_right_forever));
        }
    }
    return res;

}

pub fn _getMaxCollectableCoins(G: &Vec<String>) -> i32 {
    let mut H: Vec<Vec<char>> = Vec::with_capacity(G.len());
    for row in G {
        H.push(row.chars().collect());
    }
    return getMaxCollectableCoins(H.len() as i32, if H.is_empty() {0} else {H[0].len() as i32}, &H);
}


type RetType = i32;

struct Args
{
    G: Vec<&'static str>,
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
        let tmp = p.G.iter().map(|s| s.to_string()).collect();
        return _getMaxCollectableCoins(&tmp);
    };

    let args_list : Vec<Args> = vec![
        Args{ G: vec![ ".***", "**v>", ".*.." ], res: 4 },
        Args{ G: vec![ ">**", "*>*", "**>" ], res: 4 },
        Args{ G: vec![ ">>", "**" ], res: 0 },
        Args{ G: vec![ ">*v*>*", "*v*v>*", ".*>..*", ".*..*v" ], res: 6 },
        // extra1
        Args{ G: vec![], res: 0 },
        Args{ G: vec![ "." ], res: 0 },
        Args{ G: vec![ "v" ], res: 0 },
        Args{ G: vec![ ">" ], res: 0 },
        Args{ G: vec![ "*" ], res: 1 },
        // extra2
        Args{ G: vec![ ".", ".", ">", "*" ], res: 0 },
        Args{ G: vec![ ".", "*", ">", "*" ], res: 1 },
        Args{ G: vec![ ".", "*", ">", "." ], res: 1 },
        Args{ G: vec![ "*", ".", ">", "." ], res: 1 },
        Args{ G: vec![ "***", "...", ">vv", "..." ], res: 1 },
        // extra3
        Args{ G: vec![ "*....", ".*...", "..*..", "...*." ], res: 4 },
        Args{ G: vec![ "....", "....", "....", "...." ], res: 0 },
        Args{ G: vec![ "***>", "...." ], res: 3 },
        Args{ G: vec![ "*" ], res: 1 },
        Args{ G: vec![ "vvvv" ], res: 0 },
        Args{ G: vec![ "vvvv", "....", ">>>>" ], res: 0 },
        // extra4
        Args{ G: vec![ "******", "......", ">*>vvv", "......" ], res: 2 },
        Args{ G: vec![ "*****", ".....", ">>vvv", "....." ], res: 1 },
    ];

    return super::run_all_tests("l3_slippery_strip", args_list, wrapper, Option::None);
}
