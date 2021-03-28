#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int p, w, c, v, par[MN];

struct Edge {
  int s, e, w;
  bool operator <(const Edge &E) const { return w < E.w; }
};
vector<Edge> edge;

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  par[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> p >> w >> c >> v;
  for (int i=0; i<w; i++) {
    int s, e, width; cin >> s >> e >> width;
    edge.push_back({s, e, width});
  }
  for (int i=0; i<p; i++) par[i] = i;

  sort(edge.begin(), edge.end());
  reverse(edge.begin(), edge.end());

  int ans = 1000;
  for (auto i=0; i<w; i++) {
    if (find(c) == find(v)) break;
    merge(edge[i].s, edge[i].e);
    ans = edge[i].w;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
