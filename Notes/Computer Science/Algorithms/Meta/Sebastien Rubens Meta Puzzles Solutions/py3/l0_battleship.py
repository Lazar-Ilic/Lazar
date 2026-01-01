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


def getHitProbability(R: int, C: int, G: List[List[int]]) -> float:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=3641006936004915
    # Constraints
    #   1 ≤ R,C ≤ 100       R,C is the number of rows,columns
    #   0 ≤ Gi,j ≤ 1
    # Complexity: O(N), where N=R*C

    # Note: the solution prevents over/undersized rows/columns and assumes missing elements are 0
    return sum(elt for row in G[:R] for elt in row[:C]) / (R * C)


def tests():
    def fn(G): return len(G), len(G[0]), G
    meta_cases = "meta", [
        [([[0, 0, 1], [1, 0, 1]], ), 0.5],
        [([[1, 1], [1, 1]], ), 1.0],
    ]
    extra1_cases = "extra1", [
        [([[0, 1, 0, 0], [1, 1, 0, 0], [0, 0, 0, 0]],), 0.25],
    ]
    return getHitProbability, fn, [meta_cases, extra1_cases], lambda res, exp: abs(res - exp) < 0.000001


# End
