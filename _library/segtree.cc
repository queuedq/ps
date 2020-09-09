#include "template.h"

// Coordinate compression
// Returns 1-based index of x in xs
int compress(lld x, const vector<lld> &xs) {
  return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

// range max query + range addition
struct SegTree {
  vector<lld> seg, lazy; // lazy: lazy only
  int size;

  SegTree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    lazy.resize(size*2);
  }

  // lazy only
  void propagate(int n, int nl, int nr) {
    seg[n] += lazy[n]; // times (nr-nl) when range sum query
    if (n < size) {
      lazy[n*2] += lazy[n];
      lazy[n*2+1] += lazy[n];
    }
    lazy[n] = 0;
  }

  // non-lazy only
  void update(int i, lld val) {
    int n = size + i;
    seg[n] = val;
    while (n > 1) {
      n >>= 1;
      seg[n] = max(seg[n*2], seg[n*2+1]);
    }
  }

  void update_range(int l, int r, lld val) { update_range(1, 0, size, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, lld val) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] += val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid, nr, l, r, val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  lld query(int l, int r) { return query(1, 0, size, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr); // lazy only
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return max(query(n*2, nl, mid, l, r), query(n*2+1, mid, nr, l, r));
  }
} seg(100'000);

// Fenwick tree
// Indices are 1-based
struct fenwick_tree {
  vector<lld> A;

  fenwick_tree(int size) { A.resize(size+1); }

  void reset() { fill(A.begin(), A.end(), 0); }

  // Adds x to A[i]
  void add(int i, lld x) {
    assert(1 <= i && i <= A.size()-1);
    for (; i < A.size(); i += i&-i) A[i] += x;
  }

  // Returns sum of A[1..i]
  lld sum(int i) {
    assert(0 <= i && i <= A.size()-1);
    lld s = 0;
    for (; i > 0; i -= i&-i) s += A[i];
    return s;
  }
};

// Usage
int main() {
  // Coordinate compression
  vector<lld> xs = {2, 3, 5, 7, 11};
  lld x = 3;
  lld xi = compress(x, xs);
  assert(xi == 2);
  assert(x == xs[xi-1]);

  // Fenwick Tree
  lld N = 25;
  fenwick_tree F(N);
  for (int i=1; i<=10; i++) F.add(i, i);
  assert(F.sum(0) == 0);
  assert(F.sum(5) == 15);
  assert(F.sum(10) == 55);

  return 0;
}
