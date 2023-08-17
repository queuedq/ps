#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, K;
vector<pii> adj[MN];
vector<int> D[MN]; // D[i][k]: root color = 0, k nodes color = 1
vector<vector<pii>> E[MN]; // E[i][j][k]: j-th subtree's optimal (cnt, color)
int color[MN];

pair<vector<int>, vector<pii>> dp(vector<int> &A, vector<int> &B, int w) {
  int a = sz(A), b = sz(B);
  vector<int> D(a+b, INT_MAX);
  vector<pii> E(a+b);

  for (int i=0; i<a; i++) {
    for (int j=0; j<b; j++) {
      int d = A[i] + B[j] + w; // same root color
      if (d < D[i+j]) D[i+j] = d, E[i+j] = {j, 0};

      d = A[i] + B[j]; // diff root color
      if (d < D[i+b-j]) D[i+b-j] = d, E[i+b-j] = {j, 1};
    }
  }
  return {D, E};
}

void dfs(int u, int p) {
  D[u] = {0};
  E[u].resize(sz(adj[u]));

  for (int i=0; i<sz(adj[u]); i++) {
    auto [v, w] = adj[u][i];
    if (v == p) continue;
    dfs(v, u);

    auto [D1, E1] = dp(D[u], D[v], w);
    D[u] = D1;
    E[u][i] = E1;
  }
}

void traceback(int u, int p, int k, int c) {
  color[u] = c;

  for (int i=sz(adj[u])-1; i>=0; i--) {
    auto [v, w] = adj[u][i];
    if (v == p) continue;
    
    auto [k1, c1] = E[u][i][k];
    traceback(v, u, k1, c ^ c1);
    if (c1 == 0) k -= k1;
    else k -= sz(D[v]) - k1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1, 0);

  if (D[1][K] < D[1][N-K]) traceback(1, 0, K, 0);
  else traceback(1, 0, N-K, 1);

  cout << min(D[1][K], D[1][N-K]) << endl;
  for (int u=1; u<=N; u++) {
    if (color[u]) cout << u << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
