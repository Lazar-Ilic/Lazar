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


def getSecondsRequired(N: int, F: int, P: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=977526253003069
    # Constraints:
    #   2 ≤ N ≤ 10^12
    #   1 ≤ F ≤ 500,000
    #   1 ≤ Pi ≤ N−1
    # Complexity: O(N), but could be O(1) if P was sorted

    # When you think about it, the solution is very simple!
    return N - min(P[:F])


def tests():
    def fn(N, P): return N, len(P), P
    meta_cases = "meta", [
        ((3, [1], ), 2),
        ((6, [5, 2, 4], ), 4),
    ]
    return getSecondsRequired, fn, [meta_cases]


# End
