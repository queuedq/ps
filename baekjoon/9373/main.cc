#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct DSU {
  vector<int> parent, size;

  DSU(int s) {
    parent.resize(s); size.resize(s);
    for (int i = 0; i < s; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }

  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
  }
};

using Edge = pair<double, pair<double, double>>;

const int MAXN = 1005;
int n;
double w, x[MAXN], y[MAXN], r[MAXN];

double dist(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return max(sqrt(dx*dx + dy*dy) - r[i] - r[j], 0.);
}

double calc() {
  cin >> w >> n;
  for (int i=0; i<n; i++) cin >> x[i] >> y[i] >> r[i];

  vector<Edge> edge;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      edge.push_back({dist(i, j), {i, j}});
    }
  }

  for (int i=0; i<n; i++) {
    edge.push_back({max(x[i]-r[i], 0.), {i, n}});
    edge.push_back({max(w-x[i]-r[i], 0.), {i, n+1}});
  }

  edge.push_back({w, {n, n+1}});

  sort(edge.begin(), edge.end());

  DSU dsu(n+2);
  for (auto [d, e]: edge) {
    auto [i, j] = e;
    dsu.merge(i, j);
    if (dsu.find(n) == dsu.find(n+1)) return d/2;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cout << fixed << setprecision(9) << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
