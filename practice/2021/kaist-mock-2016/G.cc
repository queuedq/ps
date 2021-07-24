#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, K, D[MN];
vector<pii> adj[MN];

struct Edge {
  int u, v, c;
};
vector<Edge> edges;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<K; i++) {
    int t, a, b, c; cin >> t >> a >> b >> c;
    if (t == 1 || t == 3) {
      adj[b].push_back({a, c});
      edges.push_back({b, a, c});
    }
    if (t == 2 || t == 3) {
      adj[a].push_back({b, -c});
      edges.push_back({a, b, -c});
    }
  }

  for (int i=0; i<N; i++) {
    for (auto [u, v, c]: edges) {
      if (D[v] < D[u] + c) D[v] = max(0, D[u] + c);
    }
  }
  for (auto [u, v, c]: edges) {
    if (D[v] < D[u] + c) { cout << -1 << endl; return 0; }
  }

  int mn = INT_MAX, mx = 0;
  for (int i=1; i<=N; i++) {
    mn = min(mn, D[i]);
    mx = max(mx, D[i]);
  }
  if (mx - mn > 100) { cout << -1 << endl; return 0; }
  cout << mx - mn << endl;

  ////////////////////////////////
  return 0;
}
