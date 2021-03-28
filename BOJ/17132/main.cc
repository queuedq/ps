#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 100005;
int N;

struct DSU {
  int parent[MAX_N], size[MAX_N];

  DSU() {
    for (int i = 0; i < MAX_N; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  int getSize(int x) {
    return size[find(x)];
  }

  void join(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] = size[x] + size[y];
  }
} dsu;

struct Edge {
  lld x, y, w;
} edges[MAX_N];

bool cmp(Edge a, Edge b) {
  return a.w > b.w;
}

void input() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    lld x, y, w; cin >> x >> y >> w;
    edges[i] = {x, y, w};
  }
  sort(edges, edges + N - 1, cmp);
}

lld sweep() {
  lld ans = 0;
  for (int i = 0; i < N - 1; i++) {
    Edge e = edges[i];
    ans += e.w * dsu.getSize(e.x) * dsu.getSize(e.y);
    dsu.join(e.x, e.y);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  cout << sweep() << endl;

  ////////////////////////////////
  return 0;
}
