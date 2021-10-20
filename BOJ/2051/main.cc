#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// 1-based index
const int MN = 1005;
int N, M, S[MN], T[MN], vst[MN], rvst[MN], cnt, lcnt, rcnt;
vector<int> adj[MN];

bool match_node(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;

  for (int v: adj[u]) {
    if (!T[v] || match_node(T[v])) {
      S[u] = v; T[v] = u;
      return 1;
    }
  }
  return 0;
}

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = 1; lcnt++;

  for (int v: adj[u]) {
    if (rvst[v]) continue;
    rvst[v] = 1; rcnt++;
    if (T[v]) dfs(T[v]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int u=1; u<=N; u++) {
    int k; cin >> k;
    for (int j=0; j<k; j++) {
      int v; cin >> v;
      adj[u].push_back(v);
    }
  }

  // bipartite matching
  for (int u=1; u<=N; u++) {
    fill(vst+1, vst+N+1, false);
    cnt += match_node(u);
  }

  // dfs augmenting paths
  fill(vst+1, vst+N+1, false);
  for (int u=1; u<=N; u++) { if (!S[u]) dfs(u); }

  // output
  cout << cnt << endl;

  cout << N-lcnt << " ";
  for (int i=1; i<=N; i++) { if (!vst[i]) cout << i << " "; }
  cout << endl;

  cout << rcnt << " ";
  for (int i=1; i<=M; i++) { if (rvst[i]) cout << i << " "; }
  cout << endl;

  ////////////////////////////////
  return 0;
}
