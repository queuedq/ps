#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// print vector
template<class T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "[";
  for (int i=0; i<(int)vec.size()-1; i++) os << vec[i] << ", ";
  if (!vec.empty()) os << vec.back();
  os << "]";
  return os;
}

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

// length and angle
double length(Point a) { return sqrt(a*a); }
lld dist2(Point a, Point b) { return (b-a)*(b-a); }
double dist(Point a, Point b) { return sqrt((b-a)*(b-a)); }
double angle(Point a, Point b) { return atan2(cross(a, b), a * b); }

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

array<Point, 2> diameter(vector<Point> &P) {
  int n = P.size();
  pair<lld, array<Point, 2>> res = {0, {P[0], P[0]}};
  if (n == 1) return res.second;
  for (int i = 0, j = 1; i < j; i++) {
    for (;; j = (j+1) % n) {
      res = max(res, {dist2(P[i], P[j]), {P[i], P[j]}});
      if (cross(P[i+1] - P[i], P[(j+1) % n] - P[j]) <= 0) break;
    }
  }
  return res.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=0; t<T; t++) {
    int N; cin >> N;
    vector<Point> P(N);
    for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;
    vector<Point> Q = convex_hull(P);
    auto [A, B] = diameter(Q);
    cout << A.x << " " << A.y << " " << B.x << " " << B.y << endl;
  }

  ////////////////////////////////
  return 0;
}
