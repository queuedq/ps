#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

void compress(vector<int> &xs) {
  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end())- xs.begin());
}

int idx(int x, const vector<int> &xs) {
  return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

// Range max query + range addition update
struct segtree {
  vector<int> seg, lazy;
  int size;

  segtree(int sz) {
    size = 1 << (int)ceil(log2(sz));
    seg.resize(size*2);
    lazy.resize(size*2);
  }

  void propagate(int n, int nl, int nr) {
    seg[n] += lazy[n]; // times (nr-nl) when range sum query
    if (n < size) {
      lazy[n*2] += lazy[n];
      lazy[n*2+1] += lazy[n];
    }
    lazy[n] = 0;
  }

  void update_range(int l, int r, int val) { update_range(1, 0, size, l, r, val); }
  void update_range(int n, int nl, int nr, int l, int r, int val) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return;
    if (l <= nl && nr <= r) { lazy[n] += val; return propagate(n, nl, nr); }
    int mid = (nl+nr)/2;
    update_range(n*2, nl, mid, l, r, val);
    update_range(n*2+1, mid, nr, l, r, val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
  }

  int query(int l, int r) { return query(1, 0, size, l, r); }
  int query(int n, int nl, int nr, int l, int r) {
    propagate(n, nl, nr);
    if (nr <= l || r <= nl) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl+nr)/2;
    return max(query(n*2, nl, mid, l, r), query(n*2+1, mid, nr, l, r));
  }
};

////////////////////////////////////////////////////////////////

const int MN = 2e5+5;
int N;
vector<int> ys;
vector<pii> A, event;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int ux, uy, vx, vy;
    cin >> ux >> uy >> vx >> vy;
    ys.push_back(vy);
    ys.push_back(uy);
    A.push_back({vy, uy});
  }

  compress(ys);
  for (int i=0; i<N; i++) {
    auto [l, r] = A[i];
    event.push_back({idx(l, ys), -1});
    event.push_back({idx(r, ys), i});
  }

  sort(event.begin(), event.end());

  int ans = 0, cnt = 0;
  segtree seg(ys.size());
  for (auto [y, i]: event) {
    if (i == -1) {
      cnt++;
    } else {
      auto [l, r] = A[i];
      cnt--;
      seg.update_range(idx(l, ys), idx(r, ys)+1, 1);
    }
    ans = max(ans, cnt + seg.query(0, ys.size()));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
