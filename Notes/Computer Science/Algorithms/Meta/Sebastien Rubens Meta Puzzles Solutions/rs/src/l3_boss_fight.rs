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

type DamageT = u64;

#[derive(Clone)]
struct DamageInfo {
    order: usize,
    indices: [usize; 2],
    damage: DamageT,
}

impl DamageInfo {
    fn new(order: usize) -> DamageInfo {
        DamageInfo{ order, indices: [ 0, 0 ], damage: 0 }
    }
}

fn maximize_damage(N: i32, H: &Vec<i32>, D: &Vec<i32>, info: &mut DamageInfo) -> bool {
    let mut has_same_damage = true;
    for i in 0..N as usize {
        let j = info.indices[info.order];
        if j == i {
            continue;
        }
        let new_damage: DamageT;
        let Hi = H[i] as DamageT;
        let Hj = H[j] as DamageT;
        let Di = D[i] as DamageT;
        let Dj = D[j] as DamageT;
        if info.order == 0 {
            new_damage = Hj * Dj + Hj * Di + Hi * Di;
        }
        else {
            new_damage = Hi * Di + Hi * Dj + Hj * Dj;
        }
        if info.damage < new_damage {
            has_same_damage = false;
            info.damage = new_damage;
            info.indices[1 - info.order] = i;
        }
    }
    return has_same_damage;
}

pub fn getMaxDamageDealt(N: i32, H: &Vec<i32>, D: &Vec<i32>, B: i32) -> f64 {
    let mut damage_infos = Vec::<DamageInfo>::new();
    for order in 0..2 {
        let mut damage_info = DamageInfo::new(order);
        loop {
            let has_same_damage = maximize_damage(N, H, D, &mut damage_info);
            if has_same_damage {
                break;
            }
            damage_info.order = 1 - damage_info.order;
            damage_infos.push(damage_info.clone());
        }
    }

    if damage_infos.is_empty() {
        return 0.0;
    }

    let max_damage = damage_infos.iter().max_by_key(|&x| x.damage).unwrap().damage;
    return (max_damage as f64) / (B as f64);
}


type RetType = f64;

struct Args
{
    H: Vec<i32>,
    D: Vec<i32>,
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
    let wrapper = |p: &Args| -> RetType { getMaxDamageDealt(p.H.len() as i32, &p.H, &p.D, p.B) };

    let args_list : Vec<Args> = vec![
        Args{ H: vec![ 2, 1, 4 ], D: vec![ 3, 1, 2 ], B: 4, res: 6.5 },
        Args{ H: vec![ 1, 1, 2, 100 ], D: vec![ 1, 2, 1, 3 ], B: 8, res: 62.75 },
        Args{ H: vec![ 1, 1, 2, 3 ], D: vec![ 1, 2, 1, 100 ], B: 8, res: 62.75 },
        // extra1
        Args{ H: vec![ 1, 1, 2, 100, 3 ], D: vec![ 1, 2, 1, 4, 100 ], B: 8, res: 1337.5 },
        Args{ H: vec![ 9, 1, 3, 4 ], D: vec![ 0, 10, 4, 3 ], B: 1, res: 100.0 },
    ];

    return super::run_all_tests("l3_boss_fight", args_list, wrapper, Option::Some(0.000_001));
}
