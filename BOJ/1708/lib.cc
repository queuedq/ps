#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const double PI = acos(-1);

struct Point {
  lld x, y;
  Point(): x(0), y(0) {}
  Point(lld x, lld y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(lld c) const { return {x*c, y*c}; }
  Point operator /(lld c) const { return {x/c, y/c}; }
  lld operator *(Point a) const { return x*a.x + y*a.y; }
};

// print
ostream& operator <<(ostream& os, Point a) { return os << "(" << a.x << ", " << a.y << ")"; }

// cross product stuffs
lld cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
lld ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }
double area(vector<Point> P) {
  lld sum = 0;
  for (int i = 0; i < (int)P.size()-1; i++) sum += cross(P[i], P[i+1]);
  sum += cross(P.back(), P[0]);
  return abs(sum) / 2.;
}

// real numbers
double length(Point a) { return sqrt(a*a); }
double angle(Point a, Point b) { return atan2(cross(a, b), a * b); }

// print vector
template<class T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "[";
  for (int i=0; i<(int)vec.size()-1; i++) os << vec[i] << ", ";
  if (!vec.empty()) os << vec.back();
  os << "]";
  return os;
}

////////////////////////////////////////////////////////////////

vector<Point> convex_hull(vector<Point> P) {
	if (P.size() <= 1) return P;
	sort(all(P));
	vector<Point> Q(P.size()+1);

	int s = 0, i = 0;
  for (auto dir: {0, 1}) {
    for (auto p: P) {
      while (i-2 >= s && ccw(Q[i-2], Q[i-1], p) <= 0) i--;
      Q[i++] = p;
    }
    s = --i; reverse(all(P));
  }

	Q.resize(i);
  if (i == 2 && Q[0] == Q[1]) Q.resize(1); // all points are same
  return Q;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  vector<Point> P(N);
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;
  cout << convex_hull(P).size() << endl;

  ////////////////////////////////
  return 0;
}
