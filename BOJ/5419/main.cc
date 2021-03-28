#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 75005;
const int ST = 1<<17;
int n, coords[MN], seg[ST*2];

struct Point {
  int x, y;
  bool operator <(const Point &p) const {
    if (x == p.x) return y > p.y; // larger y-coordinate first
    return x < p.x;
  }
};
Point A[MN];

void update(int i, int v) {
  int n = ST+i;
  for (; n > 0; n /= 2) seg[n] += v;
}

int query(int n, int nl, int nr, int l, int r) {
  if (r < nl || nr < l) return 0;
  if (l <= nl && nr <= r) return seg[n];
  int mid = (nl+nr+1)/2;
  return query(n*2, nl, mid-1, l, r) + query(n*2+1, mid, nr, l, r);
}

void solve() {
  fill(seg, seg+ST*2, 0); // reset

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> A[i].x >> A[i].y;
    coords[i] = A[i].y;
  }

  sort(A, A+n);
  sort(coords, coords+n);

  for (int i=0; i<n; i++) {
    A[i].y = lower_bound(coords, coords+n, A[i].y) - coords;
  }

  lld ans = 0;
  for (int i=0; i<n; i++) {
    ans += query(1, 0, ST-1, A[i].y, ST-1);
    update(A[i].y, 1);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
