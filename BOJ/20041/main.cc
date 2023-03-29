#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, x[MN], y[MN], sx, sy;
bool l, r, d, u;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> x[i] >> y[i];
  cin >> sx >> sy;
  for (int i=0; i<N; i++) x[i] -= sx, y[i] -= sy;

  for (int i=0; i<N; i++) {
    if (abs(x[i]) >= abs(y[i])) {
      if (x[i] < 0) l = 1;
      if (x[i] > 0) r = 1;
    }
    if (abs(x[i]) <= abs(y[i])) {
      if (y[i] < 0) d = 1;
      if (y[i] > 0) u = 1;
    }
  }

  if (!l || !r || !d || !u) cout << "YES" << endl;
  else cout << "NO" << endl;

  ////////////////////////////////
  return 0;
}
