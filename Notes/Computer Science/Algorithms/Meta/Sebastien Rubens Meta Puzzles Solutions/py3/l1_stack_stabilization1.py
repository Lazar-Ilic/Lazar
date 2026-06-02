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


def getMinimumDeflatedDiscCount(N: int, R: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=183894130288005
    # Constraints
    #   1 ≤ N  ≤ 50                 N is the number of inflatable discs
    #   1 ≤ Ri ≤ 1,000,000,000      Ri is a disc radius
    # Complexity: O(N)

    radiuses = R[:N]
    nb = 0
    current_radius = radiuses[-1]
    for next_radius in radiuses[-2::-1]:
        target_radius = current_radius - 1
        if target_radius <= 0:
            return -1
        nb += 1 if target_radius < next_radius else 0
        current_radius = min(next_radius, target_radius)
    return nb


def tests():
    def fn(S): return len(S), S
    meta_cases = "meta", [
        (([2, 5, 3, 6, 5], ), 3),
        (([100, 100, 100], ), 2),
        (([6, 5, 4, 3], ), -1),
    ]
    return getMinimumDeflatedDiscCount, fn, [meta_cases]


# End
