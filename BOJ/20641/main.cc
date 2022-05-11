#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3005;
const lld MOD = 1e9+7;
lld N, s[MN], t[MN], D[MN][MN], E[MN][MN], fact[MN];
// D[i][k]: match k among s[i]..s[N]
// E[i][k]: match k among t[1]..t[i]

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> s[i];
  for (int i=1; i<=N; i++) cin >> t[i];
  sort(s+1, s+N+1);
  sort(t+1, t+N+1);
  s[N+1] = t[N+1] = 1e9+5;
  fact[0] = 1;
  for (int i=1; i<=N; i++) fact[i] = fact[i-1] * i % MOD;

  int j = N+1;
  D[N+1][0] = 1;
  for (int i=N; i>=1; i--) {
    while (s[i] <= t[j-1]) j--;
    D[i][0] = 1;
    for (int k=1; k<=N-i+1; k++) {
      D[i][k] = D[i+1][k];
      if (k <= N-j+1) D[i][k] += D[i+1][k-1] * ((N-j+1) - (k-1));
      D[i][k] %= MOD;
    }
  }

  j = 0;
  E[0][0] = 1;
  for (int i=1; i<=N; i++) {
    while (s[j+1] <= t[i]) j++;
    E[i][0] = 1;
    for (int k=1; k<=i; k++) {
      E[i][k] = E[i-1][k];
      if (k <= j) E[i][k] += E[i-1][k-1] * (j - (k-1));
      E[i][k] %= MOD;
    }
  }

  j = N+1;
  lld ans = E[N][N];
  for (int i=N; i>=1; i--) { // s[i]: smallest unmatched
    while (s[i] <= t[j-1]) j--;
    for (int k=0; k<=i-1; k++) { // number of s[1]..s[i-1] <-> t[j]..t[N] matchings
      if (k > N-j+1) break;
      lld cnt = D[i+1][(N-j+1) - k] * E[j-1][(i-1) - k] % MOD;
      cnt = cnt * fact[k] % MOD;
      ans = (ans + cnt) % MOD;
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
