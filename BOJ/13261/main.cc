#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 8005;
const int MK = 805;
const lld INF = 1e18;
lld N, K, C[MN], psum[MN], D[MK][MN];

lld cost(int l, int r) { return (psum[r] - psum[l-1]) * (r-l+1); }

// calc D[s..e] where opt in [l..r]
void dnco(int s, int e, int l, int r, int k) {
  if (s > e) return;
  int m = (s+e)/2;
  int opt = l;
  for (int i=l; i<=min(m-1, r); i++) {
    if (D[k-1][i] + cost(i+1, m) < D[k][m]) {
      D[k][m] = D[k-1][i] + cost(i+1, m);
      opt = i;
    }
  }
  dnco(s, m-1, l, opt, k);
  dnco(m+1, e, opt, r, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    cin >> C[i];
    psum[i] = psum[i-1] + C[i];
  }

  for (int k=0; k<=K; k++) fill(D[k], D[k]+N+1, INF);
  D[0][0] = 0;
  for (int k=1; k<=K; k++) dnco(1, N, 0, N-1, k);
  
  lld ans = INF;
  for (int k=1; k<=K; k++) ans = min(ans, D[k][N]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
