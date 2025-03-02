#include <bits/stdc++.h>
using namespace std;

double getMinExpectedHorizontalTravelDistance(int N, vector<int> H, vector<int> A, vector<int> B) {
	/* Well it suffices to simply compute for the totally all random case. Top
	down Dynamic Programming gives the probabilities of hitting that dude.
	And then bottoms up Dynamic Programming can produce the expected
	downstream contribution. So that if we flip 1 dude it certainly is the 
	case that all others are still in the sub random case and this validly
	alters the expected value by precisely that much quantity. At which point
	we can recompute upwards the downstream expected values and then simply do
	it. So we probably want to sort on height so we can then process through.
	And then maybe like store intervals covered overhead thus far for the
	initial drop as well as point masses of fall probabilities. Nothing too
	chaotic about the disorder of 1 deviation off of that case. 2024-10-31 Update: 
	See Sebastien Rubens Meta Puzzles Solutions folder. */
	return 0.0;
}