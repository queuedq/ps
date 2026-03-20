#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N;
lld t[MN], l[MN], r[MN];

struct Point { lld x, y; };
vector<Point> LH, RH;

lld ccw(Point a, Point b, Point c) {
  return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

double slope(Point a, Point b) {
  return (double)(b.y - a.y) / (b.x - a.x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> t[i] >> l[i] >> r[i];

  // convex hulls
  for (int i=0; i<N; i++) {
    while (sz(LH) >= 2) {
      Point A = LH[sz(LH) - 2], B = LH[sz(LH) - 1];
      if (ccw(A, B, {t[i], l[i]}) >= 0) LH.pop_back();
      else break;
    }
    LH.push_back({t[i], l[i]});

    while (sz(RH) >= 2) {
      Point A = RH[sz(RH) - 2], B = RH[sz(RH) - 1];
      if (ccw(A, B, {t[i], r[i]}) <= 0) RH.pop_back();
      else break;
    }
    RH.push_back({t[i], r[i]});
  }

  // tangents
  double mn = INFINITY, mx = -INFINITY;

  // max velocity
  for (int i=sz(LH)-2, j=sz(RH)-1; i>=0; i--) {
    while (j > 0 && ccw(LH[i], RH[j], RH[j-1]) < 0) j--;

    bool b1 = i == 0 || ccw(LH[i], LH[i-1], RH[j]) >= 0;
    bool b2 = i == sz(LH)-1 || ccw(LH[i], LH[i+1], RH[j]) >= 0;
    assert(LH[i].x != RH[j].x);
    if (b1 && b2) { mx = slope(LH[i], RH[j]); break; }
  }

  // min velocity
  for (int i=1, j=0; i<sz(LH); i++) {
    while (j < sz(RH)-1 && ccw(LH[i], RH[j], RH[j+1]) > 0) j++;

    bool b1 = i == sz(LH)-1 || ccw(LH[i], LH[i+1], RH[j]) <= 0;
    bool b2 = i == 0 || ccw(LH[i], LH[i-1], RH[j]) <= 0;
    assert(LH[i].x != RH[j].x);
    if (b1 && b2) { mn = slope(LH[i], RH[j]); break; }
  }

  cout << fixed << setprecision(18) << mn << " " << mx << endl;

  ////////////////////////////////
  return 0;
}
