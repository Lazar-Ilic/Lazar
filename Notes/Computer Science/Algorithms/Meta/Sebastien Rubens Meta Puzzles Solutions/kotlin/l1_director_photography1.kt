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

package l1_director_photography1

fun <T> _getArtisticPhotographCount(_N: Int, C: String, X: Int, Y: Int): T
{
    val _X = X;
    val _Y = Y;

    data class Counts(
        var p: Int,
        var b: Int, )

    // count the number of Ps or Bs till a position i: O(N)
    val w = _Y + 1;
    val count = Counts( 0, 0 );
    val counts = ArrayList<Counts>(C.length + w.toInt() * 2);
    for (i in 0 until w)  // add space at the beginning to avoid special treatment of indices later
        counts.add(Counts( 0, 0 ));
    for (ci in C)
    {
        if (ci == 'P')
            ++count.p;
        else if (ci == 'B')
            ++count.b;
        counts.add(count.copy());
    }
    val last = counts.last();
    for (i in 0 until w)  // add space at the end to avoid special treatment of indices later
        counts.add(last);

    // To make things more readable, we are finding first the point where 'A' is found: O(N)
    val possible = ArrayList<Int>(C.length);
    var j = w;
    for (ci in C) {
        if (ci == 'A')
            possible.add(j);
        ++j;
    }

    // Count PABs : O(N)
    val X1 = _X - 1;
    val Y1 = _Y + 1;
    var nb: Long = 0;  // TODO: change type to T
    for (i in possible)
    {
        val a = counts[i - _X].p - counts[i - Y1].p;
        val b = counts[i + _Y].b - counts[i + X1].b;
        nb += a.toLong() * b.toLong();
    }

    // Count BAPs : O(N)
    for (i in possible)
    {
        val a = counts[i - _X].b - counts[i - Y1].b;
        val b = counts[i + _Y].p - counts[i + X1].p;
        nb += a.toLong() * b.toLong();
    }

    return nb as T;  // result should always be positive
}

fun getArtisticPhotographCount(N: Int, C: String, X: Int, Y: Int): Int {
    return _getArtisticPhotographCount<Int>(N, C, X, Y);
}

class Args(
    val C: String,
    val X: Int,
    val Y: Int,
    val res: Int, ) : test.Result<Int> {
    override fun get_result(): Int { return res; };
}

fun tests(): UInt
{
    val wrapper = { p: Args -> getArtisticPhotographCount(p.C.length, p.C, p.X, p.Y) };

    val args_list: List<Args> = listOf(
        Args( "APABA", 1, 2, 1 ),
        Args( "APABA", 2, 3, 0 ),
        Args( ".PBAAP.B", 1, 3, 3 ),
    );

    return test.run_all_tests("l1_director_photography1", args_list, wrapper);
}
