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
const int MK = 30;
int N, K, adj[MK][MK], D[MK];
string S[MN];

int dp(int u) {
  if (D[u] != 0) return D[u];
  D[u] = 1;

  for (int v=0; v<K; v++) {
    if (u == v) continue;
    if (adj[u][v] && !adj[v][u]) D[u] = max(D[u], dp(v) + 1);
  }
  return D[u];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int k=0; k<N; k++) cin >> S[k];

  for (int k=0; k<N; k++) {
    for (int i=0; i<K; i++) {
      for (int j=i+1; j<K; j++) {
        int u = S[k][i] - 'A', v = S[k][j] - 'A';
        adj[u][v] = 1;
      }
    }
  }

  int ans = 0;
  for (int u=0; u<K; u++) ans = max(ans, dp(u));
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
