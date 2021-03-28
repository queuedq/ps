#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MH = 21;
int H, W, A[MH][MH], D[MH][MH][MH][MH];

int dp(int d, int u, int l, int r) {
  if (d > u || l > r) return 0;
  if (D[d][u][l][r] != -1) return D[d][u][l][r];

  vector<bool> S(MH*MH * 2);
  for (int i=d; i<=u; i++) {
    for (int j=l; j<=r; j++) {
      if (A[i][j]) continue;
      int g = dp(d, i-1, l, j-1) ^ dp(d, i-1, j+1, r) ^
              dp(i+1, u, l, j-1) ^ dp(i+1, u, j+1, r);
      S[g] = 1;
    }
  }

  for (int i=0; ; i++) {
    if (!S[i]) return D[d][u][l][r] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> H >> W;
  for (int i=1; i<=H; i++) {
    string S; cin >> S;
    for (int j=1; j<=W; j++) A[i][j] = S[j-1] == 'X';
  }

  fill_n(D[0][0][0], MH*MH*MH*MH, -1);
  cout << (dp(1, H, 1, W) ? "First" : "Second") << endl;

  ////////////////////////////////
  return 0;
}
