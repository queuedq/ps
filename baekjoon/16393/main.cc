#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// Disjoint set union
// 0-based index
struct disjoint_set {
  vector<int> p, s;

  disjoint_set(int sz) {
    p.resize(sz); s.resize(sz);
    for (int i = 0; i < sz; i++) {
      p[i] = i;
      s[i] = 1;
    }
  }

  // Find the set number containing x
  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  // Merge two sets
  // Note: "union" is a keyword in C++
  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
  }

  // Utility functions
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return s[find(x)]; }
};

////////////////////////////////////////////////////////////////
const int MAXN = 2505;
int N;
int A[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<pair<int, pii>> edges;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      cin >> A[i][j];
      if (i < j) edges.push_back({A[i][j], {i, j}});
    }
  }

  sort(edges.begin(), edges.end());
  disjoint_set D(N+1);

  for (auto [w, e]: edges) {
    auto [i, j] = e;
    if (D.same(i, j)) continue;
    cout << i << " " << j << endl;
    D.merge(i, j);
  }

  ////////////////////////////////
  return 0;
}
