#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 200'005;
int m, Q, f[MN][20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> m;
  for (int i=1; i<=m; i++) cin >> f[i][0];

  for (int k=1; k<20; k++) {
    for (int i=1; i<=m; i++) {
      f[i][k] = f[ f[i][k-1] ][k-1];
    }
  }

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int n, x; cin >> n >> x;
    for (int k=19; k>=0; k--) {
      if (1<<k <= n) {
        n -= 1<<k;
        x = f[x][k];
      }
    }
    cout << x << endl;
  }

  ////////////////////////////////
  return 0;
}
