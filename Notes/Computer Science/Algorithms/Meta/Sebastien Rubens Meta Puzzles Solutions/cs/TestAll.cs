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

using System;
using System.Collections.Generic;

namespace test_all
{

    class Res<T>
    {
        public T res;
    }

#nullable enable annotations

    class TestAll
    {

        public static int run_all_tests<Args, Ret>(String name, List<Args> args_list, Func<Args, Ret> fn, double precision = 0.0)
            where Args : Res<Ret>
            where Ret : IEquatable<Ret>
        {
            Console.WriteLine("\n{0}", name);

            int nb_errors = 0;
            int nb = 1;
            foreach (Args args in args_list)
            {
                var res = fn(args);
                bool is_same = res.Equals(args.res);
                if (typeof(Ret) == typeof(double))
                {
                    var x = (double)Convert.ChangeType(res, typeof(double));
                    var y = (double)Convert.ChangeType(args.res, typeof(double));
                    is_same = Math.Abs(x - y) <= precision;
                }

                if (is_same)
                    Console.WriteLine("  test #{0}: res={1} CORRECT", nb, res);
                else
                {
                    Console.WriteLine("  test #{0}: res={1} expected={2} ERROR <-----", nb, res, args.res);
                    nb_errors += 1;
                }
                ++nb;
            }

            return nb_errors;
        }

    }

}
