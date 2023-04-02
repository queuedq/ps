#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, A[MN], G[20][MN];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i], G[0][i] = A[i];

  for (int k=1; k<20; k++) {
    for (int i=0; i<N; i++) {
      if (i + (1<<(k-1)) >= N) G[k][i] = G[k-1][i];
      else G[k][i] = gcd(G[k-1][i], G[k-1][i + (1<<(k-1))]);
    }
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    lld r = i, cur = A[i];

    while (r < N) {
      for (int k=19; k>=0; k--) {
        if (gcd(cur, G[k][r]) == cur) r += (1<<k);
        if (r >= N) { r = N; break; }
      }

      ans = max(ans, cur * (r - i));
      cur = gcd(cur, A[r]);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
