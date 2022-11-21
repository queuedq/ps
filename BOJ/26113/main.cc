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
int N, vst[MN], dep[MN], par[MN];
vector<int> adj[MN];

void dfs(int u, int p, int d, int &V, int &E) {
  if (vst[u]) return;
  vst[u] = 1;
  par[u] = p;
  dep[u] = d;
  V++;
  for (auto v: adj[u]) {
    if (u < v) E++;
    dfs(v, u, d+1, V, E);
  }
}

void collect_edges(int u, vector<pii> &edges) {
  for (auto v: adj[u]) {
    if (par[v] == u) collect_edges(v, edges);
    if (dep[v] < dep[u] && v != par[u]) edges.push_back({u, v});
  }
}

void print_path(int u, int v) {
  while (u != v) { cout << u << " "; u = par[u]; }
  cout << v << endl;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*2-3; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // get connected component
  int root = 0, V, E;
  for (int i=1; i<=N; i++) {
    V = 0, E = 0;
    dfs(i, 0, 1, V, E);
    if (V >= 4 && E >= V * 2 - 3) { root = i; break; }
  }
  assert(root != 0);

  // get back edges
  vector<pii> edges;
  collect_edges(root, edges);

  // get duplicate distances
  vector<pii> D(N);
  lld len = 0;
  pii e1 = {0, 0}, e2 = {0, 0};
  for (auto [u, v]: edges) {
    auto d = dep[u] - dep[v];
    if (D[d] != pii(0, 0)) {
      len = d+1;
      e1 = D[d], e2 = {u, v};
      break;
    }
    D[d] = {u, v};
  }

  // print paths
  if (len > 0) {
    cout << len << endl;
    print_path(e1.first, e1.second);
    print_path(e2.first, e2.second);
  } else { // no duplicate distance
    // cycle back edges: (N-2) and (N-1, 2)
    cout << V - 1 << endl;
    print_path(D[N-2].first, D[N-2].second);
    
    auto [u, v] = D[N-1];
    while (u != v) {
      cout << u << " ";
      if (u == D[2].first) u = D[2].second; // jump
      else u = par[u];
    }
    cout << v << endl;
  }

  ////////////////////////////////
  return 0;
}
