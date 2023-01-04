#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, A[20], B[20], zero[20], areq, breq;
vector<pll> S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> B[i];
  for (int i=0; i<N; i++) { // zero: always contained in ans
    if (A[i] == 0) zero[i] = 1, breq += B[i];
    if (B[i] == 0) zero[i] = 1, areq += A[i];
  }

  int mask = 0;
  for (int i=0; i<N; i++) {
    if (!zero[i]) mask |= 1<<i;
  }
  assert(mask > 0);

  for (int m=mask; m>0; m=(m-1)&mask) {
    lld asum = 0;
    for (int i=0; i<N; i++) {
      if (m>>i & 1) asum += A[i];
    }
    S.push_back({asum, m});
  }
  S.push_back({0, 0});
  sort(all(S)); reverse(all(S));

  pll best = {LLONG_MAX, 0}; // a+b, a
  lld mx = 0;
  for (auto [asum, m]: S) {
    // mx+1 gloves from B is necessary to overlap with any possible encountered set(m)s
    best = min(best, {asum+1 + mx+1, asum+1});

    lld bsum = 0;
    for (int i=0; i<N; i++) {
      if (!zero[i] && (~m>>i & 1)) bsum += B[i];
    }
    mx = max(mx, bsum);
  }

  auto [sum, a] = best;
  cout << areq + a << " " << breq + sum-a << endl;

  ////////////////////////////////
  return 0;
}
