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
const int MN = 202020;
lld N, M, A[MN];
lld dp[MN], psum[MN];
vector<pll> Q, qry[MN];
lld ans[MN];

struct Line {
  lld a, b, s;
  lld inter(const Line &L) { return ceil(-(double)(b-L.b) / (a-L.a)); }
  bool operator<(const Line &L) const { return s < L.s; }
};

struct CHT {
  vector<Line> L;

  void add(lld a, lld b) { // ax + b
    Line line = {a, b, -INF};
    while (!L.empty()) {
      line.s = line.inter(L.back());
      if (L.back().s < line.s) break;
      else L.pop_back();
    }
    L.push_back(line);
  }

  lld query(lld x) {
    if (L.empty()) return -INF;
    auto it = upper_bound(all(L), Line{0, 0, x}) - 1;
    auto [a, b, s] = *it;
    return a*x + b;
  }
};
CHT cht;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int q=1; q<=M; q++) {
    lld d; cin >> d;
    Q.push_back({d, q});
  }
  sort(all(Q));

  // DP forward
  dp[0] = dp[1] = 0;
  for (int i=2; i<=N; i++) dp[i] = max(dp[i-1], dp[i-2] + A[i-1]);
  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i];

  // place queries
  int i = 0;
  for (auto [d, q]: Q) {
    while (i <= N && dp[i] + A[i+1] <= d) i++;
    // we need dp[i] <= d < dp[i] + A[i+1] (full until i, partial after i)
    // let i = first pos with d < dp[i] + A[i+1]
    // we only need to compute query at i and i+1!!!
    // why? dp[i+2] >= dp[i] + A[i+1] > d
    if (i <= N && dp[i] <= d && d < dp[i] + A[i+1])
      qry[i].push_back({d, q});
    if (i+1 <= N && dp[i+1] <= d && d < dp[i+1] + A[i+2])
      qry[i+1].push_back({d, q});
  }

  // CHT backwards
  for (int i=N; i>=0; i--) {
    for (auto [d, q]: qry[i]) {
      // remaining = max( psum[N]-psum[i] - x*(j-i-1) - A[j] )
      // where j = i+2 ... N+1
      // let's maintain max of -j*x - A[j] with CHT
      lld x = d - dp[i]; // overflowing amount
      lld remaining = psum[N]-psum[i] - x*(-i-1) + cht.query(x);
      ans[q] = max(ans[q], remaining);
    }

    cht.add(-(i+1), -A[i+1]);
  }

  // print ans
  for (int q=1; q<=M; q++) {
    cout << ans[q] << endl;
  }

  ////////////////////////////////
  return 0;
}
