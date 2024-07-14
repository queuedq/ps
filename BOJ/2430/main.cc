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
map<int, int> adj[MN]; // u -> v -> type
// types: >0 (path length), 0 (symmetric), -1 (error)

int YES() { cout << "YES" << endl; return 0; }
int NO() { cout << "NO" << endl; return 0; }

void remove_edge(int u, int v) { adj[u].erase(v); adj[v].erase(u); }

void add_edge(int u, int v, int c) {
  if (adj[u].count(v) == 0) adj[u][v] = adj[v][u] = c;
  else if (adj[u][v] % 2 == 0 && c % 2 == 0) adj[u][v] = adj[v][u] = 0;
  else adj[u][v] = adj[v][u] = -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u].insert({v, 1});
    adj[v].insert({u, 1});
  }

  // find root and deg 2 nodes
  vector<int> P;
  for (int u=1; u<=N; u++) {
    if (sz(adj[u]) == 2) P.push_back(u);
  }
  if (sz(P) == N) return N%2 == 0 ? YES() : NO(); // edge case: cycle

  // compress paths
  for (auto u: P) {
    if (sz(adj[u]) != 2) return NO(); // edge case: self-loop path
    auto it = adj[u].begin();
    auto [s, a] = *it++;
    auto [t, b] = *it++;
    remove_edge(u, s);
    remove_edge(u, t);
    add_edge(s, t, a+b);
  }

  // merge symmetric edges
  stack<pii> S;
  for (int u=1; u<=N; u++) {
    for (auto [v, c]: adj[u]) if (u < v) {
      if (c == -1) return NO();
      if (c == 0 && sz(adj[u]) == 2 && sz(adj[v]) == 2) S.push({u, v});
    }
  }

  while (!S.empty()) {
    auto [u, v] = S.top(); S.pop();
    if (sz(adj[u]) != 2 || sz(adj[v]) != 2) continue; // cycle merged
    int s, t, a, b;
    for (auto [x, c]: adj[u]) if (x != v) s = x, a = c;
    for (auto [x, c]: adj[v]) if (x != u) t = x, b = c;
    if (s == t || a == 0 || b == 0 || a != b) return NO();
    remove_edge(s, u);
    remove_edge(u, v);
    remove_edge(v, t);
    add_edge(s, t, 0);
    if (adj[s][t] == 0 && sz(adj[s]) == 2 && sz(adj[t]) == 2) S.push({s, t});
  }

  // check if only one symmetric edge left
  int cnt = 0;
  for (int u=1; u<=N; u++) {
    if (sz(adj[u]) >= 2) return NO();
    if (sz(adj[u]) == 1) {
      auto [v, c] = *adj[u].begin();
      if (c % 2 != 0) return NO();
      cnt++;
    }
  }
  return cnt == 2 ? YES() : NO();

  ////////////////////////////////
  return 0;
}
