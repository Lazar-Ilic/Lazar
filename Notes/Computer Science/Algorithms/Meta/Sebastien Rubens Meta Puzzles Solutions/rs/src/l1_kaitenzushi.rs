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

pub fn getMaximumEatenDishCount(_N: i32, D: &Vec<i32>, K: i32) -> i32 {
    // The following is O(1_000_001)
    let mut eaten: Vec<bool> = vec![false; 1_000_001];

    // The following is O(K) (where K < N)
    let mut last_eaten: Vec<usize> = vec![0; K as usize];  // circular buffer for last eaten value (0 is not used, as 1 <= Ki <= 1,000,000)
    let mut oldest_eaten: usize = 0;

    // The following is O(N)
    let mut nb: i32 = 0;
    for &_dish in D {
        let dish: usize = _dish as usize;
        if !eaten[dish] {
            oldest_eaten = (oldest_eaten + 1) % (K as usize);
            let last_eaten_dish = last_eaten[oldest_eaten];
            eaten[last_eaten_dish] = false;  // we remove the oldest eaten dish
            eaten[dish] = true;
            last_eaten[oldest_eaten] = dish as usize;  // we add the newest eaten dish to our circular buffer
            nb += 1;
        }
    }
    return nb;
}


type RetType = i32;

struct Args
{
    D: Vec<i32>,
    K: i32,
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
    let wrapper = |p: &Args| -> RetType { getMaximumEatenDishCount(p.D.len() as i32, &p.D, p.K) };

    let args_list : Vec<Args> = vec![
        Args{ D: vec![ 1, 2, 3, 3, 2, 1 ], K: 1, res: 5 },
        Args{ D: vec![ 1, 2, 3, 3, 2, 1 ], K: 2, res: 4 },
        Args{ D: vec![ 1, 2, 1, 2, 1, 2, 1 ], K: 2, res: 2 },
    ];

    return super::run_all_tests("l1_kaitenzushi", args_list, wrapper, Option::None);
}
