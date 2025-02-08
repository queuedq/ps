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
int N, M;
vector<int> adj[MN];
int nxt[MN], vst[MN];

int find(int u) {
  if (!vst[nxt[u]]) return nxt[u];
  return nxt[u] = find(nxt[u]);
}

void dfs(int u, int &cnt) {
  vst[u] = 1;
  cnt++;
  for (int v = find(0), i = 0; v <= N; v = find(v)) { // jump visited nodes
    while (adj[u][i] < v) i++;
    if (adj[u][i] == v) continue; // forbidden edge
    dfs(v, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int u=1; u<=N; u++) { sort(all(adj[u])); adj[u].push_back(N+1); }
  for (int u=0; u<=N; u++) nxt[u] = u+1;

  vector<int> comp;
  for (int u=1; u<=N; u++) {
    if (vst[u]) continue;
    int cnt = 0;
    dfs(u, cnt);
    comp.push_back(cnt);
  }
  sort(all(comp));

  cout << sz(comp) << endl;
  for (auto size: comp) cout << size << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
