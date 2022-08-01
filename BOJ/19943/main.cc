#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const string frac[4] = {".00", ".25", ".50", ".75"};
lld N, D[MN];

struct Interval {
  lld l, r;
  bool operator <(const Interval &I) const { return pll(l, -r) < pll(I.l, -I.r); }
};

struct Line {
  lld a, b; double l, r;
  double inter(Line &L) { return -(double)(b-L.b) / (a-L.a); }
  lld get(lld x) { return a*x+b; }
};

struct CHT {
  deque<Line> dq;

  lld min(lld x) {
    while (dq.front().r <= x) dq.pop_front();
    return dq.front().get(x);
  }

  void push(lld a, lld b) {
    Line L = {a, b, -INFINITY, INFINITY};
    while (sz(dq) > 0 && dq.back().inter(L) <= dq.back().l) dq.pop_back();
    if (sz(dq)) dq.back().r = L.l = dq.back().inter(L);
    dq.push_back(L);
  }
};

void solve() {
  cin >> N;
  vector<Interval> A(N);
  for (int i=0; i<N; i++) {
    lld x, h; cin >> x >> h;
    A[i] = {x-h, x+h};
  }
  sort(all(A));

  // make monotone
  vector<Interval> tmp;
  tmp.push_back(A[0]);
  for (int i=1; i<N; i++) {
    if (tmp.back().r < A[i].r) tmp.push_back(A[i]);
  }
  A = tmp, N = sz(A);

  // dp
  CHT cht;
  D[0] = 0;
  cht.push(-2 * A[0].l, A[0].l * A[0].l);

  for (int i=1; i<=N; i++) {
    D[i] = A[i-1].r * A[i-1].r + cht.min(A[i-1].r);
    cht.push(-2 * A[i].l, D[i] + A[i].l * A[i].l);
  }

  cout << D[N]/4 << frac[D[N]%4] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;
  while (T--) solve();
  return 0;
}
