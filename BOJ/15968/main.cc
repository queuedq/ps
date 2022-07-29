#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 2e9;
const int MN = 5e5+5;
lld N, Q, D[MN], P[MN], len[MN];

inline lld ceil(lld a, lld b) { return a/b + (a%b != 0); }
inline lld inter(lld l, lld r, lld s, lld e) {
  return max(0LL, min(r, e) - max(l, s) + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=N; i++) cin >> D[i];

  P[0] = 1; // jump period
  len[0] = 1; // same-P interval length
  lld m = 0; // number of intervals, O(log N)
  for (int i=1; i<=N; i++) {
    lld q = ceil(D[i], P[m]);
    if (q == 1) len[m]++;
    else {
      len[++m] = 1;
      P[m] = P[m-1] * q;
      if (P[m] >= INF) break;
    }
  }

  for (int q=1; q<=Q; q++) {
    lld T, L, R; cin >> T >> L >> R;
    lld ans = 0;
    for (int i=0, x=0; i<=m; x-=len[i++]) {
      lld e = x + T/P[i]*P[i];
      lld s = e-len[i]+1;
      ans += inter(L, R, s, e);
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
