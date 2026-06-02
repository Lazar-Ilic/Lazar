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
import sys


def get_distance(target, position, N):
    positive_move = (target - position) % N
    negative_move = N - positive_move  # positive number
    return min(positive_move, negative_move)


def getMinCodeEntryTime(N: int, M: int, C: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=1637008989815525
    # Constraints:
    #   3 ≤ N ≤ 1,000,000,000   N is the number of integers
    #   1 ≤ M ≤ 3,000           M is the number of locks
    #   1 ≤ Ci ≤ N              Ci is the combination
    # Complexity: O(M^2)

    if not C:
        return 0
    solutions = {(1, 1): 0}
    for i, target in enumerate(C[:M]):  # M iterations
        new_solutions = {}
        for (dial1, dial2), distance in solutions.items():  # 2*M iterations at most
            # we turn dial1
            distance1 = distance + get_distance(target, dial1, N)
            key1 = min(dial2, target), max(dial2, target)
            new_solutions[key1] = min(new_solutions.get(key1, sys.maxsize), distance1)
            # we turn dial2
            distance2 = distance + get_distance(target, dial2, N)
            key2 = min(dial1, target), max(dial1, target)
            new_solutions[key2] = min(new_solutions.get(key2, sys.maxsize), distance2)
        solutions = new_solutions
    return min(solutions.values())


def tests():
    def fn(N, C): return N, len(C), C
    meta_cases = "meta", [
        ((3, [1, 2, 3], ), 2),
        ((10, [9, 4, 4, 8], ), 6),
    ]
    extra1_cases = "extra1", [
        ((0, [], ), 0),
        ((3, [], ), 0),
        ((10, [], ), 0),
        ((10, [4], ), 3),
        ((10, [9], ), 2),
        ((10, [9, 9, 9, 9], ), 2),
    ]
    extra2_cases = "extra2", [
        ((10, [6, 2, 4, 8], ), 10),  # <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
        ((10, [10, 9, 8, 7, 6, 5, 4, 3, 2, 1], ), 9),  # <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
        ((4, [4, 3, 2, 1, 2, 3, 4], ), 5),  # <- this is a case highlighting issue: best (1,+5), (2,+1), (2,+2), (1,-2)
    ]
    return getMinCodeEntryTime, fn, [meta_cases, extra1_cases, extra2_cases]


# End
