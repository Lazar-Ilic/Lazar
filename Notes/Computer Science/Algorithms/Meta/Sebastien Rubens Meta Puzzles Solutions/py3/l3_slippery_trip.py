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


def get_counts(row, counts):
    # complexity: O(C)
    counts[ord('*')] = 0
    counts[ord('>')] = 0
    counts[ord('v')] = 0
    for c in row:
        ord_c = ord(c)
        if ord_c >= 256:
            ord_c = ord('.')
        counts[ord_c] += 1
    count_star = counts[ord('*')]
    count_right = counts[ord('>')]
    count_down = counts[ord('v')]
    return count_star, count_right, count_down


def get_nb_coins_right_then_down3(row, count_down, count_right):
    # Complexity: O(C)
    if count_down == 0:
        return 0
    j = row.index('v') + 1
    new_row = row[j:] + row[:j]  # transform the string the end with 'v'
    nb_coins_right_then_down, nb_coins, last = 0, 0, 0
    while count_right * count_down != 0:
        first = new_row.index('>', last)
        last = new_row.index('v', first) + 1
        nb_coins_right_then_down = max(nb_coins_right_then_down, new_row[first: last].count('*'))
        count_down -= 1
        count_right -= new_row[first: last].count('>')
    return nb_coins_right_then_down


def getMaxCollectableCoins(R: int, C: int, G: List[List[str]]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=2881982598796847
    # Constraints
    #   2 ≤ R, C ≤ 400,000
    #   R∗C ≤ 800,000
    #   Gi,j ∈ {".", "*", ">", "v"}
    # Complexity: O(N), where N = R*C

    counts = [0] * 256
    res = 0
    for row in G[::-1]:  # O(R)
        count_star, count_right, count_down = get_counts(row, counts)  # O(C)
        nb_coins_immediately_down = min(count_star, 1)
        if count_right == C:  # we can only go right
            res = 0
        elif count_right == 0:  # we cannot go right
            res += nb_coins_immediately_down
        else:
            # at the stage, we have a choice between:
            # - going down immediately (nb_coins_immediately_down), or
            # - going right then down (nb_coins_right_then_down), or
            # - going right forever (nb_coins_right_forever).
            nb_coins_right_then_down = get_nb_coins_right_then_down3(row, count_down, count_right)  # O(C)
            nb_coins_right_forever = count_star if count_down == 0 else 0
            res = max(nb_coins_immediately_down + res, nb_coins_right_then_down + res, nb_coins_right_forever)
    return res


def tests():
    def fn(G): return len(G), len(G[0]) if G else 0, G

    meta_cases = "meta", [
        (([".***", "**v>", ".*.."], ), 4),
        (([">**", "*>*", "**>"], ), 4),
        (([">>", "**"], ), 0),
        (([">*v*>*", "*v*v>*", ".*>..*", ".*..*v"], ), 6),
    ]
    extra1_cases = "extra1", [
        (([], ), 0),
        ((["."], ), 0),
        ((["v"], ), 0),
        (([">"], ), 0),
        ((["*"], ), 1),
    ]
    extra2_cases = "extra2", [
        (([".", ".", ">", "*"], ), 0),
        (([".", "*", ">", "*"], ), 1),
        (([".", "*", ">", "."], ), 1),
        ((["*", ".", ">", "."], ), 1),
        ((["***", "...", ">vv", "..."], ), 1),
    ]
    extra3_cases = "extra3", [
        ((["*....", ".*...", "..*..", "...*."], ), 4),
        ((["....", "....", "....", "...."], ), 0),
        ((["***>", "...."], ), 3),
        ((["...."], ), 0),
        ((["vvvv"], ), 0),
        ((["vvvv", "....", ">>>>"], ), 0),
    ]
    extra4_cases = "extra4", [
        ((["******", "......", ">*>vvv", "......"], ), 2),
        ((["*****", ".....", ">>vvv", "....."], ), 1),
    ]
    return getMaxCollectableCoins, fn, [meta_cases, extra1_cases, extra2_cases, extra3_cases, extra4_cases]


# End
