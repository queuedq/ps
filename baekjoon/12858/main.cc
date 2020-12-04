#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct segtree {
  vector<lld> val, diff;
  int size;

  segtree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    val.assign(size*2, 0);
    diff.assign(size*2, 0);
  }

  void propagate(int n) {
    if (n < size) {
      val[n*2] += val[n];
      val[n*2+1] += val[n];
      val[n] = 0;
    }
  }

  void add_diff(int i, lld v) {
    i += size;
    diff[i] += v;
    for (i /= 2; i >= 1; i /= 2) {
      diff[i] = gcd(diff[i*2], diff[i*2+1]);
    }
  }

  void range_add(int l, int r, lld v) {
    if (l-1 >= 0) add_diff(l-1, v);
    add_diff(r, -v);

    for (l += size, r += size; l <= r; l /= 2, r /= 2) {
      if (l & 1) val[l++] += v;
      if (!(r & 1)) val[r--] += v;
    }
  }

  lld val_query(int i) {
    int n = 1, nl = 0, nr = size-1;
    while (n < size) {
      propagate(n);
      int mid = (nl+nr)/2;
      if (i <= mid) { n = n*2; nr = mid; }
      else { n = n*2+1; nl = mid+1; }
    }
    return val[size+i];
  }

  lld gcd_query(int l, int r) {
    lld g = val_query(l);
    for (l += size, r += size-1; l <= r; l /= 2, r /= 2) {
      if (l & 1) g = gcd(g, diff[l++]);
      if (!(r & 1)) g = gcd(g, diff[r--]);
    }
    return g;
  }
};

const int MN = 1e5+5;
int N, Q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  segtree seg(N);

  for (int i=0; i<N; i++) {
    lld a; cin >> a;
    seg.range_add(i, i, a);
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    lld t; int l, r; cin >> t >> l >> r;
    l--; r--;
    if (t == 0) cout << seg.gcd_query(l, r) << endl;
    else seg.range_add(l, r, t);
  }

  ////////////////////////////////
  return 0;
}
