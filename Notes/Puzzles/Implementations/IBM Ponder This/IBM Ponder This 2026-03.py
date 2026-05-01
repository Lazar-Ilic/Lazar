import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import maximum_flow
import time
import gc

def solve_max_flow():
    start_time = time.time()
    
    N = 157
    M = 157
    p = 419
    q = 211
    
    def is_prime(n):
        if n < 2: return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0: return False
        return True
        
    primes = [n for n in range(2, 100) if is_prime(n)]
    
    total_A = 0
    total_B = 0
    
    print(f"Starting Max-Flow calculation for {len(primes)} primes on a {N}x{M} grid...")
    
    # Precompute Checkerboard Mask
    I, J = np.meshgrid(np.arange(1, N + 1), np.arange(1, M + 1), indexing='ij')
    is_L_mask = ((I + J) % 2 == 0)
    
    for count, s in enumerate(primes, 1):
        loop_start = time.time()
        
        p_pows = np.array([pow(p, i, s) for i in range(1, N + 1)])
        q_pows = np.array([pow(q, j, s) for j in range(1, M + 1)])
        grid_mod = (p_pows[:, None] + q_pows[None, :]) % s
        valid = (grid_mod != 0)
        
        L_mask = valid & is_L_mask
        R_mask = valid & ~is_L_mask
        
        N_L = np.sum(L_mask)
        N_R = np.sum(R_mask)
        
        if N_L == 0 or N_R == 0:
            total_A += (N_L + N_R)
            print(f"[{count}/{len(primes)}] Prime {s:3}: Instant Alice wins. Elapsed: {time.time()-loop_start:.2f}s")
            continue
            
        node_ids = np.full((N, M), -1, dtype=int)
        node_ids[L_mask] = np.arange(N_L)
        node_ids[R_mask] = np.arange(N_R)
        
        valid_horiz = valid[:, :-1] & valid[:, 1:]
        valid_vert = valid[:-1, :] & valid[1:, :]
        
        left_is_L = L_mask[:, :-1][valid_horiz]
        L_ids_horiz1 = node_ids[:, :-1][valid_horiz][left_is_L]
        R_ids_horiz1 = node_ids[:, 1:][valid_horiz][left_is_L]
        
        left_is_R = R_mask[:, :-1][valid_horiz]
        R_ids_horiz2 = node_ids[:, :-1][valid_horiz][left_is_R]
        L_ids_horiz2 = node_ids[:, 1:][valid_horiz][left_is_R]
        
        top_is_L = L_mask[:-1, :][valid_vert]
        L_ids_vert1 = node_ids[:-1, :][valid_vert][top_is_L]
        R_ids_vert1 = node_ids[1:, :][valid_vert][top_is_L]
        
        top_is_R = R_mask[:-1, :][valid_vert]
        R_ids_vert2 = node_ids[:-1, :][valid_vert][top_is_R]
        L_ids_vert2 = node_ids[1:, :][valid_vert][top_is_R]
        
        row = np.concatenate([L_ids_horiz1, L_ids_horiz2, L_ids_vert1, L_ids_vert2])
        col = np.concatenate([R_ids_horiz1, R_ids_horiz2, R_ids_vert1, R_ids_vert2])
        
        # 1. Build the Standard Bipartite Graph for BFS
        graph = csr_matrix((np.ones(len(row), dtype=int), (row, col)), shape=(N_L, N_R))
        
        # 2. Build the Max-Flow Network Capacity Matrix
        S = N_L + N_R
        T = N_L + N_R + 1
        num_nodes = T + 1
        
        # Source to Left edges
        flow_row_S = np.full(N_L, S, dtype=int)
        flow_col_S = np.arange(N_L, dtype=int)
        
        # Left to Right edges (Offset R by N_L)
        flow_row_LR = row
        flow_col_LR = col + N_L
        
        # Right to Sink edges
        flow_row_T = np.arange(N_L, N_L + N_R, dtype=int)
        flow_col_T = np.full(N_R, T, dtype=int)
        
        flow_row = np.concatenate([flow_row_S, flow_row_LR, flow_row_T])
        flow_col = np.concatenate([flow_col_S, flow_col_LR, flow_col_T])
        flow_data = np.ones(len(flow_row), dtype=int)
        
        capacity = csr_matrix((flow_data, (flow_row, flow_col)), shape=(num_nodes, num_nodes))
        
        # 3. Solve Max-Flow using Dinic's Algorithm (Bypasses the HK maze trap)
        flow_result = maximum_flow(capacity, S, T, method='dinic')
        
        # Extract the matching directly from the flow matrix
        flow_matrix = flow_result.flow
        L_to_R_flow = flow_matrix[:N_L, N_L:N_L+N_R]
        u, v = L_to_R_flow.nonzero()
        
        match_L = np.full(N_L, -1, dtype=int)
        match_R = np.full(N_R, -1, dtype=int)
        match_L[u] = v
        match_R[v] = u
        
        # 4. Standard Fast Matrix BFS (Dulmage-Mendelsohn)
        visited_L = np.zeros(N_L, dtype=bool)
        unmatched_L = (match_L == -1)
        visited_L[unmatched_L] = True
        frontier_L = np.zeros(N_L, dtype=int)
        frontier_L[unmatched_L] = 1
        
        while np.any(frontier_L):
            reachable_R = (graph.T.dot(frontier_L) > 0)
            matched_to_reachable_R = match_R[reachable_R]
            valid_next_L = matched_to_reachable_R[matched_to_reachable_R != -1]
            new_L = valid_next_L[~visited_L[valid_next_L]]
            visited_L[new_L] = True
            frontier_L.fill(0)
            frontier_L[new_L] = 1
            
        visited_R = np.zeros(N_R, dtype=bool)
        unmatched_R = (match_R == -1)
        visited_R[unmatched_R] = True
        frontier_R = np.zeros(N_R, dtype=int)
        frontier_R[unmatched_R] = 1
        
        while np.any(frontier_R):
            reachable_L = (graph.dot(frontier_R) > 0)
            matched_to_reachable_L = match_L[reachable_L]
            valid_next_R = matched_to_reachable_L[matched_to_reachable_L != -1]
            new_R = valid_next_R[~visited_R[valid_next_R]]
            visited_R[new_R] = True
            frontier_R.fill(0)
            frontier_R[new_R] = 1
            
        A_count = np.sum(visited_L) + np.sum(visited_R)
        B_count = (N_L + N_R) - A_count
        
        total_A += A_count
        total_B += B_count
        
        print(f"[{count}/{len(primes)}] Prime {s:3}: A={A_count}, B={B_count}. Elapsed: {time.time()-loop_start:.2f}s")
        
        # Aggressive memory cleanup
        del grid_mod, valid, L_mask, R_mask, node_ids
        del valid_horiz, valid_vert, left_is_L, left_is_R, top_is_L, top_is_R
        del row, col, flow_row, flow_col, flow_data, capacity, flow_result, flow_matrix, L_to_R_flow
        del match_L, match_R, visited_L, visited_R, frontier_L, frontier_R, graph
        gc.collect() 
        
    print("-" * 30)
    print(f"Total A squares: {total_A}")
    print(f"Total B squares: {total_B}")
    print(f"Computed entirely in {time.time() - start_time:.3f} seconds.")

if __name__ == "__main__":
    solve_max_flow()