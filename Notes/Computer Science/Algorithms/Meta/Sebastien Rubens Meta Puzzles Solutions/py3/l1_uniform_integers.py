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

def getUniformIntegerCountInInterval(A: int, B: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=228269118726856
    # Constraints:
    #   1 ≤ A ≤ B ≤ 10^12
    # Complexity: O(log(max(A, B)))
    #       logarithmic on the number of digits to represent the integers
    #       The python version works using integer<->string conversion, which is not great

    # Each of the following lines is O(log(max(A, B))) (conversion base 2 to base 10/str)
    len_a, len_b = len(str(A)), len(str(B))
    tmp_a, tmp_b = int('1' * len_a), int('1' * len_b)

    # Everything else is O(1)
    nb_a = (tmp_a * 10 - A) // tmp_a
    nb_b = B // tmp_b
    nb_m = 9 * (len_b - len_a - 1) if len_b - len_a >= 2 else 0
    nb = nb_a + nb_m + nb_b

    if len_a == len_b:
        nb -= 9
    return nb


def tests():
    def fn(A, B): return A, B
    meta_cases = "meta", [
        ((75, 300, ), 5),
        ((1, 9, ), 9),
        ((999999999999, 999999999999, ), 1),
    ]
    extra1_cases = "extra1", [
        ((1, 1_000_000_000_000, ), 108),
    ]
    extra2_cases = "extra2", [
        ((10, 99, ), 9),
        ((11, 98, ), 8),
        ((21, 89, ), 7),
        ((22, 88, ), 7),
        ((23, 87, ), 5),
    ]
    extra3_cases = "extra3", [
        ((11, 88, ), 8),
        ((11, 98, ), 8),
        ((11, 99, ), 9),
    ]
    return getUniformIntegerCountInInterval, fn, [meta_cases, extra1_cases, extra2_cases, extra3_cases]


# End
