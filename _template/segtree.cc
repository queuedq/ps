#include "template.cc"

template<class T>
int compress(vector<T> coords, int x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}


class SegTree {
public:
  vector<lld> arr;
  static int start;

  SegTree(int size) {
    int arrSize = 1;
    while (arrSize < size * 2) { arrSize <<= 1; }
    arr.resize(arrSize);
    start = arrSize / 2;
  }

  void reset() { fill(arr.begin(), arr.end(), 0); }

  void update(int pos, int value) {
    int node = start + pos;
    arr[node] = value;
    while (node > 1) {
      node /= 2;
      arr[node] = arr[node*2] + arr[node*2+1];
    }
  }

  lld query(int l, int r) { return query(1, 0, start, l, r); }
  lld query(int node, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return arr[node];
    int mid = (nl + nr) / 2;
    return query(node*2, nl, mid, l, r) + query(node*2+1, mid, nr, l, r);
  }
} seg(100'000);


class Fenwick {
public:
  vector<lld> arr;

  Fenwick(int size) { arr.resize(size); }

  void reset() { fill(arr.begin(), arr.end(), 0); }

  lld query(int i) {
    i++; // Query index should be > 0
    int s = 0;
    while (i > 0) {
      s += arr[i];
      i -= i & -i;
    }
    return s;
  }

  void update(int i, int val) {
    i++;
    while (i < arr.size()) {
      arr[i] += val;
      i += i & -i;
    }
  }
} fenwick(100'000);
