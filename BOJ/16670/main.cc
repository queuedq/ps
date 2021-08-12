#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e14;
const int ST = 1<<20;
lld seg[ST*2], seg2[ST*2], lazy[ST*2];
// seg: d, sum query / seg2: t - (d prefix sum), max query

void update(int i, lld x) {
  seg[i += ST] += x;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

lld query_sum(int l, int r) {
  lld res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}

void update2(int n, int nl, int nr, int l, int r, lld x) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) { lazy[n] += x; return; }

  int m = (nl+nr)/2;
  update2(n*2, nl, m, l, r, x);
  update2(n*2+1, m+1, nr, l, r, x);
  seg2[n] = max(seg2[n*2] + lazy[n*2], seg2[n*2+1] + lazy[n*2+1]);
}
void update2(int l, int r, lld x) { update2(1, 0, ST-1, l, r, x); }

lld query_max(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return LLONG_MIN;
  if (l <= nl && nr <= r) return seg2[n] + lazy[n];

  int m = (nl+nr)/2;
  return max(query_max(n*2, nl, m, l, r), query_max(n*2+1, m+1, nr, l, r)) + lazy[n];
}
lld query_max(int l, int r) { return query_max(1, 0, ST-1, l, r); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int Q; cin >> Q;
  vector<pll> joins(Q);

  for (int q=0; q<Q; q++) {
    char type; cin >> type;

    if (type == '+') {
      lld t, d; cin >> t >> d;
      update(t, d);
      update2(t, t, t);
      update2(t+1, ST-1, -d);
      joins[q] = {t, d};
    } else if (type == '-') {
      int i; cin >> i;
      auto [t, d] = joins[i-1];
      update(t, -d);
      update2(t, t, -t);
      update2(t+1, ST-1, d);
    } else {
      lld t; cin >> t;
      lld nxt = query_sum(0, t) + query_max(0, t);
      cout << max(nxt - t, 0LL) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
