#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<20;
int N, M, K;
lld seg[ST*2], lazy[ST*2];

void push(int n, int nl, int nr) {
  seg[n*2] += lazy[n] * (nr-nl+1)/2; // sum query
  seg[n*2+1] += lazy[n] * (nr-nl+1)/2;
  lazy[n*2] += lazy[n];
  lazy[n*2+1] += lazy[n];
  lazy[n] = 0;
}

void add_range(int n, int nl, int nr, int l, int r, lld v) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) {
    seg[n] += v * (nr-nl+1); // sum query
    lazy[n] += v;
    return;
  }
  push(n, nl, nr);
  int m = (nl+nr)/2;
  add_range(n*2, nl, m, l, r, v);
  add_range(n*2+1, m+1, nr, l, r, v);
  seg[n] = seg[n*2] + seg[n*2+1]; // sum query
}
void add_range(int l, int r, lld v) { add_range(1, 0, ST-1, l, r, v); }

lld query_sum(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return 0;
  if (l <= nl && nr <= r) return seg[n];
  push(n, nl, nr);
  int m = (nl+nr)/2;
  return query_sum(n*2, nl, m, l, r) + query_sum(n*2+1, m+1, nr, l, r); // sum query
}
lld query_sum(int l, int r) { return query_sum(1, 0, ST-1, l, r); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=N; i++) {
    lld x; cin >> x;
    add_range(i, i, x);
  }

  for (int q=0; q<M+K; q++) {
    lld a, b, c, d; cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      add_range(b, c, d);
    } else {
      cin >> b >> c;
      cout << query_sum(b, c) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
