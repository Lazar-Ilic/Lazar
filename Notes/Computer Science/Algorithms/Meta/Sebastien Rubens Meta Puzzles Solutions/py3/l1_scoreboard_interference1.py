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

from typing import List


def getMinProblemCount(N: int, S: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=348371419980095
    # Constraints
    #   1 ≤ N ≤ 500,000             N is the number of scores
    #   1 ≤ Si ≤ 1,000,000,000      Si is a score
    # Complexity: O(N)

    # Note: the way to solve this problem is to count and his fairly simple
    # - the minimum number of problems scored 2 to solve all solutions
    # - the minimum number of problems scored 1 to solve all solutions (0 or 1)
    min_number_of_twos = 0
    min_number_of_ones = 0
    for score in S[:N]:
        number_of_twos = score // 2
        number_of_ones = score % 2
        min_number_of_twos = max(min_number_of_twos, number_of_twos)
        min_number_of_ones = max(min_number_of_ones, number_of_ones)
    return min_number_of_twos + min_number_of_ones


def tests():
    def fn(S): return len(S), S
    meta_cases = "meta", [
        (([1, 2, 3, 4, 5, 6], ), 4),
        (([4, 3, 3, 4], ), 3),
        (([2, 4, 6, 8], ), 4),
    ]
    return getMinProblemCount, fn, [meta_cases]


# End
