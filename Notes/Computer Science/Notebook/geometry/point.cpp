template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct PT{
	T x, y;
	explicit PT(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(PT point) const { return tie(x,y) < tie(point.x,point.y); }
	bool operator==(PT point) const { return tie(x,y)==tie( point.x, point.y); }
	PT operator+(PT point) const { return PT(x+ point.x, y+ point.y); }
	PT operator-(PT point) const { return PT(x- point.x, y- point.y); }
	PT operator*(T d) const { return PT(x*d, y*d); }
	PT operator/(T d) const { return PT(x/d, y/d); }
	T dot(PT point) const { return x* point.x + y* point.y; }
	T cross(PT point) const { return x* point.y - y* point.x; }
	T cross(PT a, PT b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	PT unit() const { return *this/dist(); } // makes dist()=1
	PT perp() const { return PT(-y, x); } // rotates +90 degrees
	PT normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	PT rotate(double a) const {
		return PT(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, PT point) {
		return os << "(" << point.x << "," << point.y << ")"; }
};