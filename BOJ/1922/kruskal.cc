#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, M, par[MN], sz[MN];

struct Edge {
  int a, b, c;
  bool operator<(const Edge &e) const { return c < e.c; }
};
vector<Edge> edge;

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

  cin >> N >> M;
  for (int i=1; i<=N; i++) { par[i] = i; sz[i] = 1; }

  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    edge.push_back({a, b, c});
  }

  sort(edge.begin(), edge.end());
  int ans = 0;
  for (int i=0; i<M; i++) {
    if (find(edge[i].a) == find(edge[i].b)) continue;
    merge(edge[i].a, edge[i].b);
    ans += edge[i].c;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
