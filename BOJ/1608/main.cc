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
int N, M, vst[MN], comp[MN];
vector<int> g[MN], gt[MN], ord;

void dfs1(int u) {
  if (vst[u]) return;
  vst[u] = 1;
  for (auto v: g[u]) dfs1(v);
  ord.push_back(u);
}

void dfs2(int u, int c) {
  comp[u] = c;
  for (auto v: gt[u]) {
    if (!comp[v]) dfs2(v, c);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int u=1; u<=N; u++) {
    int k; cin >> k;
    M += k;
    for (int i=0; i<k; i++) {
      int v; cin >> v;
      g[u].push_back(v);
      gt[v].push_back(u);
    }
  }

  // scc
  for (int u=1; u<=N; u++) dfs1(u);
  reverse(all(ord));

  for (int i=0, c=0; i<N; i++) {
    int u = ord[i];
    if (!comp[u]) dfs2(u, ++c);
  }

  // answer: cut (A, B) with all pairwise edges (a, b), smallest A
  int cut = 0, ans = 0;
  fill(vst, vst+N+1, 0);

  for (int i=0; i<N; i++) {
    int u = ord[i];
    vst[u] = 1;
    cut += sz(g[u]) - sz(gt[u]);
    if (cut == (lld)(i+1) * (N-i-1)) { ans = i+1; break; }
  }

  cout << ans << " ";
  for (int u=1; u<=N; u++) {
    if (vst[u]) cout << u << " ";
  }

  ////////////////////////////////
  return 0;
}
