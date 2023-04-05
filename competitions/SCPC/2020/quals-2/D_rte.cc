#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Event {
  lld e, x, y; // e=0,1: road / e=2: trajectory
  bool operator <(const Event &e) const { return y < e.y; }
};
ostream& operator <<(ostream &os, Event &e) {
  return os << "Event {" << e.e << "|" << e.x << "," << e.y << "}";
}

struct Interval {
  lld y, y2, l, r, m;
};
ostream& operator <<(ostream &os, Interval &i) {
  return os << "Interval {" << i.y << "," << i.y2 << "|" << i.l << "," << i.r << "," << i.m << "}";
}

struct SegTree {
  vector<lld> seg, lazy;
  int size;

  SegTree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    lazy.resize(size*2);
  }

  void propagate(int n, int nl, int nr) {
    seg[n] += lazy[n];
    if (n < size) {
      lazy[n*2] += lazy[n];
      lazy[n*2+1] += lazy[n];
    }
    lazy[n] = 0;
  }

  void update_range(int l, int r, lld val) { update_range(1, 0, size, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, lld val) {
    propagate(n, nl, nr);
    if (nr < l || r < nl) return;
    if (l <= nl && nr <= r) { lazy[n] += val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid+1, nr, l, r, val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  lld query(int l, int r) { return query(1, 0, size, l, r); }
  lld query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr < l || r < nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return max(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
  }
};

struct Update {
  lld l, r, v;
};

void solve() {
  // Input
  lld L, M, N;
  cin >> L >> M >> N;

  vector<Event> E;
  lld x = 0, y = 0;
  lld l;
  for (int i=0; i<L; i++) {
    lld dx, dy; cin >> dx >> dy;
    x += dx;
    E.push_back({0, x, y});
    y += dy;
    if (i == 0) l = x;
  }

  x = 0, y = 0;
  lld r;
  for (int i=0; i<M; i++) {
    lld dx, dy; cin >> dx >> dy;
    x += dx;
    E.push_back({1, x, y});
    y += dy;
    if (i == 0) r = x;
  }

  x = 0, y = 0;
  lld m;
  for (int i=0; i<N; i++) {
    lld dx, dy; cin >> dx >> dy;
    x += dx;
    E.push_back({2, x, y});
    y += dy;
    if (i == 0) m = x;
  }

  lld top = y;
  sort(E.begin(), E.end());

  // for (auto e: E) cout << e << endl;

  // Get intervals
  vector<Interval> I;
  for (int i=0; i<E.size(); i++) {
    if (E[i].e == 0) l = E[i].x;
    if (E[i].e == 1) r = E[i].x;
    if (E[i].e == 2) m = E[i].x;
    I.push_back({E[i].y, E[i].y, l, r, m});
  }

  // Get segtree updates and compressed coordinates
  vector<Update> upd;
  vector<lld> coords;
  for (int i=I.size()-1; i>=0; i--) {
    upd.push_back({I[i].l+I[i].m, I[i].r+I[i].m, y-I[i].y});
    coords.push_back(I[i].l+I[i].m);
    coords.push_back(I[i].r+I[i].m+1);
    I[i].y2 = y;
    y = I[i].y;
  }

  sort(coords.begin(), coords.end());

  // Simulate from start
  vector<lld> ans(I.size());
  lld p = 0;
  for (int i=0; i<I.size(); i++) {
    if (I[i].l <= I[i].m && I[i].m <= I[i].r) p += I[i].y2 - I[i].y;
    ans[i] = p;
  }

  // for (int i=0; i<I.size(); i++) cout << I[i] << " " << ans[i] << endl;

  // Simulate from end
  SegTree seg(coords.size());
  for (int i=0; i<upd.size()-1; i++) {
    lld l = lower_bound(coords.begin(), coords.end(), upd[i].l) - coords.begin();
    lld r = lower_bound(coords.begin(), coords.end(), upd[i].r+1) - coords.begin();
    seg.update_range(l, r-1, upd[i].v);

    lld m = I[I.size()-i-2].m;
    lld df = abs(m - I[I.size()-i-1].m);
    lld ql = upper_bound(coords.begin(), coords.end(), m*2-df) - coords.begin() - 1;
    lld qr = upper_bound(coords.begin(), coords.end(), m*2+df) - coords.begin() - 1;
    ans[ans.size()-i-2] += seg.query(ql, qr);
  }

  // for (int i=0; i<I.size(); i++) cout << I[i] << " " << ans[i] << endl;

  lld res = 0;
  for (auto a: ans) res = max(res, a);

  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << endl;
    solve();
  }

  ////////////////////////////////
  return 0;
}
