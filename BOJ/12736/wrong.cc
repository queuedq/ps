#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
lld N, M, P[MAXN], C[MAXN];
vector<int> adj[MAXN];

pll dfs(int u, lld &ans) {
  if (adj[u].size() == 0) return {C[u], C[u]};

  vector<lld> lines;
  for (auto v: adj[u]) {
    auto [a, b] = dfs(v, ans);
    ans -= (b - a);
    lines.push_back(a);
    lines.push_back(b);
  }
  sort(lines.begin(), lines.end());
  lld l = lines[lines.size()/2-1];
  lld r = lines[lines.size()/2];
  for (auto x: lines) ans += abs(x - l);

  return {C[u]+l, C[u]+r};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=2; i<=N+M; i++) {
    cin >> P[i] >> C[i];
    adj[P[i]].push_back(i);
  }

  lld ans = 0;
  dfs(1, ans);

  assert(ans % 2 == 0);
  cout << ans / 2 << endl;

  ////////////////////////////////
  return 0;
}
