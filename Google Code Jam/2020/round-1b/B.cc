#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld t, a, b;

int hit(pll P) {
  cout << P.first << " " << P.second << endl;
  string res; cin >> res;
  if (res == "CENTER") return 0;
  if (res == "HIT") return 1;
  return 2;
}

bool findhit(lld &x, lld &y) {
  for (int i=-1; i<=1; i++) {
    for (int j=-1; j<=1; j++) {
      x = i*1e9/2;
      y = j*1e9/2;
      int res = hit({x, y});
      if (res == 0) return true;
      if (res == 1) return false;
    }
  }
  return false;
}

void solve() {
  lld x, y;
  lld hl, hr, vl, vr, hc, vc;

  if (findhit(x, y)) return;

  // Horizontal
  lld l = x, r = 1e9+1;
  while (l+1 < r) {
    lld mid = (l+r) / 2;
    int res = hit({mid, y});
    if (res == 0) return;
    if (res == 1) l = mid;
    else r = mid;
  }
  hr = l;

  l = -1e9-1; r = x;
  while (l+1 < r) {
    lld mid = (l+r) / 2;
    int res = hit({mid, y});
    if (res == 0) return;
    if (res == 1) r = mid;
    else l = mid;
  }
  hl = r;

  hc = (hl + hr) / 2;

  // Vertical
  l = y; r = 1e9+1;
  while (l+1 < r) {
    lld mid = (l+r) / 2;
    int res = hit({x, mid});
    if (res == 0) return;
    if (res == 1) l = mid;
    else r = mid;
  }
  vr = l;

  l = -1e9-1; r = y;
  while (l+1 < r) {
    lld mid = (l+r) / 2;
    int res = hit({x, mid});
    if (res == 0) return;
    if (res == 1) r = mid;
    else l = mid;
  }
  vl = r;

  vc = (vl + vr) / 2;

  assert(hit({hc, vc}) == 0);
}

int main() {
  ////////////////////////////////

  cin >> t >> a >> b;

  while (t--) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
