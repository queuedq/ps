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
int N, M;
struct Edge {
  int u, v, w, id;
  bool operator<(const Edge& E) const { return w < E.w; }
};
vector<Edge> edges;

int par[MN];

void reset() {
  for (int i=1; i<=N; i++) par[i] = i;
}

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) par[y] = x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({u, v, w, i});
  }

  // MinST
  sort(all(edges));
  reset();

  lld minst = 0;
  int t = 0; // bottleneck

  for (auto &e: edges) {
    if (find(e.u) != find(e.v)) {
      merge(e.u, e.v);
      minst += e.w;
      t = max(t, e.w);
    }
  }

  // MaxST with w < bottleneck edges
  reverse(all(edges));
  reset();

  lld maxst = 0;
  vector<Edge> mbst; // max sum mbst

  for (auto &e: edges) {
    if (e.w > t) continue;
    if (find(e.u) != find(e.v)) {
      merge(e.u, e.v);
      maxst += e.w;
      mbst.push_back(e);
    }
  }

  // print ans
  cout << "NO" << endl;
  if (minst < maxst) {
    cout << "YES\n";
    for (auto &e: mbst) cout << e.id << endl;
  } else {
    cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
