#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 2e6+5; // double interval lengths
lld N, Q;
lld L[MX][2], R[MX][2]; // L[x]: intervals [x, ?] / [0]: wgt sum, [1]: wgt * x sum

lld ds[MX]; // delta slope
lld contain[MX]; // interval wgt sum containing this (mid)point
lld away[MX]; // interval cost moving away from this (mid)point

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    lld l, r; cin >> l >> r;
    l *= 2, r *= 2;
    lld m = (l+r) / 2, w = (r-l) / 2;
    L[l][0] += w, L[l][1] += w * l;
    R[r][0] += w, R[r][1] += w * r;

    contain[l] += w;
    contain[r] -= w;
    // _/\_ shape
    ds[l] += w;
    ds[m] -= w * 2;
    ds[r] += w;
  }

  lld cur = 0, slope = 0;
  for (int x=0; x<MX; x++) {
    // midpoint in interval
    away[x] = cur;
    slope += ds[x];
    cur += slope;
  }

  // prefix sum
  for (int x=1; x<MX; x++) {
    contain[x] += contain[x-1];
    // midpoint on left/right
    L[x][0] += L[x-1][0];
    L[x][1] += L[x-1][1];
    R[x][0] += R[x-1][0];
    R[x][1] += R[x-1][1];
  }

  // query
  for (int q=0; q<Q; q++) {
    lld s, e; cin >> s >> e;
    s *= 2, e *= 2;
    lld m = (s+e) / 2, radius = (e-s) / 2;

    lld ans = 0;

    // midpoint in interval
    ans += (away[m] + contain[m] * radius);

    // midpoint on right
    lld wgt_r = (R[m][0] - R[s][0]);
    lld cost_r = (R[m][1] - R[s][1]) - wgt_r * s; // moving right point to s
    ans += cost_r;

    // midpoint on left
    lld wgt_l = (L[e][0] - L[m][0]);
    lld cost_l = wgt_l * e - (L[e][1] - L[m][1]); // moving left point to e
    ans += cost_l;

    // halve the dist and then double the cost (as stated in the problem) -> no change
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
