# meta_puzzles by Sebastien Rubens
#
# Please go to https://github.com/seb-pg/meta_puzzles/README.md
# for more information
#
# To the extent possible under law, the person who associated CC0 with
# meta_puzzles has waived all copyright and related or neighboring rights
# to meta_puzzles.
#
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

def get_local_modules():
    import os
    import re
    import importlib.util
    dirname = os.path.dirname(__file__)
    w = os.walk(dirname)
    files = next(w)[2]
    pattern = re.compile("^l\d_.*.py$")
    #files = sorted(os.sep.join([dirname, f]) for f in files if pattern.search(f) is not None)
    files = sorted(f[:-3] for f in files if pattern.search(f) is not None)
    tests_fns = []
    for f in files:
        m = importlib.import_module(f)
        if m:
            fn = getattr(m, 'tests', None)
            if fn:
                tests_fns.append((f, fn))
    return tests_fns


def format_args(args):
    return


if __name__ == "__main__":
    tests_fns = get_local_modules()
    nb_errors = 0
    for tests_name, tests_fn in tests_fns:
        ret = tests_fn()
        test_fn, extend_fn, all_tests = ret[:3]
        cmp = lambda res, exp: res == exp
        if len(ret) > 3:
            cmp = ret[3]
        for sub_name, tests in all_tests:
            print()
            print(tests_name, sub_name)
            if not tests:
                print("  no tests")
                continue
            for nb, (args, expected) in enumerate(tests, 1):
                ex_args = extend_fn(*args)
                res = test_fn(*ex_args)
                if cmp(res, expected):
                    print("  %s, test #%s: res=%s CORRECT" % (sub_name, nb, res))
                else:
                    print("  %s, test #%s: res=%s expected=%s ERROR <-----" % (sub_name, nb, res, expected))
                    nb_errors += 1
    print("\n%s errors found" % nb_errors)


# End
