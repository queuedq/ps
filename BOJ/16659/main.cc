#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
const int MM = 202020;
const int K = 43;
int N, M, vst[MN], ord[MN], dfn;
pii edge[MM];
vector<int> adj[MN];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (auto v: adj[u]) dfs(v);
  ord[u] = dfn++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    edge[i] = {u, v};
    adj[u].push_back(v);
  }
  for (int u=1; u<=N; u++) dfs(u);

  for (int i=1; i<=M; i++) {
    auto [u, v] = edge[i];
    int x = ord[u], y = ord[v];
    if (x/K/K != y/K/K) cout << 'R' << endl;
    else if (x/K != y/K) cout << 'G' << endl;
    else cout << 'B' << endl;
  }

  ////////////////////////////////
  return 0;
}
