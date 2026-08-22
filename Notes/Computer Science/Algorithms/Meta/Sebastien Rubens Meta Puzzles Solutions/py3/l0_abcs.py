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

def getSum(A: int, B: int, C: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=513411323351554
    # Constraints
    #   1 ≤ A,B,C ≤ 100
    # Complexity: O(1)

    return A + B + C


def tests():
    def fn(a, b, c): return a, b, c
    meta_cases = "meta", [
        [(1, 2, 3, ), 6],
        [(100, 100, 100, ), 300],
        [(85, 16, 93, ), 194],
    ]
    return getSum, fn, [meta_cases]


# End
