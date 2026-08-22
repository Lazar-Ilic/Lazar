// Might process through "Hard" "Elite Code" in minimum solve rate order.

// Might want to see about spotting superior algorithms.

// 

class Solution { // 4 Median Of Two Sorted Arrays
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		/*
		*/
	}
};

// 1139 Largest 1-Bordered Square

int largest1BorderedSquare(vector<vector<int>>& grid){
	// Works for square grid input cases.
	int outsize = 0;
	int size = grid.size();
	int size2 = grid[0].size();
	vector<vector<int>> left = vector<vector<int>> (size, vector<int> (size2));
	vector<vector<int>> right = vector<vector<int>> (size, vector<int> (size2));
	int x = 0;
	int y = 0;
	for(int i = 0; i < size; i ++){
		x = 0;
		for(int j = 0; j < size2; j++){
			if(grid[i][j]){
				x += 1;
			}
			else{
				x = 0;
			}
			left[i][j] = x;
		}
	}
	for(int i = 0; i < size; i ++){
		x = 0;
		for(int j = size2 - 1; j >= 0; j--){
			if(grid[i][j]){
				x += 1;
			}
			else{
				x = 0;
			}
			right[i][j] = x;
		}
	}
	for(int i = 0; i < size2; i ++){
		y = 0;
		for(int j = 0; j < size; j++){
			if(grid[j][i]){
				y += 1;
			}
			else{
				y = 0;
			}
			left[j][i] = min(y, left[j][i]);
		}
	}
	for(int i = 0; i < size2; i ++){
		y = 0;
		for(int j = size - 1; j >= 0; j--){
			if(grid[j][i]){
				y += 1;
			}
			else{
				y = 0;
			}
			right[j][i] = min(y, right[j][i]);
		}
	}
	/* Of course we do not want to waste compute on cases <= outsize and
	furthermore we may as well go in order of diagonal size so that we may
	e.g. halt immediately upon the case that the maximal square works etc. */
	int minx, miny, diag;
	for(int a = -(size2 - 1); a < size; a++){
		// Process through the diagonal[s] y - x = a.
		if(a <= 0){
			minx = 0;
			miny = -a;
			diag = min(size2 - miny, size - minx);
		}
		else{
			minx = a;
			miny = 0;
			diag = min(size - minx, size2 - miny);
		}
		if(outsize >= diag) break;
		vector<vector<int>> rightmost = vector<vector<int>> (diag, vector<int> (0));
		for(int b = 0; b < diag; b++){
			if(right[minx + b][miny + b] > outsize){
				rightmost[b + right[minx + b][miny + b] - 1].push_back(b);
			}
		}
		stack<int> liveleft;
		for(int b = diag - 1; b >= 0; b--){
			// Process from right to left now swooping maximally.
			for(int c : rightmost[b]){
				liveleft.push(c);
			}
			while(!liveleft.empty() && liveleft.top() >= b + 1 - left[minx + b][miny + b]){
				if(b + 1 - liveleft.top() > outsize){
					outsize = b + 1 - liveleft.top();
				}
				liveleft.pop();
			}
		}
	}
	return outsize * outsize;
}

// 420 Strong Password Checker

int strongPasswordChecker(string password) {
	bool missinglower = 1;
	bool missingupper = 1;
	bool missingdigit = 1;
	int moves = 0;
	for(char ac : password){
		if(ac - 'a' >= 0 and 'z' - ac >= 0) missinglower = 0;
		else if(ac- 'A' >= 0 and 'Z' - ac >= 0) missingupper = 0;
		else if(ac - '0' >= 0 and '9' - ac >= 0) missingdigit = 0;
	}
	int a = 2;
	while(a < password.size() and !(password[a] == password[a-1] and password[a] == password[a-2])){
		a++;
	}
	while(password.size() < 6){
		// Insert at first relevant point.
		if(missinglower){
			password.insert(a, 'a');
		}
	}
	while(password.size() > 20){
		// Delete at first relevant point.
		if
	}
}

// Eh dunno dunno maybe I simply read through the fora and copy and paste acceptable AC Accepted codes and study them perhaps tweak and tune them.

int strongPasswordChecker(string s){
	int deleteTarget = max(0, (int)s.length() - 20), addTarget = max(0, 6 - (int)s.length());
	int toDelete = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;
	for(int l = 0, r = 0; r < s.length(); r++){
		if(isupper(s[r])){
			needUpper = 0;
		}				
		if(islower(s[r])){
			needLower = 0;
		}
		if(isdigit(s[r])){
			needDigit = 0;
		}
		if(r - l == 2){
			if(s[l] == s[l + 1] && s[l + 1] == s[r]){
				if(toAdd < addTarget){
					toAdd++, l = r;
				}
				else{
					toReplace++, l = r + 1;
				}
			}
			else{
				l++;
			}
		}
	}
	if(s.length() <= 20){
		return max(addTarget + toReplace, needUpper + needLower + needDigit);
	}
	toReplace = 0;
	vector<unordered_map<int, int>> lenCnts(3);
	for(int l = 0, r = 0, len; r <= s.length(); r++){
		if(r == s.length() || s[l] != s[r]){
			if((len = r - l) > 2){
				lenCnts[len % 3][len]++;
			}
			l = r;
		}
	}
	for(int i = 0, numLetters, dec; i < 3; i++){
		for(auto it = lenCnts[i].begin(); it != lenCnts[i].end(); it++){
			if(i < 2){
				numLetters = i + 1, dec = min(it->second, (deleteTarget - toDelete) / numLetters);
				toDelete += dec * numLetters, it->second -= dec;
				if(it->first - numLetters > 2){
					lenCnts[2][it->first - numLetters] += dec;
				}
			}
			toReplace += (it->second) * ((it->first) / 3);
		}
	}
	int dec = (deleteTarget - toDelete) / 3;
	toReplace -= dec, toDelete -= dec * 3;
	return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
}

// 2286 Booking Concert Tickets In Groups

class BookMyShow{
	int n;
	int m;
	vector<array<long long, 2>> stree; // segment tree that tracks (max, sum) of each segment
	public:
	void build(int i, int p, int q){
		if(p == q){
			stree[i] = {m, m};
			return;
		}
		int r = (p + q) / 2;
		stree[i] = {m, (long long)(q - p + 1) * m};
		build(2 * i + 1, p, r);
		build(2 * i + 2, r + 1, q);
	}
	vector<int> query_max(int i, int p, int q, int k, int maxRow){
		if(p > maxRow) return {};
		if(stree[i][0] < k) return {};
		if(p == q) return {p, (int)(m - stree[i][0])};
		int r = (p + q) / 2;
		vector<int> ret = query_max(2 * i + 1, p, r, k, maxRow);
		if(ret.size()) return ret;
		return query_max(2 * i + 2, r + 1, q, k, maxRow);
	}
	void update_max(int i, int p, int q, int row, int k){
		if(p > row || q < row) return;
		if(p == q){
			stree[i][0] -= k;
			stree[i][1] -= k;
			// cout << p << " " << stree[i][0] << endl;
			return;
		}
		int r = (p + q) / 2;
		stree[i][1] -= k;
		update_max(2 * i + 1, p, r, row, k);
		update_max(2 * i + 2, r + 1, q, row, k);
		stree[i][0] = max(stree[2 * i + 1][0], stree[2 * i + 2][0]);
	}
	long long query_sum(int i, int p, int q, int maxRow){
		if(p > maxRow) return 0;
		if(q <= maxRow) return stree[i][1];
		int r = (p + q) / 2;
		return query_sum(2 * i + 1, p, r, maxRow) + query_sum(2 * i + 2, r + 1, q, maxRow);
	}
	void update_sum(int i, int p, int q, int k, int maxRow){
		if(p > maxRow) return;
		if(p == q){
			stree[i][0] -= k;
			stree[i][1] -= k;
			// cout << p << " " << stree[i][0] << endl;
			return;
		}
		int r = (p + q) / 2;
		stree[i][1] -= k;
		if(r + 1 > maxRow || stree[2 * i + 1][1] >= k){
			update_sum(2 * i + 1, p, r, k, maxRow);
		}
		else{
			k -= stree[2 * i + 1][1];
			update_sum(2 * i + 1, p, r, stree[2 * i + 1][1], maxRow);
			// Be aware: stree[2*i+1][1] updates while updating the left tree
			update_sum(2 * i + 2, r + 1, q, k, maxRow);
		}
		stree[i][0] = max(stree[2 * i + 1][0], stree[2 * i + 2][0]);
	}
	BookMyShow(int n_in, int m_in){
		n = n_in;
		m = m_in;
		int sz = 1;
		while(sz < n * 2) sz <<= 1;
		stree.resize(sz);
		build(0, 0, n - 1);
	}
	vector<int> gather(int k, int maxRow){
		// cout << "gather " << k << " " << maxRow << endl;
		vector<int> ret = query_max(0, 0, n - 1, k, maxRow);
		if(ret.size()) update_max(0, 0, n - 1, ret[0], k);
		return ret;
	}
	bool scatter(int k, int maxRow){
		// cout << "scatter " << k << " " << maxRow << endl;
		long long cnt = query_sum(0, 0, n - 1, maxRow);
		bool ret = cnt >= k;
		if(ret) update_sum(0, 0, n - 1, k, maxRow);
		return ret;
	}
};

// 1622 Fancy Sequence

int mod97 = 1000000007;
/*
Calculates multiplicative inverse.
*/
unsigned long modPow(unsigned long x, int y){
		unsigned long tot = 1, p = x;
		for(; y; y >>= 1){
			if(y & 1) tot = (tot * p) % mod97;
			p = (p * p) % mod97;
		}
		return tot;
	}
class Fancy{
	public:
	unsigned long seq[100001];
	unsigned int length = 0;
	unsigned long increment = 0;
	unsigned long mult = 1;
	Fancy(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	}
	void append(int val){
		seq[length++] = (((mod97 + val - increment) % mod97) * modPow(mult, mod97 - 2)) % mod97;
	}
	void addAll(int inc){
		increment = (increment+ inc % mod97) % mod97;
	}
	void multAll(int m){
		mult = (mult * m % mod97) % mod97;
		increment = (increment * m % mod97) % mod97;
	}
	int getIndex(int idx){	
		if(idx >= length) return -1;
		else return ((seq[idx] * mult) % mod97 + increment) % mod97;
	}
};

// 65 Valid Number

class Solution{
	public:
	bool isNumber(string str){
		// Deterministic Finite Automoton
		int state = 0, flag = 0; // flag to judge the special case "."
		while(str[0] == ' ') str.erase(0, 1); // delete the prefix Whitespace 
		while(str[str.length()-1] == ' ') str.erase(str.length() - 1, 1);
		// delete the suffix Whitespace
		for(int i = 0; i < str.length(); i++){
			if('0' <= str[i] && str[i] <= '9'){
				flag = 1;
				if(state <= 2) state = 2;
				else state = (state <= 5) ? 5 : 7;
			}
			else if('+' == str[i] || '-' == str[i]){
				if(state == 0 || state == 3) state++;
				else return false;
			}
			else if('.' == str[i]){
				if(state <= 2) state = 6;
				else return false;
			}
			else if('e' == str[i]){
				if(flag && (state == 2 || state == 6 || state == 7)) state = 3;
				else return false;
			}
			else return false;
		}
		return(state == 2 || state == 5 || (flag && state == 6) || state == 7);
	}
};

// Failed.

class Solution{
	public:
	bool isNumber(string s){
		while(!s.empty() && s[0] == ' '){
			s.erase(s.begin());
		}
		while(!s.empty() && s[s.size()-1] == ' '){
			s.erase(s.end()-1);
		}
		if(s.empty()) return false;
		int state = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '-' || s[i] == '+'){
				if(state == 0 || state == 3){
					state ++;
				}
				else{
					return false;
				}
			}			
			else if(s[i] == '.'){
				if(state == 2){
					state = 7;
				}
				else if(state == 0 || state == 1){
					state = 6;
				}
				else{
					return false;
				}
				
			}
			else if(s[i] >= '0' && s[i] <= '9'){
				if(state == 1 || state == 4 || state == 6){
					state++;
				}
				else if(state == 0 || state == 3){
					state = state + 2;
				}
			}
			else if(s[i] == 'e' || s[i] == 'E'){
				if(state == 2 ||  state == 7){
					state = 3;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		if(state == 2|| state == 7 || state == 5) return true;
		return false;
	}
};

// Is an AC Faster Than 100.00%

// 2035 Partition Array Into Two Arrays To Minimise Sum Difference

// Dunno my latency here < 600s In A Round Maybe

// Time Limit Exceeded On Next Permutation Call Is Suboptimal

class Solution{
	public:
	int minimumDifference(vector<int>& nums){
		int sum = 0;
		int mini = INT_MAX;
		for(int num : nums) sum += num;
		int count = (nums.size() - 2) / 2;
		vector<int> av = vector<int> (2 * count + 1);
		for(int a = count + 1; a <= 2 * count; a++) av[a] = 1;
		do{
			int sum2 = nums[nums.size() - 1];
			for(int b = 0; b < 2 * count + 1; b++){
				if(av[b]) sum2 += nums[b];
			}
			mini = min(mini, abs(2 * sum2 - sum));
		}while(next_permutation(((av).begin()),((av).end())));
		return mini;
	}
};

// OK AC Solution Code

class Solution{
	public:
	int minimumDifference(vector<int>& nums){
		int n = nums.size(), res = 0, sum = 0;
		sum = accumulate(nums.begin(), nums.end(), 0);
		int N = n / 2;
		vector<vector<int>> left(N + 1), right(N + 1);
		// storing all possible sum in left and right part
		for(int mask = 0; mask < (1 << N); ++mask){
			int sz = 0, l = 0, r = 0;
			for(int i = 0; i < N; ++i){
				if(mask & (1 << i)){
					sz++;
					l += nums[i];
					r += nums[i + N];
				}
			}
			left[sz].push_back(l);
			right[sz].push_back(r);
		}
		for(int sz = 0; sz <= N; ++sz){
			sort(right[sz].begin(), right[sz].end());
		}
		res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));
		// iterating over left part
		for(int sz = 1; sz < N; ++sz){
			for(auto &a : left[sz]){
				int b = (sum - 2 * a) / 2, rsz = N - sz;
				auto &v = right[rsz];
				auto itr = lower_bound(v.begin(), v.end(), b); // binary search over right part
				if(itr != v.end()) res = min(res, abs(sum - 2 * (a + (*itr))));
				if(itr != v.begin()){
					auto it = itr; --it;
					res = min(res, abs(sum - 2 * (a + (*it))));
				}				
			}
		}
		return res;
	}
};

// 149 Max Points On A Line

class Solution{
	public:
	int maxPoints(vector<vector<int>> &points){
		if(points.size() < 2) return points.size();
		int result = 0;
		for(int i = 0; i < points.size(); i++){			
			map<pair<int, int>, int> lines;
			int localmax = 0, overlap = 0 , vertical = 0;
			for(int j = i + 1; j < points.size(); j++){
				if(points[j][0] == points[i][0] && points[j][1] == points[i][1]){
					overlap++;
					continue;
				}
				else if(points[j][0] == points[i][0]) vertical++;
				else{
					int a = points[j][0] - points[i][0], b = points[j][1] - points[i][1];
					int gcd = GCD(a, b);
					a /= gcd;
					b /= gcd;
					lines[make_pair(a, b)]++;
					localmax = max(lines[make_pair(a, b)], localmax);
				}
				localmax = max(vertical, localmax);
			}
			result = max(result, localmax + overlap + 1);
		}
		return result;
	}
	private:
	int GCD(int a, int b){
		if(b == 0) return a;
		else return GCD(b, a % b);
	}
};

// 2156 Find Substring With Given Hash Value

class Solution{
public:
	string subStrHash(string s, int p, int mod, int k, int target){
		long h = 0, N = s.size(), pp = 1; // `pp` = p^k
		vector<long> hash(N);
		string r(rbegin(s), rend(s));
		for(int i = 0; i < N; ++i){
			if(i < k) pp = pp * p % mod;
			h = (h * p + (r[i] - 'a' + 1)) % mod; // push r[i] into the window
			if(i - k >= 0){ // pop r[i-k] out of the window
				h = (h - (r[i - k] - 'a' + 1) * pp % mod + mod) % mod;
			}
			if(i >= k - 1) hash[i] = h;
		}
		reverse(begin(hash), end(hash));
		for(int i = 0; i < N; ++i){
			if(hash[i] == target) return s.substr(i, k); // hash[i] is the hash of `s[i .. (i+k-1)]`
		}
		return "";
	}
};

// 564 Find The Closest Palindrome

class Solution{
	bool is10__(string s){ // for 10* and 10*(0+1) types
		if(s[0] == '1'){
			for(int i = 1; i < s.length() - 1; i++){
				if(s[i] != '0') return false;
			}
			if(s.back() != '0' && s.back() != '1') return false;
			return true;
		}
		return false;
	}
	bool is99__(string s){ // for 99* types
		for(int i = 0; i < s.length(); i++){
			if(s[i] != '9') return false;
		}
		return true;
	}
	string getReverse(string s, bool odd){
		if(odd){
			s.pop_back();
		}
		int lo = 0, hi = s.length() - 1;
		while(lo < hi){
			swap(s[lo++], s[hi--]);
		}
		return s;
	}
	public:
	string nearestPalindromic(string n){
		int len = n.length();
		if(len == 1){
			return to_string((n[0] - '0') - 1);
		}
		string res = "";
		if(is10__(n)){
			for(int i = 0; i < len - 1; i++){
				res += '9';
			}
			return res;
		}
		if(is99__(n)){
			res = "1";
			for(int i = 0; i < len - 1; i++){
				res += '0';
			}
			res += '1';
			return res;
		}
		long long half = ((len & 1) ? stoll(n.substr(0, len / 2 + 1)) : stoll(n.substr(0, len / 2)));
		long long greater, smaller, equal;
		if(len & 1){
			greater = stoll(to_string(half + 1) + getReverse(to_string(half + 1), true));
			smaller = stoll(to_string(half - 1) + getReverse(to_string(half - 1), true));
			equal = stoll(to_string(half) + getReverse(to_string(half), true));
		}
		else{
			greater = stoll(to_string(half + 1) + getReverse(to_string(half + 1), false));
			smaller = stoll(to_string(half - 1) + getReverse(to_string(half - 1), false));
			equal = stoll(to_string(half) + getReverse(to_string(half), false));
		}
		long long minDiff = LLONG_MAX;
		long long ans;
		if(stoll(n) - smaller < minDiff){
			minDiff = stoll(n) - smaller;
			ans = smaller;
		}
		if(stoll(n) != equal && abs(stoll(n) - equal) < minDiff){
			minDiff = abs(stoll(n) - equal);
			ans = equal;
		}
		if(greater - stoll(n) < minDiff){
			minDiff = greater - stoll(n);
			ans = greater;
		}
		return to_string(ans);
	}
};

// Another 0ms Faster Than 100.00% Of C++ Interesting Hmmm O[1]

// 1977 Number Of Ways To Separate Numbers

class Solution{
	public:
	int numberOfCombinations(string num){
		if(num[0] == '0') return 0;
		long N = num.size(), ans = 0, mod = 1e9 + 7;
		vector<vector<long>> lcp(N + 1, vector<long>(N + 1)), dp(N + 1, vector<long>(N + 1));
		for(int i = N - 1; i >= 0; --i){
			for(int j = N - 1; j >= 0; --j){
				if(num[i] == num[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
			}
		}
		auto le = [&](int k, int i, int j){
			int len = lcp[k][i];
			return len >= j + 1 - i || num[k + len] < num[i + len];
		};
		for(int j = 0; j < N; ++j) dp[0][j] = 1;
		for(int i = 1; i < N; ++i){
			if(num[i] == '0') continue;
			for(int j = i, k = i - 1, sum = 0; j < N; ++j){
				dp[i][j] = sum; // case 1
				if(k < 0) continue; // if k < 0, case 2 (equal length) is invalid but we still need to continue to handle case 1, so we should use `continue` here.
				if(num[k] > '0' && le(k, i, j)) dp[i][j] = (dp[i][j] + dp[k][i - 1]) % mod; // case 2
				sum = (sum + dp[k][i - 1]) % mod; // update the sum used in case 1.
				--k;
			}
		}
		for(int i = 0; i < N; ++i) ans = (ans + dp[i][N - 1]) % mod;
		return ans;
	}
};

// 2338 Count The Number Of Ideal Arrays

class Solution{
	public:
	int n, m, dp[10005][20];
	int C[10005][20];
	int idealArrays(int n, int m){
		int mod = 1e9 + 7;
		for(int i = 1; i <= m; i++){
			dp[i][1] = (dp[i][1] + 1) % mod;
			for(int j = i + i; j <= m; j += i){
				for(int k = 1; k <= 18; k++){
					dp[j][k] = (dp[j][k] + dp[i][k - 1]) % mod;
				}
			}
		}
		for(int i = 0; i <= n; i++){
			C[i][0] = 1;
			for(int j = 1; j <= min(i, 18); j++){
				C[i][j] = (C[i - 1][j]+C[i - 1][j - 1]) % mod;
			}
		}
		long long ans = 0;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= 18; j++){
				ans = (ans + 1ll * dp[i][j] * C[n - 1][j - 1] % mod) % mod;
			}
		}
		return ans;
	}
};

// 2157 Groups Of Strings

// DFS

class Solution{
public:

unordered_map<int, int> m;
int dfs(int mask){
	int res = 0;
	auto it = m.find(mask);
	if(it != end(m)){
		res += it->second;
		m.erase(it);
		for(int i = 0; i < 26; ++i){
			res += dfs(mask ^ (1 << i));
			for(int j = i + 1; j < 26; ++j){
				if(((mask >> i) & 1) != ((mask >> j) & 1)){
					res += dfs(mask ^ (1 << i) ^ (1 << j));
				}
			}
		}
	}
	return res;
}
vector<int> groupStrings(vector<string>& words){
	int groups = 0, max_size = 0;
	for(auto &w : words){
		++m[accumulate(begin(w), end(w), 0, [](int m, char ch){ return m | (1 << (ch - 'a')); })];
	}
	while (!m.empty()){
		auto size = dfs(begin(m)->first);
		max_size = max(max_size, size);
		groups += size > 0;
	}
	return{
		groups, max_size
	};
}

};

// Union Find

class Solution {
public:

unordered_map<int, int> m;
int find(vector<int> &ds, int i){
	return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
void merge(vector<int> &ds, int i, int mask){
	auto it = m.find(mask);
	if(it != end(m)){
		int pi = find(ds, i), pj = find(ds, it->second);
		if(pi != pj){
			if(ds[pi] > ds[pj]) swap(pi, pj);
			ds[pi] += ds[pj];
			ds[pj] = pi;
		}
	}
	else m[mask] = i;
}
vector<int> groupStrings(vector<string>& words){
	vector<int> ds(words.size(), -1);
	for(int i = 0; i < words.size(); ++i){
		int mask = accumulate(begin(words[i]), end(words[i]), 0, [](int m, char ch){
			return m | (1 << (ch - 'a'));
		});
		merge(ds, i, mask);
		for(int j = 0; j < 26; ++j){
			if(mask & (1 << j)) merge(ds, i, mask ^ (1 << j));
		}
	}
	return {(int)count_if(begin(ds), end(ds), [](int i){ return i < 0; }), - *min_element(begin(ds), end(ds)) };
}

};

// 2281 Sum Of Total Strength Of Wisards

class Solution{
public:

int totalStrength(vector<int>& st){
	long long MOD = 1000000007;
	const int N = st.size();
	// sum of first k elements
	vector<long long> prefix(N + 1, 0L);
	for(int i = 0; i < N; ++i){
		prefix[i + 1] = (prefix[i] + st[i]) % MOD;
	}
	// sum of first k prefix
	vector<long long> prefix_sum(N + 2, 0L);
	for(int i = 0; i <= N; ++i){
		prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
	}
	// first index on the left < current st
	vector<int> left(N, -1);
	// mono increase
	vector<int> stack;
	for(int i = 0; i < N; ++i){
		while(!stack.empty() && st[stack.back()] >= st[i]){
			stack.pop_back();
		}
		left[i] = stack.empty() ? -1 : stack.back();
		stack.push_back(i);
	}
	// first index on the right <= current st
	vector<int> right(N, N);
	stack.clear();
	for(int i = N - 1; i >= 0; --i){
		while(!stack.empty() && st[stack.back()] > st[i]){
			stack.pop_back();
		}
		right[i] = stack.empty() ? N : stack.back();
		stack.push_back(i);
	}
	long long res = 0;
	for(int i = 0; i < N; ++i){
		res += ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD + MOD * 2 - (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD) % MOD * st[i] % MOD;
		res %= MOD;
	}
	return (int) res;
}

};

// 862 Shortest Subarray With Sum At Least K

class Solution {
public:
	int shortestSubarray(vector<int>& nums, int k){
		int n = nums.size();
		vector<long> prefix_sum(n + 1, 0);
		for(int i = 0; i < n; ++i){
			prefix_sum[i + 1] = prefix_sum[i] + nums[i];
		}
		deque<long> dq;
		long res = n + 1;
		for(int i = 0; i < n + 1; ++i){
			// considering i as a potential END pointer
			while(!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k){
				res = min(res, i - dq.front());
				dq.pop_front();
			}
			// evaluating i as a potential START pointer against other potential earlier START pointers. 
			// So if the start pointer before i has a larger sum, then it i will be the better choice.
			while(!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]){
				dq.pop_back();
			}
			dq.push_back(i);
		}
		return res = res > n ? -1 : res;
	}
};

// 805 Split Array With Same Average

class Solution{
	public:
	bool dfs(int i, int sumN, int N, vector<int>& A){
		int n = A.size();
		if(N == 0) return sumN == 0;
		if(A[i] > sumN / N) return false;
		for(int j = i; j < n - N + 1; ++j){
			if(j > i && A[j] == A[j-1]) continue;
			if(dfs(j + 1, sumN - A[j], N - 1, A)) return true;
		}
		return false;
	}
	bool splitArraySameAverage(vector<int>& A){
		int n = A.size(), sum = 0;
		for(auto c : A) sum += c;
		sort(A.begin(), A.end());
		for(int len = 1; len <= n / 2; ++len){
			if(sum * len % n ) continue;
			if(dfs(0, sum * len / n, len, A)) return true;
		}
		return false;
	}
};

// Is Relatively Slow

class Solution{
	public:
	bool splitArraySameAverage(vector<int>& A){
	int N = A.size(), S = 0;
	for(int a : A) S += a;
	vector<int> p = vector<int> (S + 1);
	p[0] = 1;
	for(int a : A){
		for(int s = S - a; s >= 0; s--) p[s + a] |= p[s] << 1;
	}
	for(int n = 1; n < N; n++){
		if(S * n % N == 0  &&  p[S * n / N] & (1 << n)) return true;
	}
	return false;
	}
};

// 44 Wildcard Matching

class Solution{
	public:
	 bool isMatch(string s, string p){
		int i = 0, j = 0;
		int m = s.length(), n = p.length();
		int last_match = -1, starj = -1;
		while(i < m){
			if(j < n && (s[i] == p[j] || p[j] == '?')){
				i++;
				j++;
			}
			else if(j < n && p[j] == '*'){
				starj = j;
				j++;
				last_match = i;
			}
			else if(starj != -1){
				j = starj + 1;
				last_match++;
				i = last_match;
			}
			else return false;
		}
		while(p[j] == '*' && j <n) j++;
		return j == n;
	}
};

// Very minor changes alter runtime... need to read up more on compilers.

// 126 Word Ladder II

/* One can easily use significantly less auxiliary memory here by executing
the Breadth First Search in order on strings rather than vectors of strings
with an auxiliary hash set of strings that have already been processed
through simply terminating at the first Breadth First Search level e.g. the
minimum length path to the endWord. */

class Solution {
public:
	map<string,vector<string>> parent;
	unordered_map<string,int> dist;
	vector<vector<string>> ans;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		 for(string node : wordList) dist[node] = INT_MAX , parent[node] = {};
		 parent[beginWord] = {"root"};
		 queue<string> q;
		 dist[beginWord] = 1;
		 q.push(beginWord);
		 while(!q.empty()) {
			 string par = q.front();
			 q.pop();
			 if(par==endWord) break;
			 for(int i=0; i<par.size(); i++) {
				 string pref = "" , suff = "";
				 if(i) pref = par.substr(0,i);
				 if(i<par.size()-1) suff = par.substr(i+1);
				 string child = pref+'$'+suff;
				 int pos = pref.size();
				 for(char c='a'; c<='z'; c++) {
						if(c!=par[i]) {
							child[pos]=c;
							if(dist.count(child)) {
								 if(dist[child] > 1 + dist[par]) {
									 dist[child] =  1 + dist[par];
									 parent[child].clear();	// remove all parents , a better parent exists (shorter path from src to child)
									 parent[child].push_back(par);  // add that parent
									 q.push(child);
								 }else if(dist[child] == 1 + dist[par]) {
									 parent[child].push_back(par);  // add all parents of the best current distance 
								 }
							}
						}
				 }
			 }
		 }
		 vector<string> path;
		 pathfinder(endWord,path);
		 for(int i=0; i<ans.size(); i++) reverse(ans[i].begin(),ans[i].end());
		 return ans;
	}
	void pathfinder(string par,vector<string>&path) {
		 if(par=="root") {
			  ans.push_back(path);  // no parent exists of the root node , add the path to answer 
			  return;
		 }
		 for(string node : parent[par]) {
			  path.push_back(par);
			  pathfinder(node,path);
			  path.pop_back();
		 }
	}
};

/* Instead off the dome in round the simpler well OK maybe maybe... depends
on the target runtime performance of course we may simply generate backwards
the desired paths perhaps from the first Breadth First Search level where we
hit and use less auxiliary memory in some expected use cases. ,*/

class Solution{
	public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList){
		int a = 0;
		unordered_set<string> processed;
		processed.insert(beginWord);
		vector<string> processing, nextprocessing;
		processing.push_back(beginWord);
		while()
	}
};

// Eh OK.

// 887 Super Egg Drop

class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
		int m = 0;
		while (dp[m][K] < N) {
			m++;
			for (int k = 1; k <= K; ++k)
				dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
		}
		return m;
	}
};

// OK

// 2234 Maximum Total Beauty Of The Gardens

class Solution {
public:

long long maximumBeauty(vector<int>& fl, long long newFlowers, int target, int full, int partial) {
	sort(begin(fl), end(fl), greater<int>());
	long long p1 = 0, sum = 0, res = 0, sz = fl.size();
	for (; p1 < sz; ++p1) {
		if (target - fl[p1] > newFlowers)
			break;
		newFlowers -= max(0, target - fl[p1]);
	}
	if (p1 == sz)
		return max(sz * full, (sz - 1) * full + (fl.back() < target ? (long long)(target - 1) * partial : full));
	for (long long minF = fl.back(), p2 = fl.size() - 1; minF < target; ) {
		while (p2 >= p1 && fl[p2] <= minF)
			sum += fl[p2--];
		int needed = (sz - p2 - 1) * minF - sum;
		if (needed > newFlowers) {
			if (--p1 < 0)
				break;
			newFlowers += max(0, target - fl[p1]);
		}
		else {
			res = max(p1 * full + minF * partial, res);	
			++minF;
		}
	}
	return res;
}

};

// 2183 Count Array Pairs Divisible By K

/* One can onsight an O[something log something] algorithm here actually by 
representing say k as a product of its relevant primes to powers into that 
vector of powers and then process through the array counting up multiplicities 
for each um like induced representation of its powers on those primes as a 
vector in a sufficiently large int form might work followed by an actual 
execution of a Fast Fourier Transformation on the underlying sum of 
multiplicities vectors. Ensure to subtract off the i == j cases if executing 
this route. */

class Solution {
public:

long long countPairs(vector<int>& nums, int k) {
	long long res = 0;
	vector<pair<int, int>> factors;
	for (int i = 1; i * i <= k; ++i)
		if (k % i == 0) {
			factors.push_back({i, 0});
			if (k / i != i)
				factors.push_back({k / i, 0});
		}
	for (int n : nums) {
		long long gcd_nk = gcd(n, k);
		for (auto &[factor, cnt] : factors) {
			if (gcd_nk * factor % k == 0)
				res += cnt;
			if (gcd_nk == factor)
				++cnt;
		}
	}
	return res;
}

};

// 1923 Longest Common Subpath

class Solution {
	public:
	int longestCommonSubpath(int n, vector<vector<int>>& ps) {
	int l = 0, r = min_element(begin(ps), end(ps), [](const auto& a, const auto &b){ return a.size() < b.size(); })->size();
	long long base = 100001, mod = 100000000019;
	while (l < r) {
		int m = (l + r + 1) / 2;
		unordered_set<long long> hs;
		for (int i = 0; i < ps.size() && (i == 0 || !hs.empty()); ++i) {
			long long hash = 0, d = 1;
			unordered_set<long long> hs1;
			for (int j = 0; j < ps[i].size(); ++j) {
				hash = (hash * base + ps[i][j]) % mod;
				if (j >= m)
					hash = (mod + hash - d * ps[i][j - m] % mod) % mod;
				else
					d = d * base % mod;	
				if (j >= m - 1 && (i == 0 || hs.count(hash)))
					hs1.insert(hash);
			}
			swap(hs, hs1);
		}
		if (hs.empty())
			r = m - 1;
		else
			l = m;			
	}
	return l;
}
};

// 2117 Abbreviating The Product Of A Range

class Solution {
public:
string abbreviateProduct(int left, int right) {
	long long suff = 1, c = 0, total = 0, max_suff = 100000000000;
	double pref = 1.0;
	for (int i = left; i <= right; ++i) {
		pref *= i;
		suff *= i;
		while (pref >= 100000) {
			pref /= 10;
			total = total == 0 ? 6 : total + 1; 
		}
		while (suff % 10 == 0) {
			suff /= 10;
			++c;
		}
		suff %= max_suff;
	}
	string s = to_string(suff);
	return to_string((int)pref) + (total - c <= 10 ? "" : "...") 
			+ (total - c < 5 ? "" : s.substr(s.size() - min(5LL, total - c - 5))) + "e" + to_string(c);
}
};

// 1862 Sum Of Floored Pairs

class Solution {
public:

int ps[100001] = {};
int sumOfFlooredPairs(vector<int>& nums) {
	long res = 0, max_n = *max_element(begin(nums), end(nums));
	for (auto n : nums)
		++ps[n];
	vector<pair<int, int>> n_cnt;
	for (auto i = 1; i <= max_n; ++i) {
		if (ps[i])
			n_cnt.push_back({i, ps[i]});
		ps[i] += ps[i - 1];
	}
	for (auto &[n, cnt] : n_cnt)
		for (long f = max_n / n; f > 0; --f)
			res = (res + cnt * f * (ps[min(max_n, (f + 1) * n - 1)] - ps[f * n - 1])) % 1000000007;
	return res;
}

};

// OK

class Solution {
public:

int cnt[100001] = {}, sieve[100001] = {};
int sumOfFlooredPairs(vector<int>& nums) {
	int max_n = *max_element(begin(nums), end(nums));
	for (auto n : nums)
		++cnt[n];
	for (auto n = 1; n <= max_n; ++n)
		if (cnt[n])
			for (auto f = 1; n * f <= max_n; ++f)
				sieve[f * n] += cnt[n];
	partial_sum(begin(sieve), end(sieve), begin(sieve));
	return accumulate(begin(nums), end(nums), 0, [&](int sum, int n) { return (sum + sieve[n]) % 1000000007; });
}

};

// Causes a Runtime Error on new test sets, one supposes.

// 10 Regular Expression Matching

class Solution {
	public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<bool> cur(n + 1, false);
		for (int i = 0; i <= m; i++) {
			bool pre = cur[0];
			cur[0] = !i;
			for (int j = 1; j <= n; j++) {
				bool temp = cur[j];
				if (p[j - 1] == '*') {
					cur[j] = cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				} else {
					cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
				pre = temp;
			}
		}
		return cur[n];
	}
};

// 30 Substring With Concatenation Of All Words

class Solution {
	public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> counts;
		vector<int> indexes;
		for (string word : words)
		counts[word]++;
		int n = s.length(), num = words.size();
		if (n == 0 || num == 0) return indexes;
		int len = words[0].length();
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				string word = s.substr(i + j * len, len);
				if (counts.find(word) != counts.end()) {
					seen[word]++;
					if (seen[word] > counts[word])
						break;
				}
				else break;
			}
			if (j == num) indexes.push_back(i);
		}
		return indexes;
	}
};

// 321 Create Maximum Number

class Solution {
	public:
	#define MIN(a,b) (a<b?a:b)
	#define MAX(a,b) (a>b?a:b)
	// create max number of length t from single non-empty vector
	void getMax(int* num, int& len, int* result, int& t, int& sortedLen)
	{
		int n, top = 0;
		result[0] = num[0];
		const int need2drop = len - t;
		for (int i = 1; i < len; ++i) {
			n = num[i];
			while (top >= 0 && result[top] < n && (i - top) <= need2drop) --top; // i - top means already dropped i - top numbers
			if (i - top > need2drop) {
				sortedLen = MAX(1, top);
				while (++top < t) result[top] = num[i++];
				return;
			}
			if (++top < t) result[top] = n;
			else top = t - 1;
		}
	}
	// create max number of different length from single vector
	void dp (int *num, int len, int&sortedLen, int& minL, int& maxL, int *res, int &k) {
		int j, *head, *prevhead = res;
		const int soi = sizeof(int);
		getMax(num, len, res, maxL,sortedLen);
		for (int l = maxL; l > MAX(minL,1); --l) {
			head = prevhead + k;
			memcpy(head, prevhead, l*soi);
			for (j = sortedLen; j < l; ++j) {
				if (head[j] > head[j - 1]) {
					sortedLen = MAX(1, j - 1);
					memcpy(head + j - 1, prevhead + j, soi * (l - j));
					break;
				}
			}
			if (j == l) sortedLen = l;
			prevhead = head;
		}
	}
	// merge max number created from single vector
	void merge(int* num1,int len1,int* num2,int len2,int* result,int& resSize){
		int i = 0, j = 0, k = 0;
		while (i < resSize) {
			if (j < len1 && k < len2) {
				if (num1[j] > num2[k])
					result[i++] = num1[j++];
				else if (num1[j] < num2[k])
					result[i++] = num2[k++];
				else{
					int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
					int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
					flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
					int * num = flag > 0 ? num1 : num2;
					int & cnt = flag > 0 ? j : k;
					int len = flag > 0 ? len1 : len2;
					while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
				}
			}
			else if (j < len1) result[i++] = num1[j++];
			else result[i++] = num2[k++];
		}
	}
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
		int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
		int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
		int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
		memset(res, 0, step);
		int sortedLen1 = 1, sortedLen2 = 1;
		if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
		else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
		else if (len1 > 0 && len2 > 0){
			dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
			dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
			if (sortedLen1 + sortedLen2 > k){
				merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
				vector<int> resv(tmp, tmp + k);
				delete[] res;
				return resv;
			}
			for (int i = minL1; i <= maxL1; ++i){
				merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
				if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
			}
		}
		vector<int> resv(res, res + k);
		delete[] res;
		return resv;
	}
};

// 466 Count The Repetitions

class Solution {
	public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		vector<int> rapport(102, -1);
		vector<int> rest(102, -1);
		int b = -1;
		int posRest = 0;
		int rap = 0;
		int last = -1;
		rapport[0] = rest[0] = 0; // case when n = 0
		for(int i = 1; i <= s2.size() + 1; i++){
			int j;
			for(j = 0; j < s1.size(); j++){
				if(s2[posRest] == s1[j]){
					posRest++;
					if(posRest == s2.size()){
						rap++;
						posRest = 0;
					}
				}
			}
			for(int k = 0; k < i; k++){
				if(posRest == rest[k]){
					b = k;
					last = i;
					break;
				}
			}
			rapport[i] = rap;
			rest[i] = posRest;
			if(b >= 0) break;
		}
		int interval = last - b;
		if(b >= n1) return rapport[n1] / n2;
		return ((n1-b)/interval*(rapport[last]-rapport[b])+rapport[(n1-b)%interval+b])/n2;
		// corrected thanks to @zhiqing_xiao and @iaming 
	}
};

// 335 Self Crossing

class Solution {
	public:
	bool isSelfCrossing(vector<int>& x) {
		int len = x.size(), i;
		if(len <= 3) return false;
		bool grow_spiral;
		for(i = 3, grow_spiral = x[2] > x[0]; i < len; ++i){
			if(!grow_spiral && x[i] >= x[i-2]) return true;
			if(grow_spiral && x[i] <= x[i-2]){
				grow_spiral = false;
				x[i-1] = x[i] + ( i>= 4 ? x[i-4] : 0) < x[i-2] ? x[i-1] : x[i-1] - x[i-3];
			}
		}
		return false;
	}
};

// Yeah so spaces and comments majorly throw off execution times... flags?

// 1960 Maximum Product Of The Length Of Two Palindromic Substrings

class Solution {
	public:
	long long maxProduct(string s) {
	long long res = 0, l = 0, n = s.size();
	vector<int> m(n), r(n);
	// Manacher's Algorithm (https://cp-algorithms.com/string/manacher.html)
	for (int i = 0, l = 0, r = -1; i < n; ++i) {
		int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
			k++;
		m[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	queue<array<int, 2>> q, q1;
	// Right-to-left to track max palindrome in [i, n).
	for (int i = n - 1; i >= 0; --i) {
		while (!q.empty() && q.front()[0] - q.front()[1] > i - 1)
			q.pop();
		r[i] = 1 + (q.empty() ? 0 : (q.front()[0] - i) * 2);
		q.push({i, m[i]});
	}
	// Left-to-right to track max palindrome in [0, i].
	for (int i = 0; i < n - 1; i += 1) {
		while (!q1.empty() && q1.front()[0] + q1.front()[1] < i + 1)
			q1.pop();
		l = max(l, 1ll + (q1.empty() ? 0 : (i - q1.front()[0]) * 2));
		res = max(res, l * r[i + 1]);
		q1.push({i, m[i]});
	}
	return res;
}
};

// OK

class Solution {
	public:
	vector<int> manachers(string s, int n) {
	 vector<int> m(n), l2r(n, 1);
	 for (int i = 0, l = 0, r = -1; i < n; ++i) {
		  int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
		  while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
				l2r[i + k] = 2 * k + 1;
				k++;
		  }
		  m[i] = k--;
		  if (i + k > r) {
				l = i - k;
				r = i + k;
		  }
	 }
	 for(int i = 1; i < n; i++) 
		  l2r[i] = max(l2r[i], l2r[i - 1]);
	 return l2r;
}
long long maxProduct(string s) {
	 long long res = 1, n = s.size();
	 auto l2r = manachers(s, n), r2l = manachers(string(rbegin(s), rend(s)), n);
	 for (int i = 0, j = n - 2; i < n - 1; ++i, --j)
		  res = max(res, (long long)l2r[i] * r2l[j]);
	 return res;
}
};

// 2040 Kth Smallest Product Of Two Sorted Arrays

class Solution {
	public:
	bool check(long long midval, vector<int>& nums1, vector<int>& nums2, long long k){
		long long cnt = 0;
		for(int i = 0; i < nums1.size(); i++){
			long long val = nums1[i];
			// If val == 0, product of val and each element in nums2 will be 0. And if midval>=0, then because all
			// products are 0, all products will be smaller or equal to midval. So we can add all products in the answer
			if(val == 0 and midval >= 0)
				cnt += nums2.size();
			else if(val > 0)
				cnt += findmaxIndex(nums2, val, midval);
			else if(val < 0)
				cnt += findminIndex(nums2, val, midval);
		  }
		  return cnt >= k;
	}
	int findmaxIndex(vector<int>&nums2, long long val, long long midval){
		int l = 0, r = nums2.size() - 1, res = -1;
		while(l <= r){
			long long mid = (l + r) / 2;
			if(val * nums2[mid] <= midval){
				res = mid;
				l = mid + 1;
			}
			else r=mid-1;
		}
		return res+1;
	}
	int findminIndex(vector<int>&nums2 , long long  val , long long midval){
		int l = 0, r = nums2.size() - 1 , res = r + 1;
		while(l <= r){
			long long mid = (l + r) / 2;
			if(val * nums2[mid] <= midval) {
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return nums2.size() - res;
	}
	long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
	long long l = -1e10, r = 1e10, res = -1;
	while(l <= r){
		long long mid = (l + r) / 2;
		// cout << mid << endl;
		if(check(mid, nums1, nums2, k)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
	}
};

// 273 Integer To English Words

class Solution {
	public:
	string intToString(int n){
		string ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		string tens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		if(n >= 1000000000) return intToString(n/1000000000) + " Billion" + intToString(n % 1000000000);
		if(n >= 1000000) return intToString(n/1000000) + " Million" + intToString(n % 1000000);
		if(n >= 1000) return intToString(n/1000) + " Thousand" + intToString(n % 1000);
		if(n >= 100) return intToString(n/100) + " Hundred" + intToString(n % 100);
		if(n >= 20) return " " + tens[n / 10 - 2 ] + intToString(n % 10) ;
		if(n >= 1) return " " + ones[n];
		return "";
	}
	string numberToWords(int n) {
		if(n == 0) return "Zero";
		return intToString(n).substr(1);  
	}
};

// 2132 Stamping The Grid

class Solution {
public:

vector<vector<int>> pref2d(vector<vector<int>> &v, int m, int n) {
	vector<vector<int>> p(m + 1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			p[i + 1][j + 1] = v[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
	return p;
}
int sum2d(vector<vector<int>> &p, int c1, int r1, int c2, int r2) {
	return p[c2 + 1][r2 + 1] + p[c1][r1] - p[c1][r2 + 1] - p[c2 + 1][r1];
}
bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
	int m = g.size(), n = g[0].size();
	vector<vector<int>> stamp(m, vector<int>(n));
	auto pref = pref2d(g, m, n);
	for (int i = h - 1; i < m; ++i)
		for (int j = w - 1; j < n; ++j)
			stamp[i][j] = sum2d(pref, i - h + 1, j - w + 1, i, j) == 0;
	auto pref2 = pref2d(stamp, m, n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (g[i][j] == 0 && sum2d(pref2, i, j, min(m - 1, i + h - 1), min(n - 1, j + w - 1)) == 0)
				return false;
	return true;
}

};

// OK

class Solution {
public:
	bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
		int n=grid.size();
		int m=grid[0].size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		vector<vector<int>> blocked(n+1,vector<int>(m+1,0));

		for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < m; ++j)
		  {
			if(grid[i][j])
			{
			  blocked[i+1][j+1]=1;
			}
			// cout<<blocked[i+1][j+1]<<" "
;		  }
			// cout<<endl;
		}
		for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < m; ++j)
		  {
			blocked[i+1][j+1]+=blocked[i+1][j]+blocked[i][j+1]-blocked[i][j];
		  }
		}

		for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < m; ++j)
		  {
			if(grid[i][j]==0 and (i+stampHeight)<=n and (j+stampWidth)<=m)
			{
			  int x=i+stampHeight,y=j+stampWidth;
			  int l=i+1;
			  int r=j+1;
			  int sum=blocked[x][y]-blocked[l-1][y]-blocked[x][r-1]+blocked[l-1][r-1];
			  if(sum==0)
			  dp[i+1][j+1]=1;
			}
			// cout<<dp[i+1][j+1]<<" ";
		  }
			// cout<<endl;
		}
		for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < m; ++j)
		  {
			dp[i+1][j+1]+=dp[i+1][j]+dp[i][j+1]-dp[i][j];
			// cout<<dp[i+1][j+1]<<" ";
		  }
		  // cout<<endl;
		}
		for (int i = 0; i < n; ++i)
		{
		  for (int j = 0; j < m; ++j)
		  {
			  if(grid[i][j]==0)
			  {
				int x=i+1,y=j+1;
				int l=max(1,x- stampHeight+1);
				int r=max(1,y- stampWidth+1);
				int sum=dp[x][y]-dp[l-1][y]-dp[x][r-1]+dp[l-1][r-1];
				if(sum==0)
				{
				  // cout<<i+1<<" "<<j+1<<endl;
				  return false;
				}
			  }
		  }
		}
		return true;
	}
};

// Just OK for another day here studying some C++ compiler details again.

class LRUCache {
public:
	int vec[(int) 1e4 + 1][2] = {};
	int capacity;
	queue<int> q;

	LRUCache(int c) {
		cin.tie(0); ios_base::sync_with_stdio(0);
		capacity = c;
	}
	
	int get(int key) {
		if(!vec[key][1]) return -1;
		++vec[key][1];
		q.push(key);
		return vec[key][0];
	}
	
	void put(int key, int value) {
		if(vec[key][1]) {
			vec[key][0] = value;
			++vec[key][1];
			q.push(key);
		}
		else {
			if(!capacity) {
				while(vec[q.front()][1] > 1) {
					--vec[q.front()][1];
					q.pop();
				}
				vec[q.front()][1] = 0; 
				q.pop();
			}
			else --capacity;
			vec[key][0] = value;
			vec[key][1] = 1;
			q.push(key);
		}
	}
};

// Random Task k Points Closest To Origin

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<pair<int, int>> getClosestPoints(vector<pair<int, int>> points, int k) {
	/* Simple idea process through with a heap or priority_queue. */
	if(points.size() <= k) return points;
	// if(k == 1)
	priority_queue<pair<int, int>> apq;
	for(int a = 0; a < k; a++) apq.push(points[a]);
	long topsquared = long((apq.top()).first) * (apq.top()).first + long((apq.top()).second) * (apq.top()).second;
	for(int a = k; a < points.size(); a++){
		if(long((points[a]).first) * (points[a]).first + long((points[a]).second) * (points[a]).second < topsquared){
			apq.pop();
			apq.push(points[a]);
			topsquared = long((apq.top()).first) * (apq.top()).first + long((apq.top()).second) * (apq.top()).second;
		}
	}
	vector<pair<int, int>> output;
	while(!apq.empty()){
		output.push_back(apq.top());
		apq.pop();
	}
	return output;
}

int main(){
	vector<pair<int, int>> input = {{1, 1}, {3, 3}, {2, 2}};
	int k = 2;
	vector<pair<int, int>> output = getClosestPoints(input, k);
	for(pair<int, int> ap : output) cout << ap.first << " " << ap.second << endl;
	return 0;
}

// Boggle Solver Draft

vector<string> BoggleSolve(vector<string> wordslist, vector<vector<char>> board) {
	/* Simple idea rather than hash map from prefix to bool is 2 maps. */
	unordered_set<string> words, prefixes, outputset;
	vector<string> output;
	for(string word : wordslist){
		string a = "";
		for(char achar : word){
			a.push_back(achar);
			prefixes.insert(a);
		}
		words.insert(a);
	}
	for(int a = 0; a < board.size(); a++){
		for(int b = 0; b < board[0].size(); b++){
			// Depth First Search With Pruning Works Not In Mood Track Paths
		}
	}
	for(string as : outputset) output.push_back(as);
	return output;
}

// Some Linked List Tasks From The Trash So Called "Geeks For Geeks"


// C++ program for the above approach
 
#include <iostream>
using namespace std;
 
class Node {
public:
	int data;
	Node* next;
};
 
class NodeOperation {
public:
	// Function to add a new node
	void pushNode(class Node** head_ref, int data_val)
	{
 
		// Allocate node
		class Node* new_node = new Node();
 
		// Put in the data
		new_node->data = data_val;
 
		// Link the old list off the new node
		new_node->next = *head_ref;
 
		// move the head to point to the new node
		*head_ref = new_node;
	}
 
	// A utility function to print a given linked list
	void printNode(class Node* head)
	{
		while (head != NULL) {
			cout << head->data << "->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
 
	/* Utility Function to find length of linked list */
	int getLen(class Node* head)
	{
		int len = 0;
		class Node* temp = head;
		while (temp) {
			len++;
			temp = temp->next;
		}
		return len;
	}
 
	void printMiddle(class Node* head)
	{
 
		if (head) {
			// find length
			int len = getLen(head);
			class Node* temp = head;
 
			// trvaers till we reached half of length
			int midIdx = len / 2;
			while (midIdx--) {
				temp = temp->next;
			}
			// temp will be storing middle element
			cout << "The middle element is [" << temp->data
				 << "]" << endl;
		}
	}
};
 
// Driver Code
int main()
{
	class Node* head = NULL;
	class NodeOperation* temp = new NodeOperation();
	for (int i = 5; i > 0; i--) {
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	}
	return 0;
}
 
// This code is contributed by Tapesh(tapeshdua420)


// C++ program for flattening a Linked List
#include <bits/stdc++.h>
using namespace std;
 
// Link list node
class Node {
public:
	int data;
	Node *right, *down;
};
 
Node* head = NULL;
 
// An utility function to merge two sorted
// linked lists
Node* merge(Node* a, Node* b)
{
 
	// If first linked list is empty then second
	// is the answer
	if (a == NULL)
		return b;
 
	// If second linked list is empty then first
	// is the result
	if (b == NULL)
		return a;
 
	// Compare the data members of the two linked
	// lists and put the larger one in the result
	Node* result;
 
	if (a->data < b->data) {
		result = a;
		result->down = merge(a->down, b);
	}
 
	else {
		result = b;
		result->down = merge(a, b->down);
	}
	result->right = NULL;
	return result;
}
 
Node* flatten(Node* root)
{
 
	// Base Cases
	if (root == NULL || root->right == NULL)
		return root;
 
	// Recur for list on right
	root->right = flatten(root->right);
 
	// Now merge
	root = merge(root, root->right);
 
	// Return the root
	// it will be in turn merged with its left
	return root;
}
 
// Utility function to insert a node at
// beginning of the linked list
Node* push(Node* head_ref, int data)
{
 
	// Allocate the Node & Put in the data
	Node* new_node = new Node();
 
	new_node->data = data;
	new_node->right = NULL;
 
	// Make next of new Node as head
	new_node->down = head_ref;
 
	// Move the head to point to new Node
	head_ref = new_node;
 
	return head_ref;
}
 
void printList()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}
 
// Driver's code
int main()
{
 
	/* Let us create the following linked list
		5 -> 10 -> 19 -> 28
		|	|	 |	 |
		V	V	 V	 V
		7	20	22	35
		|		  |	 |
		V		  V	 V
		8		  50	40
		|				|
		V				V
		30			   45
	*/
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);
 
	head->right = push(head->right, 20);
	head->right = push(head->right, 10);
 
	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);
 
	head->right->right->right
		= push(head->right->right->right, 45);
	head->right->right->right
		= push(head->right->right->right, 40);
	head->right->right->right
		= push(head->right->right->right, 35);
	head->right->right->right
		= push(head->right->right->right, 20);
 
	// Function call
	head = flatten(head);
 
	printList();
	return 0;
}
 
// This code is contributed by rajsanghavi9.

// Note: does not compile! assumes negative numbers are after positive numbers in list
Node removeCancellableNodes(Node listHead)
{
	if (listHead == null) return null; // or listHead
	Stack<Node> stack = new Stack<Node>();
	Node node = listHead;  	
	while(node != null)
	{
		if (node.value < 0)
		{
			int sum = node.value;
						while (!stack.isEmpty())
			{
				Node temp = stack.pop();
				sum -= temp.value;
				temp = null;
				if (sum == 0)
				{
					node = stack.peek();
					break;
				}
			}
		}
		else
		{
			stack.push(node);
		}
		node = node.next;
	}
	
	return listHead;
}

struct LNode
{
  int data;
  shared_ptr<LNode> next;

  LNode(int d) : data(d){};
};

void cancelOut(shared_ptr<LNode> &head)
{
  shared_ptr<LNode> start = head;
  shared_ptr<LNode> end;

  while(start){
	end = start->next;
	int sum = 0;
	bool modified = false;

	while(end){
	  sum += end->data;
	  if(sum == 0){
		start->next = end->next;
		modified = true;
		break;
	  }
	  end = end->next;
	}
	if(!modified)
	  start = start->next;
  }
}

// C++ program to add 1 to a linked list 
#include <bits/stdc++.h>
using namespace std;
  
/* Linked list node */
class Node 
{ 
	public:
	int data; 
	Node* next; 
}; 
  
/* Function to create a new node with given data */
Node *newNode(int data) 
{ 
	Node *new_node = new Node; 
	new_node->data = data; 
	new_node->next = NULL; 
	return new_node; 
} 
  
/* Function to reverse the linked list */
Node *reverse(Node *head) 
{ 
	Node * prev = NULL; 
	Node * current = head; 
	Node * next; 
	while (current != NULL) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	return prev; 
} 
  
/* Adds one to a linked lists and return the head 
node of resultant list */
Node *addOneUtil(Node *head) 
{ 
	// res is head node of the resultant list 
	Node* res = head; 
	Node *temp; 
  
	int carry = 1, sum; 
  
	while (head != NULL) //while both lists exist 
	{ 
		// Calculate value of next digit in resultant list. 
		// The next digit is sum of following things 
		// (i) Carry 
		// (ii) Next digit of head list (if there is a 
		// next digit) 
		sum = carry + head->data; 
  
		// update carry for next calculation 
		carry = (sum >= 10)? 1 : 0; 
  
		// update sum if it is greater than 10 
		sum = sum % 10; 
  
		// Create a new node with sum as data 
		head->data = sum; 
  
		// Move head and second pointers to next nodes 
		temp = head; 
		head = head->next; 
	} 
  
	// if some carry is still there, add a new node to 
	// result list. 
	if (carry > 0) 
		temp->next = newNode(carry); 
  
	// return head of the resultant list 
	return res; 
} 
  
// This function mainly uses addOneUtil(). 
Node* addOne(Node *head) 
{ 
	// Reverse linked list 
	head = reverse(head); 
  
	// Add one from left to right of reversed 
	// list 
	head = addOneUtil(head); 
  
	// Reverse the modified list 
	return reverse(head); 
} 
  
// A utility function to print a linked list 
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data; 
		node = node->next; 
	} 
	cout<<endl;
} 
  
/* Driver program to test above function */
int main(void) 
{ 
	Node *head = newNode(1); 
	head->next = newNode(9); 
	head->next->next = newNode(9); 
	head->next->next->next = newNode(9); 
  
	cout << "List is "; 
	printList(head); 
  
	head = addOne(head); 
  
	cout << "\nResultant list is "; 
	printList(head); 
  
	return 0; 
} 
  
// This is code is contributed by rathbhupendra

#include<bits/stdc++.h>
using namespace std; 
  
class Node {
public:
		int data;
		Node(int d){
			data = d;
		}
		Node *ptr;
};
  
// Function to check if the linked list 
// is palindrome or not 
bool isPalin(Node* head){
		  
		// Temp pointer 
		Node* slow= head;
  
		// Declare a stack 
		stack <int> s;
   
  
		// Push all elements of the list 
		// to the stack 
		while(slow != NULL){
				s.push(slow->data);
  
				// Move ahead 
				slow = slow->ptr;
		}
  
		// Iterate in the list again and 
		// check by popping from the stack
		while(head != NULL ){
			  
			// Get the top most element 
			 int i=s.top();
  
			 // Pop the element 
			 s.pop();
  
			 // Check if data is not
			 // same as popped element 
			if(head -> data != i){
				return false;
			}
  
			// Move ahead 
		   head=head->ptr;
		}
  
return true;
}
  
// Driver Code 
int main(){
  
	// Addition of linked list 
	Node one =  Node(1);
	Node two = Node(2);
	Node three = Node(3);
	Node four = Node(2);
	Node five = Node(1);
  
	// Initialize the next pointer
	// of every current pointer 
	five.ptr = NULL;
	one.ptr = &two;
	two.ptr = &three;
	three.ptr = &four;
	four.ptr = &five;
	Node* temp = &one;
  
	  
	// Call function to check palindrome or not 
	int result = isPalin(&one);
	
	if(result == 1)
			cout<<"isPalindrome is true\n";
	else
		cout<<"isPalindrome is true\n";
  
return 0;
}
  
// This code has been contributed by Striver 

// C++ program to reverse alternate
// k nodes in a linked list
#include <bits/stdc++.h>
using namespace std;
  
/* Link list node */
class Node 
{ 
	public:
	int data; 
	Node* next; 
}; 
  
/* Reverses alternate k nodes and 
returns the pointer to the new head node */
Node *kAltReverse(Node *head, int k) 
{ 
	Node* current = head; 
	Node* next; 
	Node* prev = NULL; 
	int count = 0; 
  
	/*1) reverse first k nodes of the linked list */
	while (current != NULL && count < k) 
	{ 
	next = current->next; 
	current->next = prev; 
	prev = current; 
	current = next; 
	count++; 
	} 
	  
	/* 2) Now head points to the kth node. 
	So change next  of head to (k+1)th node*/
	if(head != NULL) 
	head->next = current; 
  
	/* 3) We do not want to reverse next k 
	   nodes. So move the current 
		pointer to skip next k nodes */
	count = 0; 
	while(count < k-1 && current != NULL ) 
	{ 
	current = current->next; 
	count++; 
	} 
  
	/* 4) Recursively call for the list 
	starting from current->next. And make
	rest of the list as next of first node */
	if(current != NULL) 
	current->next = kAltReverse(current->next, k); 
  
	/* 5) prev is new head of the input list */
	return prev; 
} 
  
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node();
  
	/* put in the data */
	new_node->data = new_data; 
  
	/* link the old list off the new node */
	new_node->next = (*head_ref);	 
  
	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 
  
/* Function to print linked list */
void printList(Node *node) 
{ 
	int count = 0; 
	while(node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
		count++; 
	} 
} 
  
/* Driver code*/
int main(void) 
{ 
	/* Start with the empty list */
	Node* head = NULL; 
	int i; 
	  
	// create a list 1->2->3->4->5...... ->20 
	for(i = 20; i > 0; i--) 
	push(&head, i); 
  
	cout<<"Given linked list \n"; 
	printList(head); 
	head = kAltReverse(head, 3); 
  
	cout<<"\n Modified Linked list \n"; 
	printList(head); 
	return(0); 
} 
  
  
// This code is contributed by rathbhupendra

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  
// A linked list Node
struct Node 
{
	int data;
	struct Node* next;
};
  
// Function to delete the last occurrence
void deleteLast(struct Node** head, int x)
{
	struct Node** tmp1 = NULL;
	while (*head)
	{
			if ((*head)->data == x) 
			{
				tmp1 = head;
			}
			head = &(*head)->next;
	}
	if (tmp1)
	{
		struct Node* tmp = *tmp1;
		*tmp1 = tmp->next;
		free(tmp);
	}
}
  
// Utility function to create a new node with
// given key 
struct Node* newNode(int x)
{
	Node* node = new Node;
	node->data = x;
	node->next = NULL;
	return node;
}

// This function prints contents of linked
// list starting from the given Node
void display(struct Node* head)
{
	struct Node* temp = head;
	if (head == NULL)
	{
		cout << "NULL\n";
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data <<" --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

// Driver code
int main()
{
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(4);
	head->next->next->next->next->next->next = newNode(4);
	  
	cout << "Created Linked list: ";
	display(head);
	  
	// Pass the address of the head pointer
	deleteLast(&head, 4);   
	cout << "List after deletion of 4: ";
	  
	display(head);
	  
	return 0;
}
  
// This code is contributed by khushboogoyal499


// C++ program to rotate
// a linked list counter clock wise
  
#include <bits/stdc++.h>
using namespace std;
  
/* Link list node */
class Node {
public:
	int data;
	Node* next;
};
  
// This function rotates a linked list
// counter-clockwise and updates the
// head. The function assumes that k is
// smaller than size of linked list.
// It doesn't modify the list if
// k is greater than or equal to size
void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;
  
	// Let us understand the below
	// code for example k = 4 and
	// list = 10->20->30->40->50->60.
	Node* current = *head_ref;
  
	// current will either point to
	// kth or NULL after this loop.
	// current will point to node
	// 40 in the above example
	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}
  
	// If current is NULL, k is greater than
	// or equal to count of nodes in linked list.
	// Don't change the list in this case
	if (current == NULL)
		return;
  
	// current points to kth node.
	// Store it in a variable. kthNode
	// points to node 40 in the above example
	Node* kthNode = current;
  
	// current will point to
	// last node after this loop
	// current will point to
	// node 60 in the above example
	while (current->next != NULL)
		current = current->next;
  
	// Change next of last node to previous head
	// Next of 60 is now changed to node 10
	current->next = *head_ref;
  
	// Change head to (k+1)th node
	// head is now changed to node 50
	*head_ref = kthNode->next;
  
	// change next of kth node to NULL
	// next of 40 is now NULL
	kthNode->next = NULL;
}
  
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();
  
	/* put in the data */
	new_node->data = new_data;
  
	/* link the old list off the new node */
	new_node->next = (*head_ref);
  
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
  
/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}
  
/* Driver code*/
int main(void)
{
	/* Start with the empty list */
	Node* head = NULL;
  
	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);
  
	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);
  
	cout << "\nRotated Linked list \n";
	printList(head);
  
	return (0);
}
  
// This code is contributed by rathbhupendra


// C++ program to delete N nodes
// after M nodes of a linked list 
#include <bits/stdc++.h>
using namespace std;

// A linked list node 
class Node 
{
	public:
	int data;
	Node *next;
};

/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
} 
  
/* Function to print linked list */
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
} 
  
// Function to skip M nodes and then
// delete N nodes of the linked list. 
void skipMdeleteN(Node *head, int M, int N) 
{ 
	Node *curr = head, *t; 
	int count; 
  
	// The main loop that traverses
	// through the whole list 
	while (curr) 
	{ 
		// Skip M nodes 
		for (count = 1; count < M && 
				curr!= NULL; count++) 
			curr = curr->next; 
  
		// If we reached end of list, then return 
		if (curr == NULL) 
			return; 
  
		// Start from next node and delete N nodes 
		t = curr->next; 
		for (count = 1; count<=N && t!= NULL; count++) 
		{ 
			Node *temp = t; 
			t = t->next; 
			free(temp); 
		} 
		  
		// Link the previous list with remaining nodes 
		curr->next = t; 
  
		// Set current pointer for next iteration 
		curr = t; 
	} 
} 
  
// Driver code 
int main() 
{ 
	/* Create following linked list 
	1->2->3->4->5->6->7->8->9->10 */
	Node* head = NULL; 
	int M=2, N=3; 
	push(&head, 10); 
	push(&head, 9); 
	push(&head, 8); 
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 
  
	cout << "M = " << M<< " N = " << N << "\nGiven Linked list is :\n"; 
	printList(head); 
  
	skipMdeleteN(head, M, N); 
  
	cout<<"\nLinked list after deletion is :\n"; 
	printList(head); 
  
	return 0; 
} 
  
// This code is contributed by rathbhupendra

// C++ program to merge a linked list into another at 
// alternate positions 
#include <bits/stdc++.h>
using namespace std;
  
// A nexted list node 
class Node 
{ 
	public:
	int data; 
	Node *next; 
}; 
  
/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data) 
{ 
	Node* new_node = new Node();
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 
  
/* Utility function to print a singly linked list */
void printList(Node *head) 
{ 
	Node *temp = head; 
	while (temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
	cout<<endl;
} 
  
// Main function that inserts nodes of linked list q into p at 
// alternate positions. Since head of first list never changes 
// and head of second list may change, we need single pointer 
// for first list and double pointer for second list. 
void merge(Node *p, Node **q) 
{ 
	Node *p_curr = p, *q_curr = *q; 
	Node *p_next, *q_next; 
  
	// While there are available positions in p 
	while (p_curr != NULL && q_curr != NULL) 
	{ 
		// Save next pointers 
		p_next = p_curr->next; 
		q_next = q_curr->next; 
  
		// Make q_curr as next of p_curr 
		q_curr->next = p_next; // Change next pointer of q_curr 
		p_curr->next = q_curr; // Change next pointer of p_curr 
  
		// Update current pointers for next iteration 
		p_curr = p_next; 
		q_curr = q_next; 
	} 
  
	*q = q_curr; // Update head pointer of second list 
} 
  
// Driver code 
int main() 
{ 
	Node *p = NULL, *q = NULL; 
	push(&p, 3); 
	push(&p, 2); 
	push(&p, 1); 
	cout<<"First Linked List:\n"; 
	printList(p); 
  
	push(&q, 8); 
	push(&q, 7); 
	push(&q, 6); 
	push(&q, 5); 
	push(&q, 4); 
	cout<<"Second Linked List:\n"; 
	printList(q); 
  
	merge(p, &q); 
  
	cout<<"Modified First Linked List:\n"; 
	printList(p); 
  
	cout<<"Modified Second Linked List:\n"; 
	printList(q); 
  
	return 0; 
} 
  
// This code is contributed by rathbhupendra

// C++ program to delete a linked list
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
	int data;
	Node* next;
};
 
/* Function to delete the entire linked list */
void deleteList(Node** head_ref)
{
 
	/* deref head_ref to get the real head */
	Node* current = *head_ref;
	Node* next = NULL;
 
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
 
	/* deref head_ref to affect the real head back
		in the caller. */
	*head_ref = NULL;
}
 
/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();
 
	/* put in the data */
	new_node->data = new_data;
 
	/* link the old list off the new node */
	new_node->next = (*head_ref);
 
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
 
/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;
 
	/* Use push() to construct below list
	1->12->1->4->1 */
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);
 
	cout << "Deleting linked list";
	deleteList(&head);
 
	cout << "\nLinked list deleted";
}
 
// This is code is contributed by rathbhupendra

// Iterative C++ program to reverse a linked list
#include <iostream>
using namespace std;
 
/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
 
struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }
 
	/* Function to reverse the linked list */
	void reverse()
	{
		// Initialize current, previous and next pointers
		Node* current = head;
		Node *prev = NULL, *next = NULL;
 
		while (current != NULL) {
			// Store next
			next = current->next;
			// Reverse current node's pointer
			current->next = prev;
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
	}
 
	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
 
	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};
 
/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);
	
	cout << "Given linked list\n";
	ll.print();
 
	ll.reverse();
 
	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

// OA Uber And SIG Puzzles Round Semi Public

long long solution(vector<string> queryType, vector<vector<int>> query) {
	long long keyOffset = 0, valueOffset = 0, answer = 0;
	unordered_map<long long, long long> amap;
	for(int a = 0; a < int(queryType.size()); a++){
		if(queryType[a][0] == 'i') amap.insert({query[a][0] - keyOffset , query[a][1] - valueOffset});
		else if(queryType[a][0] == 'g') answer += amap[query[a][0] - keyOffset] + valueOffset;
		else if(queryType[a][5] == 'K') keyOffset += query[a][0];
		else valueOffset += query[a][0];
	}
	return answer;
}

// Supposedly asked by Hudson River Trading recently.

class Solution {
public:
    vector<int> addBinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = (carry >> 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> addNegabinary(vector<int>& a1, vector<int>& a2) {
		vector<int> res;
		int bit = 0, carry = 0, sz = max(a1.size(), a2.size());
		for (auto bit = 0; bit < sz || carry != 0; ++bit) {
			auto b1 = bit < a1.size() ? a1[a1.size() - bit - 1] : 0;
			auto b2 = bit < a2.size() ? a2[a2.size() - bit - 1] : 0;
			auto sum = b1 + b2 + carry;
			res.push_back(abs(sum) % 2); 
			carry = sum < 0 ? 1 : sum > 1 ? -1 : 0;
		}
		while (res.size() > 1 && res.back() == 0) res.pop_back();
		reverse(begin(res), end(res));
		return res;
	}
};

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        
    }
};

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
       if (arr1.size() > arr2.size()) swap(arr1,arr2);
        arr2.insert(arr2.begin(), 3, 0);
        for (int i = arr1.size()-1, j = arr2.size()-1; j>=0; i--, j--) {
            if (i>=0) arr2[j]+=arr1[i];
            if (arr2[j] == -1) {
                arr2[j] = 1;
                arr2[j-1]++;
            } else if (arr2[j] == 2) {
                arr2[j] = 0;
                arr2[j-1]--;
            } else if (arr2[j] == 3) {
                arr2[j] = 1;
                arr2[j-1]--;
            }
        }
        while (arr2.front() == 0 && arr2.size()>1) arr2.erase(arr2.begin());
        return arr2;
    }
};

//----------

// Task 1 Map Shwoop Again Redux Unsaved

/* I was given this task roughly 1 year ago in a SIG puzzles round so... last
time I opted to use the Python programming language I think this time I do it
in C++. Again use a pair of offset variables and an underlying map in
the native Standard Template Library implementation works very well. Unclear
what any expectation on processing frequency or optimal order is. map should be faster than unordered_map hash map for the given input limits and constraints. */

long long solution(vector<string> queryType, vector<vector<int>> query) {
	long long keyOffset = 0, valueOffset = 0, answer = 0;
	map<long long, long long> amap;
	for(int a = 0; a < int(queryType.size()); a++){
		if(queryType[a][0] == 'i') amap.insert({query[a][0] - keyOffset , query[a][1] - valueOffset});
		else if(queryType[a][0] == 'g') answer += amap[query[a][0] - keyOffset] + valueOffset;
		else if(queryType[a][5] == 'K') keyOffset += query[a][0];
		else valueOffset += query[a][0];
	}
	return answer;
}

// Task 2 Sudoku Again

bool solution(vector<vector<int>> grid) {
	/* Right off the bat it ought to be noted that we are targeting optimal
	performance here and so we want to be pruning As Soon As Possible
	rejecting non solutions immediately as quickly as we can infer them. The
	task statement does not specify a Probability Mass Function over the
	entire space of possible input Sudoku grids. The most obvious naive kind
	of solution works pretty well that is we process through rows and columns
	first local memory here it is optimal to do rows first and then simply
	naturally execute the columns lookups. And then finally write up a 3 x 3
	for for loop with an internal for for loop for each of the sub grids and
	that is that check it out and done ought to work quite well from an
	algorithms design stand point. The optimal way to do this is check if a
	set of size 9 contains each of the digits 1 through 9 once perhaps the
	fastest way is to simply note Binary Representation uniqueness and then
	just take an int and add the powers of 2 and check if and only if the sum
	is 1022. Rejected last time so I tried a different approach this time. Can try a bitset or vector of booleans instead rather than sum. */
	for(int a = 0; a < 9; a++){
		// Check row a.
		int sum = 0;
		for(int b = 0; b < 9; b++){
			if(!(sum & (1 << grid[a][b]))) sum += 1 << grid[a][b];
			else return false;
		}
	}
	for(int a = 0; a < 9; a++){
		// Check column a.
		int sum = 0;
		for(int b = 0; b < 9; b++){
			if(!(sum & (1 << grid[b][a]))) sum += 1 << grid[b][a];
			else return false;
		}
	}
	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			// Check sub grid a b.
			int sum = 0;
			int e = 3 * a + 3;
			int f = 3 * b + 3;
			for(int c = 3 * a; c < e ; c++){
				for(int d = 3 * b; d < f ; d++){
					if(!(sum & (1 << grid[c][d]))) sum += 1 << grid[c][d];
					else return false;
				}
			}
		}
	}
	return true;
}

//----------

