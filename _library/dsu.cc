#include "template.cc"

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
} dsu(100'000);
