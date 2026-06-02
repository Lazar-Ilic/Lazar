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

pub fn _getArtisticPhotographCount<T>(_N: i32, C: &str, X: i32, Y: i32) -> T
    where T: std::default::Default + From<i32> + std::ops::AddAssign + std::ops::Mul<Output=T>
{
    type Index = usize;
    let _X = X as Index;
    let _Y = Y as Index;

    #[derive(Copy, Clone)]
    struct Counts
    {
        p: i32,
        b: i32,
    }

    let w = _Y + 1;
    let mut count = Counts{ p: 0, b: 0 };
    let mut counts = Vec::<Counts>::with_capacity(C.len() + (w * 2) as usize);
    for _ in 0..w {  // add space at the beginning to avoid special treatment of indices later
        counts.push(Counts{ p: 0, b: 0 });
    }
    for ci in C.chars() {
        if ci == 'P' {
            count.p += 1;
        }
        else if ci == 'B' {
            count.b += 1;
        }
        counts.push(count);
    }
    let last = *counts.last().unwrap();
    for _ in 0..w {  // add space at the end to avoid special treatment of indices later
        counts.push(last);
    }

    // To make things more readable, we are finding first the point where 'A' is found: O(N)
    let mut possible = Vec::<Index>::with_capacity(C.len());
    let mut j = w;
    for ci in C.chars() {
        if ci == 'A' {
            possible.push(j);
        }
        j += 1;
    }

    // Count PABs : O(N)
    let _X1: Index = _X - 1;
    let _Y1: Index = _Y + 1;
    let mut nb: T = Default::default();
    for i in &possible {
        nb += T::from(counts[i - _X].p - counts[i - _Y1].p) * T::from(counts[i + _Y].b - counts[i + _X1].b);
    }

    // Count BAPs : O(N)
    for i in &possible {
        nb += T::from(counts[i - _X].b - counts[i - _Y1].b) * T::from(counts[i + _Y].p - counts[i + _X1].p);
    }

    return nb;
}

pub fn getArtisticPhotographCount(N: i32, C: &str, X: i32, Y: i32) -> i32 {
    return _getArtisticPhotographCount::<i32>(N, C, X , Y);
}


type RetType = i32;

struct Args
{
    C: &'static str,
    X: i32,
    Y: i32,
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
    let wrapper = |p: &Args| -> RetType { getArtisticPhotographCount(p.C.len() as i32, &p.C, p.X, p.Y) };

    let args_list : Vec<Args> = vec![
        Args{ C: "APABA", X: 1, Y: 2, res: 1 },
        Args{ C: "APABA", X: 2, Y: 3, res: 0 },
        Args{ C: ".PBAAP.B", X: 1, Y: 3, res: 3 },
    ];

    return super::run_all_tests("l1_director_photography1", args_list, wrapper, Option::None);
}
