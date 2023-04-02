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
lld N, A[MN];
vector<pll> G[MN];

void solve() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  lld ans = 0;
  for (int i=1; i<=N; i++) {
    // calc gcd-changing left pos
    for (auto [g, l]: G[i-1]) {
      lld g2 = gcd(g, A[i]);
      if (G[i].empty() || G[i].back().first != g2) G[i].push_back({g2, l});
    }
    if (G[i].empty() || G[i].back().first != A[i]) G[i].push_back({A[i], i});

    // calc ans
    for (auto [g, l]: G[i]) ans = max(ans, g * (i-l+1));
  }

  cout << ans << endl;

  // reset
  for (int i=1; i<=N; i++) G[i].clear();
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
