#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int ST = 1<<19;
lld N, idx[ST], D[ST]; // D[i]: use Y_i, and it is the highest among [1..i]
pll A[ST];
vector<int> ys;

struct SegTree {
  lld seg[ST*2], lazy[ST*2];

  void propagate(int n) {
    if (n < ST) {
      seg[n*2] += lazy[n]; lazy[n*2] += lazy[n];
      seg[n*2+1] += lazy[n]; lazy[n*2+1] += lazy[n];
    }
    lazy[n] = 0;
  }

  void update(int i, lld v) { update(1, 0, ST-1, i, v); }
  void update(int n, int nl, int nr, int i, lld v) {
    propagate(n);
    if (i < nl || nr < i) return;
    if (nl == nr) { seg[n] = v; return; }
    int m = (nl+nr)/2;
    update(n*2, nl, m, i, v);
    update(n*2+1, m+1, nr, i, v);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  void add_range(int l, int r, lld v) { add_range(1, 0, ST-1, l, r, v); }
  void add_range(int n, int nl, int nr, int l, int r, lld v) {
    propagate(n);
    if (r < nl || nr < l) return;
    if (l <= nl && nr <= r) { seg[n] += v; lazy[n] += v; return; }
    int m = (nl+nr)/2;
    add_range(n*2, nl, m, l, r, v);
    add_range(n*2+1, m+1, nr, l, r, v);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  lld query_max(int l, int r) { return query_max(1, 0, ST-1, l, r); } // max dp + something
  lld query_max(int n, int nl, int nr, int l, int r) {
    propagate(n);
    if (r < nl || nr < l) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int m = (nl+nr)/2;
    return max(query_max(n*2, nl, m, l, r), query_max(n*2+1, m+1, nr, l, r));
  }

} seg;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=1; i<=N; i++) {
    lld x, y; cin >> x >> y;
    A[i] = {x, y};
    ys.push_back(y);
  }
  
  sort(A+1, A+N+1);
  sort(all(ys));
  for (int i=1; i<=N; i++) idx[i] = lower_bound(all(ys), A[i].second) - ys.begin() + 1;

  // for (int i=1; i<=N; i++) cout << "(" << A[i].first << "," << A[i].second << ") " << idx[i] << " ";
  // cout << endl;

  // DP
  for (int i=1; i<=N; i++) {
    D[i] = seg.query_max(0, idx[i]) + A[i].second;
    seg.update(idx[i], D[i]);
    seg.add_range(0, idx[i]-1, A[i].first);
    seg.add_range(idx[i]+1, ST-1, A[i].second);

    // cout << i << endl;
    // for (int i=1; i<=N; i++) cout << D[i] << " "; cout << endl;
    // for (int i=1; i<=N; i++) cout << seg.query_max(i, i) << " "; cout << endl;
    // cout << endl;
  }

  cout << seg.query_max(0, ST-1) << endl;

  return 0;
}
