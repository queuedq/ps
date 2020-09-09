#include "template.h"

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

// Usage
int main() {
  const int size = 25;
  disjoint_set D(size);

  for (int i=0; i<20; i++) D.merge(i, i+5);
  assert(D.find(3) == D.find(23));
  assert(D.same(3, 23));
  assert(D.size(13) == 5);

  return 0;
}
