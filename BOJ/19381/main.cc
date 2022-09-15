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
lld N, C[MN], ans;
vector<int> adj[MN];
priority_queue<lld> pq[MN];

void dfs(int u, int d) {
  for (auto v: adj[u]) {
    dfs(v, d+1);
    if (sz(pq[u]) < sz(pq[v])) swap(pq[u], pq[v]);
    while (!pq[v].empty()) { pq[u].push(pq[v].top()); pq[v].pop(); }
  }
  pq[u].push(C[u] + d);
  pq[u].push(C[u] + d);
  ans += pq[u].top() - (C[u] + d);
  pq[u].pop();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> C[1];
  for (int i=2; i<=N; i++) {
    int p; cin >> p >> C[i];
    adj[p].push_back(i);
  }

  dfs(1, 0);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
