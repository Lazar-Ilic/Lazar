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


def getMaximumEatenDishCount(N: int, D: List[int], K: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=958513514962507
    # Constraints
    #   1 ≤ N ≤ 500,000         N is the number of dishes
    #   1 ≤ K ≤ N               K is the number of previous dishes needed to be different
    #   1 ≤ Di ≤ 1,000,000      Di is a dish
    # Complexity: O(N) ~ O(max(N, 1_000_001))   (as asymptotically, N -> +inf)

    # The following is O(1_000_001)
    eaten = [False] * (1_000_000 + 1)  # we could use bitwise operation in c++ (std::vector<bool>)

    # The following is O(K) (where K < N)
    last_eaten = [0] * K  # circular buffer for last eaten value (0 is not used, as 1 <= Ki <= 1,000,000)
    oldest_eaten = 0

    # The following is O(N)
    nb = 0
    for dish in D[:N]:
        if not eaten[dish]:
            oldest_eaten = (oldest_eaten + 1) % K
            last_eaten_dish = last_eaten[oldest_eaten]
            eaten[last_eaten_dish] = False  # we remove the oldest eaten dish
            eaten[dish] = True
            last_eaten[oldest_eaten] = dish  # we add the newest eaten dish to our circular buffer
            nb += 1
    return nb


def tests():
    def fn(D, K): return len(D), D, K
    meta_cases = "meta", [
        (([1, 2, 3, 3, 2, 1], 1, ), 5),
        (([1, 2, 3, 3, 2, 1], 2, ), 4),
        (([1, 2, 1, 2, 1, 2, 1], 2, ), 2),
    ]
    return getMaximumEatenDishCount, fn, [meta_cases]


# End
