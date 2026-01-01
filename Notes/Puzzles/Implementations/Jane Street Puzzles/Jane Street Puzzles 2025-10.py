import math
from decimal import Decimal, getcontext

getcontext().prec = 100  # high precision

def solve_game(p):
    V, H, strat = {}, {}, {}  # store values, full-count probabilities, strategies

    def value(b, s):
        if b >= 4:
            return Decimal(1)
        if s >= 3:
            return Decimal(0)
        key = (b, s)
        if key in V:
            return V[key]

        # Outcomes
        w_b  = value(b+1, s);   h_wb  = hitfull(b+1, s)
        w_s  = value(b, s+1);   h_ws  = hitfull(b, s+1)
        sw_b = value(b, s+1);   h_sw_b= hitfull(b, s+1)
        sw_s = p*Decimal(4)+(Decimal(1)-p)*value(b, s+1)
        h_sw_s=(Decimal(1)-p)*hitfull(b, s+1)

        # Matrix
        a, b_, c, d = w_b, w_s, sw_b, sw_s
        ha, hb_, hc, hd = h_wb, h_ws, h_sw_b, h_sw_s

        denom = (a - b_ - c + d)

        alpha = beta = None
        if denom != 0:
            alpha = (d - c) / denom
            beta  = (d - b_) / denom

        if denom != 0 and Decimal(0) <= alpha <= 1 and Decimal(0) <= beta <= 1:
            val = (a*d - b_*c) / denom
            hval = alpha*(beta*ha + (1-beta)*hb_) + (1-alpha)*(beta*hc + (1-beta)*hd)
        else:
            row1min, row2min = min(a, b_), min(c, d)
            if row1min > row2min:
                val, hval = row1min, min(ha, hb_)
                alpha, beta = Decimal(1), None  # pure Wait
            elif row2min > row1min:
                val, hval = row2min, min(hc, hd)
                alpha, beta = Decimal(0), None  # pure Swing
            else:
                val, hval = row1min, max(min(ha, hb_), min(hc, hd))
                alpha, beta = None, None  # multiple equilibria possible

        V[key], H[key] = val, hval
        strat[key] = (alpha, beta)
        return val

    def hitfull(b, s):
        if (b, s) == (3, 2):
            return Decimal(1)
        if b >= 4 or s >= 3:
            return Decimal(0)
        if (b, s) in H:
            return H[(b, s)]
        _ = value(b, s)
        return H[(b, s)]

    _ = value(0, 0)
    return V, H, strat

def maximize():
    lo, hi = Decimal(0), Decimal(1)
    phi = (Decimal(5).sqrt()-1)/2
    x1 = lo + (1-phi)*(hi-lo)
    x2 = lo + phi*(hi-lo)
    f1, f2 = solve_game(x1)[1][(0,0)], solve_game(x2)[1][(0,0)]
    for _ in range(200):
        if f1 < f2:
            lo, x1, f1 = x1, x2, f2
            x2 = lo + phi*(hi-lo); f2 = solve_game(x2)[1][(0,0)]
        else:
            hi, x2, f2 = x2, x1, f1
            x1 = lo + (1-phi)*(hi-lo); f1 = solve_game(x1)[1][(0,0)]
    if f1 > f2:
        return x1, f1
    else:
        return x2, f2

if __name__ == "__main__":
    p_opt, q_opt = maximize()
    print(f"Optimal p = {p_opt}")
    print(f"Maximal q = {q_opt}")

    V, H, strat = solve_game(p_opt)

    print("\nStrategies at each count (b balls, s strikes):")
    for b in range(4):
        for s in range(3):
            if (b, s) in strat:
                alpha, beta = strat[(b, s)]
                if alpha is not None and beta is not None:
                    print(f"(b={b}, s={s}): Batter Wait α={alpha}, Pitcher Ball β={beta}")
                elif alpha is not None:
                    print(f"(b={b}, s={s}): Pure Batter α={alpha}")
                else:
                    print(f"(b={b}, s={s}): Degenerate equilibrium")
