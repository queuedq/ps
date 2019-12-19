#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 5e5 + 5;
int N, L[MAX_N], R[MAX_N];
vector<int> coords, seg;
list<int> inter;
int edges;

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

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    coords.push_back(L[i]);
    coords.push_back(R[i]);
  }
  sort(coords.begin(), coords.end());

  seg.resize(2*N);
  for (int i = 0; i < N; i++) {
    int l = lower_bound(coords.begin(), coords.end(), L[i]) - coords.begin();
    int r = lower_bound(coords.begin(), coords.end(), R[i]) - coords.begin();
    seg[l] = i+1;
    seg[r] = -i-1;
  }

  // for (int i = 0; i < 2*N; i++) cout << seg[i] << " ";
  // cout << endl;

  for (int i = 0; i < 2*N; i++) {
    if (seg[i] > 0) {
      inter.push_back(seg[i]);
    } else {
      // cout << "inter: ";
      // for (auto it = inter.begin(); it != inter.end(); it++) {
      //   cout << *it << " ";
      // }
      // cout << endl;

      for (auto it = prev(inter.end()); ; it--) {
        int v = *it;
        if (v == -seg[i]) {
          inter.erase(it);
          break;
        }
        if (dsu.find(-seg[i]) == dsu.find(v)) {
          // cout << -seg[i] << " " << v << endl;
          cout << "NO" << endl;
          return 0;
        }
        dsu.merge(v, -seg[i]);
        edges++;
      }
    }
  }

  if (edges == N - 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
