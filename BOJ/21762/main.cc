#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int xl[MN], xr[MN], yl[MN], yr[MN];
int P[MN][26], Q[MN][26];

bool solve() {
  string X, Y, W; cin >> X >> Y >> W;
  int N = sz(X), M = sz(Y), K = sz(W);
  X = " " + X; Y = " " + Y; W = " " + W;

  // prefix sum
  for (int i=1; i<=N; i++) {
    for (int c=0; c<26; c++) P[i][c] = P[i-1][c];
    P[i][X[i]-'a']++;
  }
  for (int i=1; i<=M; i++) {
    for (int c=0; c<26; c++) Q[i][c] = Q[i-1][c];
    Q[i][Y[i]-'a']++;
  }

  // find leftmost/rightmost match
  xl[0] = 0, xr[K+1] = N+1;
  for (int i=1, j=1; i<=N; i++) if (X[i] == W[j]) xl[j++] = i;
  for (int i=N, j=K; i>=1; i--) if (X[i] == W[j]) xr[j--] = i;

  yl[0] = 0, yr[K+1] = M+1;
  for (int i=1, j=1; i<=M; i++) if (Y[i] == W[j]) yl[j++] = i;
  for (int i=M, j=K; i>=1; i--) if (Y[i] == W[j]) yr[j--] = i;

  // get ans
  for (int j=0; j<=K; j++) {
    int xs = xl[j], xe = xr[j+1];
    int ys = yl[j], ye = yr[j+1];
    for (int c=0; c<26; c++) {
      if (P[xe-1][c] - P[xs][c] > 0 && Q[ye-1][c] - Q[ys][c] > 0) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
