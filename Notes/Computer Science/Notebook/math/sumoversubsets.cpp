// Memory optimised, super easy to code.
for(int i = 0; i<(1<<N); ++i)F[i] = A[i];
for(int i = 0;i < N; ++i){
	for(int mask = 0; mask < (1<<N); ++mask){
		if(mask & (1<<i))F[mask] += F[mask^(1<<i)];
	}
}

// Iterative version
for(int mask = 0; mask < (1<<N); ++mask){
	dp[mask][-1] = A[mask];	// Handle base case separately [leaf states]
	for(int i = 0;i < N; ++i){
		if(mask & (1<<i)) dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
		else dp[mask][i] = dp[mask][i-1];
	}
	F[mask] = dp[mask][N-1];
}

// Rather than Suboptimal Solution:

// Iterate over all the masks
for(int mask = 0; mask < (1<<n); mask++){
	F[mask] = A[0];
    // Iterate over all the subsets of the mask
    for(int i = mask; i > 0; i = (i-1) & mask)F[mask] += A[i];
}

// Or Brute Force:

for(int mask = 0;mask < (1<<N); ++mask){
	for(int i = 0;i < (1<<N); ++i){
		if((mask&i) == i)F[mask] += A[i];
	}
}