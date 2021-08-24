#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
#define X first
#define Y second

pll operator +(pll A, pll B) {
  return {A.X + B.X, A.Y + B.Y};
}

////////////////////////////////////////////////////////////////
const int ST = 1<<21;
lld N;
pll A[ST];

struct segtree {
  vector<pll> seg; // {count, sum}
  int offset;

  segtree(int offset = 0): offset(offset) {
    seg = vector<pll>(ST*2, {0, 0});
  }

  void update(int i, pll val) {
    i += ST-offset;
    seg[i] = seg[i] + val;
    for (i /= 2; i > 0; i /= 2) {
      seg[i] = seg[i*2] + seg[i*2+1];
    }
  }

  // query [l, r]
  pll query(int l, int r) { return query(1, 0, ST-1, l-offset, r-offset); }
  pll query(int n, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return {0, 0};
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return query(n*2, nl, mid, l, r) + query(n*2+1, mid+1, nr, l, r);
  }
};
segtree seg_y, seg_sum, seg_diff(-ST/2);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].X;
  for (int i=0; i<N; i++) cin >> A[i].Y;
  sort(A, A+N);

  lld ans = 0, ysum = 0;
  for (int i=0; i<N; i++) {
    auto [x, y] = A[i];
    
    auto [y_up_cnt, y_up_sum] = seg_y.query(y, ST-1);
    ans += y_up_sum - y * y_up_cnt;
    ans += y * (i - y_up_cnt) - (ysum - y_up_sum);

    auto [sum_cnt, sum_sum] = seg_sum.query(x+y, ST-1);
    ans += (x+y) * sum_cnt - sum_sum;

    auto [diff_cnt, diff_sum] = seg_diff.query(seg_diff.offset, y-x);
    ans += diff_sum - (y-x) * diff_cnt;

    // update
    ysum += y;
    seg_y.update(y, {1, y});
    seg_sum.update(x+y, {1, x+y});
    seg_diff.update(y-x, {1, y-x});
  }

  cout << ans * 2 << endl;

  ////////////////////////////////
  return 0;
}
