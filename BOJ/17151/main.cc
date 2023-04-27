#include <bits/stdc++.h>
#include <climits>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
lld N, h, a, b, x[MN], y[MN], D[MN];
bool ok[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> h >> a >> b;
  for (int i=0; i<N; i++) cin >> x[i] >> y[i];
  for (int i=0; i<N; i++) y[i] = h - y[i];

  for (int i=0; i<N; i++) {
    // max radius = x + y + sqrt(2xy)
    double R = y[i];
    for (int j=i+1; j<N; j++) {
      R = min(R, x[j]-x[i] + y[j] + sqrt(2 * (x[j]-x[i]) * y[j]));
      if (x[j]-x[i] <= 2*R) ok[i][j] = 1;
      else break;
    }

    R = y[i];
    for (int j=i-1; j>=0; j--) {
      R = min(R, x[i]-x[j] + y[j] + sqrt(2 * (x[i]-x[j]) * y[j]));
      if (x[i]-x[j] <= 2*R) ok[i][j] = 1;
      else break;
    }
  }

  D[0] = a * y[0];
  for (int i=1; i<N; i++) {
    D[i] = LLONG_MAX;
    for (int j=0; j<i; j++) {
      if (ok[i][j] && ok[j][i] && D[j] != LLONG_MAX) {
        D[i] = min(D[i], D[j] + a*y[i] + b*(x[i]-x[j])*(x[i]-x[j]));
      }
    }
  }

  if (D[N-1] == LLONG_MAX) cout << "impossible" << endl;
  else cout << D[N-1] << endl;

  ////////////////////////////////
  return 0;
}
