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
		1. Types and operators
		
		2. Util methods
		
		3. Intersections, rotations, projections and distances
		
		4. Special points
		
		5. Areas
		
		6. Convex polygon
		
		7. Rotating calipers
			POJ 2187 - Beauty Contest (farthest pair of points)
			UVA 1111 - Trash Removal (polygon width)
*/


/*
	NOTES:
		1. Angle formed by vector a with the x-axis
			angle = arg(a);		
*/

typedef complex<double> point;

namespace std
{
	bool operator <(const point &a, const point &b)
	{
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

namespace geometry
{	
	#define NEXT(i) (((i) + 1) % n)
	
	const double EPS = 1e-8;
	const double oo = 1e12;
	
	/*	1. Types and operators	*/
	int cmp (double a, double b = 0)
	{
    	if (fabs(a - b) < EPS) 
			return 0;
    	
    	return a - b > EPS ? 1 : -1;
	}	
	
	typedef vector<point> polygon;
	
	enum {OUT, ON, IN};
	
	struct line: public vector <point>
	{
		//Line determined by two points
		line (const point & a, const point & b)
		{
			push_back(a);
			push_back(b);
		}
		
		//Line determined by a point and an angle (?)
		line (point p, double angle)
	    {
			push_back(p);
			
	        if (cmp(angle, M_PI / 2) == 0)
				push_back(p + point(0, 1));	        
	        else 
				push_back(p + point(1, tan(angle)));
	    }   
		
		//Line in the form Ax + By + C = 0 (?)
	    line (double a, double b, double c)
	    {
			if (cmp(a) == 0)
			{
				push_back(point(0, -c / b));
				push_back(point(1, -c / b));
			}
			else if (cmp(b) == 0)
			{
				push_back(point(-c / a, 0));
				push_back(point(-c / a, 1));
			}
			else
			{
				push_back(point(0, -c / b));
				push_back(point(1, (-c - a) / b));
			}
	    }    
	    
	    double angle () //Line inclination angle 0 <= angle < 180 (?)
	    {
			point a = (*this)[0];
			point b = (*this)[1];
	        double k = atan2(b.imag() - a.imag(), b.real() - a.real());
	        
	        if (cmp(k) < 0)
				k += M_PI;
				
	        if (cmp(k, M_PI) == 0)
				k -= M_PI;
				
	        return k;
	    }
	};
		
	/*	2. Util methods	*/
	double dot (point a, point b)
	{
		return real(conj(a) * b);
	}
	
	double cross (point a, point b)
	{
		return imag(conj(a) * b);
	}
	
	int ccw (point a, point b, point c) //Turn of a -> b -> c
	{
		b -= a; c -= a;
		
		if (cross(b,c) > 0)
			return +1;  	//counter clockwise
			
		if (cross(b,c) < 0)
			return -1;  	//clockwise
			
		if (dot(b,c) < 0)
			return +2;    	//c - a - b line
			
		if (norm(b) < norm(c))
			return -2; 		//a - b - c line
			
		return 0;
	}
	
	/*	3. Intersections, rotations, projections and distances	*/
	
	bool intersectLL (line l, line m)
	{
		return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || //non-parallel
			   abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;   //same-line
	}
	
	bool intersectLS (line l, line s)
	{
		return cross(l[1] - l[0], s[0] - l[0]) * 		//s[0] is left of l
			   cross(l[1] - l[0], s[1] - l[0]) < EPS;  	//s[1] is right of l
	}
	
	bool intersectLP (line l, point p)
	{
		return abs(cross(l[1] - p, l[0]  -p)) < EPS;
	}
	
	bool intersectSS (line s, line t)
	{
		if (abs(s[0] - t[0]) < EPS || abs(s[0] - t[1]) < EPS || abs(s[1] - t[0]) < EPS || abs(s[1] - t[1]) < EPS)
			return 1;  // same point
			
		return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
			   ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
	}
	
	bool intersectSP (line s, point p)
	{
		return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
	}
	
	//Rotates point p about point 'about' by 'radians' angles (?)
	point rotate_by (point p, point about, double radians)
	{
		return (p - about) * exp(point(0, radians)) + about;
	}
	
	//Rotates line l abount point 'about' by 'radians' angles (?)
	line rotate_by (line l, point about, double radians)
	{
		return line(rotate_by(l[0], about, radians), rotate_by(l[1], about, radians));
	}
	
	point projection (line l, point p)
	{
		double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
		return l[0] + t * (l[0] - l[1]);
	}
	
	point reflection (line l, point p)
	{
		return p + (point(2, 0) * (projection(l, p)  -p));
	}
	
	double distanceLP (line l, point p)
	{
		return abs(p - projection(l, p));
	}
	
	double distanceLL (line l, line m)
	{
		return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
	}
	
	double distanceLS (line l, line s)
	{
		if (intersectLS(l, s))
			return 0;
			
		return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
	}
	
	double distanceSP (line s, point p)
	{
		const point r = projection(s, p);
		
		if (intersectSP(s, r))
			return abs(r - p);
			
		return min(abs(s[0] - p), abs(s[1] - p));
	}
	
	double distanceSS (line s, line t)
	{
		if (intersectSS(s, t))
			return 0;
			
		return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])), min(distanceSP(t, s[0]), distanceSP(t, s[1])));
	}
	
	/****************
	* Great Circle *
	****************
	* Given two pairs of (latitude, longitude), returns the
	* great circle distance between them.
	* FIELD TESTING
	*      - Valladolid 535: Globetrotter
	**/
	double great_circle (double laa, double loa, double lab, double lob)
	{
		double PI = acos(-1.0), R = 6378.0;
		double u[3] = { cos(laa) * sin(loa), cos(laa) * cos(loa), sin(laa) };
		double v[3] = { cos(lab) * sin(lob), cos(lab) * cos(lob), sin(lab) };
		double dot = u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
		bool flip = false;
		
		if( dot < 0.0 )
		{
			flip = true;
			
			for (int i = 0; i < 3; ++i) 
				v[i] = -v[i];
		}
		
		double cr[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0] };
		double theta = asin(sqrt(cr[0] * cr[0] + cr[1] * cr[1] + cr[2] * cr[2]));
		double len = theta * R;
		
		if (flip) 
			len = PI * R - len;
			
		return len;
	}
	
	point crosspoint(line l, line m)
	{ 
		double A = cross(l[1] - l[0], m[1] - m[0]);
		double B = cross(l[1] - l[0], l[1] - m[0]);
		
		if (abs(A) < EPS && abs(B) < EPS)
			return m[0];  //Same line
			
		if (abs(A) < EPS)
			return point(0, 0);  //parallels
			
		return m[0] + B / A * (m[1] - m[0]);
	}
	
	/*	4. Special points	*/
	
	//Gets the center of the circunference determined by the three points abc
	point circunference_center(point a, point b, point c)
	{
		point x = 1.0 / conj(b - a), y = 1.0 / conj(c - a);
		return (y - x) / (conj(x) * y - x * conj(y)) + a;
	}	
	
	/*********************************************
	* Circle of a given radius through 2 points *
	*********************************************
	* Computes the center of a circle containing the 2 given
	* points. The circle has the given radius. The returned
	* center is never to the right of the vector
	* (x1, y1)-->(x2, y2).
	* If this is possible, returns true and passes the center
	* through the ctr array. Otherwise, returns false.
	* #include <math.h>
	* FIELD TESTING:
	*      - Valladolid 10136: Chocolate Chip Cookies
	**/
	pair<bool, point> circle_2pts_rad (point a, point b, double r)
	{
		double d2 = norm(a - b);
		double det = r * r / d2 - 0.25;
		
		if (det < 0)	
			return make_pair(false, point());
			
		double h = sqrt(det);
		double x = (a.real() + b.real()) / 2 + (a.imag() - b.imag()) * h;
		double y = (a.imag() + b.imag()) / 2 + (b.real() - a.real()) * h;
		return make_pair(true, point(x, y));
	}
	
	//Says if the point p is inside triangle abc
	bool in_triangle (point a, point b, point c, point p)
	{
		a -= p;
		b -= p;
		c -= p;
	
		return cross(a, b) >= 0 && cross(b, c) >= 0 && cross(c, a) >= 0;
	}
	
	//Says if the four points are on some circunference (maybe wrong)
	bool in_circle (point a, point b, point c, point p) 
	{
		a -= p; b -= p; c -= p; 
		return norm(a) * cross(b, c) + norm(b) * cross(c, a) + norm(c) * cross(a, b) >= 0; // < : inside, = cocircular, > outside 
	} 
	
	//If we have a triangle with vertex at x, y and z, then:
	//Gets the point where cross the three heights of the triangle (?)
	point orthocenter (point x, point y, point z)
	{
		x -= z;
		y -= z;
		return (conj(x) * y + conj(y) * x) * (x - y) / (conj(y) * x - conj(x) * y);
	}
	
	//Gets the point where cross the three mediatrixes of the triangle (?)
	point circumcenter (point x, point y, point z)
	{
		x -= z;
		y -= z;
		return x * y * (conj(x) - conj(y)) / (conj(x) * y - conj(y) * x);
	}	
	
	/*	5. Areas	*/
	
	//Gets the area of a polygon
	double area (polygon &P)
	{
		double ans = 0;
		
		for (int i = 0; i < P.size(); ++i)
		{
			ans += cross(P[i], P[(i + 1) % P.size()]);
		}
		
		return abs(ans) / 2;
	}
	
	//Returns the area of a triangle given the lengths of its sides
	double area (double a, double b, double c)
	{
		double p = (a + b + c) / 2.0;
		double ans = p * (p - a) * (p - b) * (p - c);
		return sqrt(ans);
	}
	
	/******************************
	* Triangle Area from Medians *
	******************************
	* Given the lengths of the 3 medians of a triangle,
	* returns the triangle's area, or -1 if it impossible.
	* WARNING: Deal with the case of zero area carefully.
	* #include <math.h>
	* FIELD TESTING:
	*      - Valladolid 10347: Medians
	**/
    double area_from_medians (double ma, double mb, double mc)
    {
        double x = 0.5 * (ma + mb + mc);
        double a = x * (x - ma) * (x - mb) * (x - mc);
        
        if( a < 0.0 ) 
			return -1.0;
			
        return sqrt(a) * 4.0 / 3.0;
    }
	
	/*	6. Convex Polygon	*/
	polygon convex_hull (polygon ps)
	{
		int n = ps.size(), k = 0;
		sort(ps.begin(), ps.end());
		polygon ch(2 * n);
	
		for (int i = 0 ; i < n; ch[k++] = ps[i++]) // lower-hull
			while (k >= 2 && ccw(ch[k - 2 ], ch[k - 1 ], ps[i]) <= 0 )
				--k;
	
		for (int i = n - 2 , t = k + 1 ; i >= 0 ; ch[k++] = ps[i--]) // upper-hull
			while (k >= t && ccw(ch[k - 2 ], ch[k - 1 ], ps[i]) <= 0 )
				--k;
	
		ch.resize(k - 1);
		return ch;
	}
	
	//Checks if the convex polygon P contains the point p
	//P is given in counter clockwise order
	int convex_contains (polygon &P, point p)
	{
		int n = P.size();
		point g = (P[0] + P[n / 3] + P[2 * n / 3]) / 3.0; //inner point
		int lo = 0, hi = n;
		
		while (lo + 1 < hi) //invariant: m is in fan g-P[lo]-P[hi]
		{
			int m = (lo + hi) / 2;
			
			if (cross(P[lo] - g, P[m] - g) > 0) //angle < 180 degrees
			{
				if (cross(P[lo] - g, p - g) > 0 && cross(P[m] - g, p - g) < 0)
					hi = m;
				else
					lo = m;
			}
			else if (cross(P[lo] - g, p - g) < 0 && cross(P[m] - g, p - g) > 0)
				lo = m;
			else
				hi = m;
		}
		
		hi %= n;
		double c = cross(P[lo] - p, P[hi] - p);
		
		if (abs(c) < EPS)
			return ON;
			
		if (c < 0)
			return OUT;
			
		return IN;
	}	
	
	/*	7. Rotating calipers	*/
	
	//Gets all the antipodal pair of points
	double area (point a, point b, point c) //actually 2 * area
	{
		return abs(cross(b - a, c - a));
	}
	
	vector<pii> get_points (polygon &P)
	{
		vector<pii> ans;
		int n = P.size();
		
		if (P.size() == 2)
			ans.push_back(make_pair(0, 1));
			
		if (P.size() < 3)
			return ans;
			
		int q0 = 0;
		
		while (area(P[n - 1], P[0], P[NEXT(q0)]) > area(P[n - 1], P[0], P[q0]))
			++q0;
		
		for (int q = q0, p = 0; q != 0 && p <= q0; ++p)
		{
			ans.push_back(make_pair(p, q));
			
			while (area(P[p], P[NEXT(p)], P[NEXT(q)]) > area(P[p], P[NEXT(p)], P[q]))
			{
				q = NEXT(q);
				
				if (p != q0 || q != 0)
					ans.push_back(make_pair(p, q));
				else
					return ans;
			}
	
			if (area(P[p], P[NEXT(p)], P[NEXT(q)]) == area(P[p], P[NEXT(p)], P[q]))
			{
				if (p != q0 || q != n - 1)
					ans.push_back(make_pair(p, NEXT(q)));
				else
					ans.push_back(make_pair(NEXT(p), q));
			}
		}	
	
		return ans;
	}
	
	//Gets the farthest pair of points of the given points. (maybe TLE using double)
	pair<point, point> farthest_pair (polygon &P)
	{
		P = convex_hull(P);
		vector<pii> pairs = get_points(P);	
				
		double best = 0;
		pair<point, point> ans;
		
		for (int i = 0; i < pairs.size(); ++i)
		{
			point p1 = P[pairs[i].first];
			point p2 = P[pairs[i].second];
			double dist = norm(p1- p2);
			
			if (dist > best)
			{
				best = dist;
				ans = make_pair(p1, p2);
			}
		}
		
		return ans;
	}
	
	//Gets the minimum distance between parallel lines of support of the convex polygon P
	
	double check (int a, int b, int c, int d, polygon &P)
	{
		for (int i = 0; i < 4 && a != c; ++i)
		{
			if (i == 1)
				swap(a, b);
			else
				swap(c, d);
		}
		
		if (a == c) //a admits a support line parallel to bd
		{
			//assert(b != d)
			double A = area(P[a], P[b], P[d]); 	//double of the triangle area
			double base = abs(P[b] - P[d]);		//base of the triangle abd		
			return A / base;			
		}
		
		return oo;
	}
	
	double polygon_width (polygon &P)
	{		
		if (P.size() < 3)
			return 0;
			
		vector<pii> pairs = get_points(P);			
		double best = oo;
		int n = pairs.size();
		
		for (int i = 0; i < n; ++i)
		{
			double tmp = check(pairs[i].first, pairs[i].second, pairs[NEXT(i)].first, pairs[NEXT(i)].second, P);
			best = min(best, tmp);
		}
			
		return best;
	}

}// end geometry namespace
