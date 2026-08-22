#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# fc_value_progress.py
#
# Fast evaluation of f(r,c) for the Alice/Bob cutting game with progress.
# Non-notebook-friendly: expects exactly TWO positional args (r and c).
#
# Each arg may be:
#   - a decimal integer, e.g. 123456789...
#   - OR a factorized string using '^' and separators '*', 'x', or '×', e.g.:
#       151^3×239^2×1229^3×4691^11×5879^7×7351×8317^3×8501×10133^7×16339×16883^6×16903^6
#
# Example:
#   python fc_value_progress.py "4691^11×10133^7×16883^6" "151^3×239^2×1229^3×5879^7"

import sys, time, math, random
from functools import lru_cache

# ---------------- Utils: parse integers or factorized strings ----------------

def parse_n_or_factors(s: str) -> tuple[int, tuple[tuple[int,int],...]]:
    """
    Return (n, factors_tuple). If input is factorized, we compute n from it and
    return factors directly. If input is decimal, factors_tuple is empty (to be factored).
    """
    t = s.strip().lower().replace('×','*').replace('x','*')
    if t.isdigit():
        return int(t), ()
    parts = [p for p in t.split('*') if p]
    out = {}
    n = 1
    for part in parts:
        if '^' in part:
            a,b = part.split('^',1)
            p = int(a.strip()); e = int(b.strip())
        else:
            p = int(part.strip()); e = 1
        if p < 2 or e < 1:
            raise ValueError(f"Bad factor: {part}")
        out[p] = out.get(p,0) + e
        n *= pow(p,e)
    return n, tuple(sorted(out.items()))

def multiset_desc(facts: tuple[tuple[int,int],...]) -> list[int]:
    ms = []
    for p,e in facts:
        ms.extend([p]*e)
    ms.sort(reverse=True)
    return ms

def tau_from_facts(facts: tuple[tuple[int,int],...]) -> int:
    t = 1
    for _,e in facts:
        t *= (e+1)
    return t

# ---------------- Prime sieve up to 100k ----------------

def sieve_primes(limit: int) -> list[int]:
    if limit < 2: return []
    sv = bytearray(b"\x01")*(limit+1)
    sv[0:2] = b"\x00\x00"
    r = int(limit**0.5)
    for p in range(2, r+1):
        if sv[p]:
            start = p*p
            sv[start:limit+1:p] = b"\x00"*(((limit-start)//p)+1)
    return [i for i,b in enumerate(sv) if b]

PRIMES_100K = sieve_primes(100_000)
_SMALL = [2,3,5,7,11,13,17,19,23,29]

# ---------------- Miller–Rabin (probabilistic) ----------------

def is_probable_prime(n: int) -> bool:
    if n < 2: return False
    for p in _SMALL:
        if n % p == 0:
            return n == p
    d = n-1; s = 0
    while d % 2 == 0:
        d //= 2; s += 1
    bases = [2,3,5,7,11,13,17]
    for _ in range(3):  # extra safety for large n
        bases.append(random.randrange(18, 1<<32))
    def check(a: int) -> bool:
        a %= n
        if a == 0: return True
        x = pow(a,d,n)
        if x == 1 or x == n-1: return True
        for _ in range(s-1):
            x = (x*x) % n
            if x == n-1: return True
        return False
    return all(check(a) for a in bases)

# ---------------- Pollard–Rho ----------------

def pollard_rho(n: int) -> int:
    if n % 2 == 0: return 2
    if n % 3 == 0: return 3
    while True:
        c = random.randrange(1,n)
        f = lambda x: (pow(x,2,n) + c) % n
        x = random.randrange(2,n); y = x; d = 1
        while d == 1:
            x = f(x); y = f(f(y))
            d = math.gcd(abs(x-y), n)
        if d != n: return d

# ---------------- Factorization with trial to 100k then Rho ----------------

@lru_cache(maxsize=None)
def factor_int(n: int) -> tuple[tuple[int,int],...]:
    if n <= 1: return ()
    out = {}
    m = n
    for p in PRIMES_100K:
        if p*p > m: break
        if m % p == 0:
            e = 0
            while m % p == 0:
                m //= p; e += 1
            out[p] = out.get(p,0) + e
    if m > 1:
        if is_probable_prime(m):
            out[m] = out.get(m,0) + 1
        else:
            d = pollard_rho(m)
            for (q,eq) in factor_int(d) + factor_int(m//d):
                out[q] = out.get(q,0) + eq
    return tuple(sorted(out.items()))

# ---------------- G(n) from factors: G = 1 + p1 + p1p2 + ... ----------------

@lru_cache(maxsize=None)
def G_from_facts(facts: tuple[tuple[int,int],...]) -> int:
    if not facts: return 0
    total = 0
    running = 1
    for p in multiset_desc(facts):
        total += running
        running *= p
    return total

# ---------------- Factor arith helpers on factor-tuples (immutable) ---------

@lru_cache(maxsize=None)
def dec_facts(facts: tuple[tuple[int,int],...], p: int, k: int) -> tuple[tuple[int,int],...]:
    """Return facts with exponent of p reduced by k (and p removed if exponent hits 0)."""
    res = []
    for q,e in facts:
        if q == p:
            e2 = e - k
            if e2 < 0: raise ValueError("bad decrement")
            if e2 > 0: res.append((q,e2))
        else:
            res.append((q,e))
    return tuple(res)

@lru_cache(maxsize=None)
def prime_powers_from_facts(facts: tuple[tuple[int,int],...]) -> tuple[tuple[int,int],...]:
    """Return all (p, k) with 1<=k<=e for every (p,e) in facts; order arbitrary."""
    out = []
    for p,e in facts:
        for k in range(1, e+1):
            out.append((p,k))
    return tuple(out)

# ---------------- Core evaluation with aggressive pruning & progress --------

class Progress:
    __slots__ = ("t0","nodes","memo_hits","options","prunes_zero","prunes_low_ge0","prunes_high_le0",
                 "root_low","root_high","last_print")
    def __init__(self):
        self.t0 = time.time()
        self.nodes = 0
        self.memo_hits = 0
        self.options = 0
        self.prunes_zero = 0
        self.prunes_low_ge0 = 0
        self.prunes_high_le0 = 0
        self.root_low = float("-inf")
        self.root_high = float("inf")
        self.last_print = self.t0

    def maybe_print(self, where=""):
        now = time.time()
        if now - self.last_print >= 0.5:
            rate = self.nodes / max(now - self.t0, 1e-9)
            print(f"[prog] nodes={self.nodes} ({rate:.0f}/s), memo={self.memo_hits}, "
                  f"opts={self.options}, low={self.root_low}, high={self.root_high}  {where}")
            self.last_print = now

P = Progress()

@lru_cache(maxsize=None)
def f_from_facts(rf: tuple[tuple[int,int],...], cf: tuple[tuple[int,int],...]) -> int:
    # Progress accounting
    P.nodes += 1

    # Equal sides => 0
    if rf == cf: return 0
    # One-row / one-column
    if not rf:   return G_from_facts(cf)
    if not cf:   return -G_from_facts(rf)

    # Heuristic move ordering:
    #  Left (Alice): sort by descending m * G(cf - p^k)
    left_opts = []
    for p,k in prime_powers_from_facts(cf):
        cf2 = dec_facts(cf, p, k)
        m = pow(p,k)
        score = m * G_from_facts(cf2)  # upper bound heuristic
        left_opts.append(( -score, m, cf2))   # minus for descending
    left_opts.sort()

    #  Right (Bob): sort by ascending n * (-G(rf - p^k))
    right_opts = []
    for p,k in prime_powers_from_facts(rf):
        rf2 = dec_facts(rf, p, k)
        n = pow(p,k)
        score = n * (-G_from_facts(rf2))  # lower bound heuristic
        right_opts.append(( score, n, rf2))
    right_opts.sort()

    low = float("-inf")
    high = float("inf")

    # Interleave exploration: best L, best R, next L, next R, ...
    i = j = 0
    lenL, lenR = len(left_opts), len(right_opts)
    while i < lenL or j < lenR:
        # Alice step (improve low)
        if i < lenL:
            _, m, cf2 = left_opts[i]; i += 1
            P.options += 1
            low = max(low, m * f_from_facts(rf, cf2))
            # Early outs
            if low >= 0:
                P.prunes_low_ge0 += 1
                return int(low) + 1
            if low >= P.root_low:  # improve root view if this is the top call
                P.root_low = low
        # Bob step (improve high)
        if j < lenR:
            _, n, rf2 = right_opts[j]; j += 1
            P.options += 1
            high = min(high, n * f_from_facts(rf2, cf))
            if high <= 0:
                P.prunes_high_le0 += 1
                return math.ceil(high) - 1
            if high <= P.root_high:
                P.root_high = high

        # Zero in between?
        if low < 0 < high:
            P.prunes_zero += 1
            return 0

        P.maybe_print()

    # No early termination; choose simplest integer between
    if low < 0 < high: return 0
    if low >= 0:       return int(low) + 1
    return math.ceil(high) - 1

# ---------------- Entry point ----------------

def main():
    if len(sys.argv) != 3:
        print("Usage: python fc_value_progress.py \"<r int or factorized>\" \"<c int or factorized>\"")
        sys.exit(2)

    random.seed(random.randrange(1 << 63))

    # Parse inputs
    r_str, c_str = sys.argv[1], sys.argv[2]
    r_int, rf0 = parse_n_or_factors(r_str)
    c_int, cf0 = parse_n_or_factors(c_str)

    # Factor if needed
    print(f"[input] r bits={r_int.bit_length()}, c bits={c_int.bit_length()}")
    if not rf0:
        t0 = time.time()
        rf0 = factor_int(r_int)
        print(f"[factor r] {rf0}  (time {time.time()-t0:.3f}s)")
    else:
        print(f"[factor r] (provided) {rf0}")
    if not cf0:
        t0 = time.time()
        cf0 = factor_int(c_int)
        print(f"[factor c] {cf0}  (time {time.time()-t0:.3f}s)")
    else:
        print(f"[factor c] (provided) {cf0}")

    # Stats
    tau_r = tau_from_facts(rf0); tau_c = tau_from_facts(cf0)
    omega_r = len(rf0); omega_c = len(cf0)
    big_omega_r = sum(e for _,e in rf0); big_omega_c = sum(e for _,e in cf0)
    print(f"[stats r] ω={omega_r}, Ω={big_omega_r}, τ={tau_r}")
    print(f"[stats c] ω={omega_c}, Ω={big_omega_c}, τ={tau_c}")
    # Upper bound on states (very loose): τ(r)*τ(c)
    try:
        prod_tau = tau_r * tau_c
        print(f"[loose upper bound states] τ(r)*τ(c) = {prod_tau}")
    except OverflowError:
        print("[loose upper bound states] too large to print")

    # Initial trivial bounds
    g_r = G_from_facts(rf0); g_c = G_from_facts(cf0)
    print(f"[initial bounds] f(r,c) ∈ [{-g_r}, {g_c}]  (using G)")

    # Evaluate with progress
    t0 = time.time()
    val = f_from_facts(rf0, cf0)
    t1 = time.time()
    print(f"[result] f(r,c) = {val}")
    print(f"[time] {t1 - t0:.3f}s total")
    rate = P.nodes / max(t1 - P.t0, 1e-9)
    print(f"[work] nodes={P.nodes}, memo_hits={P.memo_hits}, options={P.options}, rate={rate:.0f}/s")
    print(f"[prunes] zero_between={P.prunes_zero}, low_ge0={P.prunes_low_ge0}, high_le0={P.prunes_high_le0}")

# Patch lru_cache to count memo hits (for f_from_facts only)
orig_f = f_from_facts
def f_from_facts_with_count(rf, cf):
    key = (rf, cf)
    res = f_from_facts.cache_get(key)
    if res is not None:
        P.memo_hits += 1
        return res
    res2 = orig_f(rf, cf)
    f_from_facts.cache_set(key, res2)
    return res2

# Monkey-patch cache accessors
def _wrap_lru_with_access(func):
    cache = {}
    def cache_get(k): return cache.get(k, None)
    def cache_set(k,v): cache[k] = v
    def wrapped(*args):
        k = args
        if k in cache:
            P.memo_hits += 1
            return cache[k]
        v = func(*args)
        cache[k] = v
        return v
    wrapped.cache_get = cache_get
    wrapped.cache_set = cache_set
    return wrapped

# Rewrap f_from_facts to expose cache_get/ cache_set
f_from_facts = _wrap_lru_with_access(f_from_facts.__wrapped__)  # type: ignore

if __name__ == "__main__":
    main()

# ---------- Convenience / demo ----------
#
#def main():
#    import sys
#    if len(sys.argv) == 3:
#        r = int(sys.argv[1]); c = int(sys.argv[2])
#        print(f_value(r, c))
#    else:
#        # Small smoke tests
#        tests = [(1,1), (1,2), (2,1), (2,2), (2,4), (2,8), (4,6), (1,8), (8,1), (4323855975562114726518487102722055842514310244656547479, 470147284842004245175081008799131351685318626829460321), (3396061787351437365560785267965234012799064104044242529256561027187645540909306599628231712601016121941243125433481313447172851850524777447140380830407565706177350759478762583119838528311717009, 7464746477226496222046301003339284704063450899406727072696371142567730009951170882833599768380584465924066413849500475118418591755457666001930720494110499599758793660468148459835668058314279)]
#        for r,c in tests:
#            print(f"f({r},{c}) = {f_value(r,c)}")
#    for m in prime_powers_dividing(4323855975562114726518487102722055842514310244656547479):
#        print(m)
#    for m in prime_powers_dividing(470147284842004245175081008799131351685318626829460321):
#        print(m)
#    for m in prime_powers_dividing(3396061787351437365560785267965234012799064104044242529256561027187645540909306599628231712601016121941243125433481313447172851850524777447140380830407565706177350759478762583119838528311717009):
#        print(m)
#    for m in prime_powers_dividing(7464746477226496222046301003339284704063450899406727072696371142567730009951170882833599768380584465924066413849500475118418591755457666001930720494110499599758793660468148459835668058314279):
#        print(m)
#
#if __name__ == "__main__":
#    # Make randomness different per run (affects Pollard–Rho only)
#    random.seed(random.randrange(1 << 63))
#    main()
#    # 3396061787351437365560785267965234012799064104044242529256561027187645540909306599628231712601016121941243125433481313447172851850524777447140380830407565706177350759478762583119838528311717009
#    # 7464746477226496222046301003339284704063450899406727072696371142567730009951170882833599768380584465924066413849500475118418591755457666001930720494110499599758793660468148459835668058314279