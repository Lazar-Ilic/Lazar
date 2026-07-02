// Description: Add and remove intervals from a set of disjoint intervals. Will merge the added interval with any overlapping intervals in the set when adding. Intervals are [inclusive, exclusive).
// Time: O(log N)
SETP::iterator addinterval(SETP& is,I left,I right){//Simon Lindholm
	if (left == right) return is.end();
	auto it = is.lower_bound({left, right}), before = it;
	while (it != is.end() && it->first <= right) {
		right = max(right, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= left){
		left = min(left, it->first);
		right = max(right, it->second);
		is.erase(it);
	}
	return is.insert(before,{left,right});
}

Z removeinterval(SETP& is,I left,I right){
	if (left == right) return;
	auto it = addinterval(is, left, right);
	auto r2 = it->second;
	if (it->first == left) is.erase(it);
	else (I&)it->second = left;
	if (right != r2) is.emplace(right, r2);
}