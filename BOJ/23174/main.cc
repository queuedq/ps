#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100;
const lld INF = 3e18;
lld N, K, P, c[MN], w[MN];
vector<pll> D[MN][MN], E[MN]; // D[i][j]: c[i] * 2^j // E[i]: P % c[i]

pll min_max(pll a, pll b) {
  return {min(a.X, b.X), max(a.Y, b.Y)};
}

vector<pll> conv(vector<pll> &A, vector<pll> &B) {
  vector<pll> res(K+1, {INF, -INF});
  for (int i=0; i<=K; i++) {
    for (int j=0; j<=K-i; j++) {
      res[i+j] = min_max(res[i+j], {A[i].X + B[j].X, A[i].Y + B[j].Y});
    }
  }
  return res;
}

void fill_D(int i) {
  D[i+1][0].assign(K+1, {INF, -INF});
  D[i+1][0][0] = {0, 0};
  
  lld r = c[i+1] / c[i];
  for (int j=0; r>0; j++) {
    if (j > 0) D[i][j] = conv(D[i][j-1], D[i][j-1]);

    if (r>>j & 1) {
      D[i+1][0] = conv(D[i+1][0], D[i][j]);
      r -= 1LL<<j;
    }
  }
  if (i+1 < N) D[i+1][0][1] = {w[i+1], w[i+1]};
}

void fill_E(int i) {
  E[i+1] = E[i];
  
  lld r = (P % c[i+1]) / c[i];
  for (int j=0; r>0; j++) {
    if (r>>j & 1) {
      E[i+1] = conv(E[i+1], D[i][j]);
      r -= 1LL<<j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> P;
  for (int i=0; i<N; i++) cin >> c[i] >> w[i];
  if (P % c[0] != 0) { cout << "-1" << endl; return 0; }
  c[N] = P; // for simpler implementation

  D[0][0].assign(K+1, {INF, -INF}); D[0][0][1] = {w[0], w[0]};
  E[0].assign(K+1, {INF, -INF}); E[0][0] = {0, 0};
  for (int i=0; i<N; i++) { fill_D(i); fill_E(i); }

  pll ans = conv(D[N][0], E[N-1])[K];
  if (ans.X >= INF) cout << "-1" << endl;
  else cout << ans.X << " " << ans.Y << endl;

  ////////////////////////////////
  return 0;
}
