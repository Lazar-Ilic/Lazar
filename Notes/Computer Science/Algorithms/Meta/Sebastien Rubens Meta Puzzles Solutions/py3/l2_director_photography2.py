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

from dataclasses import dataclass


@dataclass
class Counts:
    p: int
    b: int


def getArtisticPhotographCount(N: int, C: str, X: int, Y: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=156565259776376
    # Constraints
    #   1 ≤ N ≤ 300,000     N is the number of cells in a row
    #   1 ≤ X ≤ Y ≤ N       X,Y are the distance between a photograph and an actor
    # Complexity: O(N) ~ O(N * (Y-X+1)) because Y-X << N

    C = C[:N]  # this is to be sure N = len(C)

    # count the number of Ps or Bs till a position i: O(N)
    w = Y + 1
    count_p, count_b = 0, 0
    counts = [Counts(0, 0)] * w  # add space at the beginning to avoid special treatment of indices later
    for ci in C:
        if ci == 'P':
            count_p += 1
        elif ci == 'B':
            count_b += 1
        counts.append(Counts(count_p, count_b))
    counts.extend([counts[-1]] * w)  # add space at the end to avoid special treatment of indices later

    # To make things more readable, we are finding first the point where 'A' is found: O(N)
    possible = [i for i, ci in enumerate(C, w) if ci == 'A']  # counting PAB

    # Count PABs: O(N)
    nb1 = sum((counts[i - X].p - counts[i - Y - 1].p) * (counts[i + Y].b - counts[i + X - 1].b) for i in possible)

    # Count BAPs: O(N)
    nb2 = sum((counts[i - X].b - counts[i - Y - 1].b) * (counts[i + Y].p - counts[i + X - 1].p) for i in possible)
    return nb1 + nb2


def tests():
    def fn(C, X, Y): return len(C), C, X, Y
    meta_cases = "meta", [
        (("APABA", 1, 2, ), 1),
        (("APABA", 2, 3, ), 0),
        ((".PBAAP.B", 1, 3, ), 3),
    ]
    extra1_cases = "extra1", [
        (("PP.A.BB.B", 1, 3, ), 4),
    ]
    return getArtisticPhotographCount, fn, [meta_cases, extra1_cases]


# End
