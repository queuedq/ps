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
int N, M, K, vst[MN*3][3], D[MN*3][3], scc_cnt;
vector<int> ord, comp;

struct Node { int u, dk, w; };
vector<Node> adj[MN*3], rev[MN*3];

void make_edge(int u, int v, int w) {
  adj[u].push_back({v, 0, w});
  rev[v].push_back({u, 0, w});
}

void dfs1(int u) {
  if (vst[u][0]) return;
  vst[u][0] = 1;
  for (auto [v, dk, w]: adj[u]) dfs1(v);
  ord.push_back(u);
}

void dfs2(int u, int id) {
  comp[u] = id;
  for (auto [v, dk, w]: rev[u]) {
    if (comp[v] == -1) dfs2(v, id);
  }
}

void get_scc() {
  ord.clear();
  dfs1(0);
  reverse(ord.begin(), ord.end());

  comp.assign(3*N+3, -1);
  scc_cnt = 0;
  for (auto u: ord) {
    if (comp[u] == -1) dfs2(u, scc_cnt++);
  }
}

bool compress(vector<vector<pii>> &dag) {
  dag.resize(scc_cnt);

  for (int u=0; u<3*N+3; u++) {
    for (auto [v, dk, w]: adj[u]) {
      if (w && comp[u] == comp[v]) return 0; // infty
      if (comp[u] != comp[v]) dag[comp[u]].push_back({comp[v], w});
    }
  }
  return 1;
}

int dag_dp(vector<vector<pii>> &dag, int u) {
  if (vst[u][0]) return D[u][0];
  vst[u][0] = 1, D[u][0] = 0;
  for (auto [v, w]: dag[u]) {
    D[u][0] = max(D[u][0], dag_dp(dag, v)+w);
  }
  return D[u][0];
}

void solve_infty(int t) {
  // No K, just consider edge weight
  for (int i=0; i<M; i++) {
    int u, v; char c; cin >> u >> v >> c;

    if (c == 'A') make_edge(3*u, 3*v+1, 1);
    if (c == 'B') make_edge(3*u+1, 3*v+2, 1);
    if (c == 'C') make_edge(3*u+2, 3*v, 1);
    
    make_edge(3*u, 3*v, 0);
    make_edge(3*u+1, 3*v+1, 0);
    make_edge(3*u+2, 3*v+2, 0);
  }

  for (int u=1; u<=N; u++) {
    make_edge(0, 3*u, 0);
    make_edge(0, 3*u+1, 0);
    make_edge(0, 3*u+2, 0);
  }

  get_scc();
  vector<vector<pii>> dag;
  bool ok = compress(dag);
  if (!ok) {
    cout << "Case #" << t << endl;
    cout << -1 << endl;
    return;
  }

  for (int i=0; i<scc_cnt; i++) vst[i][0] = 0;
  int ans = dag_dp(dag, 0);
  cout << "Case #" << t << endl;
  cout << ans << endl;
}

bool dp(int u, int k) { // true = has cycle
  vst[u][k] = 1, D[u][k] = 0;
  for (auto [v, dk, w]: adj[u]) {
    if (k-dk < 0) continue;
    if (vst[v][k-dk] == 1) return 1; // to ancestor
    if (vst[v][k-dk] == 0) {
      if (dp(v, k-dk)) return 1;
    }
    D[u][k] = max(D[u][k], D[v][k-dk] + w);
  }
  vst[u][k] = 2;
  return 0;
}

void solve(int t) {
  cin >> N >> M >> K;
  if (K == -1) { solve_infty(t); return; }

  for (int i=0; i<M; i++) {
    int u, v; char c; cin >> u >> v >> c;

    if (c == 'A') adj[3*u].push_back({3*v+1, 0, 1});
    if (c == 'B') adj[3*u+1].push_back({3*v+2, 0, 1});
    if (c == 'C') adj[3*u+2].push_back({3*v, 0, 1});
    
    adj[3*u].push_back({3*v, 1, 0});
    adj[3*u+1].push_back({3*v+1, 1, 0});
    adj[3*u+2].push_back({3*v+2, 1, 0});
  }

  for (int u=1; u<=N; u++) {
    adj[0].push_back({3*u, 0, 0});
    adj[0].push_back({3*u+1, 0, 0});
    adj[0].push_back({3*u+2, 0, 0});
  }

  bool cyc = dp(0, K);
  cout << "Case #" << t << endl;
  cout << (cyc ? -1 : D[0][K]) << endl;
}

void reset() {
  for (int u=0; u<3*N+3; u++) {
    vst[u][0] = vst[u][1] = vst[u][2] = 0;
    adj[u].clear();
    rev[u].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
