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


def getSecondsElapsed(C: int, N: int, A: List[int], B: List[int], K: int) -> int:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=1492699897743843
    # Constraints:
    #   3 ≤ C ≤ 10^12       C is the circumference
    #   1 ≤ N ≤ 500,000     N is the number of tunnels
    #   1 ≤ Ai < Bi ≤ C     Ai and Bi are the start and end of the tunnels
    #   1 ≤ K ≤ 10^12       K is the time spent in tunnels
    # Complexity: O(N*log(N)), would be O(N) if tunnels were sorted

    tunnel_time_total = sum((b - a) for a, b in zip(A, B))  # O(N)
    number_of_complete_track = (K // tunnel_time_total)  # O(1)
    total_time_left = K - number_of_complete_track * tunnel_time_total  # O(1)
    travel_time = number_of_complete_track * C  # O(1)
    if total_time_left == 0:
        travel_time -= C - max(B)  # O(N)
    else:
        tunnels = sorted(zip(A, B))  # O(N*log(N))
        for a, b in tunnels:    # O(N)
            tunnel_length = b - a
            if tunnel_length >= total_time_left:
                travel_time += a + total_time_left
                break
            total_time_left -= tunnel_length
    return travel_time


def tests():
    def fn(C, A, B, K): return C, min(len(A), len(B)), A, B, K
    meta_cases = "meta", [
        ((10, [1, 6], [3, 7], 7, ), 22),
        ((50, [39, 19, 28], [49, 27, 35], 15, ), 35),
    ]
    extra1_cases = "extra1", [
        ((50, [19, 28, 39], [27, 35, 49], 1, ), 20),  # tunnel length = 25 [8, 7, 10]
        ((50, [19, 28, 39], [27, 35, 49], 8, ), 27),
        ((50, [19, 28, 39], [27, 35, 49], 9, ), 29),
        ((50, [19, 28, 39], [27, 35, 49], 15, ), 35),
        ((50, [19, 28, 39], [27, 35, 49], 16, ), 40),
        ((50, [19, 28, 39], [27, 35, 49], 25, ), 49),
        ((50, [19, 28, 39], [27, 35, 49], 26, ), 50 + 20),
    ]
    return getSecondsElapsed, fn, [meta_cases, extra1_cases]


# End
