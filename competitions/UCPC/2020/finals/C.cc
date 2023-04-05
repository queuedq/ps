#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAXN = 505;
const lld MOD = 1e9+7;

int N, adj[MAXN][MAXN], outdeg[MAXN], indeg[MAXN], vst[MAXN];

int dfs(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;
  int size = 1;
  for (int v=0; v<N; v++) {
    if (adj[u][v]) size += dfs(v);
  }
  return size;
}

lld factorial(lld n) {
  lld ans = 1;
  for (lld i=1; i<=n; i++) ans = ans * i % MOD;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int u=0; u<N; u++) {
    for (int v=0; v<N; v++) {
      int e; cin >> e;
      if (u != v && e) {
        adj[u][v] = 1;
        outdeg[u]++;
        indeg[v]++;
      }
    }
  }

  lld ans = 1;
  queue<int> q;
  for (int u=0; u<N; u++) {
    if (indeg[u] == 0 && outdeg[u] != 0) q.push(u);
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();

    int out = 0, cnt = 0;
    for (int v=0; v<N; v++) {
      if (adj[u][v]) {
        if (outdeg[v] == out) cnt++;
        else if (outdeg[v] > out) {
          out = outdeg[v];
          cnt = 1;
        }
      }
    }

    ans = ans * cnt % MOD;

    for (int v=0; v<N; v++) {
      if (adj[u][v]) {
        adj[u][v] = 0;
        outdeg[u]--;
        indeg[v]--;
        if (indeg[v] == 0 && outdeg[v] != 0) q.push(v);
      }
    }
  }

  for (int u=0; u<N; u++) {
    int size = dfs(u);
    if (size > 0) ans = ans * factorial(size-1) % MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
