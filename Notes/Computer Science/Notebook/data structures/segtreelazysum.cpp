I segsize, numqueries, lo[800000], hi[800000];
L x, del[800000], ass[800000], sum[800000];
I len(I i){
    return hi[i]-lo[i]+1;
}
Z increment(I i, L v){
    del[i] += v;
    sum[i] += len(i) * v;
}
Z assign(I i, L v){
    ass[i] = v;
    del[i] = 0;
    sum[i] = len(i) * v;
}
Z push(I i){
    if(ass[i]){
        assign(2*i, ass[i]);
        assign(2*i+1, ass[i]);
        ass[i] = 0;
    }
    if(del[i]){
        increment(2*i, del[i]);
        increment(2*i+1, del[i]);
        del[i] = 0;
    }
}
Z pull(I i){
    sum[i] = sum[2*i] + sum[2*i+1];
}
Z build(I i, I l, I r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        L al;
        in>>al;
        sum[i]=al;
        return;
    }
    I m = l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    pull(i);
}
Z increment(I i, I l, I r, L v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        increment(i, v); return;
    }
    push(i);
    increment(2*i, l, r, v);
    increment(2*i+1, l, r, v);
    pull(i);
}
Z assign(I i, I l, I r, L v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        assign(i, v); return;
    }
    push(i);
    assign(2*i, l, r, v);
    assign(2*i+1, l, r, v);
    pull(i);
}
L query(I i, I l, I r){
    if(l > hi[i] || r < lo[i])  return 0;
    if(l <= lo[i] && hi[i] <= r){
        return sum[i];
    }
    push(i);
    L lsum = query(2*i, l, r);
    L rsum = query(2*i+1, l, r);
    pull(i);
    return lsum + rsum;
}