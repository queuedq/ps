#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, K, L, m[MN], coke[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> L;
  for (int i=0; i<N; i++) cin >> m[i];
  for (int i=0; i<K; i++) {
    int t; cin >> t; t--;
    coke[t]++;
    if (t+L < N) coke[t+L]--;
  }

  for (int i=1; i<N; i++) coke[i] += coke[i-1];
  sort(m, m+N);
  sort(coke, coke+N);

  lld ans = 0;
  for (int i=0; i<N; i++) {
    lld x = m[i];
    for (int j=0; j<min(coke[i], 32LL); j++) x /= 2;
    ans += x;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
