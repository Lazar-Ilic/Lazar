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

package l3_boss_fight

import (
	"math"
	"meta_puzzles/std"
	"meta_puzzles/test"
)

type damage_t = uint64

type DamageInfo struct {
	order   uint32
	indices [2]uint32
	damage  damage_t
}

func maximize_damage(N uint32, H []int32, D []int32, info *DamageInfo) bool {
	// this maximizes damage for a fixed index(max_i if order is True, otherwise max_j)
	// and also returns the value of max_i and max_j
	has_same_damage := true
	for i := uint32(0); i < N; i += 1 {
		j := info.indices[info.order]
		if j == i {
			continue
		}
		new_damage := damage_t(0)
		Hi := damage_t(H[i])
		Hj := damage_t(H[j])
		Di := damage_t(D[i])
		Dj := damage_t(D[j])
		if info.order == 0 {
			new_damage = Hj*Dj + Hj*Di + Hi*Di
		} else {
			new_damage = Hi*Di + Hi*Dj + Hj*Dj
		}
		if info.damage < new_damage {
			has_same_damage = false
			info.damage = new_damage
			info.indices[1-info.order] = i
		}
	}
	return has_same_damage
}

func getMaxDamageDealt(N int32, H []int32, D []int32, B int32) float64 {
	damage_infos := make([]DamageInfo, 0) // note: no reserve() here
	for _, order := range [2]uint32{0, 1} {
		damage_info := DamageInfo{order, [2]uint32{0, 0}, 0}
		for {
			has_same_damage := maximize_damage(uint32(N), H, D, &damage_info)
			if has_same_damage {
				break
			}
			damage_info.order = 1 - damage_info.order
			damage_infos = append(damage_infos, damage_info)
		}
	}
	if len(damage_infos) == 0 {
		return 0.0
	}

	max_fn := func(a DamageInfo, b DamageInfo) bool { return a.damage > b.damage }
	max_elt := std.MaxMinElement(damage_infos, max_fn)
	return float64(max_elt.damage) / float64(B)
}

type Args struct {
	H   []int32
	D   []int32
	B   int32
	res float64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) float64 { return getMaxDamageDealt(int32(len(p.H)), p.H, p.D, p.B) }

	args_lists := []Args{
		{[]int32{2, 1, 4}, []int32{3, 1, 2}, 4, 6.5},
		{[]int32{1, 1, 2, 100}, []int32{1, 2, 1, 3}, 8, 62.75},
		{[]int32{1, 1, 2, 3}, []int32{1, 2, 1, 100}, 8, 62.75},
		// extra1
		{[]int32{1, 1, 2, 100, 3}, []int32{1, 2, 1, 4, 100}, 8, 1337.5},
		{[]int32{9, 1, 3, 4}, []int32{0, 10, 4, 3}, 1, 100.0},
	}

	pred := func(lhs float64, rhs float64) bool { return math.Abs(lhs-rhs) < 0.000_001 }
	return test.RunAllTests("l3_boss_fight", args_lists, wrapper, pred)
}
