#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using OSET=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//----------

	in>>a>>e;
	OSET<P> aosetp;
	aosetp.insert({1000000001,-1});
	for(b=0;b<a;b++){
		in>>c;
		av.add(c);
		aosetp.insert({c,b});
	}
	for(b=a;b<a+e;b++){
		in>>ac;
		if(ac=='!'){
			in>>c;
			c--;
			in>>d;
			aosetp.erase(aosetp.lower_bound({av[c],0}));
			aosetp.insert({d,b});
			av[c]=d;
		}
		else{
			in>>c>>d;
			out<<aosetp.orderofkey(*aosetp.lower_bound({d+1,0}))-aosetp.orderofkey(*aosetp.lower_bound({c,0}))<<nl;
		}
	}

//----------

	auto aa=aoset.find_by_order(c);
	out<<*aa<<" ";
	aoset.erase(aa);