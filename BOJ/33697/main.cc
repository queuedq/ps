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
int N, M, Q;
vector<int> adj_up[MN], adj_down[MN];
pii qry_up[MN], qry_down[MN]; // queries

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=1; i<=M; i++) {
    int x, y; cin >> x >> y;
    adj_up[x].push_back(y);
    adj_down[y].push_back(x);
  }

  for (int q=1; q<=Q; q++) {
    int x, d, c; cin >> x >> d >> c;
    if (d == 1) qry_up[x] = {q, c};
    else qry_down[x] = {q, c};
  }

  // propagate up
  for (int u=1; u<=N; u++) {
    for (auto v: adj_down[u]) qry_up[u] = max(qry_up[u], qry_up[v]);
  }

  // propagate down
  for (int u=N; u>=1; u--) {
    for (auto v: adj_up[u]) qry_down[u] = max(qry_down[u], qry_down[v]);
  }

  // print
  for (int u=1; u<=N; u++) {
    cout << max(qry_up[u], qry_down[u]).second;
    cout << (u < N ? " " : "\n");
  }

  ////////////////////////////////
  return 0;
}
