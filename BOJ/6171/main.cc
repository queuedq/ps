#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50505;
lld N, D[MN];

struct Rect {
  lld w, h;
  bool operator <(const Rect &R) const { return pll(w, h) < pll(R.w, R.h); }
};

struct Line {
  lld a, b; double l = -INFINITY, r = INFINITY;
  double inter(Line L) { return -(double)(b-L.b) / (a-L.a); }
  lld get(lld x) { return a*x+b; }
  bool operator <(const Line &L) const { return r < L.r; }
};

struct CHT {
  deque<Line> dq;

  void push(lld a, lld b) {
    Line L = {a, b};
    while (sz(dq) && dq.back().inter(L) <= dq.back().l) dq.pop_back();
    if (sz(dq)) dq.back().r = L.l = dq.back().inter(L);
    dq.push_back(L);
  }

  lld min_pop(lld x) {
    while (dq.front().r <= x) dq.pop_front();
    return dq.front().get(x);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vector<Rect> A(N);
  for (int i=0; i<N; i++) cin >> A[i].w >> A[i].h;
  sort(all(A));

  // make monotone
  vector<Rect> tmp;
  tmp.push_back(A.back());
  for (int i=N-2; i>=0; i--) {
    if (A[i].h > tmp.back().h) tmp.push_back(A[i]);
  }
  A = vector(tmp.rbegin(), tmp.rend()), N = sz(A);

  // dp
  CHT cht;
  D[0] = 0;
  cht.push(A[0].h, 0);
  for (int i=1; i<=N; i++) {
    D[i] = cht.min_pop(A[i-1].w);
    cht.push(A[i].h, D[i]);
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
