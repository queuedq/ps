#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 101010;
lld N, D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  D[0] = 1, D[1] = 0;
  for (int i=1; i<=N; i++) {
    D[i] = (i-1) * (D[i-1] + D[i-2]) % MOD;
  }
  lld ans = D[N];
  for (int i=1; i<=N; i++) ans = ans * i % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
