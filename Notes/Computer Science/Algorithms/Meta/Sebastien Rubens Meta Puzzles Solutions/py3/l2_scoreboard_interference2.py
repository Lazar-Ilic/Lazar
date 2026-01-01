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


def getMinProblemCount(N: int, S: List[int]) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=503122501113518
    # Constraints:
    #   1 ≤ N ≤ 500,000
    #   1 ≤ i ≤ 1,000,000,000
    # Complexity: O(N)

    max_score, second_max_score,  two_remainder, one_remainder, need_one = 0, 0, 0, 0, False
    for score in S[:N]:
        score_mod_3 = score % 3
        two_remainder |= (score_mod_3 >> 1)
        one_remainder |= (score_mod_3 & 1)
        need_one = need_one or (score == 1)
        if max_score < score:
            second_max_score = max_score
            max_score = score
        elif second_max_score < score:
            second_max_score = score

    # number of solutions, without any optimisation
    count = max_score // 3 + two_remainder + one_remainder

    # not optimisation is possible if "two_remainder and one_remainder" is not true
    if two_remainder * one_remainder != 1:
        return count

    # replace "last +3" by "+1+2"
    if max_score % 3 == 0:
        count -= 1

    # replace last "+3+1" by "+2+2"
    if need_one:  # exit early because 1 is required but at least one sum (i.e. it cannot be replaced)
        return count
    if max_score % 3 != 1:  # max_score does not have a 1 (so it cannot be replaced)
        return count
    if (max_score - second_max_score) not in (1, 3):  # [ ok, not ok (3), ok ] || [ not ok (1) | here | unimportant ]
        count -= 1
    return count


def tests():
    def fn(S): return len(S), S
    meta_cases = "meta", [
        (([1, 2, 3, 4, 5], ), 3),       # problems would be [1, 1, 3]
        (([4, 3, 3, 4], ), 2),          # problems would be [1, 3]
        (([2, 4, 6, 8], ), 4),          # problems would be [2, 2, 2, 2]
        (([8], ), 3),                   # problems would be [2, 3, 3]
    ]
    extra1_cases = "extra1", [
        (([1, 2, 3, 4, 5], ), 3),       # problems would be [1, 1, 3]
        (([4, 3, 3, 4], ), 2),          # problems would be [1, 3]
        (([2, 4, 6, 8], ), 4),          # problems would be [2, 2, 2, 2]
        (([8], ), 3),                   # problems would be [2, 3, 3]
        (([1, 2, 3], ), 2),             # problems would be [2, 2, 2]
        (([5, 7], ), 3),                # problems would be [(3+2), (3+2+2)]
        (([5, 9, 10], ), 5),            # problems would be [(3+0+2+0), (3+3+0+0), (3+3+0+1)]
        (([5, 9, 11], ), 4),            # problems would be [(3+0+2), (3+3+0), (3+3+2)]
        (([2, 4, 6], ), 3),             # problems would be [(2+0+0), (2+2+0), (2+2+2)]
        (([2, 4, 7], ), 4),             # problems would be [(2+0+0), (2+2+0), (2+2+3)]
    ]
    extra2_cases = "extra2", [
        (([1, 2, 4], ), 3),  # problems would be [(1+0+0+0), (0+2+0+0), (0+2+2)]
        (([2, 4], ), 2),  # problems would be [(2+0), (2+2)]
        (([4, 5], ), 3),  # problems would be [(2+2), (2+2+1) or (2+3)]
        (([9, 12], ), 4),  # problems would be [(3+3+3), (3+3+3+3)]
        (([11, 13], ), 5),  # problems would be [(3+3+3+2), (3+3+3+3+1=3+3+3+2+2)]
        # edge case: {2,4,6}-->{1,2,3}
        # // deal with the 2nd big num is the edge case of {2,4,7}
        # edge case : 2 4 7, {1, 2, 3, 3} -> {2, 2, 3}   3 questions
        # deal with the 2nd big num is the edge case of {2,4,6}
    ]
    return getMinProblemCount, fn, [meta_cases, extra1_cases, extra2_cases]


# End
