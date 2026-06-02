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


def getMinCodeEntryTime(N: int, M: int, C: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=990060915068194
    # Constraints
    #   3 ≤ N ≤ 50,000,000      N is the number of integers
    #   1 ≤ M ≤ 1,000           M is the number of locks
    #   1 ≤ Ci ≤ N              Ci is the combination
    # Complexity: O(M)

    pos = 1
    nb = 0
    for target in C[:M]:
        positive_move = (target - pos) % N  # positive move
        negative_move = N - positive_move
        nb += min(positive_move, negative_move)
        pos = target
    return nb


def tests():
    def fn(N, C): return N, len(C), C
    meta_cases = "meta", [
        ((3, [1, 2, 3], ), 2),
        ((10, [9, 4, 4, 8], ), 11),
    ]
    return getMinCodeEntryTime, fn, [meta_cases]


# End
