#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, D[MN], ans[MN];
vector<pii> adj[MN];
map<pii, int> edge;

int dfs1(int u, int p) {
  int d = 0;
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    d += dfs1(v, u) + w;
  }
  return d;
}

void dfs2(int u, int p, int d) {
  D[u] = d;
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs2(v, u, d + (w?-1:1));
  }
}

void dfs3(int u, int p) {
  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    ans[edge[{u, v}]] = w;
    dfs3(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
    edge[{u, v}] = edge[{v, u}] = i;
  }

  int d = dfs1(1, 0);
  dfs2(1, 0, d);

  int u = min_element(D+1, D+N+1) - D;
  dfs3(u, 0);

  for (int i=0; i<N-1; i++) cout << ans[i];

  ////////////////////////////////
  return 0;
}
