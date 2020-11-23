#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2005;
const int ST = 2048;
int N;

struct Point { 
  lld x, y, w;
  bool operator <(const Point &p) const { x < p.x; }
} A[MAXN];

struct Node { lld l, r, m, s; };
Node seg[ST*2];

Node merge(Node L, Node R) {
  Node res;
  res.l = max(L.l, L.s + R.l);
  res.r = max(R.r, R.s + L.r);
  res.m = max({L.m, R.m, L.r + R.l});
  res.s = L.s + R.s;
  return res;
}

void update(int i, lld val) {
  seg[ST+i] = {val, val, val, val};
  for (int n = (ST+i)/2; n > 0; n /= 2) {
    seg[n] = merge(seg[n*2], seg[n*2+1]);
  }
}

// query [l, r]
Node query(int n, int nl, int nr, int l, int r) {
  if (nr < l || r < nl) return {INT_MIN, INT_MIN, INT_MIN, 0};
  if (l <= nl && nr <= r) return seg[n];
  int mid = (nl+nr)/2;
  return merge(query(n*2, nl, mid, l, r), query(n*2+1, mid+1, nr, l, r));
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  vector<lld> xs, ys;

  lld n1; cin >> n1;
  for (int i=0; i<n1; i++) {
    cin >> A[i].x >> A[i].y;
    xs.push_back(A[i].x);
    ys.push_back(A[i].y);
  }
  lld n2; cin >> n2;
  for (int i=n1; i<n1+n2; i++) {
    cin >> A[i].x >> A[i].y;
    xs.push_back(A[i].x);
    ys.push_back(A[i].y);
  }
  N = n1 + n2;

  lld c1, c2; cin >> c1 >> c2;
  for (int i=0; i<n1; i++) A[i].w = c1;
  for (int i=n1; i<n1+n2; i++) A[i].w = -c2;

  sort(A, A+N);
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  for (int i=0; i<N; i++) {
    A[i].x = lower_bound(xs.begin(), xs.end(), A[i].x) - xs.begin();
    A[i].y = lower_bound(ys.begin(), ys.end(), A[i].y) - ys.begin();
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    fill(seg, seg+ST*2, (Node){0, 0, 0, 0});

    for (int j=i; j<N; j++) {
      update(A[j].y, A[j].w);
    }
    ans = max(ans, query(1, 0, ST-1, 0, N-1).m);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
