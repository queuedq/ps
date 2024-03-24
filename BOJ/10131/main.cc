#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, C[MN], dst[MN], mx[MN];
vector<int> adj[MN];

void dfs(int u, int p) {
  vector<pii> sub;
  for (auto v: adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    dst[v] += 2, mx[v]++; // u -> v edge
    sub.push_back({mx[v] - dst[v], dst[v]});
  }
  sort(sub.rbegin(), sub.rend()); // descending additional time

  dst[u] = 0;
  mx[u] = C[u];
  for (auto [w, d]: sub) {
    dst[u] += d;
    mx[u] = max(mx[u], dst[u] + w);
  }
  mx[u] = max(mx[u], dst[u]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> C[i];
  for (int i=1; i<N; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  mx[1] = max(mx[1], dst[1] + C[1]);
  cout << mx[1] << endl;

  ////////////////////////////////
  return 0;
}
