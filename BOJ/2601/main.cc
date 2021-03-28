#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct SegTree {
  vector<int> seg, lazy;
  int size;

  SegTree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    lazy.resize(size*2);
  }

  void propagate(int n) {
    seg[n] += lazy[n];
    if (n < size) {
      lazy[n*2] += lazy[n];
      lazy[n*2+1] += lazy[n];
    }
    lazy[n] = 0;
  }

  int query(int l, int r) { return query(1, 0, size, l, r); }
  int query(int n, int nl, int nr, int l, int r) {
    propagate(n);
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return max(query(n*2, nl, mid, l, r), query(n*2+1, mid, nr, l, r));
  }

  void update(int l, int r, int val) { update(1, 0, size, l, r, val); }
  void update(int n, int nl, int nr, int l, int r, int val) {
    propagate(n);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] += val; return propagate(n); }
    int mid = (nl+nr)/2;
    update(n*2, nl, mid, l, r, val);
    update(n*2+1, mid, nr, l, r, val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }
};

struct Rect {
  int x; pii range; int val;

  bool operator <(Rect r) const {
    if (x == r.x) return val > r.val;
    return x < r.x;
  }
};

int N, X, Y, S;
vector<Rect> R;
vector<int> coords;

int compress(int x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int _;
  cin >> _ >> Y >> X >> _;
  cin >> S >> N;

  for (int i=0; i<N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x2 - x1 > S || y1 - y2 > S) continue;
    pii range = {y1-S, y2};
    R.push_back({x2-S, range, 1});
    R.push_back({x1, range, -1});
    coords.push_back(range.first);
    coords.push_back(range.second);
  }

  sort(R.begin(), R.end());
  sort(coords.begin(), coords.end());

  SegTree seg(coords.size());

  int ans = 0;
  for (auto [x, range, val]: R) {
    // cout << x << " " << range.first << " " << range.second << " " << val << endl;
    auto [l, r] = range;
    l = compress(l);
    r = compress(r);
    seg.update(l, r+1, val);
    ans = max(ans, seg.query(0, seg.size));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
