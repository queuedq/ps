#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 4005;
const int MK = 805;
const int INF = 1e9;
int N, K, A[MN][MN], psum[MN][MN], cost[MN][MN], D[MK][MN];

void dnco(int s, int e, int l, int r, int k) {
  if (s > e) return;
  int m = (s+e)/2;
  int opt = l;
  D[k][m] = INF;
  for (int i=l; i<=min(r, m-1); i++) {
    if (D[k-1][i] + cost[i+1][m] < D[k][m]) {
      D[k][m] = D[k-1][i] + cost[i+1][m];
      opt = i;
    }
  }
  dnco(s, m-1, l, opt, k);
  dnco(m+1, e, opt, r, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      cin >> A[i][j];
      psum[i][j] = psum[i][j-1] + A[i][j];
    }
  }

  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      cost[i][j] = cost[i][j-1] + (psum[j][j-1] - psum[j][i-1]);
    }
  }

  fill(D[0], D[0]+N+1, INF);
  D[0][0] = 0;
  for (int k=1; k<=K; k++) dnco(1, N, 0, N, k);
  cout << D[K][N] << endl;

  ////////////////////////////////
  return 0;
}
