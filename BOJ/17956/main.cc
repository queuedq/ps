#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int n, s1, s2;
lld D[2][MN*2][MN];

struct Quest {
  lld x, t, y, r;
  bool operator<(const Quest &Q) const { return x < Q.x; }
};
Quest A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> s1 >> s2;
  for (int i=0; i<n; i++) cin >> A[i].x >> A[i].t >> A[i].y >> A[i].r;
  sort(A, A+n);

  for (int j=0; j<=s1+s2; j++) fill(D[0][j], D[0][j]+s2+1, LLONG_MAX);
  D[0][0][0] = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<=s1+s2; j++) fill(D[~i&1][j], D[~i&1][j]+s2+1, LLONG_MAX);

    for (int j=0; j<=s1+s2; j++) {
      for (int k=0; k<=s2; k++) {
        if (D[i&1][j][k] == LLONG_MAX) continue;
        int jj = min(j+A[i].x, (lld)s1+s2);
        int kk = min(k+A[i].y, (lld)s2);
        D[~i&1][j][k] = min(D[~i&1][j][k], D[i&1][j][k]);
        if (j < s1) D[~i&1][jj][k] = min(D[~i&1][jj][k], D[i&1][j][k] + A[i].t);
        D[~i&1][j][kk] = min(D[~i&1][j][kk], D[i&1][j][k] + A[i].r);
      }
    }
  }

  lld ans = LLONG_MAX;
  for (int j=s1; j<=s1+s2; j++) {
    for (int k=s2-(j-s1); k<=s2; k++) {
      ans = min(ans, D[n&1][j][k]);
    }
  }

  cout << (ans == LLONG_MAX ? -1 : ans) << endl;

  ////////////////////////////////
  return 0;
}
