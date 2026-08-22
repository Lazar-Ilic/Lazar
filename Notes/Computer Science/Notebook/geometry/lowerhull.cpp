#include <bits/stdc++.h>
using namespace std;

using point = pair<long double, long double>;
using points = vector<point>;

long double cross(point o, point a, point b) {
	return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

points lower_hull(points p) {
	int n = p.size(), k = 0;
	sort(p.begin(), p.end());
	vector<point> res(n);
	for(int i = 0; i < n; i++) {
		while(k >= 2 and cross(res[k - 2], res[k - 1], p[i]) <= 0) k--;
		res[k++] = p[i];
	}
	res.resize(k);
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << fixed << setprecision(10);
	points p(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		int c;
		cin >> c;
		p[i].first /= c, p[i].second /= c;
	}
	sort(p.begin(), p.end());
	//下側凸包を作る
	points lh = lower_hull(p);
	n = lh.size();
	if(n == 1) {
		cout << 1 / max(lh[0].first, lh[0].second) << endl;
		return 0;
	}
	long double mx = 1ll << 60;
	for(int i = 0; i < n - 1; i++) {
		auto [lx, ly] = lh[i];
		auto [rx, ry] = lh[i + 1];
		if(ly <= ry) {
			mx = min(mx, max(lx, ly));
			continue;
		}
		if(rx <= ry) {
			mx = min(mx, ry);
			continue;
		}
		if(lx >= ly) {
			mx = min(mx, lx);
			continue;
		}
		auto lef_diff = ly - lx;
		auto rig_diff = ry - rx;
		assert(lef_diff >= 0 and rig_diff <= 0);
		auto md = lx + (rx - lx) * lef_diff / (lef_diff + abs(rig_diff));
		mx = min(mx, md);
	}
	cout << 1 / mx << endl;
}