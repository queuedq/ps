#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 105;
const int _W = 1e6+5;
int X, T, M, V, N, x[_N], m[_N], c[_N];
int D[_N][_W];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> X >> T >> M >> V >> N;
  for (int i=1; i<=N; i++) cin >> x[i] >> m[i] >> c[i];

  int W = M*V*T - M*X;
  if (W < 0) { cout << -1 << endl; return 0; }

  for (int i=1; i<=N; i++) {
    int w = m[i] * x[i];
    for (int j=0; j<=W; j++) {
      D[i][j] = D[i-1][j];
      if (j >= w) D[i][j] = max(D[i][j], D[i-1][j-w] + c[i]);
    }
  }

  cout << D[N][W] << endl;

  ////////////////////////////////
  return 0;
}
