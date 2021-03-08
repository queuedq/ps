#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1e5+5;
int N, D[MN][20], mn[MN][2];
vector<int> adj[MN];

int dfs(int u, int p) {
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int c=1; c<=20; c++) {
      if (c != mn[v][0]) D[u][c] += D[v][mn[v][0]];
      else D[u][c] += D[v][mn[v][1]];
    }
  }

  D[u][0] = INF;
  for (int c=1; c<=20; c++) {
    D[u][c] += c;
    if (D[u][c] < D[u][mn[u][0]]) mn[u][1] = mn[u][0], mn[u][0] = c;
    else if (D[u][c] < D[u][mn[u][1]]) mn[u][1] = c;
  }

  return D[u][mn[u][0]];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << dfs(1, 0) << endl;

  ////////////////////////////////
  return 0;
}
