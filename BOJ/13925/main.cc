#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const lld MOD = 1e9+7;

struct SegTree {
  vector<lld> seg, mul, add;
  int size;

  SegTree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    mul.resize(size*2, 1);
    add.resize(size*2);
  }

  void build(vector<lld> arr) {
    for (int i=0; i<arr.size(); i++) seg[size + i] = arr[i];
    for (int i=size-1; i>0; i--) seg[i] = (seg[i*2] + seg[i*2+1]) % MOD;
  }

  void propagate(int n, int nl, int nr) {
    seg[n] = (seg[n] * mul[n] + add[n] * (nr-nl)) % MOD;
    if (n < size) {
      mul[n*2] = mul[n*2] * mul[n] % MOD;
      mul[n*2+1] = mul[n*2+1] * mul[n] % MOD;
      add[n*2] = (add[n*2] * mul[n] + add[n]) % MOD;
      add[n*2+1] = (add[n*2+1] * mul[n] + add[n]) % MOD;
    }
    mul[n] = 1;
    add[n] = 0;
  }

  void update_range(int l, int r, lld m, lld a) { update_range(1, 0, size, l, r, m, a); }
  void update_range(int n, int nl, int nr, int l, int r, lld m, lld a) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) {
      mul[n] = mul[n] * m % MOD;
      add[n] = (add[n] * m + a) % MOD;
      return propagate(n, nl, nr);
    }

    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, m, a);
    update_range(n*2+1, mid, nr, l, r, m, a);
    seg[n] = (seg[n*2] + seg[n*2+1]) % MOD;
  }

  lld query(int l, int r) { return query(1, 0, size, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return (query(n*2, nl, mid, l, r) + query(n*2+1, mid, nr, l, r)) % MOD;
  }
};

ostream& operator <<(ostream& os, SegTree& seg) {
  for (int i=0; i<seg.seg.size(); i++) os << seg.seg[i] << " "; os << endl;
  for (int i=0; i<seg.seg.size(); i++) os << seg.mul[i] << " "; os << endl;
  for (int i=0; i<seg.seg.size(); i++) os << seg.add[i] << " "; os << endl;
  return os;
}

int N, M;
vector<lld> A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  SegTree seg(N);
  for (int i=0; i<N; i++) {
    lld a; cin >> a;
    A.push_back(a);
  }
  seg.build(A);

  cin >> M;
  for (int i=0; i<M; i++) {
    lld q, x, y, v; cin >> q;
    if (q == 1) {
      cin >> x >> y >> v;
      seg.update_range(x-1, y, 1, v);
    } else if (q == 2) {
      cin >> x >> y >> v;
      seg.update_range(x-1, y, v, 0);
    } else if (q == 3) {
      cin >> x >> y >> v;
      seg.update_range(x-1, y, 0, v);
    } else {
      cin >> x >> y;
      cout << seg.query(x-1, y) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
