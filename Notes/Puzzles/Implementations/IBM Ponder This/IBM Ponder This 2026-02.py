import random
import math
import statistics
from functools import lru_cache

# ---------- State representation ----------

def canonical_dist(state):
    if state == 'FIVE':
        return ((0,5),)
    back, gap = state
    front = 5 - back
    return ((0, back), (gap, front))

def dist_to_state(dist):
    # Reject blots
    for _, c in dist:
        if c == 1:
            return None

    if len(dist) == 1:
        if dist[0][1] == 5:
            return 'FIVE'
        return None

    if len(dist) == 2:
        (p1,c1),(p2,c2) = dist
        if sorted((c1,c2)) == [2,3]:
            gap = p2 - p1
            if gap > 0:
                return (c1, gap)  # back stack is first
    return None

# ---------- Move generation ----------

def move_one(dist, step):
    d = dict(dist)
    for pos in list(d.keys()):
        if d[pos] <= 0:
            continue
        nd = d.copy()
        nd[pos] -= 1
        if nd[pos] == 0:
            del nd[pos]
        nd[pos + step] = nd.get(pos + step, 0) + 1
        yield tuple(sorted(nd.items()))

def apply_moves(dist, moves):
    S = {dist}
    for step in moves:
        newS = set()
        for d in S:
            for nd in move_one(d, step):
                newS.add(nd)
        S = newS
    return S

@lru_cache(None)
def safe_next_states(state, roll):
    a,b = roll
    moves = [a,b] if a != b else [a]*4

    start = canonical_dist(state)
    finals = apply_moves(start, moves)

    result = set()
    for f in finals:
        s2 = dist_to_state(f)
        if s2 is not None:
            result.add(s2)

    return tuple(result)

# ---------- Dice distributions ----------

def roll_distribution(sides):
    rolls = []
    for a in range(1, sides+1):
        rolls.append(((a,a), 1/(sides*sides)))
    for a in range(1, sides+1):
        for b in range(a+1, sides+1):
            rolls.append(((a,b), 2/(sides*sides)))
    return rolls

# Special case for {1,2}
def roll_distribution_12():
    return [
        ((1,1), 1/4),
        ((2,2), 1/4),
        ((1,2), 1/2)
    ]

# ---------- Value iteration ----------

def compute_optimal(sides, Dmax=200):
    if sides == 2:
        rolls = roll_distribution_12()
    else:
        rolls = roll_distribution(sides)

    states = ['FIVE'] + [(2,d) for d in range(1,Dmax+1)] + [(3,d) for d in range(1,Dmax+1)]
    idx = {s:i for i,s in enumerate(states)}

    V = [0.0]*len(states)
    policy = {}

    for _ in range(200):  # converges fast
        Vnew = V.copy()
        for s in states:
            total = 1.0
            for r,p in rolls:
                nxt = [t for t in safe_next_states(s,r) if t in idx]

                if not nxt:
                    best = 0.0
                    choice = None
                else:
                    best = max(V[idx[t]] for t in nxt)
                    choice = max(nxt, key=lambda t: V[idx[t]])

                total += p * best
                policy[(s,r)] = choice

            Vnew[idx[s]] = total

        if max(abs(Vnew[i]-V[i]) for i in range(len(V))) < 1e-14:
            break
        V = Vnew

    return V[idx['FIVE']], policy, rolls

# ---------- Simulation ----------

def simulate(policy, rolls, N=1_000_000):
    roll_vals = [r for r,_ in rolls]
    probs = [p for _,p in rolls]

    # cumulative distribution
    cum = []
    s = 0
    for p in probs:
        s += p
        cum.append(s)

    def sample_roll():
        x = random.random()
        for i,c in enumerate(cum):
            if x <= c:
                return roll_vals[i]
        return roll_vals[-1]

    results = []

    for _ in range(N):
        state = 'FIVE'
        steps = 0

        while True:
            steps += 1
            r = sample_roll()

            if (state,r) not in policy or policy[(state,r)] is None:
                break

            state = policy[(state,r)]

        results.append(steps)

    mean = statistics.fmean(results)
    var = statistics.pvariance(results)
    se = math.sqrt(var/N)

    return mean, (mean - 1.96*se, mean + 1.96*se)

# ---------- Run ----------

if __name__ == "__main__":
    random.seed(0)

    v2, pol2, rolls2 = compute_optimal(2)
    print("Dice {1,2} expected rolls:", v2)

    v6, pol6, rolls6 = compute_optimal(6)
    print("Dice {1..6} expected rolls:", v6)

    print("\nSimulating...")

    m2, ci2 = simulate(pol2, rolls2, N=2_000_000)
    print("Sim {1,2}:", m2, "CI:", ci2)

    m6, ci6 = simulate(pol6, rolls6, N=3_000_000)
    print("Sim {1..6}:", m6, "CI:", ci6)