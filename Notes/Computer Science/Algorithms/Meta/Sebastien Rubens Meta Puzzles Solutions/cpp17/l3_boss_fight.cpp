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
#include <array>
#include <cstdint>  // int**_t
#include <vector>

namespace l3_boss_fight {

using damage_t = uint64_t;

struct DamageInfo
{
    uint32_t order;
    std::array<uint32_t, 2> indices = { { 0, 0 } };
    damage_t damage = 0;
};

static bool maximize_damage(uint32_t N, const std::vector<int32_t>& H, const std::vector<int32_t>& D, DamageInfo& info)
{
    // this maximizes damage for a fixed index(max_i if order is True, otherwise max_j)
    // and also returns the value of max_i and max_j
    auto has_same_damage = true;
    for (uint32_t i = 0; i < N; ++i)
    {
        const auto j = info.indices[info.order];
        if (j == i)
            continue;
        const auto Hi = static_cast<damage_t>(H[i]);
        const auto Hj = static_cast<damage_t>(H[j]);
        const auto Di = static_cast<damage_t>(D[i]);
        const auto Dj = static_cast<damage_t>(D[j]);
        damage_t new_damage;
        if (info.order == 0)
            new_damage = Hj * Dj + Hj * Di + Hi * Di;
        else
            new_damage = Hi * Di + Hi * Dj + Hj * Dj;
        if (info.damage < new_damage)
        {
            has_same_damage = false;
            info.damage = new_damage;
            info.indices[1 - info.order] = i;
        }
    }
    return has_same_damage;
}

double getMaxDamageDealtCpp17(uint32_t N, const std::vector<int32_t>& H, const std::vector<int32_t>& D, int32_t B)
{
    // https://www.metacareers.com/profile/coding_puzzles/?puzzle=149169347195386
    // Constraints :
    //      2 ≤ N  ≤ 500,000
    //      1 ≤ Hi ≤ 1,000,000,000
    //      1 ≤ Di ≤ 1,000,000,000
    //      1 ≤ B  ≤ 1,000,000,000
    // Complexity: O(N^2)

    // we are maximizing H[i] * D[i] + H[i] * D[j] + H[j] * D[j] where i < j

    std::vector<DamageInfo> damage_infos;  // note: no reserve() here
    for (auto order : { 0u, 1u })
    {
        DamageInfo damage_info{ order };
        while (true)
        {
            const auto has_same_damage = maximize_damage(N, H, D, damage_info);
            if (has_same_damage)
                break;
            damage_info.order = 1 - damage_info.order;
            damage_infos.emplace_back(damage_info);
        }
    }
    if (damage_infos.empty())
        return 0.;

    const auto max_fn = [](const DamageInfo& a, const DamageInfo& b) { return a.damage < b.damage; };
    const auto max_elt = std::max_element(std::cbegin(damage_infos), std::cend(damage_infos), max_fn);
    return static_cast<double>(max_elt->damage) / static_cast<double>(B);
}

using namespace std;

double getMaxDamageDealt(int N, vector<int> H, vector<int> D, int B) {
    return getMaxDamageDealtCpp17(static_cast<uint32_t>(N), H, D, B);
}


struct Args
{
    std::vector<int> H;
    std::vector<int> D;
    int B;
};

auto tests()
{
    const auto wrapper = [](Args& p)
    {
        return getMaxDamageDealt(static_cast<int>(p.H.size()), p.H, p.D, p.B);
    };

    std::vector<NamedTests<Args, double>> tests = {
        { "Meta", {
                { { { 2, 1, 4 }, { 3, 1, 2 }, 4 }, 6.5 },
                { { { 1, 1, 2, 100 }, { 1, 2, 1, 3 }, 8 }, 62.75 },
                { { { 1, 1, 2, 3 }, { 1, 2, 1, 100 }, 8 }, 62.75 },
            }
        },
        { "extra1", {
                { { { 1, 1, 2, 100, 3 }, { 1, 2, 1, 4, 100 }, 8 }, 1337.5 },
                // what if all Hi*Di are equal?
                { { { 9, 1, 3, 4 }, { 0, 10, 4, 3 }, 1 }, 100.0 },
            }
        },
    };

    return run_all_tests("l3_boss_fight", tests, wrapper, 0.000'001);
}

}  // namespace l3_boss_fight
