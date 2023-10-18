#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
lld N, M, K, vst[MN], D[MN];
vector<int> adj[MN], ord;
vector<pii> ans;

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (auto v: adj[u]) dfs(v);
  ord.push_back(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[v].push_back(u);
  }

  dfs(N);

  // connect twice
  for (int i=1; i<min(N, 30LL); i++) {
    int u = ord[i-1], v = ord[i];
    int cnt = 0;
    for (auto x: adj[v]) cnt += x == u;
    for (; cnt<2; cnt++) {
      adj[v].push_back(u);
      ans.push_back({u, v});
    }
  }

  // D[b] / D[a] is between 2 and 3
  D[1] = 1;
  for (int i=1; i<N; i++) {
    int v = ord[i];
    for (auto u: adj[v]) D[v] = (D[v] + D[u]) % K;
  }

  // like base 3
  for (int i=min(N, 30LL)-1; i>=0; i--) {
    int u = ord[i];
    for (int j=0; j<2; j++) {
      if (D[N] + D[u] <= K) {
        D[N] += D[u];
        ans.push_back({u, N});
      }
    }
  }

  cout << ans.size() << endl;
  for (auto [u, v]: ans) cout << u << " " << v << endl;

  ////////////////////////////////
  return 0;
}
