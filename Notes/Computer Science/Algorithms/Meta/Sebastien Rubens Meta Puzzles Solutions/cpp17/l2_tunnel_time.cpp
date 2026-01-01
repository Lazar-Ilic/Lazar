// meta_puzzles by Sebastien Rubens
//
// Please go to https://github.com/seb-pg/meta_puzzles/README.md
// for more information
//
// To the extent possible under law, the person who associated CC0 with
// meta_puzzles has waived all copyright and related or neighboring rights
// to meta_puzzles.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

#include "test_all.h"

#include <algorithm>
#include <cstdint>  // int**_t
#include <vector>

namespace l2_tunnel_time {

struct Tunnel
{
    int64_t a;
    int64_t b;

    int64_t length() const
    {
        return b - a;
    }

    bool operator<(const Tunnel& rhs) const
    {
        return std::tie(a, b) < std::tie(rhs.a, rhs.b);
    }
};

int64_t getSecondsElapsedCpp17(int64_t C, uint32_t N, const std::vector<long long>& A, const std::vector<long long>& B, int64_t K)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=1492699897743843
    // Constraints:
    //      3 ≤ C ≤ 10^12       C is the circumference
    //      1 ≤ N ≤ 500,000     N is the number of tunnels
    //      1 ≤ Ai < Bi ≤ C     Ai and Bi are the start and end of the tunnels
    //      1 ≤ K ≤ 10^12       K is the time spent in tunnels
    // Complexity: O(N*log(N)), would be O(N) if tunnels were sorted

    std::vector<Tunnel> tunnels;
    tunnels.reserve(N);
    for (uint32_t i = 0; i < N; ++i)
        tunnels.emplace_back(Tunnel{ A[i], B[i] });

    int64_t tunnel_time_total = 0;
    for (const auto& tunnel : tunnels)
        tunnel_time_total += tunnel.length();  // could use std::views::zip in C++23

    int64_t number_of_complete_track = (K / tunnel_time_total);  // O(1)
    int64_t total_time_left = K - number_of_complete_track * tunnel_time_total;  // O(1)
    int64_t travel_time = number_of_complete_track * C;  // O(1)

    if (total_time_left == 0)
        travel_time -= C - (*std::max_element(std::cbegin(B), std::cend(B)));  // O(N)
    else
    {
        std::sort(std::begin(tunnels), std::end(tunnels));
        for (const auto& tunnel : tunnels)
        {
            int64_t tunnel_length = tunnel.length();
            if (tunnel_length >= total_time_left)
            {
                travel_time += tunnel.a + total_time_left;
                break;
            }
            total_time_left -= tunnel_length;
        }
    }
    return travel_time;
}

using namespace std;

long long getSecondsElapsed(long long C, int N, vector<long long> A, vector<long long> B, long long K) {
    return getSecondsElapsedCpp17(C, static_cast<uint32_t>(N), A, B, K);
}


struct Args
{
    long long C;
    std::vector<long long> A;
    std::vector<long long> B;
    long long K;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        const auto min_len = static_cast<int>(std::min(p.A.size(), p.B.size()));
        return getSecondsElapsed(p.C, min_len, p.A, p.B, p.K);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { 10, { 1, 6 }, { 3, 7 }, 7 }, 22 },
                { { 50, { 39, 19, 28 }, { 49, 27, 35 }, 15 }, 35 },
            }
        },
        { "extra1", {
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 1 }, 20 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 8 }, 27 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 9 }, 29 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 15 }, 35 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 16 }, 40 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 25 }, 49 },
                { { 50, { 19, 28, 39 }, { 27, 35, 49 }, 26 }, 70 },
            }
        },
    };

    return run_all_tests("l2_tunnel_time", tests, wrapper);
}

}  // namespace l2_tunnel_time
