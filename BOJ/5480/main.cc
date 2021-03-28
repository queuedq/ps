#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld INF = 1e9;

struct seg_tree {
  vector<lld> seg;
  int size;

  seg_tree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg = vector<lld>(size*2, INF);
  }

  void update(int i, lld val) {
    seg[size+i] = val;
    for (int n = (size+i)/2; n > 0; n /= 2) seg[n] = min(seg[n*2], seg[n*2+1]);
  }

  lld query(int l, int r) { return query(1, 0, size-1, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return INF;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return min(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
  }
};

int compress(lld x, const vector<lld> &xs) {
  return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, K, L;

struct Line { lld x1, y1, x2, y2, w; } A[MAXN];
pll laser[MAXN];

void solve() {
  vector<lld> xs, ys;

  cin >> N >> K >> L;
  for (int i=0; i<K; i++) {
    cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2 >> A[i].w;
    xs.push_back(A[i].x1);
    xs.push_back(A[i].x2);
    ys.push_back(A[i].y1);
    ys.push_back(A[i].y2);
  }
  for (int i=0; i<L; i++) {
    lld a, b; cin >> a >> b;
    laser[i] = {a, b};
    if (b) xs.push_back(a);
    else ys.push_back(a);
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

  seg_tree X(xs.size()), Y(ys.size());

  for (int i=L-1; i>=0; i--) {
    if (laser[i].second) {
      int j = compress(laser[i].first, xs);
      X.update(j, i);
    } else {
      int j = compress(laser[i].first, ys);
      Y.update(j, i);
    }
  }

  vector<lld> ans(L);

  for (int i=0; i<K; i++) {
    int xl = compress(A[i].x1, xs);
    int xr = compress(A[i].x2, xs);
    int yl = compress(A[i].y1, ys);
    int yr = compress(A[i].y2, ys);
    if (xl > xr) swap(xl, xr);
    if (yl > yr) swap(yl, yr);
    int j = min(X.query(xl, xr), Y.query(yl, yr));
    if (j < L) ans[j] = max(ans[j], A[i].w);
  }

  for (int i=0; i<L; i++) cout << ans[i] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
