L cost[3001][3001];
L prefix[3001];
L prefixinc[3001];
L prefixdec[3001];
VL dpbefore;
VL dpcurrent;
 
Z compute(I left,I right,I leftoptimal,I rightoptimal){
	I a,mid,optimal;
	PL best;
	if(left>right)return;
	mid=(left+right)/2;
	best={LLONG_MAX,-1};
	for(a=leftoptimal;a<=min(mid,rightoptimal);a++){
		best=min(best,{(a?dpbefore[a-1]:0)+cost[a][mid],a});
	}
	dpcurrent[mid]=best.first;
	optimal=best.second;
	compute(left,mid-1,leftoptimal,optimal);
	compute(mid+1,right,optimal,rightoptimal);
}