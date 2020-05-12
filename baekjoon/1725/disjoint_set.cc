#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

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

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;
pll A[MAXN];
bool vst[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A[i] = {a, i+1};
  }

  sort(A, A+N, greater<pll>());

  DSU dsu(N+2);

  lld ans = 0;
  for (int i=0; i<N; i++) {
    auto [a, j] = A[i];
    vst[j] = true;
    if (vst[j-1]) dsu.merge(j-1, j);
    if (vst[j+1]) dsu.merge(j+1, j);

    ans = max(ans, a * dsu.size[dsu.find(j)]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
