// The glory is for GOD

#include <bits/stdc++.h>

#define DB(a) cerr << __LINE__ << ": " << #a << " = " << (a) << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
	NOTES:
		Implementations marked as (?) are not verified
*/

/*
	INDEX
		1. Util functions	
		
		2. Prime numbers
*/

/*
	NOTES
		1. Let f[x] be the smallest prime divisor of x, and inv[x] the inverse of x, then 
			inv[x] =(inv[x / f[x]] * inv[f[x]]) % mod. (x is non prime)
			
		2. Inverse element:
			p % i = p - (p / i) * i
			p % i = -(p / i) * i (mod p) // divide by i * (p % i)
			inv[i] = - (p / i) * inv[p % i]
*/

namespace number_theory
{
	const int MAXN = 10000000;   	//maximum value of N
	
	/*	1. Util functions	*/	
	
	//Returns (a * b) % m (?)
	ull mmul (ull a, ull b, ull m)
	{
		ull dev = 0;
		
		for (ull tmp = a % m; b; b >>= 1)
		{
			if (b & 1)
			{
				if ((dev += tmp) >= m)
					dev -= m;
			}
			
			if ((tmp <<= 1) >= m)
				tmp -= m;
		}
		
		return dev;
	}
	
	//Returns a ^ b
	ll bpow (ll a, ll b)
	{
		ll ans = 1;
		
		for (; b; b >>= 1)
		{
			if (b & 1)
				ans *= a;
				
			a *= a;
		}
		
		return ans;
	}
	
	//Returns (a ^ b) % m
	ull mpow (ull a, ull b, ull m)
	{
		ll ans = 1;
		
		for (; b; b >>= 1)
		{
			if (b & 1)
				ans = mmul(ans, a, m);
				
			a = mmul(a, a, m);
		}
		
		return ans;
	}
	
	//Returns the least common multiple of a and b (least positive integer n such that a|n and b|n)
	ll lcm (ll a, ll b)
	{
		return a * b / __gcd(a, b);
	}
	
	//Returns the greatest integer number d such that d|a and d|b. Also gets the values of x and y such that:
	//a * x + b * y = d (?)
	ll ext_gcd (ll a, ll b, ll &x, ll &y)
	{
		ll g = a; x = 1, y = 0;
		
		if (b != 0)
		{
			g = ext_gcd(b, a % b, y, x);
			y -= (a / b) * x;
		}
		
		return g;
	}
	
	ll inv_mod (ll a, ll m)
	{
		ll x, y;
		
		if (ext_gcd(a, m, x, y) != 1)
			return 0;	//the inverse does not exist
			
		return (x + m) % m;
	}
	
	ll inv_mod2 (ll a, ll p)
	{
		static int first = true, inv[MAXN];
		
		if (first)
		{
			first = false;
			
			inv[1] = 1;
		
			for (int i= 2; i < p; ++i)
				inv[i] = (p - (p / i) * inv[p % i] % p) % p;
		}	
		
		return inv[a];	
	}
	
	/*	2. Prime numbers	*/
	
	//Euler phi. Returns the amount of number 'a' in [1...n] such that gcd(n, a) == 1
	ll phi (ll n)
	{
		ll ans = n;
		
		for (int i = 2; i * 1ll * i <= n; ++i)
		{
			if (n % i == 0)
			{
				for (; n % i == 0; n /= i);
				
				ans -= ans / i;
			}
		}
		
		if (n > 1)
			ans -= ans / n;
			
		return ans;
	}
	
	ll phi2 (ll n)
	{
		static int first = true, p[MAXN], f[MAXN];
		
		if (first)
		{
			first = false;
			
			for (int i = 0; i < MAXN; ++i)
				p[i] = 1, f[i] = i;
				
			for (int i = 2; i < MAXN; ++i)
			{
				if (p[i])
				{
					f[i] -= f[i] / i;
					
					for (int j = i + i; j < MAXN; j += i)
						p[j] = false, f[j] -= f[j] / i;
				}
			}
		}
		
		return f[n];
	}
	
	//Miller-Rabin (primality test)
	bool suspect (ll a, int s, ll d, ll n)
	{
		ll x = mpow (a, d, n);
	
		if (x == 1)
			return true;
	
		for (int r = 0; r < s; ++r)
		{
			if (x == n - 1)
				return true;
				
			x = x * x % n;
		}
		
		return false;
	}
	
	// {2, 7, 61, -1} is for n < 4759123141 (= 2 ^ 32)
	// {2, 3, 5, 7, 11, 13, 17, 19, 23, -1} is for n < 10 ^ 16 (at least)	
	bool is_prime (ll n)  // check overflow in mpow!!!
	{
		if (n < 2 || (n > 2 && (n & 1) == 0))
			return false;
	
		int test [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, - 1};
		ll d = n - 1, s = 0;
		
		for (; (d & 1) == 0; d >>= 1)
		    ++s;
		    
		for (int i = 0; test[i] < n && test[i] != -1; ++i)
		{
			if (!suspect(test[i], s, d, n))
				return false;
		}
		
		return true;
	}
	
	//Sieve of Eratosthenes 1 (O(nloglogn))
	const int 	P1 = (MAXN + 63) / 64,  //ceil(MAXN / 64)
				P2 = (MAXN + 1) / 2,    //ceil(MAXN / 2)
				P3 = 5000;              //ceil(ceil(sqrt(MAXN)) / 2)

	int sieve[P1];
	
	#define GET(b) ((sieve[(b) >> 5] >> ((b) & 31)) & 1)
	
	void make ()
	{
		for (int k = 1; k <= P3; ++k)
		{
			if (GET(k) == 0)
			{
				for (int i = 2 * k * (k + 1), j = 2 * k + 1; i < P2; i += j)
				    sieve[i >> 5] |= 1 << (i & 31);
			}
		}
	}
	
	inline int is_prime (int p)
	{
		return p == 2 || (p > 2 && (p & 1) == 1 && (GET(p >> 1) == 0));
	}
	
	//Sieve of Eratosthenes 2 (O(n))
	int primes[MAXN], primes_n, min_fact[MAXN];

	//The number of primes below 10^8 is 5761455
	void make2 ()
	{
		memset(min_fact, -1, sizeof min_fact);
		
		for (int i = 2, tmp; i < MAXN; ++i)
		{
			if (min_fact[i] == -1)
			{
				min_fact[i] = primes_n;
				primes[primes_n++] = i;
			}
			
			for (int j = 0; j <= min_fact[i] && i * primes[j] < MAXN; ++j)				
				min_fact[i * primes[j]] = j;
		}
	}	
	
	//Returns the n-th gray code
	int gray (int n) 
	{
		return n ^ (n >> 1);
	}
	
	//Gets the number n such that g is the n-th gray code
	int reverse_gray (int g) 
	{
		int n = 0;
		
		for (; g; g>>=1)
			n ^= g;
			
		return n;
	}
	
	struct bignum
	{
		static const int MAXD = 100; //Can store up to D * MAXD digits
		static const int B = 1e9;
		static const int D = 9;

		int size, digits[MAXD];
		
		bignum (int size = 0, int v = 0) : size(size)
		{
			memset(digits, 0, sizeof digits);
			digits[0] = v;
		}
		
		int & last()
		{
			return digits[size - 1];
		}
		
		void justify ()
		{
			for (; size > 1 && digits[size - 1] == 0; digits[size--] = 0);
		}
		
		void read (char *s)
		{
			size = 0;
			
			for (int i = strlen(s); i > 0; i -= D)
			{
				s[i] = 0;
				digits[size++] = atoi(i >= 9 ? s + i - 9 : s);
			}
			justify();
		}
	
		int & operator [] (int i)
		{
			return digits[i];
		}
		
		bool operator < (bignum & b)
		{
			if (size != b.size)
				return size < b.size;
				
			for (int i = size - 1; i >= 0; --i)
			{
				if (digits[i] != b[i])
				    return digits[i] < b[i];
			}
				
			return false;
		}
		
		bignum operator + (bignum & b)
		{
			bignum ans;
			
			for (int i = 0, l = max(size, b.size), c = 0; i < l || c; ++i)
			{
				ans[ans.size++] = c + digits[i] + b[i];
				c = ans.last() >= B;
				
				if (c)  ans.last() -= B;
			}
			return ans;
		}
		
		void operator += (bignum & b)
		{
			*this = *this + b;
		}
		
		bignum operator - (bignum & b)
		{
			bignum ans;
			
			for (int i = 0, c = 0; i < size; ++i)
			{
				ans[ans.size++] = digits[i] - c - b[i];
				c = ans.last() < 0;
				
				if (c)  ans.last() += B;
			}
			
			ans.justify();
			return ans;
		}
		
		void operator -= (bignum & b)
		{
			*this = *this - b;
		}
		
		bignum operator * (bignum & b)
		{
			bignum ans;
			ans.size = size + b.size;
			
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0, c = 0; j < b.size || c; ++j)
				{
					ll tmp = digits[i] * 1ll * b[j] + ans[i + j] + c;
					ans[i + j] = tmp % B;
					c = tmp / B;
				}
			}
			ans.justify();
			return ans;
		}
		
		void operator *= (bignum & b)
		{
			*this = *this * b;
		}
		
		bignum operator * (int b)
		{
			bignum ans;
			
			for (int i = 0, c = 0; i < size || c; ++i)
			{
				ll tmp = digits[i] * 1ll * b + c;
				ans[ans.size++] = tmp % B;
				c = tmp / B;
			}
			ans.justify();
			return ans;
		}
		
		void operator *= (int b)
		{
			*this = *this * b;
		}
		
		pair<bignum, int> div(int b)
		{
			int c = 0;
			bignum ans;
			
			for (int i = size - 1; i >= 0; --i)
			{
				ll tmp = digits[i] + c * 1ll * B;
				ans[ans.size++] = tmp / b;
				c = tmp % b;
			}
			
			ans.justify();
			return make_pair(ans, c);
		}
		
		bignum operator / (int b)
		{
			return div(b).first;
		}
		
		void operator /= (int b)
		{
			*this = *this / b;
		}
		
		int operator % (int b)
		{
			return div(b).second;
		}
		
		void operator %= (int b)
		{
			*this = bignum(1, div(b).second);
		}
		
		pair<bignum, bignum> div(bignum b)
		{
			if (size < b.size)
			    return make_pair(bignum(), *this);
			    
			bignum x = *this;
			int fact = B / (b.last() + 1);
			x *= fact;
			b *= fact;
			bignum ans(size - b.size + 1);
			
			for (int i = ans.size - 1, j = x.size - 1; i >= 0; --i, --j)
			{
				ll tmp = x[i + 1] * 1ll * B + x[i];
				tmp /= b.last();
				bignum aux(i + b.size + 1);
				
				for (int k = 0, c = 0; k < b.size || c; ++k)
				{
					ll t = tmp * b[k] + c;
					aux[i + k] = t % B;
					c = t / B;
				}
	
				aux.justify();
				
				for (aux.justify(); x < aux; --tmp, aux.justify())
				{
					for (int k = 0, c = 0; k < b.size || c; ++k)
					{
						aux[i + k] -= b[k];
						c = aux[i + k] < 0;
						
						if (c)  aux[i + k] += B;
					}
				}
				x -= aux;
				tmp += ans[i];
				ans[i] = tmp % B;
				bignum bn(1, tmp / B);
				//x += bn;
			}
	
			ans.justify();
			return make_pair(ans, x / fact);
		}
		
		bignum operator / (bignum & b)
		{
			return div(b).first;
		}
		
		void operator /= (bignum & b)
		{
			*this = *this / b;
		}
		
		bignum operator % (bignum & b)
		{
			return div(b).second;
		}
		
		void operator %= (bignum & b)
		{
			*this = *this % b;
		}
	};
	
	istream & operator >> (istream & in, bignum & b)
	{
		char s[bignum::MAXD * bignum::D];
		in >> s;
		b.read(s);
		return in;
	}
	
	ostream & operator << (ostream & out, bignum b)
	{
		out << (b.size ? b.last() : 0);
	
		for (int i = b.size - 2; i >= 0; --i)
			out << setw(bignum::D) << setfill('0') << b[i];
	
		return out;
	}
}//end namespace number_theory
