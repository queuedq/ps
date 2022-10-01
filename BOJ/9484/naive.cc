#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;

struct Point {
  int x, y;
  Point operator -(const Point &P) const { return {x-P.x, y-P.y}; }
};
inline int cross(Point P, Point Q) { return P.x*Q.y - P.y*Q.x; }
inline int area2(Point P, Point Q, Point R) { return abs(cross(Q-P, R-P)); }

int N;
Point P[MN];

void solve() {
  cin >> N;
  if (N == 0) exit(0);
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;

  int mn = INT_MAX, mx = INT_MIN;
  for (int i=0; i<N; i++) for (int j=i+1; j<N; j++) for (int k=j+1; k<N; k++) {
    mn = min(mn, area2(P[i], P[j], P[k]));
    mx = max(mx, area2(P[i], P[j], P[k]));
  }

  cout << fixed << setprecision(1) << mn/2.0 << " " << mx/2.0 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  while (1) solve();

  ////////////////////////////////
  return 0;
}
