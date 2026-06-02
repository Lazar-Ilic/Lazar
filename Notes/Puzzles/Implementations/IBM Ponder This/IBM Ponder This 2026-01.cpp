#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <omp.h>
#include <atomic>
#include <iomanip>

// Use standard long long to prevent overflow (x can reach ~10^12)
using ll = long long;

// Configuration
const int MAX_N = 10000000;
const int NUM_THREADS = 8;

// Atomic counter for progress tracking
std::atomic<int> progress_cnt(0);

/**
 * Generates all possible sums obtained by splitting the string representation of n.
 * Returns a vector of sums (A_n).
 */
void get_split_sums(const std::string& s, int idx, ll current_sum, std::vector<ll>& results) {
    if (idx == s.length()) {
        results.push_back(current_sum);
        return;
    }

    ll current_val = 0;
    for (int i = idx; i < s.length(); ++i) {
        current_val = current_val * 10 + (s[i] - '0');
        // Optimization: The remaining part of the string must sum to at least something.
        // We pass (current_sum + current_val) to the next level.
        get_split_sums(s, i + 1, current_sum + current_val, results);
    }
}

/**
 * Checks if the number string 's' can be split into parts that sum exactly to 'target'.
 * Implements DFS with Pruning.
 */
bool can_split_to_target(const std::string& s, int idx, ll target) {
    // Base case: If we consumed the whole string, check if target reached 0
    if (idx == s.length()) {
        return target == 0;
    }
    
    // Pruning: If target goes negative, this path is invalid
    if (target < 0) return false;

    ll current_val = 0;
    for (int i = idx; i < s.length(); ++i) {
        current_val = current_val * 10 + (s[i] - '0');
        
        // Pruning: If the current chunk is already larger than the remaining target,
        // extending this chunk further (e.g., 5 -> 50) will also fail.
        if (current_val > target) {
            break;
        }

        if (can_split_to_target(s, i + 1, target - current_val)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Thread-local sets to store valid x values without locking contention
    std::vector<std::set<ll>> thread_results(NUM_THREADS);

    std::cout << "Starting calculation with " << NUM_THREADS << " threads..." << std::endl;
    double start_time = omp_get_wtime();

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int thread_id = omp_get_thread_num();
        std::string n_str, x_str; // Reusable strings to minimize allocation
        std::vector<ll> An;       // Reusable vector
        
        // Dynamic schedule helps load balance if some numbers are harder than others
        #pragma omp for schedule(dynamic, 1000)
        for (int n = 1; n <= MAX_N; ++n) {
            
            // Filter 1: Modulo 9 Property
            // n must be congruent to 0 or 1 mod 9
            int mod9 = n % 9;
            if (mod9 != 0 && mod9 != 1) {
                // Update progress even for skipped numbers
                int c = ++progress_cnt;
                if (c % 50000 == 0 && thread_id == 0) {
                     std::cout << "\rProgress: " << std::fixed << std::setprecision(1) 
                               << (100.0 * c / MAX_N) << "%" << std::flush;
                }
                continue;
            }

            // Generate A_n
            n_str = std::to_string(n);
            An.clear();
            get_split_sums(n_str, 0, 0, An);

            for (ll s : An) {
                // Optimization: Magnitude Heuristic
                // If n is large (>100) and s is small (<10 but >1), 
                // n is likely too large to be a split-sum of n*s.
                if (n > 100 && s < 10 && s != 1) continue;

                ll x = (ll)n * s;
                
                // Check if n is in A_x
                x_str = std::to_string(x);
                if (can_split_to_target(x_str, 0, n)) {
                    thread_results[thread_id].insert(x);
                }
            }

            // Progress logging
            int c = ++progress_cnt;
            if (c % 50000 == 0 && thread_id == 0) {
                 std::cout << "\rProgress: " << std::fixed << std::setprecision(1) 
                           << (100.0 * c / MAX_N) << "%" << std::flush;
            }
        }
    }

    std::cout << "\rProgress: 100.0%          " << std::endl;
    std::cout << "Merging results..." << std::endl;

    // Merge thread-local sets into one global set
    std::set<ll> distinct_x;
    for (const auto& local_set : thread_results) {
        distinct_x.insert(local_set.begin(), local_set.end());
    }

    ll total_sum = 0;
    for (ll val : distinct_x) {
        total_sum += val;
    }

    double end_time = omp_get_wtime();
    std::cout << "Valid x count: " << distinct_x.size() << std::endl;
    std::cout << "Total Sum: " << total_sum << std::endl;
    std::cout << "Time elapsed: " << (end_time - start_time) << "s" << std::endl;

    return 0;
}