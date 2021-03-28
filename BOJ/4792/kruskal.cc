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
  int c, f, t;
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

bool solve() {
  int n, m, k; cin >> n >> m >> k;
  if (n == 0) return false;

  edge.clear();

  for (int i=0; i<m; i++) {
    char c; int f, t; cin >> c >> f >> t;
    edge.push_back({c == 'B', f, t});
  }

  sort(edge.begin(), edge.end());

  int low = 0;
  for (int i=1; i<=n; i++) { par[i] = i; sz[i] = 1; }
  for (auto [c, f, t]: edge) {
    if (find(f) == find(t)) continue;
    merge(f, t);
    low += c;
  }

  reverse(edge.begin(), edge.end());

  int high = 0;
  for (int i=1; i<=n; i++) { par[i] = i; sz[i] = 1; }
  for (auto [c, f, t]: edge) {
    if (find(f) == find(t)) continue;
    merge(f, t);
    high += c;
  }

  cout << (low <= k && k <= high) << endl;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (solve()) {}

  ////////////////////////////////
  return 0;
}
