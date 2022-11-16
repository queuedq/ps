#include <bits/stdc++.h>
#include <cassert>
#include <cmath>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using lf = double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using pff = pair<lf, lf>;

////////////////////////////////////////////////////////////////

pair<lf, lf> vector_equation(lf a, lf b, lf c, lf d, lf e, lf f) {
  // ax + by = c; dx + ey = f
  // x = | c b |  / | a b |
  //     | f e | /  | d e |
  lf x = (c*e - b*f) / (a*e - b*d);
  // y = | a c |  / | a b |
  //     | d f | /  | d e |
  lf y = (a*f - c*d) / (a*e - b*d);
  assert(a*x + b*y - c < 1e-9);
  assert(d*x + e*y - f < 1e-9);
  return {x, y};
}

struct Point {
  lf x, y;
  Point() = default;
  Point(lf x, lf y): x(x), y(y) {}
  Point(int x, int y): x(x), y(y) {}
  Point operator +(const Point &P) const { return {x+P.x, y+P.y}; }
  Point operator -(const Point &P) const { return {x-P.x, y-P.y}; }
  Point operator *(lf c) const { return {x*c, y*c}; }
  Point operator /(lf c) const { return {x/c, y/c}; }
  lf dist2() const { return x*x + y*y; }
  lf angle() const { return atan2(y, x); }
};

ostream& operator <<(ostream &os, Point &P) {
  return os << "(" << P.x << " " << P.y << ")";
}

lf ccw(Point A, Point B, Point C) {
  return (A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x);
}

struct Line {
  Point A, B;
  Line() = default;
  Line(Point A, Point B): A(A), B(B) {}
  Line operator -(const Point &P) const { return {A-P, B-P}; }
  lf dist2() const { return (A+B).dist2(); }
};

Point inter(Line L, Line K) {
  // L.A + (L.B - L.A) * t = K.A + (K.B - K.A) * u
  auto [t, u] = vector_equation(
    (L.B - L.A).x, -(K.B - K.A).x, (K.A - L.A).x,
    (L.B - L.A).y, -(K.B - K.A).y, (K.A - L.A).y
  );
  return L.A + (L.B - L.A) * t;
}

const int _N = 55;
int N, M, wall_cnt;
char A[_N][_N];
Point O;
vector<Line> L;
vector<Point> E;

bool filled(int i, int j) {
  return A[i][j] == 0 || A[i][j] == '#';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];

  Point O; // origin (*)
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j] == '*') O = {i+0.5, j+0.5};
      if (A[i][j] == '#') wall_cnt++;
    }
  }
  
  // Rays (E)
  for (int i=0; i<=N; i++)
    for (int j=0; j<=M; j++)
      E.push_back(Point(i, j) - O);

  sort(all(E), [](Point P, Point Q) { return P.angle() < Q.angle(); });

  // Walls (L)
  for (int i=0; i<N; i++) L.push_back(Line({i, 0}, {i+1, 0}) - O); // left boundary
  for (int j=0; j<M; j++) L.push_back(Line({0, j}, {0, j+1}) - O); // top boundary
  for (int i=0; i<N; i++) {
    // right/bottom of each cell
    for (int j=0; j<M; j++) {
      if (filled(i, j) ^ filled(i, j+1)) L.push_back(Line({i, j+1}, {i+1, j+1}) - O);
      if (filled(i, j) ^ filled(i+1, j)) L.push_back(Line({i+1, j}, {i+1, j+1}) - O);
    }
  }

  for (auto &l: L) // make (A, B) ccw order
    if (ccw({0, 0}, l.A, l.B) < 0) swap(l.A, l.B);

  // Sweep to get visible walls
  vector<Line> V; // visible walls
  for (auto ray: E) {
    Line v = {{INFINITY, 0.}, {0, 0}};
    for (auto l: L) {
      if (ccw({0, 0}, l.A, ray) >= 0 && ccw({0, 0}, ray, l.B) > 0) { // intersect
        if (l.dist2() < v.dist2()) v = l;
      }
    }
    assert(v.A.x != INFINITY);
    V.push_back(v);
  }

  // Sweep to get visible area
  lf visible = 0;
  E.push_back(E[0]);
  for (int i=0; i<sz(E)-1; i++) {
    Point P = inter({{0, 0}, E[i]}, V[i]);
    Point Q = inter({{0, 0}, E[i+1]}, V[i]);
    lf tri = ccw({0, 0}, P, Q) / 2;
    visible += tri;
  }

  cout << fixed << setprecision(15) << N*M - wall_cnt - visible << endl;

  ////////////////////////////////
  return 0;
}
