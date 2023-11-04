template <typename T>
class fenwick{
	public:
		vector<T> fenw;
		int n;
		fenwick(int _n):n(_n){
			fenw.resize(n);
		}
		void update(int x,T v){
			while(x<n){
				fenw[x]+=v;
				x|=(x+1);
			}
		}
		T query(int x){
			T v{};
			while(x>=0){
				v+=fenw[x];
				x=(x&(x+1))-1;
			}
			return v;
		}
};
struct node{
	int a=0;
	inline void operator+=(node &other){ // Can do associative operations like prefix sums as well as prefix maxima etc.
		a=max(a,other.a);
	}
};