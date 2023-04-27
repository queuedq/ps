#include <bits/stdc++.h>
#include <cmath>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const double eps = 1e-12;
const double PI = acos(-1);
const int MN = 2020;
int N, D[MN], ok[MN][MN];
double d;

struct Point {
  double x, y;
  Point operator -(Point P) const { return {x-P.x, y-P.y}; }
  double dist() const { return sqrt(x*x + y*y); }
  double angle() const { return atan2(y, x); }
};
Point P[MN];

pair<double, double> get_range(Point P, Point Q) {
  double t = (Q-P).angle();
  double dt = asin(d / (Q-P).dist());
  if (isnan(dt)) return {-INFINITY, INFINITY};
  return {t-dt-eps, t+dt+eps};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> d;
  for (int i=1; i<=N; i++) cin >> P[i].x >> P[i].y;

  for (int i=1; i<=N; i++) {
    for (int d: {-1, 1}) { // direction
      double l = -INFINITY, r = INFINITY;

      for (int j=i+d; 1<=j && j<=N; j+=d) {
        double t = (P[j]-P[i]).angle();
        if (r == INFINITY) ok[i][j] = 1;
        else {
          t -= PI*2;
          while (t < r-PI*2) t += PI*2;
          ok[i][j] = l <= t && t <= r;
        }

        auto [s, e] = get_range(P[i], P[j]);
        if (r == INFINITY) l = s, r = e;
        else if (e < INFINITY) {
          s -= PI*2, e -= PI*2;
          while (s < r-PI*2) s += PI*2, e += PI*2;
          l = max(l, s), r = min(r, e);
        }
        if (l > r) break;
      }
    }
  }

  for (int i=1; i<=N; i++) {
    D[i] = i;
    for (int j=1; j<i; j++) {
      if (ok[i][j] && ok[j][i]) D[i] = min(D[i], D[j]+1);
    }
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
