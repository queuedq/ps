#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int ST = 1<<19;
lld N, L, R, S;

struct Fair {
  lld x, w;
  bool operator <(const Fair &F) const { return x < F.x; } 
};
vector<Fair> A[ST];

struct SegTree {
  lld seg[ST*2];

  void init() {
    fill(seg, seg+ST*2, -INF);
  }

  void update(int i, lld val) {
    seg[i+=ST] = val;
    for (i/=2; i>0; i/=2) seg[i] = max(seg[i*2], seg[i*2+1]);
  }

  lld query(int l, int r) { // [l, r]
    lld res = -INF;
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) res = max(res, seg[l++]);
      if (r&1) res = max(res, seg[--r]);
    }
    return res;
  }
} SL, SR; // SL: D[x] - L*x / SR: D[x] + R*x

lld D[ST], DL[ST], DR[ST]; // DL: same day l->r / DR: r->l

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L >> R >> S;
  for (int i=0; i<N; i++) {
    lld t, x, w; cin >> t >> x >> w;
    A[t].push_back({x, w});
  }

  fill(D, D+ST, -INF);
  fill(DL, DL+ST, -INF);
  fill(DR, DR+ST, -INF);
  D[S] = DL[S] = DR[S] = 0;
  SL.init(); SL.update(S, -L*S);
  SR.init(); SR.update(S, R*S);

  for (int t=1; t<ST; t++) {
    // D[x] = min(
    //   min_{y > x} D[y] - L*(y-x) + w[x],
    //   min_{y < x} D[y] - R*(x-y) + w[x])
    sort(all(A[t]));

    lld px = 0, pd = -INF;
    for (auto [x, w]: A[t]) {
      DL[x] = max({
        SL.query(x, ST-1) + L*x + w,
        SR.query(0, x) - R*x + w,
        pd - R*(x-px) + w,
        -INF
      });
      px = x, pd = DL[x];
    }
    reverse(all(A[t]));

    px = ST, pd = -INF;
    for (auto [x, w]: A[t]) {
      DR[x] = max({
        SL.query(x, ST-1) + L*x + w,
        SR.query(0, x) - R*x + w,
        pd - L*(px-x) + w,
        -INF
      });
      px = x, pd = DR[x];
    }
    reverse(all(A[t]));

    for (auto [x, w]: A[t]) {
      D[x] = max(DL[x], DR[x]);
      SL.update(x, D[x] - L*x);
      SR.update(x, D[x] + R*x);
    }
  }

  lld ans = 0;
  for (int x=0; x<ST; x++) {
    if (x > S) ans = max(ans, D[x] - L*(x-S));
    else ans = max(ans, D[x] - R*(S-x));
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
