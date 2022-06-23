#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, R, C[MN], S[MN], par[MN], vst[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  par[u] = p;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> R;
  for (int i=1; i<=N; i++) {
    cin >> C[i];
    S[i] = 1;
  }
  S[0] = 1;

  for (int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(R, 0);

  int ans = 0;
  for (int t=0; t<N; t++) {
    // find max C[u]/S[u]
    float mx = 0;
    int u = 0;
    for (int i=1; i<=N; i++) {
      if (vst[i]) continue;
      float cost = (float)C[i] / S[i];
      tie(mx, u) = max(make_pair(mx, u), make_pair(cost, i));
    }

    // merge u with par
    vst[u] = 1;
    int p = par[u];
    ans += C[u] * S[p];
    C[p] += C[u];
    S[p] += S[u];
    for (int i=1; i<=N; i++) {
      if (vst[i]) continue;
      if (par[i] == u) par[i] = p;
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
