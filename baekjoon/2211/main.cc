#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, M;
vector<pii> adj[MAXN];
int dst[MAXN], parent[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (int u=2; u<=N; u++) dst[u] = INT_MAX;

  vector<pii> ans;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dst[u]) continue;
    for (auto [v, w]: adj[u]) {
      if (d+w >= dst[v]) continue;
      dst[v] = d+w;
      parent[v] = u;
      pq.push({dst[v], v});
    }
  }

  cout << N-1 << endl;
  for (int u=2; u<=N; u++) {
    cout << u << " " << parent[u] << endl;
  }

  ////////////////////////////////
  return 0;
}
