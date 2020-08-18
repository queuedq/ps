#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 50'005;
int N, D[MAXN];
vector<pii> adj[MAXN];

pii dfs(int u, int p, int dist) {
  D[u] = max(D[u], dist);
  pii high = {0, u};

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    pii h = dfs(v, u, dist+w);
    if (h.first + w > high.first) {
      high = h;
      high.first += w;
    }
  }

  return high;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  auto [d0, s] = dfs(1, 1, 0);
  auto [d1, e] = dfs(s, s, 0);
  dfs(e, e, 0);

  for (int i=1; i<=N; i++) {
    cout << D[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
