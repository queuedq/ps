#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
vector<pii> adj[MAXN];

pii dfs(int u, int p, int d) {
  pii far = {d, u};
  for (auto [v, c]: adj[u]) {
    if (v == p) continue;
    pii w = dfs(v, u, d+c);
    if (far.first < w.first) far = w;
  }
  return far;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  auto [_, u] = dfs(1, 0, 0);
  auto [diam, v] = dfs(u, 0, 0);

  cout << diam << endl;

  ////////////////////////////////
  return 0;
}
