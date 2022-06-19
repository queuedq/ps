#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld pow(lld a, lld e, lld m) {
  if (e == 0) return 1;
  lld p = pow(a, e/2, m), pp = p*p % m;
  if (e%2 == 0) return pp;
  return pp*a % m;
}

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MN = 5050;
lld N, P[MN], D[MN], S[MN], inv[MN];
vector<int> adj[MN];

void dfs(int u, int p, int r, lld len, lld sum, lld ex, lld pr) {
  lld deg = (int)adj[u].size() - (p != 0);
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(
      v, u, r,
      len+1,
      sum+P[v],
      (ex + S[u]-D[v]) % MOD,
      pr*inv[deg] % MOD
    );
  }

  if (deg == 0) {
    D[r] += (len*sum + ex)%MOD * pr;
    D[r] %= MOD;
  }
}

void dp(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    dp(v, u);
    S[u] += D[v];
  }
  dfs(u, p, u, 1, P[u], 0, 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////


  cin >> N;
  for (int i=1; i<=N; i++) cin >> P[i];
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i=1; i<=N; i++) inv[i] = pow(i, MOD-2, MOD);
  dp(1, 0);
  cout << D[1] << endl;

  ////////////////////////////////
  return 0;
}
