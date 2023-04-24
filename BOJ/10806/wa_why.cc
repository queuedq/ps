#include <algorithm>
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
map<pii, int> mul; // multi-edge
int idx, dfn[MN], low[MN];
int bcnt, color[MN], rep[MN];

vector<int> tree[MN];
vector<pii> matching;
pii up[MN]; // 1 or 2 paths escaping subtree


void dfs1(int u, int p) {
  dfn[u] = low[u] = ++idx;

  for (auto v: adj[u]) {
    if (v == p && mul[{u, v}] == 1) continue;
    if (dfn[v]) { low[u] = min(low[u], dfn[v]); continue; }
    dfs1(v, u);
    low[u] = min(low[u], low[v]);
  }
}

void dfs2(int u, int c) {
  if (low[u] == dfn[u]) c = ++bcnt;
  color[u] = c;
  rep[c] = u;

  for (auto v: adj[u]) {
    if (color[v]) continue;
    dfs2(v, c);
  }
}

void dp(int u, int p) { // subtree all covered 
  if (sz(tree[u]) == 1) up[u] = {u, 0};

  for (auto v: tree[u]) {
    if (v == p) continue;
    dp(v, u);
    auto [a, b] = up[u];
    auto [c, d] = up[v];
    if (a == 0) { up[u] = up[v]; continue; }
    if (b || d) { // cross-match
      matching.push_back({a, c});
      if (b) up[u] = {b, d};
      else up[u] = {d, b};
    } else { // delegate
      up[u] = {a, c};
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    if (mul[{u, v}] == 0) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    mul[{u, v}]++;
    mul[{v, u}]++;
  }

  // bcc
  dfs1(1, 0);
  dfs2(1, 0);
  if (bcnt == 1) { cout << 0 << endl; return 0; }

  // make tree
  for (int u=1; u<=N; u++) {
    for (auto v: adj[u]) {
      int cu = color[u], cv = color[v];
      if (cu <= cv) continue;
      tree[cu].push_back(cv);
      tree[cv].push_back(cu);
    }
  }

  // connect leaves
  dp(1, 0);
  auto [a, b] = up[1];
  if (b) matching.push_back({a, b});
  else matching.push_back({a, matching[0].first});

  cout << sz(matching) << endl;
  for (auto [a, b]: matching) cout << rep[a] << " " << rep[b] << endl;

  ////////////////////////////////
  return 0;
}
