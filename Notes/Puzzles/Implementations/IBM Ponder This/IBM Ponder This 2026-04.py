import math

def find_all_triples(total_seconds=43200):
    triples = []
    limit_H = int(total_seconds ** (1/3)) + 1
    
    for H in range(1, limit_H):
        if total_seconds % H == 0:
            rem = total_seconds // H
            limit_M = int(math.isqrt(rem)) + 1
            
            for M in range(H, limit_M):
                if rem % M == 0:
                    S = rem // M
                    if M <= S:
                        triples.append((H, M, S))
                        
    return triples

def compute_undeducible(H, M, S):
    K = H - 1
    L = H * M - 1
    
    if K == 0 or L == 0:
        return 0
        
    if math.gcd(K, L) == 1:
        return 3 * L**2 - L * K - K**2 - 2 * L - 1
        
    g = math.gcd(K, L)
    
    M2 = abs(L**2 - K**2) // g
    M3 = abs(K**2 - 2*K*L) // g
    M4 = abs(L**2 - L*K + K**2) // g
    M6 = abs(2*K*L - L**2) // g
    
    G2 = abs(L - K)
    G3 = abs(K)
    G4 = math.gcd(K + L, 3 * K)
    G6 = abs(L)
    
    params = [M2, M3, M4, M6, G2, G3, G4, G6]
    
    def is_valid(mask):
        for i in range(4):
            if (mask & (1 << i)) and not (mask & (1 << (i + 4))):
                return True
        return False

    total = 0
    for y in range(1, 256):
        y_params = [params[i] for i in range(8) if (y & (1 << i))]
        if not y_params: continue
        
        y_gcd = y_params[0]
        for val in y_params[1:]:
            y_gcd = math.gcd(y_gcd, val) if val != 0 else 0
        if y_gcd == 0: continue
        
        Wy = 0
        for x in range(256):
            if (x & y) == x and is_valid(x):
                sign = 1 if ((y - x).bit_count() % 2 == 0) else -1
                Wy += sign
                
        total += Wy * y_gcd
        
    return total

print(f"Standard 12-hour clock (12, 60, 60): {compute_undeducible(12, 60, 60)} undeducible moments\n")

triples = find_all_triples(43200)
best_triple = None
max_moments = -1

for H, M, S in triples:
    moments = compute_undeducible(H, M, S)
    if moments > max_moments:
        max_moments = moments
        best_triple = (H, M, S)

print(f"MAXIMUM FOUND: {max_moments} moments")
print(f"Winning Configuration: H={best_triple[0]}, M={best_triple[1]}, S={best_triple[2]}")