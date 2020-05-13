#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 50005;
const int ST = 1<<16;
int N, D;
lld seg[ST*2][2][2];

void update(int i, lld val) {
  int n = ST+i;
  seg[n][1][1] = val;

  for (n /= 2; n > 0; n /= 2) {
    for (int l=0; l<2; l++) {
      for (int r=0; r<2; r++) {
        seg[n][l][r] = max({
          seg[n*2][l][0] + seg[n*2+1][0][r],
          seg[n*2][l][0] + seg[n*2+1][1][r],
          seg[n*2][l][1] + seg[n*2+1][0][r],
        });
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=0; i<N; i++) {
    int m; cin >> m;
    update(i, m);
  }

  lld ans = 0;
  for (int i=0; i<D; i++) {
    int j, m; cin >> j >> m;
    update(j-1, m);
    ans += max({seg[1][0][0], seg[1][0][1], seg[1][1][0], seg[1][1][1]});
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
