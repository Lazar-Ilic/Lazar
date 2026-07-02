
public class Main {
    public static void main(String[] args)
    {
        int nb_errors = 0;
        // l0
        nb_errors += l0_abcs.tests();
        nb_errors += l0_all_wrong.tests();
        nb_errors += l0_battleship.tests();
        // l2
        nb_errors += l2_rotary_lock2.tests();
        System.out.println("\n" + nb_errors + " errors found");
    }
}
