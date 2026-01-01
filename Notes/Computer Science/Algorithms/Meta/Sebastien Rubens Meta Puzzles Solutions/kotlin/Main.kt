
fun main(args: Array<String>) {
    var nb_errors = 0U;
    // l0
    nb_errors += l0_abcs.tests();
    nb_errors += l0_all_wrong.tests();
    nb_errors += l0_battleship.tests();
    // l1
    nb_errors += l1_cafeteria.tests();
    nb_errors += l1_director_photography1.tests();
    nb_errors += l1_kaitenzushi.tests();
    nb_errors += l1_rotary_lock1.tests();
    nb_errors += l1_scoreboard_interference1.tests();
    nb_errors += l1_stack_stabilization1.tests();
    nb_errors += l1_uniform_integers.tests();
    // l2
    nb_errors += l2_director_photography2.tests();
    nb_errors += l2_hops.tests();
    nb_errors += l2_missing_mail.tests();
    nb_errors += l2_portals.tests();  // FIXME #A: You solved 22 / 31 test cases, Wrong Answer on 9 test cases
    nb_errors += l2_rabbit_hole1.tests();
    nb_errors += l2_rotary_lock2.tests();
    nb_errors += l2_scoreboard_interference2.tests();
    nb_errors += l2_tunnel_time.tests();
    // l3
    nb_errors += l3_boss_fight.tests();
    nb_errors += l3_rabbit_hole2.tests();  // FIXME: You solved 15 / 22 test cases. Runtime Error on 7 test cases
    nb_errors += l3_slippery_strip.tests();  // FIXME #A: You solved 8 / 35 test cases., Time Limit Exceeded on 1 test case, Wrong Answer on 26 test cases
    nb_errors += l3_stack_stabilization2.tests();
    // l4
    nb_errors += l4_conveyor_chaos.tests();  // FIXME: You solved 17 / 19 test cases. Runtime Error on 2 test cases
    //nb_errors += l4_mathematical_art.tests();  // TODO

    // FIXME #A: should be working, but Meta's website seems to provide corrupted input test data
    // FIXME #A: for the tests affected (l2_portals and l3_slippery_strip), Meta should have been using
    // FIXME #A: Array<String> as test input, but used Array<Array<Char>> in all languages except Kotlin
    // FIXME #A: where it used Array<Array<String>> instead.  All String represent a single character, and
    // FIXME #A: each row is shifted to the right, and an empty String is inserted on the left, creating
    // FIXME #A: a mismatch between the expected value for the input data and result value for the shifted input data

    println("\n${nb_errors} errors found");
}
