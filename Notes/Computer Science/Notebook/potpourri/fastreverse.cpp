template <typename T>
Z fastreverse(T first,T last){
	if((first==last)||next(first)==last)return;
	T middle=first;
	advance(middle,distance(first,last)/2);
	fastreverse(first,middle);
	fastreverse(middle,last);
	rotate(first,middle,last);
}