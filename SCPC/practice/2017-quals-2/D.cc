#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve(int test) {
  int N, P;
  vector<set<pll>> adj;

  cin >> N;
  adj.resize(N+1);
  for (int i=0; i<N-1; i++) {
    lld a, b, w; cin >> a >> b >> w;
    adj[a].insert({b, w});
    adj[b].insert({a, w});
  }
  cin >> P;

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int u=1; u<=N; u++) {
    if (adj[u].size() == 1) pq.push({adj[u].begin()->second, u});
  }

  lld ans = 0;
  for (int i=0; i<N-P; i++) {
    auto [d, u] = pq.top(); pq.pop();
    auto [v, w] = *adj[u].begin();
    adj[v].erase({u, w});
    if (adj[v].size() == 1) pq.push({d + adj[v].begin()->second, v});
    ans = d;
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
