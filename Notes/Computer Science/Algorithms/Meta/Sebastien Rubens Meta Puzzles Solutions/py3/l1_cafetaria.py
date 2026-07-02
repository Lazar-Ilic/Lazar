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


def getMaxAdditionalDinersCount(N: int, K: int, M: int, S: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=203188678289677
    # Constraints
    #   1 ≤ N ≤ 10^15       N is the number of seats
    #   1 ≤ K ≤ N           K is the number of empty seats needed between occupied seats
    #   1 ≤ M ≤ 500,000     M is the number of diners
    #   1 ≤ Si ≤ N          Si is a seat
    # Complexity: O(M*log(M)), but the complexity could be O(M) if S was sorted

    # First, we sort elements of S: O(M*log(M))
    # and we are checking seat positions are valid too (1 <= si <= N)
    taken = sorted(si for si in S[:M] if 1 <= si <= N)

    # we are adding "fake" seats at the beginning and end to have a single loop: O(M)
    d = K + 1
    taken = [-K] + taken + [N+d]

    # we are calculating the extra seats available between each consecutive seats: O(M)
    nb = sum((b - a - d) // d for a, b in zip(taken, taken[1:]))
    return nb


def tests():
    def fn(N, K, S): return N, K, len(S), S
    meta_cases = "meta", [
        [(10, 1, [2, 6], ), 3],
        [(15, 2, [11, 6, 14], ), 1],
    ]
    return getMaxAdditionalDinersCount, fn, [meta_cases]


# End
