#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, K, x[MN], y[MN], vst[MN], t1[MN], t2[MN], last;
vector<int> adj[MN];

bool cmp(int i, int j) { return x[i] < x[j] || y[i] > y[j]; }

void dfs1(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (int i=0; i<sz(adj[u]); i++) dfs1(adj[u][i]);
  t1[u] = ++last;
}

void dfs2(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (int i=sz(adj[u])-1; i>=0; i--) dfs2(adj[u][i]);
  t2[u] = ++last;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) cin >> x[i] >> y[i];
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    if (!cmp(u, v)) swap(u, v);
    adj[u].push_back(v);
  }
  for (int i=1; i<=N; i++) {
    if (sz(adj[i]) == 2 && x[adj[i][0]] > x[adj[i][1]]) swap(adj[i][0], adj[i][1]);
  }

  fill(vst, vst+N+1, 0); last = 0; dfs1(1);
  fill(vst, vst+N+1, 0); last = 0; dfs2(1);

  for (int i=1; i<=K; i++) {
    int u, v; cin >> u >> v;
    bool b1 = t1[u] < t1[v], b2 = t2[u] < t2[v];
    if (b1 == b2) cout << "TAK\n";
    else cout << "NIE\n";
  }

  ////////////////////////////////
  return 0;
}
