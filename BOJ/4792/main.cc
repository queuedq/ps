#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

bool solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<pii>> adj(n+1);
  if (n == 0) return false;

  for (int i=0; i<m; i++) {
    char c; int f, t; cin >> c >> f >> t;
    adj[f].push_back({t, c == 'B'});
    adj[t].push_back({f, c == 'B'});
  }

  int min_cost = 0;
  deque<pii> dq(1, {1, 0});
  vector<bool> vst(n+1);

  while (!dq.empty()) {
    auto [u, c] = dq.front(); dq.pop_front();
    if (vst[u]) continue;
    vst[u] = true;
    min_cost += c;

    for (auto [v, d]: adj[u]) {
      if (vst[v]) continue;
      if (d == 0) dq.push_front({v, d});
      else dq.push_back({v, d});
    }
  }

  int max_cost = 0;
  dq.push_back({1, 0});
  vst.assign(n+1, false);

  while (!dq.empty()) {
    auto [u, c] = dq.back(); dq.pop_back();
    if (vst[u]) continue;
    vst[u] = true;
    max_cost += c;

    for (auto [v, d]: adj[u]) {
      if (vst[v]) continue;
      if (d == 0) dq.push_front({v, d});
      else dq.push_back({v, d});
    }
  }

  cout << (min_cost <= k && k <= max_cost) << endl;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (solve()) {}

  ////////////////////////////////
  return 0;
}
