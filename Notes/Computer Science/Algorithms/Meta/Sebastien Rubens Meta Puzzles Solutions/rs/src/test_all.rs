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

mod l0_abcs;
mod l0_all_wrong;
mod l0_battleship;

mod l1_cafeteria;
mod l1_director_photography1;
mod l1_kaitenzushi;
mod l1_rotary_lock1;
mod l1_scoreboard_interference1;
mod l1_stack_stabilization1;
mod l1_uniform_integers;

mod l2_director_photography2;
mod l2_hops;
mod l2_missing_mail;
mod l2_portals;
mod l2_rabbit_hole1;
mod l2_rotary_lock2;
mod l2_scoreboard_interference2;
mod l2_tunnel_time;

mod l3_boss_fight;
mod l3_rabbit_hole2;
mod l3_slippery_strip;
mod l3_stack_stabilization2;

pub trait Result<T> {
    fn get_result(&self) -> T;
}

// TODO: without using macros...
// TODO: ... is there a way to have a generic implementation of "compare",
// TODO: ... and a single specialization for f32/f64?

trait ResultEquality {
    fn compare(&self, rhs: &Self, precision: Option<f64>) -> bool;
}

macro_rules! result_equality_impl {
    ($($t:ty)*) => ($(
        impl ResultEquality for $t {
            fn compare(&self, rhs: &$t, _precision: Option<f64>) -> bool { return *self == *rhs; }
        }
    )*)
}

result_equality_impl! { usize u8 u16 u32 u64 u128 isize i8 i16 i32 i64 i128 String }

impl ResultEquality for f64 {
    fn compare(&self, rhs: &f64, precision: Option<f64>) -> bool {
        return (*self - *rhs) < precision.unwrap();
    }
}

fn run_all_tests<Args, Ret>(name: &'static str, args_list: Vec<Args>, fnc: fn(&Args) -> Ret, _precision: Option<f64>) -> u32
    where Args: Result<Ret>, Ret: std::fmt::Display + ResultEquality
{
    let mut nb_errors: u32 = 0;
    println!("\n{}", name);
    let mut nb: u32 = 1;
    for args in &args_list
    {
        let res = fnc(args);
        let expected = args.get_result();
        let is_same = res.compare(&expected, _precision);
        if is_same {
            println!("  test #{}: res={} CORRECT", nb, res);
        }
        else
        {
            println!("  test #{}: res={} expected={} ERROR <-----", nb, res, expected);
            nb_errors += 1;
        }
        nb += 1;
    }
    return nb_errors;
}


#[allow(non_snake_case)]
fn main() {
    // The Rust version is based on the C++17 version
    // The tests are minimum for now, and not all puzzles solutions have been published yet
    let mut nb_errors: u32 = 0;

    // l0
    nb_errors += l0_abcs::tests();
    nb_errors += l0_all_wrong::tests();
    nb_errors += l0_battleship::tests();
    // l1
    nb_errors += l1_cafeteria::tests();
    nb_errors += l1_director_photography1::tests();
    nb_errors += l1_kaitenzushi::tests();
    nb_errors += l1_rotary_lock1::tests();
    nb_errors += l1_scoreboard_interference1::tests();
    nb_errors += l1_stack_stabilization1::tests();
    nb_errors += l1_uniform_integers::tests();
    // l2
    nb_errors += l2_director_photography2::tests();
    nb_errors += l2_hops::tests();
    nb_errors += l2_missing_mail::tests();
    nb_errors += l2_portals::tests();
    nb_errors += l2_rabbit_hole1::tests();
    nb_errors += l2_rotary_lock2::tests();
    nb_errors += l2_scoreboard_interference2::tests();
    nb_errors += l2_tunnel_time::tests();
    // l3
    nb_errors += l3_boss_fight::tests();
    nb_errors += l3_rabbit_hole2::tests();  // TODO: see FIXME
    nb_errors += l3_slippery_strip::tests();
    nb_errors += l3_stack_stabilization2::tests();
    // l4 (not done yet)
    //nb_errors += l4_conveyor_chaos::tests();  // TODO: not implemented yet
    //nb_errors += l4_mathematical_art::tests();  // TODO: not implemented yet

    println!("\n{} errors found",  nb_errors);
}
