#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1010;
const int MM = 101010;
const int MQ = 202020;
int N, M, Q;
pii edge[MM];
int del[MM];
vector<int> adj[MN];
int dst[MN];

struct Query { char t; int x; };
Query qry[MQ];

void bfs(int s) {
  queue<pii> q;
  q.push({s, dst[s]});

  while (!q.empty()) {
    auto [u, d] = q.front(); q.pop();
    for (auto v: adj[u]) {
      if (dst[v] <= d+1) continue;
      dst[v] = d+1;
      q.push({v, dst[v]});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    edge[i] = {u, v};
  }
  for (int i=1; i<=Q; i++) {
    char t; int x; cin >> t >> x;
    qry[i] = {t, x};
    if (t == 'U') del[x] = 1;
  }

  // build graph
  for (int i=1; i<=M; i++) {
    if (del[i]) continue;
    auto [u, v] = edge[i];
    adj[u].push_back(v);
  }
  
  fill(dst+1, dst+N+1, INF);
  dst[1] = 0;
  bfs(1);
  
  // query
  vector<int> ans;
  for (int i=Q; i>=1; i--) {
    auto [t, x] = qry[i];

    if (t == 'U') {
      auto [u, v] = edge[x];
      adj[u].push_back(v);
      if (dst[v] <= dst[u]+1) continue;

      dst[v] = dst[u]+1;
      bfs(v);

    } else {
      ans.push_back(dst[x]);
    }
  }

  reverse(all(ans));
  for (auto d: ans) cout << (d == INF ? -1 : d) << endl;

  ////////////////////////////////
  return 0;
}
