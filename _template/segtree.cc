#include "template.cc"

int compress(vector<int> coords, int x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

// range max query + range addition
struct SegTree {
  vector<int> seg, lazy; // lazy: lazy only
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
  void update(int i, int val) {
    int n = size + i;
    seg[n] = val;
    while (n > 1) {
      n >>= 1;
      seg[n] = max(seg[n*2], seg[n*2+1]);
    }
  }

  void update_range(int l, int r, int val) { update_range(1, 0, size, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, int val) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] += val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid, nr, l, r, val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  int query(int l, int r) { return query(1, 0, size, l, r); }
  int query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr); // lazy only
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return max(query(n*2, nl, mid, l, r), query(n*2+1, mid, nr, l, r));
  }
} seg(100'000);

class Fenwick {
public:
  vector<lld> arr;

  Fenwick(int size) { arr.resize(size); }

  void reset() { fill(arr.begin(), arr.end(), 0); }

  lld query(int i) {
    i++; // with: sum {<= i} / without: sum {< i}
    int s = 0;
    while (i > 0) { s += arr[i]; i -= i & -i; }
    return s;
  }

  void update(int i, int val) {
    i++; // to make i > 0
    while (i < arr.size()) { arr[i] += val; i += i & -i; }
  }
} bit(100'000);
