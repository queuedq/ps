#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct segtree {
  vector<lld> seg, left, lazy;
  int size;

  segtree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    left.resize(size*2);
    lazy.resize(size*2);
  }

  void propagate(int n, int nl, int nr) {
    if (lazy[n] == -1) return;
    seg[n] = lazy[n] * (nr-nl);
    left[n] = lazy[n];
    if (n < size) {
      lazy[n*2] = lazy[n];
      lazy[n*2+1] = lazy[n];
    }
    lazy[n] = -1;
  }

  void update_range(int l, int r, lld val) { update_range(1, 0, size, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, lld val) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] = val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid, nr, l, r, val);
    seg[n] = seg[n*2] + seg[n*2+1];
    left[n] = left[n*2];
  }

  lld query_sum(int l, int r) { return query_sum(1, 0, size, l, r); }
  lld query_sum(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return query_sum(n*2, nl, mid, l, r) + query_sum(n*2+1, mid, nr, l, r);
  }

  int query_pos(lld x) {
    propagate(1, 0, size);
    if (x >= left[1]) return 0;
    return query_pos(1, 0, size, x);
  }
  int query_pos(int n, int nl, int nr, lld x) {
    if (n >= size) return nr;
    int mid = (nl+nr)/2;
    propagate(n*2, nl, mid);
    propagate(n*2+1, mid, nr);
    if (x >= left[n*2+1]) {
      return query_pos(n*2, nl, mid, x);
    } else {
      return query_pos(n*2+1, mid, nr, x);
    }
  }
};

////////////////////////////////////////////////////////////////
const int MN = 2e5+5;
int N, Q;
set<pll> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  segtree seg(N);

  for (int i=0; i<N; i++) {
    lld a; cin >> a;
    while (!S.empty() && S.rbegin()->Y <= a) {
      S.erase(prev(S.end()));
    }
    S.insert({i, a});
    seg.update_range(i, i+1, a);
  }

  for (int q=0; q<Q; q++) {
    lld t, x, y; cin >> t >> x >> y;
    x--;

    if (t == 1) {
      auto it = S.lower_bound({x, y});
      if (it != S.end() && y <= it->Y) continue;
      auto jt = reverse_iterator(it);
      while (jt != S.rend()) {
        if (jt->Y > y) break;
        jt++;
      }
      S.erase(jt.base(), it);
      S.insert({x, y});

      it = S.lower_bound({x, y});
      lld l = it == S.begin() ? 0 : prev(it)->X + 1;
      seg.update_range(l, x+1, y);

      // for (int i=0; i<N; i++) {
      //   cout << seg.query(i, i+1) << " "; 
      // } cout << endl;
    } else {
      int cnt = 0;
      while (y > 0) {
        

        int l = x, r = N;
        while (l+1 < r) {
          int m = (l+r)/2;
          if (seg.query(x, m) <= y) l = m;
          else r = m;
        }
        y -= seg.query(x, l);
      }


      cout << cnt << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
