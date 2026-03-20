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
const double MV = 1e9;
int N;
lld t[MN], l[MN], r[MN];

struct Init {
  double x; int i; // x: initial pos for some v, i: index of point
  bool operator <(const Init &X) const { return x < X.x; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> t[i] >> l[i] >> r[i];

  // max velocity
  double s = -MV, e = MV;
  for (int trial=0; trial<60; trial++) {
    double v = (s+e)/2;
    
    Init L = {-INFINITY, 0}, R = {INFINITY, 0};
    for (int i=0; i<N; i++) {
      L = max(L, {l[i] - v * t[i], i});
      R = min(R, {r[i] - v * t[i], i});
    }

    if (L.x > R.x && L.i < R.i) e = v;
    else s = v;
  }

  double mx = s;
  
  // min velocity
  s = -MV, e = MV;
  for (int trial=0; trial<60; trial++) {
    double v = (s+e)/2;
    
    Init L = {-INFINITY, 0}, R = {INFINITY, 0};
    for (int i=0; i<N; i++) {
      L = max(L, {l[i] - v * t[i], i});
      R = min(R, {r[i] - v * t[i], i});
    }

    if (L.x > R.x && L.i > R.i) s = v;
    else e = v;
  }

  double mn = s;

  cout << fixed << setprecision(12) << mn << " " << mx << endl;

  ////////////////////////////////
  return 0;
}
