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

int dfs(int u, int p) {
  int res = 0;
  for (auto [v, c]: adj[u]) {
    if (v == p) continue;
    res = max(res, dfs(v, u) + c);
  }
  return res;
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

  int diam = 0;
  for (int i=1; i<=N; i++) {
    diam = max(diam, dfs(i, 0));
  }

  cout << diam << endl;

  ////////////////////////////////
  return 0;
}
