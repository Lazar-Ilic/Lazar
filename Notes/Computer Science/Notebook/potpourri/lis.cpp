// Description: Compute indices for the longest increasing subsequence.
// Time: O(N log N)
V lis(const V& z){//Johan Sannemo
	if(z.empty())return {};
	V prev(sz(z));
	VP res;
	rep(i,0,sz(z)){
		// change 0 -> i for longest non-decreasing subsequence
		auto it=lower_bound(all(res),P{z[i],0});
		if(it==res.end())res.emplace_back(),it=res.end()-1;
		*it={z[i],i};
		prev[i]=it==res.begin()?0:(it-1)->second;
	}
	I l=sz(res),cur=res.back().second;
	V ans(l);
	while(l--)ans[l]=cur,cur=prev[cur];
	return ans;
}