#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
int N, Q, A[ST], B[ST];

// range sum query + range set value update
struct segtree {
  vector<int> seg, lazy;

  segtree() {
    seg.resize(ST*2);
    lazy.resize(ST*2, -1);
  }

  void propagate(int n, int nl, int nr) {
    if (lazy[n] == -1) return;
    seg[n] = lazy[n] * (nr-nl);
    if (n < ST) {
      lazy[n*2] = lazy[n];
      lazy[n*2+1] = lazy[n];
    }
    lazy[n] = -1;
  }

  void update_range(int l, int r, int val) { update_range(1, 0, ST, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, int val) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] = val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid, nr, l, r, val);
    seg[n] = seg[n*2] + seg[n*2+1];
  }

  int query(int l, int r) { return query(1, 0, ST, l, r); }
  int query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return query(n*2, nl, mid, l, r) + query(n*2+1, mid, nr, l, r);
  }

  int query_pos(int s, int d) {
    int base = query(0, s);
    int sum = 0, n = 1, nl = 0, nr = ST;

    while (n < ST) {
      propagate(n, nl, nr);
      int mid = (nl+nr)/2;

      if (mid < s || sum + seg[n*2] == base + d * (mid-s)) {
        sum += seg[n*2];
        n = n*2+1;
        nl = mid;
      } else {
        n = n*2;
        nr = mid;
      }
    }
    return nl;
  }
} seg;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string AS, BS;
  cin >> N >> Q >> AS >> BS;
  for (int i=0; i<N; i++) A[i] = AS[N-1-i] - '0';
  for (int i=0; i<N; i++) B[i] = BS[N-1-i] - '0';
  int carry = 0;
  for (int i=0; i<N+1; i++) {
    int sum = A[i] + B[i] + carry;
    seg.update_range(i, i+1, sum % 10);
    carry = sum >= 10;
  }

  for (int q=0; q<Q; q++) {
    char c; int i, d; cin >> c >> i >> d;
    i--;

    int delta;
    if (c == 'A') { delta = d-A[i]; A[i] = d; }
    else { delta = d-B[i]; B[i] = d; }

    if (delta == 0) {
      cout << 0 << endl;
      continue;
    }

    int sum = seg.query(i, i+1) + delta;
    if (0 <= sum && sum < 10) {
      seg.update_range(i, i+1, sum);
      cout << 1 << endl;
    }

    if (sum >= 10) {
      int e = seg.query_pos(i+1, 9);
      seg.update_range(i, i+1, sum - 10);
      seg.update_range(i+1, e, 0);
      seg.update_range(e, e+1, seg.query(e, e+1) + 1);
      cout << e+1 - i << endl;
    }

    if (sum < 0) {
      int e = seg.query_pos(i+1, 0);
      seg.update_range(i, i+1, sum + 10);
      seg.update_range(i+1, e, 9);
      seg.update_range(e, e+1, seg.query(e, e+1) - 1);
      cout << e+1 - i << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
