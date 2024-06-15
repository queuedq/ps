#include <bits/stdc++.h>
#include <iomanip>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using llf = long double;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N;

struct Point {
  llf x, y;
  Point operator+(Point P) { return {x+P.x, y+P.y}; }
  Point operator-(Point P) { return {x-P.x, y-P.y}; }
  Point operator*(llf t) { return {x*t, y*t}; }
  llf length() { return sqrt(x*x + y*y); }
};
Point P[MN];
llf L = 0, A = 0; // perimeter, area

llf ccw(Point A, Point B, Point C) { return (A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x); }
llf dist(Point A, Point B) { return (B-A).length(); }

struct Info { Point X; int idx; llf ratio, area; };

Info point_at(llf t) {
  llf sum = 0, area = 0;
  for (int i=1; i<=N; i++) {
    llf l = dist(P[i], P[i+1]);
    if (sum + l >= t) {
      llf dl = t - sum;
      Point X = P[i] + (P[i+1]-P[i]) * (dl/l);
      return {X, i, dl/l, area + ccw(P[1], P[i], X) / 2};
    }
    sum += l;
    area += ccw(P[1], P[i], P[i+1]) / 2;
  }
  return {P[1], N, 1., area};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i].x >> P[i].y;
  P[N+1] = P[1];

  for (int i=1; i<=N; i++) L += dist(P[i], P[i+1]);
  for (int i=2; i<N; i++) A += ccw(P[1], P[i], P[i+1]) / 2;

  llf init_area = point_at(L/2).area;
  
  llf s = 0, e = L/2;
  while (1) {
    llf t = (s+e)/2;
    if (t == s || t == e) break;
    auto [X, j, a, S1] = point_at(t);
    auto [Y, k, b, S2] = point_at(t + L/2);
    llf area = S2 - S1 - ccw(P[1], X, Y) / 2;
    if ((init_area < A/2) == (area < A/2)) s = t;
    else e = t;
  }

  auto [X, j, a, S1] = point_at(s);
  auto [Y, k, b, S2] = point_at(s + L/2);

  cout << "YES" << endl;
  cout << fixed << setprecision(12) << j << " " << a << endl;
  cout << fixed << setprecision(12) << k << " " << b << endl;

  ////////////////////////////////
  return 0;
}
