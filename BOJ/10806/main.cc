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

vector<int> tree[MN], leaf;


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

void dfs3(int u, int p) {
  if (sz(tree[u]) == 1) leaf.push_back(u);
  for (auto v: tree[u]) {
    if (v == p) continue;
    dfs3(v, u);
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
  dfs3(1, 0);

  int L = sz(leaf);
  cout << (L+1)/2 << endl;
  for (int i=0; i<(L+1)/2; i++) {
    cout << rep[leaf[i]] << " " << rep[leaf[i+L/2]] << endl;
  }

  ////////////////////////////////
  return 0;
}
