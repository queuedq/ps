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
int N, T, Q, A[MN], par[MN];
vector<pii> adj[MN];
priority_queue<pii, vector<pii>, greater<pii>> S[MN];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void dfs(int u, int p, int dep) {
  if (A[u]) S[u].push({dep, u});

  for (auto [v, w]: adj[u]) {
    if (v == p) continue;
    dfs(v, u, dep + w);
    if (sz(S[u]) < sz(S[v])) swap(S[u], S[v]);
    while (!S[v].empty()) {
      auto [d, x] = S[v].top(); S[v].pop();
      if (d - dep <= T) S[u].push({d, x});
    }
  }

  if (!S[u].empty()) {
    auto [d, x] = S[u].top(); S[u].pop(); // hub for other nodes

    while (!S[u].empty()) {
      auto [e, y] = S[u].top();
      if (d + e - dep*2 > T) break;
      S[u].pop();
      par[y] = x; // reachable to hub
    }

    S[u].push({d, x});
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> T;
  for (int u=1; u<=N; u++) cin >> A[u];
  for (int i=0; i<N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int u=1; u<=N; u++) par[u] = u;
  dfs(1, 0, 0);

  // query
  cin >> Q;
  for (int q=0; q<Q; q++) {
    int u, v; cin >> u >> v;
    cout << (find(u) == find(v)) << endl;
  }

  ////////////////////////////////
  return 0;
}
 