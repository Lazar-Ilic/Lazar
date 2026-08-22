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


def getMinimumSecondsRequired(N: int, R: List[int], A: int, B: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=290955626029019
    # Constraints:
    #   1 ≤ N ≤ 50
    #   1 ≤ Ri ≤ 1,000,000,000
    #   1 ≤ A,B ≤ 100
    # Complexity: O(N^2)

    # This could be optimised greatly (e.g. finding first could be O(N)) but the engineering cost is not worth it
    if N == 0 or not R:
        return 0
    cost = 0
    costs = [0] * N
    intervals = [0]
    for i in range(1, N):
        min_inflate = R[i - 1] + 1 - R[i]
        # inflate first
        if min_inflate > 0:
            cost += min_inflate * A
            R[i] += min_inflate
            costs[i] = min_inflate
        # track continuous intervals
        if min_inflate < 0:
            intervals.append(i)
            continue
        # deflate eventually
        while True:
            first = intervals[-1]
            nb_tot = i + 1 - first
            #
            nb_pos, min_pos1 = 0, 0
            for value in costs[first: i + 1]:
                if value > 0:
                    nb_pos += 1
                    min_pos1 = min(min_pos1, value) if min_pos1 > 0 else value
            #
            min_pos2 = (R[first] - R[first - 1]) if (first > 0) else R[0]
            min_pos = min(min_pos1, min_pos2 - 1)
            nb_neg = nb_tot - nb_pos
            cost_change = (nb_neg * B - nb_pos * A) * min_pos
            if cost_change > 0:
                break
            cost += cost_change
            for j in range(first, i + 1):
                costs[j] -= min_pos
                R[j] -= min_pos
            if first > 0:
                if R[first] == R[first - 1] + 1:
                    intervals.pop()
            if min_pos <= 0:
                break
    return cost


def tests():
    def fn(R, A, B): return len(R), R, A, B

    meta_cases = "meta", [
        (([2, 5, 3, 6, 5], 1, 1, ), 5),  # -2, +1
        (([100, 100, 100], 2, 3, ), 5),
        (([100, 100, 100], 7, 3, ), 9),
        (([6, 5, 4, 3], 10, 1, ), 19),
        (([100, 100, 1, 1], 2, 1, ), 207),
        (([6, 5, 2, 4, 4, 7], 1, 1, ), 10),
    ]
    extra1_cases = "extra1", [
        (([10, 6, 2], 2, 1, ), 15),
        (([1, 2, 3, 4, 5, 6], 1, 1, ), 0),
        (([6, 5, 4, 3, 2, 1], 1, 1, ), 18),
    ]
    extra2_cases = "extra2", [
        (([4, 6, 2], 2, 1, ), 9),
        (([6, 5, 2, 4, 4, 7], 1, 1, ), 10),
        (([2, 5, 3, 6, 5], 1, 1, ), 5),  # -2, +1
        (([2, 3, 8, 1, 7, 6], 2, 1, ), 15),  # -2, +1
        (([5, 4, 3, 6, 8, 1, 10, 11, 6, 1], 4, 1, ), 85),
        (([3, 4, 7, 8, 2], 4, 1, ), 24),
        (([1, 1, 1, 1, 1], 4, 1, ), 40),
        (([1, 1, 1, 1, 1], 1, 4, ), 10),
        (([8, 6, 4, 2], 1, 4, ), 18),
        (([1_000_000_000, 500_000_000, 200_000_000, 1_000_000], 1, 4, ), 2_299_000_006),
    ]
    return getMinimumSecondsRequired, fn, [meta_cases, extra1_cases, extra2_cases]


# End
