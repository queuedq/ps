#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
using lld = long long;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, sub[MN];
vector<int> adj[MN];

void dfs1(int u, int p) {
  sub[u] = 1;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    sub[u] += sub[v];
  }

  // sort by decreasing subtree size
  // this is not the best greedy but works for 20 curses
  sort(all(adj[u]), [&](auto &x, auto &y) {
    return sub[x] > sub[y];
  });
}

void dfs2(int u, int p) {
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs2(v, u);
  }
  cout << u << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(1, 0);
  dfs2(1, 0);

  ////////////////////////////////
  return 0;
}
