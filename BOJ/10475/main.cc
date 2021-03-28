#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Point {
  double x, y;

  Point operator +(Point p) { return {x+p.x, y+p.y}; }
  Point operator -(Point p) { return {x-p.x, y-p.y}; }
  Point operator *(double c) { return {x*c, y*c}; }
  Point operator /(double c) { return {x/c, y/c}; }

  double length() { return sqrt(x*x + y*y); }
  double dist(Point p) { return (*this - p).length(); }
  Point normalize() { return (*this) / length(); }
  Point ortho() { return {-y, x}; }
};

const double eps = 1e-5;
int m;
double d;
Point P[32];

void solve() {
  int ans = 1;
  for (int i=0; i<m; i++) {
    for (int j=0; j<i; j++) {
      if (P[i].dist(P[j]) > d) continue;
      Point mid = (P[i] + P[j]) / 2;
      double r = mid.dist(P[i]);
      Point normal = (P[i] - mid).ortho().normalize();
      Point c1 = mid + normal * sqrt(d*d/4 - r*r);
      Point c2 = mid - normal * sqrt(d*d/4 - r*r);

      int cnt = 0;
      for (int k=0; k<m; k++) {
        if (c1.dist(P[k]) <= d/2 + eps) cnt++;
      }
      ans = max(ans, cnt);

      cnt = 0;
      for (int k=0; k<m; k++) {
        if (c2.dist(P[k]) <= d/2 + eps) cnt++;
      }
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  while (N--) {
    cin >> m >> d;
    for (int i=0; i<m; i++) cin >> P[i].x >> P[i].y;
    solve();
  }

  ////////////////////////////////
  return 0;
}
