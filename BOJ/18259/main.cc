#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

void set_max(int &a, int b) { a = max(a, b); }

////////////////////////////////////////////////////////////////
const int MN = 305;
int N, M, D[MN][MN], mw[MN][MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int w, l, r; cin >> w >> l >> r;
    for (int j=l; j<=r; j++) set_max(mw[l][r][j], w);
  }

  for (int i=1; i<=N; i++) {
    for (int l=i; l>=1; l--) {
      for (int r=i; r<=N; r++) {
        if (l < i) set_max(mw[l][r][i], mw[l+1][r][i]);
        if (r > i) set_max(mw[l][r][i], mw[l][r-1][i]);
      }
    }
  }

  for (int r=1; r<=N; r++) {
    for (int l=r; l>=1; l--) {
      for (int i=l; i<=r; i++) {
        set_max(D[l][r], D[l][i-1] + D[i+1][r] + mw[l][r][i]);
      }
    }
  }

  cout << D[1][N] << endl;

  ////////////////////////////////
  return 0;
}
