from collections import defaultdict

'''
rules = {
    "G": "T",
    "T": "CA",
    "C": "TG",
    "A": "C",
}
'''

#'''
rules = {
    "G": "T",
    "T": "CA",
    "C": "BR",
    "A": "I",
    "R": "B",
    "B": "IS",
    "I": "TG",
    "S": "C",
}
#'''

ALPHABET = sorted(set(rules) | set("".join(rules.values())))
MAX_DEPTH = 3000  # precompute lengths up to this depth

def precompute_lengths(max_depth: int = MAX_DEPTH):
    """
    Return len_table[ch][d] = |F(ch, d)| for all ch in ALPHABET and 0<=d<=max_depth.
    Base: |F(ch,0)| = 1 (a single letter).
    """
    len_table = {ch: [1] * (max_depth + 1) for ch in ALPHABET}
    for d in range(1, max_depth + 1):
        for ch in ALPHABET:
            # |F(ch, d)| = sum_{y in rules[ch]} |F(y, d-1)|
            total = 0
            for y in rules[ch]:
                total += len_table[y][d - 1]
            len_table[ch][d] = total
    return len_table

LEN = precompute_lengths(MAX_DEPTH)

def char_single(s0: str, n: int, k: int) -> str:
    """
    Character at index k of s_n with single-letter start s0.
    Requires 0 <= n <= MAX_DEPTH and 0 <= k < LEN[s0][n].
    Time: O(n) steps; Space: O(1) (table already built).
    """
    if n > MAX_DEPTH:
        raise ValueError(f"n={n} exceeds precomputed MAX_DEPTH={MAX_DEPTH}")
    if s0 not in ALPHABET:
        raise ValueError(f"Unknown start letter {s0!r}")
    total = LEN[s0][n]
    if k < 0 or k >= total:
        raise IndexError(f"k out of range (0..{total-1}) for s_{n}")

    letter, depth = s0, n
    while depth > 0:
        # Walk children left-to-right, steering with child lengths at (depth-1)
        for child in rules[letter]:
            L = LEN[child][depth - 1]
            if k < L:
                letter = child
                depth -= 1
                break
            k -= L
        else:
            raise RuntimeError("Malformed morphism (no children found).")
    return letter

def char_seed(seed: str, n: int, k: int) -> str:
    """
    Character at index k of s_n with arbitrary start word 'seed'.
    Splits across blocks F(c, n) for c in seed.
    """
    if n > MAX_DEPTH:
        raise ValueError(f"n={n} exceeds precomputed MAX_DEPTH={MAX_DEPTH}")
    if not seed:
        raise ValueError("Seed must be non-empty.")
    # Find which seed-block contains k
    for c in seed:
        block = LEN[c][n]
        if k < block:
            return char_single(c, n, k)
        k -= block
    raise IndexError("k out of range for the expanded seed.")

def slice_seed(seed: str, n: int, a: int, b: int) -> str:
    """
    Return s_n[a..b) for start word 'seed'. Simple per-char version.
    For large spans you can optimize with a recursive range emitter,
    but for (b-a) around ~1e3 and n around ~500 this is fine.
    """
    return "".join(char_seed(seed, n, i) for i in range(a, b))

answer=""
for a in range(1000):
    answer+=char_single("C",500,10**100+a)
print(answer)