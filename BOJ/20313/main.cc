#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
const int MK = 105;
int N, M, A, B, K;
vector<pll> edges;
vector<pll> adj[MN][MK];
bool vst[MN][MK];
lld dst[MN][MK];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> A >> B;
  for (int i=0; i<M; i++) {
    lld u, v, t; cin >> u >> v >> t;
    edges.push_back({u, v});
    adj[u][0].push_back({v, t});
    adj[v][0].push_back({u, t});
  }
  cin >> K;
  for (int i=1; i<=K; i++) {
    for (auto [u, v]: edges) {
      lld t; cin >> t;
      adj[u][i].push_back({v, t});
      adj[v][i].push_back({u, t});
    }
  }

  priority_queue<pair<lld, pii>> pq;
  pq.push({0, {A, 0}});

  while (!pq.empty()) {
    auto [d, pos] = pq.top(); pq.pop();
    auto [u, k] = pos;
    d = -d;
    if (u == B) { cout << d << endl; return 0; }

    for (int i=k; i<=K; i++) {
      if (vst[u][i]) continue;
      vst[u][i] = true;
      dst[u][i] = d;
      for (auto [v, t]: adj[u][i]) {
        if (vst[v][i]) continue;
        pq.push({-(d+t), {v, i}});
      }
    }
  }

  ////////////////////////////////
  return 0;
}
