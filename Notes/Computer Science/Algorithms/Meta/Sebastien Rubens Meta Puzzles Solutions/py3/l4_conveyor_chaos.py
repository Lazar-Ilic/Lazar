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
from sortedcontainers import SortedSet


@dataclass
class Interval:
    n: int
    h: int
    xmin: int
    xmax: int
    children: List[object] = field(default_factory=lambda: [])
    # the following is used for cost calculation
    weight: float = 0.
    costs: List[float] = field(default_factory=lambda: [0., 0.])

    @property
    def width(self):
        return self.xmax - self.xmin

    @property
    def middle(self):
        return (self.xmax + self.xmin) / 2

    def __repr__(self):
        children = sorted([(drop_point, c.n) if c else -1 for drop_point, c in self.children])
        costs = [c / 1_000_000 for c in self.costs]
        return 'Interval(n=%d, h=%d, xmin=%.1f, xmax=%.1f, children=%s, costs=%s, weight=%.1f)' %\
               (self.n, self.h, self.xmin, self.xmax, children, costs, self.weight)

    def __hash__(self):  # for sortedcontainers.SortedSet
        return hash(self.h)

    def __lt__(self, rhs):  # for sortedcontainers.SortedSet
        return self.h < rhs.h


def build_intervals(N, H, A, B, x_min, x_max, h_min, h_max):  # O(N*log(N))
    G = N + 1
    mid = (h_max + h_min) / 2
    grd = Interval(0, h_min, float(x_min), float(x_max), [])  # ground level
    sky = Interval(G, h_max, float(x_min), float(x_max), [(mid, grd)])
    user_intervals = [Interval(n, h, float(a), float(b), [(mid, grd), (mid, grd)])
                      for n, (h, a, b) in enumerate(zip(H[:N], A, B), 1)]  # O(N)
    intervals = [grd] + user_intervals + [sky]
    intervals.sort(key=lambda p: p.h)  # O(N*log(N))
    return intervals


def add_entries(N, intervals):  # O(N*log(N))
    ground = intervals[0]
    mid = (ground.xmax + ground.xmin) / 2
    sky_h = intervals[-1].h

    # O(N*log(N))
    points = [(p.xmin, p, +1) for p in intervals[1:-1]] +\
             [(p.xmax, p, -1) for p in intervals[1:-1]]  # O(N)
    points.sort(key=lambda x: (x[0], x[1].h))  # O(N*log(N))

    # build entry intervals (we do not save intervals dropping immediately to the ground)
    intervals.pop()
    if points[0][0] > ground.xmin:
        intervals.append(Interval(0, sky_h, ground.xmin, -1, [(mid, ground)]))

    stack = SortedSet([ground])
    first, last_p, len_points = 0, None, len(points)
    while first < len_points:
        # find the set next set of rows for the current x
        x = points[first][0]
        last = first + 1
        while last < len_points:
            y, p, op = points[last]
            if x != y:
                break
            last += 1
        rows = points[first: last]
        #
        p = stack[-1]
        if last_p != p:  # if the interval is different
            last_p = p
            intervals.append(None)  # create some space
        # First pass, we remove intervals, and deal with addd/remove on left/right
        for _, p, op in rows:
            prev = stack[stack.bisect_left(p) - 1]  # O(log(N))
            if op == -1:  # "remove" interval
                p.children[1] = p.xmax, prev
                stack.remove(p)  # O(log(N))
            elif op == +1:  # "add" interval
                p.children[0] = p.xmin, prev
        # Second pass, we add intervals
        for _, p, op in rows:
            if op == +1:  # add interval
                stack.add(p)  # O(log(N))
        intervals[-1] = Interval(0, sky_h, x, -1,  [(0, stack[-1])])  # we do not know xmax at that stage
        #
        first = last
    #
    if intervals[-1].xmin == ground.xmax:
        intervals.pop()
    # stitching xmin and xmax
    for e1, e2 in zip(intervals[N + 1:], intervals[N + 2:]):
        e1.xmax = e2.xmin
    intervals[-1].xmax = ground.xmax
    # fix children by adding drop_point
    for n, p in enumerate(intervals[N + 1:], N):
        p.n = n
        _, child = p.children[0]
        p.children[0] = p.middle, child
    return intervals


def populate_costs(N, intervals):  # O(N)
    # set up weight for entry interval from the sky: O(N)
    for p in intervals[N + 1:]:
        p.weight = p.width if p.children[0][1].n > 0 else 0

    # Accumulate costs from top to bottom: O(E) where E is 2*N at most
    edges = []
    for parent in reversed(intervals[1:]):  # N iterations at most
        weight = 0.5 * parent.weight
        if weight == 0:
            continue
        for side, (drop_point, child) in enumerate(parent.children):
            if child.n > 0:
                cost_l = weight * (drop_point - child.xmin)
                cost_r = weight * (child.xmax - drop_point)
                child.weight += weight
                child.costs[0] += cost_l
                child.costs[1] += cost_r
                edges.append((parent, child, side, weight))

    # Accumulate costs from bottom to top: O(E) where E is 2*N at most
    for parent, child, side, weight in reversed(edges):
        parent.costs[side] += sum(child.costs) * weight / child.weight
    return intervals


def calc_dist(N, intervals):  # O(N)
    # calculate base_cost: O(N)
    base_cost = sum(p.costs[0] for p in intervals[N+1:])

    # calculate min_delta, min_dir, min_p: O(N)
    min_delta, min_dir, min_entry = 0, 0, None
    for entry in intervals[:N+1]:
        delta = entry.costs[0] - entry.costs[1]
        if min_delta > delta:
            min_delta, min_dir, min_p = delta, 0, entry
            continue
        delta *= -1
        if min_delta > delta:
            min_delta, min_dir, min_p = delta, 1, entry

    return base_cost, min_delta, min_dir, min_entry


def __getMinExpectedHorizontalTravelDistance(N: int, H: List[int], A: List[int], B: List[int]) -> float:
    params = dict(
            x_min=0, x_max=1_000_000,  # inclusive
            h_min=0, h_max=1_000_000,  # non inclusive
    )
    intervals = build_intervals(N, H, A, B, **params)  # O(N)
    intervals = add_entries(N, intervals)  # O(N*log(N))
    intervals = populate_costs(N, intervals)  # O(N)
    base_cost, min_delta, min_dir, min_entry = calc_dist(N, intervals)  # O(N)
    smallest_cost = (base_cost + min_delta) / (params['x_max'] - params['x_min'])
    return smallest_cost


def getMinExpectedHorizontalTravelDistance(N: int, H: List[int], A: List[int], B: List[int]) -> float:
    # https://www.metacareers.com/profile/coding_puzzles/?puzzle=280063030479374
    # Constraints:
    #   1 ≤ N ≤ 500,000
    #   1 ≤ Hi ≤ 999,999
    #   1 ≤ Ai < Bi ≤ 1,000,000
    # Complexity: O(N*log(N))
    return __getMinExpectedHorizontalTravelDistance(N, H, A, B)


def tests():
    def fn(H, A, B): return len(A), H, A, B
    meta_cases = "meta", [
        (([10, 20], [100000, 400000], [600000, 800000], ), 155000.0),
        (([2, 8, 5, 9, 4], [5000, 2000, 7000, 9000, 0], [7000, 8000, 11000, 11000, 4000], ), 36.5),
    ]
    extra1_cases = "extra1", [
        (([2, 4, 5, 8, 9], [5000, 0, 7000, 2000, 9000], [7000, 4000, 11000, 8000, 11000], ), 36.5),
        #
        (([10], [0], [1_000_000], ), 500_000.0),
        (([10], [0], [500_000], ), 125_000.0),
        (([9], [500_000], [1_000_000], ), 125_000.0),
        (([10, 9], [0, 500_000], [500_000, 1_000_000], ), 250_000.0),
        #
        (([20, 10], [200000, 400000], [600000, 800000], ), 120_000.0),
        (([20, 10], [400000, 200000], [800000, 600000], ), 120_000.0),
        (([20, 20, 10], [100000, 500000, 200000], [300000, 700000, 600000], ), 100_000.0),
        #
        (([1], [0], [1_000_000], ), 500_000.0),
        (([1], [250_000], [750_000], ), 125_000.0),
        (([1, 3, 3, 5],
         [400_000, 200_000,  600_000, 400_000],
         [700_000, 500_000, 1000_000, 700_000], ), 213750.0),  # direction=1 ; p=3 (base 247500.0)
        (([1, 3, 3, 5, 7],
         [400_000, 200_000,  600_000, 400_000, 400_000],
         [700_000, 500_000, 1000_000, 700_000, 600_000], ), 215000.0),  # direction=1 ; p=3 (base 247500.0)
    ]

    return getMinExpectedHorizontalTravelDistance, fn, [meta_cases, extra1_cases], lambda res, exp: abs(res - exp) < 0.000001


# End
