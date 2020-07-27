#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
lld N, D[MAXN][4];
vector<int> adj[MAXN];

void dfs(int u, int p) {
  D[u][1] = adj[u].size() - (p != 0);
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    D[u][2] += D[v][1];
    D[u][3] += D[v][2];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  lld d = 0, g = 0;

  dfs(1, 0);

  for (int u=1; u<=N; u++) {
    d += D[u][3] + D[u][1] * D[u][2] - D[u][2];
  }

  for (int u=1; u<=N; u++) {
    lld c = adj[u].size();
    g += c * (c-1) * (c-2) / 6;
  }

  // cout << d << " " << g << endl;
  if (d > g*3) cout << "D" << endl;
  else if (d < g*3) cout << "G" << endl;
  else cout << "DUDUDUNGA" << endl;

  ////////////////////////////////
  return 0;
}
