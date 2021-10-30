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

// length and angle
double length(Point a) { return sqrt(a*a); }
lld dist2(Point a, Point b) { return (b-a)*(b-a); }
double dist(Point a, Point b) { return sqrt((b-a)*(b-a)); }
double angle(Point a, Point b) { return atan2(cross(a, b), a * b); }


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

// rotating calipers
lld diameter(const vector<Point> &P) {
  int n = P.size();
  lld res = 0;
  if (n == 1) return res;
  for (int i = 0, j = 1; i < j; i++) {
    for (;; j = (j+1) % n) {
      res = max(res, dist2(P[i], P[j]));
      if (cross(P[i+1] - P[i], P[(j+1) % n] - P[j]) <= 0) break;
    }
  }
  return res;
}

////////////////////////////////////////////////////////////////
const int MN = 30303;
lld N, T, x[MN], y[MN], dx[MN], dy[MN];

lld check(int t) {
  vector<Point> P(N);
  for (int i=0; i<N; i++) P[i] = {x[i] + dx[i]*t, y[i] + dy[i]*t};
  return diameter(convex_hull(P));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> T;
  for (int i=0; i<N; i++) cin >> x[i] >> y[i] >> dx[i] >> dy[i];

  int l = 0, r = T;
  while (r-l >= 3) {
    int m1 = (l+l+r)/3, m2 = (l+r+r)/3;
    if (check(m1) > check(m2)) l = m1;
    else r = m2;
  }

  lld mn = LLONG_MAX, opt = l;
  for (int i=l; i<=r; i++) {
    lld d = check(i);
    if (d < mn) mn = d, opt = i;
  }

  cout << opt << endl;
  cout << mn << endl;

  ////////////////////////////////
  return 0;
}
