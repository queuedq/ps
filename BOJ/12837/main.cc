#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct SegTree {
  vector<lld> seg;
  int size;

  SegTree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
  }

  void update(int i, lld val) {
    int n = size + i;
    seg[n] += val;
    while (n > 1) {
      n >>= 1;
      seg[n] = seg[n*2] + seg[n*2+1];
    }
  }

  lld query(int l, int r) { return query(1, 0, size, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return query(n*2, nl, mid, l, r) + query(n*2+1, mid, nr, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, Q; cin >> N >> Q;
  SegTree seg(N+1);

  for (int i=0; i<Q; i++) {
    int t, p, q; cin >> t >> p >> q;
    if (t == 1) seg.update(p, q);
    else cout << seg.query(p, q+1) << endl;
  }

  ////////////////////////////////
  return 0;
}
