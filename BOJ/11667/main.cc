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
const int MN = 205;
int N, P;
struct Interval { int s, e; };
vector<Interval> I, crit, spare;
lld D[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> P;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    I.push_back({a, b});
  }

  // separate critical/spare
  sort(all(I), [](auto X, auto Y) { return pii(-X.s, X.e) < pii(-Y.s, Y.e); });

  int mn = INT_MAX;
  for (auto [s, e]: I) {
    if (e < mn) mn = e, crit.push_back({s, e});
    else spare.push_back({s, e});
  }
  
  // DP for critical
  int M = sz(crit);
  reverse(all(crit));
  for (int i=0; i<=M; i++) fill(D[i], D[i]+M+1, -INF);
  D[0][0] = 0;

  for (int r=1; r<=M; r++) {
    for (int l=0; l<r; l++) {
      for (int k=1; k<=r; k++) {
        int w = crit[l].e - crit[r-1].s;
        if (w > 0) D[r][k] = max(D[r][k], D[l][k-1] + w);
      }
    }
  }

  // use spare
  sort(all(spare), [](auto X, auto Y) { return X.e-X.s > Y.e-Y.s; });
  vector<int> S = {0}; // psum
  for (auto x: spare) S.push_back(S.back() + x.e-x.s);

  lld ans = -INF;
  for (int k=0; k<=min(M, P); k++) {
    if (P-k <= sz(spare)) ans = max(ans, D[M][k] + S[P-k]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
