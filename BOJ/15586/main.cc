#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, Q, par[MN], sz[MN], ans[MN];

struct Edge {
  int p, q, r;
  bool operator <(const Edge &e) const { return r < e.r; }
};
vector<Edge> edges;

struct Query {
  int k, v, i;
  bool operator <(const Query &q) const { return k < q.k; }
};
vector<Query> queries;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N-1; i++) {
    int p, q, r; cin >> p >> q >> r;
    edges.push_back({p, q, r});
  }
  for (int i=0; i<Q; i++) {
    int k, v; cin >> k >> v;
    queries.push_back({k, v, i});
  }

  sort(edges.rbegin(), edges.rend());
  sort(queries.rbegin(), queries.rend());

  for (int i=1; i<=N; i++) { par[i] = i; sz[i] = 1; }

  for (int i=0, j=0; i<Q; i++) {
    auto [k, v, idx] = queries[i];
    while (j < N-1 && edges[j].r >= k) {
      merge(edges[j].p, edges[j].q);
      j++;
    }
    ans[idx] = sz[find(v)] - 1;
  }

  for (int i=0; i<Q; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
