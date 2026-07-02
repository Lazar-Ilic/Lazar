VL rowmatrix(VL avl,VVL avvl){
    VL bvl(sz(avvl[0]));
    I a,b;
    for(a=0;a<sz(avvl[0]);a++){
        for(b=0;b<sz(avl);b++){
            bvl[a]=(bvl[a]+avl[b]*avvl[b][a])%p;
        }
    }
    return bvl;
}
VL matrixcolumn(VVL avvl,VL avl){
    VL bvl(sz(avvl));
    I a,b;
    for(a=0;a<sz(avvl);a++){
        for(b=0;b<sz(avl);b++){
            bvl[a]=(bvl[a]+avvl[a][b]*avl[b])%p;
        }
    }
    return bvl;
}
VVL matrixmatrix(VVL avvl,VVL bvvl){
    VVL cvvl(sz(avvl),VL(sz(bvvl[0])));
    I a,b,c;
    for(a=0;a<sz(avvl);a++){
        for(b=0;b<sz(bvvl[0]);b++){
            for(c=0;c<sz(bvvl);c++){
                cvvl[a][b]=(cvvl[a][b]+avvl[a][c]*bvvl[c][b])%p;
            }
        }
    }
    return cvvl;
}
VVL matrixexp(VVL avvl,L al){
	if(al==0){
    	VVL bvvl(sz(avvl),VL(sz(avvl)));
    	I b;
    	for(b=0;b<sz(avvl);b++){
        	bvvl[b][b]=1;
    	}
		return bvvl;
	}
    VVL bvvl=matrixexp(avvl,al/2);
	bvvl=matrixmatrix(bvvl,bvvl);
	if(al%2==1)bvvl=matrixmatrix(bvvl,avvl);
    return bvvl;
}
VD rowmatrixd(VD avd,VVD avvd){
    VD bvd(sz(avvd[0]));
    I a,b;
    for(a=0;a<sz(avvd[0]);a++){
        for(b=0;b<sz(avd);b++){
            bvd[a]=(bvd[a]+avd[b]*avvd[b][a]);
        }
    }
    return bvd;
}
VD matrixcolumnd(VVD avvd,VD avd){
    VD bvd(sz(avvd));
    I a,b;
    for(a=0;a<sz(avvd);a++){
        for(b=0;b<sz(avd);b++){
            bvd[a]=(bvd[a]+avvd[a][b]*avd[b]);
        }
    }
    return bvd;
}
VVD matrixmatrixd(VVD avvd,VVD bvvd){
    VVD cvvd(sz(avvd),VD(sz(bvvd[0])));
    I a,b,c;
    for(a=0;a<sz(avvd);a++){
        for(b=0;b<sz(bvvd[0]);b++){
            for(c=0;c<sz(bvvd);c++){
                cvvd[a][b]=(cvvd[a][b]+avvd[a][c]*bvvd[c][b]);
            }
        }
    }
    return cvvd;
}
VVD matrixexpd(VVD avvd,L al){
	if(al==0){
    	VVD bvvd(sz(avvd),VD(sz(avvd)));
    	I b;
    	for(b=0;b<sz(avvd);b++){
        	bvvd[b][b]=1;
    	}
		return bvvd;
	}
    VVD bvvd=matrixexpd(avvd,al/2);
	bvvd=matrixmatrixd(bvvd,bvvd);
	if(al%2==1)bvvd=matrixmatrixd(bvvd,avvd);
    return bvvd;
}
//VL rowmatrix(VL avl,VVL avvl)
//VL matrixcolumn(VVL avvl,VL avl)
//VVL matrixmatrix(VVL avvl,VVL bvvl)
//VVL matrixexp(VVL avvl,L al)
//VD rowmatrixd(VD avd,VVD avvd)
//VD matrixcolumnd(VVD avvd,VD avd)
//VVD matrixmatrixd(VVD avvd,VVD bvvd)
//VVD matrixexpd(VVD avvd,L al)