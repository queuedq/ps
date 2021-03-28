#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, M, par[MN], sz[MN];
vector<pii> adj[MN];
bool vst[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  vst[1] = true;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (auto [c, v]: adj[1]) pq.push({c, v});

  int ans = 0;
  while (!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if (vst[u]) continue;
    vst[u] = true;
    ans += w;

    for (auto [c, v]: adj[u]) {
      if (vst[v]) continue;
      pq.push({c, v});
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
