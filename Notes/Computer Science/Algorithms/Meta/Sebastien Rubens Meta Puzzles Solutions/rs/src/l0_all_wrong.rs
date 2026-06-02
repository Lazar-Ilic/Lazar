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

pub fn getWrongAnswers(_N: i32, C: &str) -> String {
    // We are not using something like match c { 'A' => 'B', 'B' => 'A', _ => c }

    // Alternative 1
    let mut ret: String = String::with_capacity(C.len());
    for c in C.chars() {
        ret.push(if c == 'A' {'B'} else {'A'});
    }
    return ret;

    // Alternative 2 (one liner, no "reserve")
    //return String::from_iter(C.chars().map(|c| if c == 'A' {'B'} else {'A'}));
}


type RetType = String;

struct Args
{
    C: &'static str,
    res: RetType,
}

impl super::Result<RetType> for Args {
    fn get_result(&self) -> RetType
    {
        return self.res.to_string();
    }
}

pub fn tests() -> u32
{
    let wrapper = |p: &Args| -> RetType { getWrongAnswers(p.C.len() as i32, p.C) };

    let args_list : Vec<Args> = vec![
        Args{ C: "ABA", res: "BAB".to_string() },
        Args{ C: "BBBBB", res: "AAAAA".to_string() },
    ];

    return super::run_all_tests("l0_all_wrong", args_list, wrapper, Option::None);

}
