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

//trait Result[T]:
//  def get_result(): T

import java.util.function.Function;

public class test_all {

public interface Result<T> {
    T getResult();
}

static <Args extends Result<Ret>, Ret> int run_all_tests(String name, Args[] args_list, Function<Args, Ret> fnc, Double... precision)
{
    System.out.printf("\n%s\n", name);
    int nb_errors = 0;
    int nb = 1;
    for (Args args : args_list)
    {
        var res = fnc.apply(args);
        var expected = args.getResult();
        var is_same = false;
        if (res instanceof Double)
            is_same = Math.abs((double) res - (double) expected) < precision[0];
        else
            is_same = expected.equals(res);
        if (is_same) {
            System.out.printf("  test #%s: res=%s CORRECT\n", nb, String.valueOf(res));
        }
        else {
            System.out.printf("  test #%s: res=%s expected=%s ERROR <-----\n", nb, String.valueOf(res), String.valueOf(expected));
            nb_errors += 1;
        }
        nb += 1;
    }
    return nb_errors;
}

}
