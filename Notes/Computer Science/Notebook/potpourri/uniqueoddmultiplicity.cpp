L uniqueodd(VL avl){
	if(sz(avl)==0)return -1;
	L al=avl[0];
	for(I a=1;a<sz(avl);a++)al=(al bx avl[a]);
	return al;
}