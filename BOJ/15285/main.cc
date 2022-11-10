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
int N, M, vst[MN];
vector<int> G[MN], GT[MN];
set<pii> used;

void dfs1(int u, int p) {
  if (vst[u]) return;
  vst[u] = 1;
  if (p != 0) used.insert({p, u});
  for (auto v: G[u]) dfs1(v, u);
}

void dfs2(int u, int p) {
  if (vst[u]) return;
  vst[u] = 1;
  if (p != 0) used.insert({u, p});
  for (auto v: GT[u]) dfs2(v, u);
}

void solve() {
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    GT[v].push_back(u);
  }

  fill(vst, vst+N+1, 0);
  dfs1(1, 0);
  fill(vst, vst+N+1, 0);
  dfs2(1, 0);

  int cnt = 0;
  for (int u=1; u<=N; u++) {
    for (auto v: G[u]) {
      if (used.count({u, v})) continue;
      if (cnt++ < M-N*2) {
        cout << u << " " << v << endl;
      }
    }
  }
}

void reset() {
  for (int i=1; i<=N; i++) G[i].clear(), GT[i].clear();
  used.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
    reset();
  }

  ////////////////////////////////
  return 0;
}
