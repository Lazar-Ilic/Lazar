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

package l2_tunnel_time

import (
	"meta_puzzles/std"
	"meta_puzzles/test"
	"sort"
)

type Tunnel struct {
	a int64
	b int64
}

func (t Tunnel) length() int64 {
	return t.b - t.a
}

func getSecondsElapsed(C int64, N int32, A []int64, B []int64, K int64) int64 {
	tunnels := make([]Tunnel, N)
	for i := int32(0); i < N; i += 1 {
		tunnels = append(tunnels, Tunnel{A[i], B[i]})
	}

	tunnel_time_total := int64(0)
	for _, tunnel := range tunnels {
		tunnel_time_total += tunnel.length()
	}

	number_of_complete_track := K / tunnel_time_total                 // O(1)
	total_time_left := K - number_of_complete_track*tunnel_time_total // O(1)
	travel_time := number_of_complete_track * C                       // O(1)

	if total_time_left == 0 {
		travel_time -= C - *std.MaxElement(B) // O(N)
	} else {
		sort.Slice(tunnels, func(i, j int) bool {
			return tunnels[i].a < tunnels[j].a
		})
		for _, tunnel := range tunnels {
			tunnel_length := tunnel.length()
			if tunnel_length >= total_time_left {
				travel_time += tunnel.a + total_time_left
				break
			}
			total_time_left -= tunnel_length
		}
	}
	return travel_time
}

type Args struct {
	C   int64
	A   []int64
	B   []int64
	K   int64
	res int64
}

func (self Args) GetResult() any {
	return self.res
}

func Tests() uint {
	wrapper := func(p Args) int64 {
		min_len := int32(std.Min(len(p.A), len(p.B)))
		return getSecondsElapsed(p.C, min_len, p.A, p.B, p.K)
	}

	args_lists := []Args{
		{10, []int64{1, 6}, []int64{3, 7}, 7, 22},
		{50, []int64{39, 19, 28}, []int64{49, 27, 35}, 15, 35},
		// extra1
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 1, 20},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 8, 27},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 9, 29},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 15, 35},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 16, 40},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 25, 49},
		{50, []int64{19, 28, 39}, []int64{27, 35, 49}, 26, 70},
	}

	return test.RunAllTests("l2_scoreboard_interference2", args_lists, wrapper)
}
