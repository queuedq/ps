#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const double PI = acos(-1);

struct Point {
  double x, y;
  Point(): x(0), y(0) {}
  Point(double x, double y): x(x), y(y) {}

  bool operator ==(Point a) const { return x == a.x && y == a.y; }
  bool operator !=(Point a) const { return !(*this == a); }
  bool operator <(Point a) const { return pair(x, y) < pair(a.x, a.y); }
  Point operator +(Point a) const { return {x+a.x, y+a.y}; }
  Point operator -(Point a) const { return {x-a.x, y-a.y}; }
  Point operator *(double c) const { return {x*c, y*c}; }
  Point operator /(double c) const { return {x/c, y/c}; }
  double operator *(Point a) const { return x*a.x + y*a.y; }

  double length() { return sqrt(*this * *this); }
  Point normalize() { return *this / this->length(); }
  Point rotate(double th) { return {x*cos(th) - y*sin(th), x*sin(th) + y*cos(th)}; }
};

ostream& operator <<(ostream& os, Point a) { return os << "(" << a.x << ", " << a.y << ")"; }

double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
double ccw(Point a, Point b, Point c) { return cross(b-a, c-a); }
double angle(Point a, Point b) { return atan2(cross(a, b), a * b); }

////////////////////////////////////////////////////////////////
const int MN = 105;

struct Circle {
  Point o; double r;

  pair<Point, Point> inter(Circle c) {
    Point v = c.o - o;
    double d = v.length();
    double th = acos((d*d + r*r - c.r*c.r) / (2*d*r));
    return {o + v.normalize().rotate(th) * r, o + v.normalize().rotate(-th) * r};
  }
};

int N;
vector<Circle> C;
Point P[MN][2];
double D[MN][2];

bool reachable(int i, int j, Point p, Point q) {
  for (int k=i+1; k<j; k++) {
    if (ccw(p, P[k][0], q) > 0) return false;
    if (ccw(p, P[k][1], q) < 0) return false;
  }
  return true;
}

void solve() {
  C.clear();
  for (int i=0; i<N; i++) {
    double x, y, r; cin >> x >> y >> r;
    C.push_back({{x, y}, r});
  }

  // get intersections
  P[0][0] = P[0][1] = C[0].o;
  P[N][0] = P[N][1] = C[N-1].o;
  for (int i=1; i<N; i++) {
    auto [p0, p1] = C[i-1].inter(C[i]);
    P[i][0] = p0; P[i][1] = p1;
  }

  // dp
  D[0][0] = D[0][1] = 0;
  for (int j=1; j<=N; j++) {
    D[j][0] = D[j][1] = INFINITY;
    for (int i=0; i<j; i++) {
      for (int a: {0, 1}) {
        for (int b: {0, 1}) {
          if (reachable(i, j, P[i][a], P[j][b])) {
            D[j][b] = min(D[j][b], D[i][a] + (P[j][b] - P[i][a]).length());
          }
        }
      }
    }
  }

  cout << fixed << setprecision(6) << D[N][0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (cin >> N) {
    if (N == 0) break;
    solve();
  }

  ////////////////////////////////
  return 0;
}
