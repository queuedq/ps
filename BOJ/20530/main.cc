#include <unistd.h>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2e5+5;
int N, Q, group[MN];
bool vst[MN], in_cycle[MN];
vector<int> adj[MN];
vector<int> cycle;

void dfs1(int u, int p, vector<int> &path) {
  if (vst[u]) {
    int i = 0;
    for (; i<path.size(); i++) { if (path[i] == u) break; }
    for (; i<path.size(); i++) {
      cycle.push_back(path[i]);
      in_cycle[path[i]] = true;
    }
    return;
  }

  vst[u] = true;
  path.push_back(u);
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs1(v, u, path);
  }
  path.pop_back();
}

void dfs2(int u, int p, int g) {
  group[u] = g;
  for (auto v: adj[u]) {
    if (v == p || in_cycle[v]) continue;
    dfs2(v, u, g);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> path;
  dfs1(1, 1, path);
  
  for (auto g: cycle) dfs2(g, g, g);

  for (int i=0; i<Q; i++) {
    int u, v; cin >> u >> v;
    if (group[u] == group[v]) cout << 1 << endl;
    else cout << 2 << endl;
  }

  ////////////////////////////////
  return 0;
}
