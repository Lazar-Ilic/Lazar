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

namespace l1_cafeteria {

int64_t getMaxAdditionalDinersCountCpp17(int64_t N, int64_t K, uint32_t M, const std::vector<long long>& S)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=203188678289677
    // Constraints
    //      1 ≤ N ≤ 10^15       N is the number of seats
    //      1 ≤ K ≤ N           K is the number of empty seats needed between occupied seats
    //      1 ≤ M ≤ 500,000     M is the number of diners
    //      1 ≤ Si ≤ N          Si is a seat
    // Complexity: O(M*log(M)), but the complexity could be O(M) if S was sorted

    (void)M;

    const auto d = K + 1;
    std::vector<int64_t> taken;
    taken.reserve(S.size() + 2);
    taken.emplace_back(0ull - K);  // we are adding "fake" seats at the beginning
    taken.insert(std::end(taken), std::cbegin(S), std::cend(S));
    taken.insert(std::end(taken), N + d);  // we are adding "fake" seats at the end

    // we sort elements of S: O(M * log(M))
    std::sort(std::begin(taken) + 1, std::end(taken) - 1);

    // we are calculating the extra seats available between each consecutive seats: O(M)
    int64_t nb = 0;
    for (size_t i = 0, e = taken.size() - 1; i < e; ++i)
        nb += (taken[i + 1] - taken[i] - d) / d;
    return nb;  // result should always be positive
}

using namespace std;

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    return getMaxAdditionalDinersCountCpp17(N, K, static_cast<uint32_t>(M), S);
}


struct Args
{
    long long N;
    long long K;
    std::vector<long long> S;  // error: could not convert ‘p.l1_cafeteria::Args::S’ from ‘vector<long int>’ to ‘vector<long long int>’
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMaxAdditionalDinersCount(p.N, p.K, static_cast<int>(p.S.size()), p.S);
    };

    std::vector<NamedTests<Args, long long>> tests = {
        { "Meta", {
                { { 10, 1, { 2, 6 } }, 3 },
                { { 15, 2, { 11, 6, 14 } }, 1 },
            }
        },
    };

    return run_all_tests("l1_cafetaria", tests, wrapper);
}

}  // namespace l1_cafetaria
