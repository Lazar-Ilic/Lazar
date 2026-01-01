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

def getWrongAnswers(N: int, C: str) -> str:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=1082217288848574
    # Constraints
    #   1 ≤ N ≤ 100         N is the number of characters of string C
    #   Ci ∈ { "A", "B" }
    # Complexity: O(N)

    return ''.join('B' if c == 'A' else 'A' for c in C[:N])


def tests():
    def fn(C): return len(C), C
    meta_cases = "meta", [
        [("ABA", ), "BAB"],
        [("BBBBB", ), "AAAAA"],
    ]
    return getWrongAnswers, fn, [meta_cases]


# End
