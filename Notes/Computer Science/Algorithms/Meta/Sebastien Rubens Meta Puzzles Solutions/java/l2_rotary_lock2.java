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

import java.util.function.*;
import java.util.SortedMap;
import java.util.TreeMap;

public class l2_rotary_lock2 {

static class Solution {

    class Dials implements Comparable<Dials> {
        int dial1;
        int dial2;

        Dials(int dial1, int dial2)
        {
            this.dial1 = dial1;
            this.dial2 = dial2;
        }

        @Override
        public int compareTo(Dials o) {
            if (dial1 != o.dial1)
                return dial1 - o.dial1;
            return dial2 - o.dial2;
        }
    }

    int get_distance(int target, int position, int N)
    {
        var positive_move = (target - position) % N;
        if (positive_move < 0)  // modulo must be positive (must check that in C++)
            positive_move += N;
        final var negative_move = N - positive_move;  // positive number
        return Math.min(positive_move, negative_move);
    }

    void insert_solution(SortedMap<Dials, Long> new_solutions, int N, int target, int dial1, int dial2, long distance)
    {
        final var new_distance = distance + get_distance(target, dial1, N);
        final Dials key = new Dials(Math.min(dial2, target), Math.max(dial2, target));
        final var value = new_solutions.getOrDefault(key, Long.MAX_VALUE);
        new_solutions.put(key, Math.min(value, new_distance));
    }

    public long getMinCodeEntryTime(int N, int M, int[] C) {
        SortedMap<Dials, Long> solutions = new TreeMap<Dials, Long>();
        solutions.put(new Dials(1, 1), 0L);
        for (var target : C)
        {
            SortedMap<Dials, Long> new_solutions = new TreeMap();
            for (var entry : solutions.entrySet())
            {
                final var dials = entry.getKey();
                final var distance = entry.getValue();
                // we turn dial1
                insert_solution(new_solutions, N, target, dials.dial1, dials.dial2, distance);
                // we turn dial2
                insert_solution(new_solutions, N, target, dials.dial2, dials.dial1, distance);
            }
            solutions = new_solutions;
        }
        var min_distance = Long.MAX_VALUE;
        for (long distance : solutions.values())
            min_distance = Math.min(min_distance, distance);
        return min_distance;
    }

}

static class Args implements test_all.Result<Long> {
    int N;
    int[] C;
    long res;

    Args(int N, int[] C, Long res)
    {
        this.N = N;
        this.C = C;
        this.res = res;
    }

    @Override
    public Long getResult()
    {
        return res;
    }
}

public static int tests()
{
    var s = new Solution();

    Function<Args, Long> wrapper = (p) -> s.getMinCodeEntryTime(p.N, p.C.length, p.C);

    var args_list = new Args[]{
        new Args(3, new int[]{1, 2, 3}, 2L ),
        new Args( 10, new int[]{9, 4, 4, 8}, 6L ),
        // extra1
        new Args( 0, new int[]{}, 0L ),
        new Args( 3, new int[]{}, 0L ),
        new Args( 10, new int[]{}, 0L ),
        new Args( 10, new int[]{4}, 3L ),
        new Args( 10, new int[]{9}, 2L ),
        new Args( 10, new int[]{9, 9, 9, 9}, 2L ),
        // extra2
        new Args( 10, new int[]{6, 2, 4, 8}, 10L ),
        new Args( 10, new int[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 9L ),
        new Args( 4, new int[]{4, 3, 2, 1, 2, 3, 4}, 5L ),
    };

    return test_all.run_all_tests("l2_rotary_lock2", args_list, wrapper);
}

}  // class l2_rotary_lock2
