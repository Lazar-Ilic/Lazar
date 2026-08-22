// Remove instances of "AB", "BA", "CD", "DC" until left with output.

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {
	/* The target asymptotic is O[n]
	A natural solution is to process through
	Producing a prefix thus far so deletions from the right end are O[1].
	Then at the end we will have the target string.
	Think I should have known this one might come up again.
	And actually precomputed an optimal implementation prior to this round.
	Would be to check if and only if a certain sum is 1 modulo 4.
	Perhaps a simple 2 compare is better.
	Can clock if unsure check == 131 or == 135 versus this.
	But one expects native bit comparison modulo 4 computation to work OK.
	Should know this off of the top of my head if that 4 and == is faster.
	Rather than executing this 1 + operation and 1 modulo operation.
	Here I think that in the compiler the native % executes fast.
	I am fairly confident that on certain architectures this will take
	1 or 2 machine cycles to execute and it depends in fact.
	We can clock and micro analyse versus that earlier implementation with
	the 4 ands. */
	string output = "";
	for(char character : S){
		if(!output.empty() and (output.back() + character) % 4 == 3){
			output.pop_back();
		}
		else{
			output.push_back(character);
		}
	}
	return output;
	/* Later post facto analysis here circa 2022-07-22 is that they may have
	indeed wanted me to not waste memory and instead modify the string S in
	place so more something like: */
	int a = -1;
	for(char character : S){
		if(a >= 0 and (S[a] + character) % 4 == 3){
			a--;
		}
		else{
			a++;
			S[a] = character;
		}
	}
	S.resize(a + 1);
	return S;
}



// Compute maximal path in tree with alternating vertices.

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// #include <stack>

vector<vector<int>> children;
vector<int> maxpath;
int maximum = 0;

void dfs(int a){
	visited[a] = 1;
	int c = -1;
	int d = -1;
	for(int b : children[a]){
			dfs(b);
			/* The expected number of children is ~1 but we can think about
			expected distributions or optimal way to have the maximum 2 in a
			reservoir in terms of comparison operations here. */
			if(maxpath[b] > c){
				d = c;
				c = maxpath[b];
			}
			else if(maxpath[b] > d){
				d = maxpath[b];
			}
	}
	//cout << a << " " << c << " " << d << endl;
	maxpath[a] = c + 1;
	if(3 + c + d > maximum){
		maximum = 3 + c + d;
	}
}

int solution(string &S, vector<int> &A) {
    /*
	OK this feels like a pretty canonical classic Competitive Programming
	style of task. We aim to simply Dynamic Program from the leafs up
	towards the root of the tree and at each vertex we can simply compute
	the maximum 2 of its relevant down dudes and compare with the maximum
	thus far and then store the maximum 1 for relevant upward compares
	operations. This should work in O[V]. I think that a separate function
	is not needed as we can use a Depth First Search stack approach here.
	In particular each path in a tree has a unique maximum level node in a
	Depth First Search and so it suffices to consider the maximum path
	down to a different bit, which brings up a conversion into bits. Or
	we can simply process through storing only the valid implicit edges.
	Using a simple comparison operation works fast enough here. Think uh
	last time I did the usual canonical Maximum Path In A Tree algorithm
	via 2 Breadth First Searches on a queue based implementation. It was
	quite subotpimal in a few ways including memory usage which can be easily avoided in that one as the current Breadth First Search level distance may simply be stored in 1 variable to be output at the end. Do not think
	that pre processing through S will hurt too much. 1 cycle. It is possible
	to do all of this in loop via for example processing once through to
	produce the usual stack or in order such that each child comes after its
	parent and then process through that backwards with the relevant memory
	data structure such that processing order is ensured and all children are
	processed prior to the processing of the parent vertex.
	*/
	children = vector<vector<int>> (A.size(), vector<int> (0));
	maxpath = vector<int> (A.size());
	maximum = 0;
	vector<int> subroots;
	subroots.push_back(0);
	for(int a = 1; a < A.size(); a++){
		if(S[a] != S[A[a]]){ // Compiler works out these lookups.
			children[A[a]].push_back(a);
		}
		else{
			subroots.push_back(a);
		}
	}
	for(int a : subroots){
		dfs(a);
	}
	return maximum;
}