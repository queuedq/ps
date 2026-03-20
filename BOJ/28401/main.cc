#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int X, Y, K;

struct Point {
  int x, y;
  bool operator==(Point P) const { return x==P.x && y==P.y; }
  bool operator<(Point P) const { return pii(x, y) < pii(P.x, P.y); }
  Point operator-(Point P) const { return {x-P.x, y-P.y}; }
  int operator*(Point P) const { return x*P.x + y*P.y; }
};
struct Line { Point A, B; };
vector<Point> P[2];

int ccw(Point A, Point B, Point C) {
  return (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x);
}

bool on_segment(Point P, Line L) {
  return ccw(P, L.A, L.B) == 0 && (P-L.A) * (P-L.B) <= 0;
}

bool intersect(Line L, Line M) {
  if (on_segment(M.A, L) || on_segment(M.B, L) || on_segment(L.A, M) || on_segment(L.B, M))
    return 1;
  int c1 = ccw(L.A, L.B, M.A);
  int c2 = ccw(L.A, L.B, M.B);
  int c3 = ccw(M.A, M.B, L.A);
  int c4 = ccw(M.A, M.B, L.B);
  int t1 = (c1 > 0 && c2 < 0) || (c1 < 0 && c2 > 0);
  int t2 = (c3 > 0 && c4 < 0) || (c3 < 0 && c4 > 0);
  return t1 && t2;
}

vector<Point> convex_hull(vector<Point> &P) {
  int N = sz(P), j = 0;
  sort(all(P));
  vector<Point> Q(N+1);
  for (auto d: {0, 1}) {
    for (int i=0, s=j; i<N; i++) {
      while (j-s >= 2 && ccw(Q[j-2], Q[j-1], P[i]) <= 0) j--;
      Q[j++] = P[i];
    }
    j--; reverse(all(P));
  }
  Q.resize(j);
  return Q;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> X >> Y >> K;
  for (int i=0; i<K; i++) {
    int x, y; cin >> x >> y;
    int c = ccw({1, 1}, {X, Y}, {x, y}); // is (x,y) above line ((1,1),(X,Y))?
    if (c == 0) { cout << 0 << endl; return 0; }

    if (c > 0 && ccw({0, 1}, {X-1, Y}, {x, y-1})) P[0].push_back({x, y-1}); // above
    if (c < 0 && ccw({1, 0}, {X, Y-1}, {x-1, y})) P[1].push_back({x-1, y}); // below
  }

  P[0].push_back({0, 1});
  P[0].push_back({X-1, Y});
  P[1].push_back({1, 0});
  P[1].push_back({X, Y-1});

  P[0] = convex_hull(P[0]);
  P[1] = convex_hull(P[1]);

  for (auto A: P[0]) {
    for (auto B: P[0]) {
      for (auto C: P[1]) {
        for (auto D: P[1]) {
          if (intersect({A, B}, {C, D})) { cout << 0 << endl; return 0; }
        }
      }
    }
  }

  cout << 1 << endl; return 0;

  ////////////////////////////////
  return 0;
}
