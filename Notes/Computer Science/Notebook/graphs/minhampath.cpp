L graph2[20][20]; // Adjacency Matrix
L minhampath(I a){// Number of vertices in original graph, source can be freely set to be auxiliary a and then loop in to enter in costs of 0 or 1 from that auxiliary imaginary source to all of the other vertices in the original graph.
    L subminpath[(1<<(a))][a];
    L min=LONG_MAX;
    for(I d=0;d<=a-1;d++){
        subminpath[1<<d][d]=graph2[a][d];
    }
    for(I c=2;c<=a;c++){
        for(I d=0;d<(1<<(a));d++){
            if(subsetsize(d)==c){
                for(I e=0;e<=a-1;e++){
                    if((d ba (1<<e))!=0){
                        min=LONG_MAX;
                        for(I f=0;f<=a-1;f++){
                            if(((d bx (1<<e)) ba (1<<f)) !=0){
                                if(subminpath[(d bx (1<<e))][f]+graph2[f][e]<min){
                                    min=subminpath[(d bx (1<<e))][f]+graph2[f][e];
                                }
                            }
                        }
                        subminpath[d][e]=min;
                    }
                }
            }
        }
    }
    min=LONG_MAX;
    for(I d=0;d<=a-1;d++){
        if(subminpath[(1<<(a))-1][d]<min){
            min=subminpath[(1<<(a))-1][d];
        }
    }
    return min;
}

//----------

L graph2[20][20]; // adjacency matrix
L minhampath(I a){//number in graph, source is a-1 if no source add 0 source
    L subminpath[(1<<(a-1))][a-1];
    L min=LONG_MAX;
    for(I d=0;d<=a-2;d++){
        subminpath[1<<d][d]=graph2[a-1][d];
    }
    for(I c=2;c<=a-1;c++){
        for(I d=0;d<(1<<(a-1));d++){
            if(subsetsize(d)==c){
                for(I e=0;e<=a-2;e++){
                    if((d ba (1<<e))!=0){
                        min=LONG_MAX;
                        for(I f=0;f<=a-2;f++){
                            if(((d bx (1<<e)) ba (1<<f)) !=0){
                                if(subminpath[(d bx (1<<e))][f]+graph2[f][e]<min){
                                    min=subminpath[(d bx (1<<e))][f]+graph2[f][e];
                                }
                            }
                        }
                        subminpath[d][e]=min;
                    }
                }
            }
        }
    }
    min=LONG_MAX;
    for(I d=0;d<=a-2;d++){
        if(subminpath[(1<<(a-1))-1][d]<min){
            min=subminpath[(1<<(a-1))-1][d];
        }
    }
    return min;
}