#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using OSET=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
L inversions(V av){
	OSET<P> aoset;I a;L al=0;
	for(a=0;a<sz(av);a++){
		aoset.insert({av[a],a});
		al+=sz(aoset)-1-aoset.orderofkey({av[a],a});
	}
	return al;
}