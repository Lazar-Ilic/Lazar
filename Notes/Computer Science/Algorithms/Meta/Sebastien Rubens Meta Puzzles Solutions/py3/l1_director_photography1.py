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

def getArtisticPhotographCount(N: int, C: str, X: int, Y: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=870874083549040
    # Constraints
    #   1 ≤ N ≤ 200         N is the number of cells in a row
    #   1 ≤ X ≤ Y ≤ N       X,Y are the distance between a photograph and an actor
    # Complexity: O(N) ~ O(N * (Y-X+1)) because Y-X << N

    # Note: the solution is not really elegant speed-wise, but focuses on the algorithm
    # The solution calculates the pairs of sub string (of width w), surrounding 'A' characters, this is O(N)
    w = Y - X + 1  # w = width of the interval
    c = ' ' * Y + C[:N] + ' ' * Y  # make our life easier by adding blank characters

    # calculation sub-intervals: O(N) ~ O(N * (Y-X+1))
    possible = [(c[i - Y: i - Y + w], c[i + X: i + X + w]) for i in range(Y, N + Y) if c[i] == 'A']

    # Now count the possible combination of (P, B) on both sides of eligible positions: O(N) ~ O(N * (Y-X+1))
    nb = sum(left.count('P') * right.count('B') for left, right in possible)
    nb += sum(left.count('B') * right.count('P') for left, right in possible)
    return nb


def tests():
    def fn(C, X, Y): return len(C), C, X, Y
    meta_cases = "meta", [
        (("APABA", 1, 2, ), 1),
        (("APABA", 2, 3, ), 0),
        ((".PBAAP.B", 1, 3, ), 3),
    ]
    extra1_cases = "extra1", [
        #(("PP.A.BB.B", 1, 3, ), 2),
    ]
    return getArtisticPhotographCount, fn, [meta_cases, extra1_cases]


# End
