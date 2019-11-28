#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1'000'005;
const int MAX_M = 100'005;
int N, M;

struct DSU {
  int parent[MAX_N], size[MAX_N];

  DSU() {
    for (int i = 0; i < MAX_N; i++) {
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
} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int q = 0; q < M; q++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 0) {
      dsu.merge(a, b);
    } else {
      int aa = dsu.find(a);
      int bb = dsu.find(b);
      if (aa == bb) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
