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
from dataclasses import dataclass, field


@dataclass
class DamageInfo:
    order: int = 0
    indices: List[int] = field(default_factory=lambda: [0, 0])
    damage: int = 0


def maximize_damage(N: int, H: List[int], D: List[int], info: DamageInfo):
    # this maximizes damage for a fixed index (max_i if order is True, otherwise max_j)
    # and also returns the value of max_i and max_j
    has_same_damage = True
    for i in range(N):
        index = info.indices[info.order]
        if index == i:
            continue
        if info.order == 0:
            new_damage = H[index] * D[index] + H[index] * D[i] + H[i] * D[i]
        else:
            new_damage = H[i] * D[i] + H[i] * D[index] + H[index] * D[index]
        if info.damage < new_damage:
            has_same_damage = False
            info.damage = new_damage
            info.indices[1 - info.order] = i
    return has_same_damage


def getMaxDamageDealt(N: int, H: List[int], D: List[int], B: int) -> float:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=149169347195386
    # Constraints:
    #   2 ≤ N ≤ 500,000
    #   1 ≤ Hi ≤ 1,000,000,000
    #   1 ≤ Di ≤ 1,000,000,000
    #   1 ≤ B ≤ 1,000,000,000
    # Complexity: O(N^2)

    # we are maximizing H[i] * D[i] + H[i] * D[j] + H[j] * D[j] where i < j

    damage_infos = []  # This contains only two solutions and was done this way to make things look simpler
    for order in [0, 1]:
        damage_info = DamageInfo(order)
        while True:  # N iterations at most
            has_same_damage = maximize_damage(N, H, D, damage_info)  # N iterations
            if has_same_damage:
                break
            damage_info.order = 1 - damage_info.order
            damage_infos.append(DamageInfo(**damage_info.__dict__))
    if not damage_infos:
        return 0.
    damage_info = max(damage_infos, key=lambda d: d.damage)  # do not really need to set key
    return damage_info.damage / B


def tests():
    def fn(H, D, B): return len(H), H, D, B

    meta_cases = "meta", [
        (([2, 1, 4], [3, 1, 2], 4, ), 6.5),
        (([1, 1, 2, 100], [1, 2, 1, 3], 8, ), 62.75),
        (([1, 1, 2, 3], [1, 2, 1, 100], 8, ), 62.75),
    ]
    extra1_cases = "extra1", [
        (([1, 1, 2, 100, 3], [1, 2, 1, 4, 100], 8, ), 1337.5),
        # what if all Hi*Di are equal?
        (([9, 1, 3, 4], [0, 10, 4, 3], 1, ), 100.0),
    ]
    return getMaxDamageDealt, fn, [meta_cases, extra1_cases], lambda res, exp: abs(res - exp) < 0.000001


# End
