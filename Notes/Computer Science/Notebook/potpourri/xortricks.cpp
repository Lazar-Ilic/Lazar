// https://codeforces.com/blog/entry/68953

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
const int MAX_A = 70;
const int TOTAL_PRIMES = 19;
const int MOD = 1e9 + 7;

int n;
int poss[MAX_A + 1][2];
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int mask[MAX_A + 1];
int dp[MAX_A + 1][1 << TOTAL_PRIMES];

int main() {
	cin >> n;
	for (int i = 1; i <= MAX_A; i++) poss[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		int tmp = poss[a][0];
		poss[a][0] = (poss[a][0] + poss[a][1]) % MOD;
		poss[a][1] = (poss[a][1] + tmp) % MOD;
	}
	for (int i = 1; i <= MAX_A; i++) {
		for (int p = 0; p < TOTAL_PRIMES; p++) {
			int cnt = 0;
			int at = i;
			while (at % primes[p] == 0) {
				at /= primes[p];
				cnt++;
			}
			if (cnt & 1) mask[i] |= (1 << p);
		}
	}
	int max_mask = 1 << TOTAL_PRIMES;
	dp[0][0] = 1;
	for (int at = 1; at <= MAX_A; at++)
		for (int msk = 0; msk < max_mask; msk++) {
			dp[at][msk] = dp[at - 1][msk] * 1LL * poss[at][0] % MOD;
			dp[at][msk] += dp[at - 1][msk ^ mask[at]] * 1LL * poss[at][1] % MOD;
			dp[at][msk] %= MOD;
		}
	cout << (dp[MAX_A][0] + MOD - 1) % MOD << endl;
	return 0;
}

// Vector Basis

int basis[d]; // basis[i] keeps the mask of the vector whose f value is i
int sz; // Current size of the basis
void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)
		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;		
			return;
		}
		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

// Number Of Distinct Integers That Can Be Represented As XOR From Set

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, LOG_A = 20;
int basis[LOG_A];
int sz;
void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			++sz;		
			return;
		}
		mask ^= basis[i];
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		scanf("%d", &a);
		insertVector(a);
	}
	cout << (1 << sz) << endl;
	return 0;
}

// Maximum Possible XOR Of Subset Of S

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, LOG_A = 20;
int basis[LOG_A];
void insertVector(int mask) {
	for (int i = LOG_A - 1; i >= 0; i--) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			return;
		}
		mask ^= basis[i];
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		scanf("%d", &a);
		insertVector(a);
	}
	int ans = 0;
	for (int i = LOG_A - 1; i >= 0; i--) {
		if (!basis[i]) continue;
		if (ans & 1 << i) continue;
		ans ^= basis[i];
	}
	cout << ans << endl;
	return 0;
}

// Queries Of Insertion Or kth Order Statistic On Set Of All Possible XORs Of Subsets

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, LOG_K = 30;
int basis[LOG_K], sz;
void insertVector(int mask) {
	for (int i = LOG_K - 1; i >= 0; i--) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			sz++;
			return;
		}
		mask ^= basis[i];
	}
}
 
int query(int k) {
	int mask = 0;
	int tot = 1 << sz;
	for (int i = LOG_K - 1; i >= 0; i--)
		if (basis[i]) {
			int low = tot / 2;
			if ((low < k && (mask & 1 << i) == 0) ||
				(low >= k && (mask & 1 << i) > 0)) mask ^= basis[i];
			if (low < k) k -= low;
			tot /= 2;
		}
	return mask;
}
 
int main() {
	int n;
	cin >> n;
	while (n--) {
		int t, k;
		scanf("%d %d", &t, &k);
		if (t == 1) insertVector(k);
		else printf("%d\n", query(k));
	}
	return 0;
}

// Queries Of Number Modulo p Of Subsequences Of Length l Prefix With Bitwise XOR Value Of X

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; 
#define x first
#define y second
const int N = 1e5 + 10;
const int LOG_A = 20;
const int MOD = 1e9 + 7;
int n;
int a[N];
int q;
ii q_data[N];
vector<int> q_at[N];
int powers[N];
int ans[N];
int base[LOG_A], sz;
bool checkXor(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
		if (!base[i]) return false;
		mask ^= base[i];
	}
	return true;
}

void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
		if (!base[i]) {
			base[i] = mask;
			sz++;
			return;
		}
		mask ^= base[i];
	}
}
 
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &q_data[i].x, &q_data[i].y);
		q_at[q_data[i].x].push_back(i);
	}
	powers[0] = 1;
	for (int i = 1; i < N; i++)
		powers[i] = powers[i - 1] * 2LL % MOD;
	for (int at = 1; at <= n; at++) {
		insertVector(a[at]);
		for (int at_q : q_at[at])
			if (checkXor(q_data[at_q].y)) {
				ans[at_q] = powers[at - sz];
			}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}

// Educational Task About Segment Partitioning Into Maximal Number Of Segments So No Subset Of Segments Has A Bitwise XOR Value Of 0

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, LOG_PREF = 31;
int n;
int basis[LOG_PREF];
void insertVector(int mask) {
	for (int i = 0; i < LOG_PREF; i++) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			return;
		}
		mask ^= basis[i];
	}
}
 
int main() {
	cin >> n;
	int pref = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		pref ^= a;
		insertVector(pref);
	}
	if (pref == 0) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < LOG_PREF; i++) {
		ans += (basis[i] > 0);
	}
	cout << ans << endl;
	return 0;
}