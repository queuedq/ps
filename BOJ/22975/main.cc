#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2005;
int N, H[MN], ans = 1;

struct Line {
  int s, e, dp;
  bool operator <(const Line &L) const {
    return (lld)(H[e] - H[s]) * (L.e - L.s) < (lld)(H[L.e] - H[L.s]) * (e - s);
  }
  bool operator <=(const Line &L) const { return !(L < *this); }
};
Line D[MN][MN];
int dmax[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];

  for (int i=1; i<=N; i++) {
    for (int j=1; j<i; j++) {
      D[i][j] = {j, i, 0};

      int l = 0, r = j;
      while (l+1 < r) {
        int m = (l+r) / 2;
        if (D[j][m] <= D[i][j]) l = m;
        else r = m;
      }

      D[i][j].dp = dmax[j][l] + 1;
    }

    sort(D[i]+1, D[i]+i);
    dmax[i][0] = 1;
    for (int j=1; j<i; j++) {
      dmax[i][j] = max(dmax[i][j-1], D[i][j].dp);
      ans = max(ans, dmax[i][j]);
    }
  }

  cout << N - ans << endl;

  ////////////////////////////////
  return 0;
}
