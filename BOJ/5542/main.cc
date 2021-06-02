#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 101010;

int N, M, K, Q;
vector<pii> adj[MN];
int dst[MN], node[MN], par[MN], ans[MN];
bool vst[MN];
unordered_set<int> qry[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y, int t) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (qry[x].size() < qry[y].size()) swap(x, y);
  par[y] = x;

  for (auto q: qry[y]) {
    if (qry[x].count(q) != 0) ans[q] = t;
  }
  for (auto q: qry[y]) qry[x].insert(q);
  qry[y].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K >> Q;

  // graph
  for (int i=0; i<M; i++) {
    int a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  // get dst
  fill(dst+1, dst+N+1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  for (int i=0; i<K; i++) {
    int a; cin >> a;
    pq.push({0, a});
  }

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (dst[u] != INF) continue;
    dst[u] = d;

    for (auto [v, w]: adj[u]) {
      if (dst[v] == INF) pq.push({d+w, v});
    }
  }

  // sort nodes by dst
  iota(node+1, node+N+1, 1);
  sort(node+1, node+N+1, [&](int i, int j){ return dst[i] > dst[j]; });

  // process queries
  for (int i=1; i<=N; i++) par[i] = i;

  for (int i=1; i<=Q; i++) {
    int a, b; cin >> a >> b;
    qry[a].insert(i);
    qry[b].insert(i);
  }

  for (int i=1; i<=N; i++) {
    int u = node[i];
    vst[u] = true;
    for (auto [v, w]: adj[u]) {
      if (vst[v]) merge(u, v, dst[u]);
    }
  }

  // print ans
  for (int i=1; i<=Q; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
