// Description: Computes partial sums a[0]+a[1]+...+a[pos-1], and updates single elements a[i], taking the difference between the old and new value
// Time: Both operations are O(log N)
STR BIT{//Lukas Polacek
	VL s;
	BIT(I n):s(n){}
	Z update(I pos,L dif){ // a[pos] += dif
		for(;pos<sz(s);pos|=pos+1)s[pos]+=dif;
	}
	L query(I pos){ // sum of values in [0, pos)
		L res=0;
		for(;pos>0;pos&=pos-1)res+=s[pos-1];
		return res;
	}
	I lowerbound(L sum){ // min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is
		if(sum<=0)return -1;
		I pos=0;
		for(I w=1<<25;w;w>>=1){
			if(pos+w<=sz(s) and s[pos+w-1]<sum)pos+=w,sum-=s[pos-1];
		}
		return pos;
	}
};