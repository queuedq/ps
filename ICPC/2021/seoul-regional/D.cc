#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, M, adj[MN][MN], color[MN], ok=true, cnt;
vector<int> diff;
int G, D[MN][MN*2];

void dfs(int u, int c) {
  if (color[u]) {
    if (color[u] != c) ok = false;
    return;
  }
  color[u] = c;
  if (c == 1) cnt++;
  else cnt--;

  for (int v=1; v<=N; v++) {
    if (!adj[u][v]) continue;
    dfs(v, 3-c);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    fill(adj[i]+1, adj[i]+N+1, 1);
    adj[i][i] = 0;
  }
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v;
    adj[u][v]--;
    adj[v][u]--;
  }
  // for (int i=1; i<=N; i++) {
  //   for (int j=1; j<=N; j++) {
  //     cout << adj[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int u=1; u<=N; u++) {
    if (!color[u]) {
      cnt = 0;
      dfs(u, 1);
      diff.push_back(abs(cnt));
    }
  }
  // for (int u=1; u<=N; u++) cout << color[u] << " "; cout << endl;

  G = diff.size();

  if (!ok) { cout << -1 << endl; return 0; }

  D[0][MN] = 1;
  for (int i=0; i<G; i++) {
    for (int j=0; j<MN*2; j++) {
      if (j-diff[i] >= 0 && D[i][j-diff[i]]) D[i+1][j] = 1;
      if (j+diff[i] < MN*2 && D[i][j+diff[i]]) D[i+1][j] = 1;
    }
  }

  int ans = MN;
  for (int i=0; i<MN*2; i++) {
    if (D[G][i]) ans = min(ans, abs(i - MN));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
