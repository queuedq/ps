#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, M, Q;
int x[MN], y[MN];

struct Node {
  int u, v;
  int dist() { return (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]); }
  int hash() { return (u-1) * N + (v-1); }
};

struct Edge {
  Node p, q;
  int cost;
  bool operator<(Edge E) const { return cost < E.cost; }
};

vector<Edge> E;
int par[MN*MN];
set<int> qry[MN*MN]; // query numbers in each component
int ans[MN*MN/2];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> x[i] >> y[i];

  cin >> M;
  for (int i=1; i<=M; i++) {
    int u, v; cin >> u >> v;
    for (int t=1; t<=N; t++) {
      if (t == u || t == v) continue;
      int d1 = Node({t, u}).dist();
      int d2 = Node({t, v}).dist();
      int cost = min(d1, d2);
      E.push_back({{u, t}, {v, t}, cost});
      E.push_back({{t, u}, {t, v}, cost});
    }
  }

  cin >> Q;
  for (int i=1; i<=Q; i++) {
    int u, v; cin >> u >> v;
    qry[Node({u, v}).hash()].insert(i);
    qry[Node({v, u}).hash()].insert(i);
  }

  // solve
  for (int i=0; i<N*N; i++) par[i] = i;
  sort(all(E));
  reverse(all(E));

  for (auto [p, q, c]: E) {
    int a = find(p.hash()), b = find(q.hash());
    if (a == b) continue;
    if (sz(qry[a]) < sz(qry[b])) swap(a, b);

    // merge sets
    for (auto i: qry[b]) {
      if (qry[a].count(i)) ans[i] = c;
      else qry[a].insert(i);
    }
    qry[b].clear();
    par[b] = a;
  }

  for (int i=1; i<=Q; i++) {
    cout << fixed << setprecision(9) << sqrt(ans[i]) << endl;
  }
  
  ////////////////////////////////
  return 0;
}
