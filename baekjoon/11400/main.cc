#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
int N, M;
vector<int> adj[MAXN];

int id, dfn[MAXN], low[MAXN];
vector<pii> cut;

void dfs(int u, int p) {
  dfn[u] = low[u] = ++id;
  for (auto v: adj[u]) {
    if (v == p) continue;
    if (dfn[v]) {
      low[u] = min(low[u], dfn[v]);
      continue;
    }
    dfs(v, u);
    low[u] = min(low[u], low[v]);
    if (low[v] > dfn[u]) {
      if (u < v) cut.push_back({u, v});
      else cut.push_back({v, u});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=1; i<=N; i++) {
    if (!dfn[i]) dfs(i, 0);
  }

  sort(cut.begin(), cut.end());
  cout << cut.size() << endl;
  for (auto [a, b]: cut) {
    cout << a << " " << b << endl;
  }

  ////////////////////////////////
  return 0;
}
