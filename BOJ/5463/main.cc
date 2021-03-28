#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, A[55][55], S[55][55];
int D[55][55][55][55];

int dp(int ax, int ay, int bx, int by) {
  if (D[ax][ay][bx][by]) return D[ax][ay][bx][by];
  if (ax == bx && ay == by) return 0;

  int ans = INT_MAX;
  for (int i=ax; i<bx; i++) {
    ans = min(ans, dp(ax, ay, i, by) + dp(i+1, ay, bx, by));
  }
  for (int j=ay; j<by; j++) {
    ans = min(ans, dp(ax, ay, bx, j) + dp(ax, j+1, bx, by));
  }
  int s = S[bx][by] - S[ax-1][by] - S[bx][ay-1] + S[ax-1][ay-1];
  return D[ax][ay][bx][by] = ans + s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      cin >> A[i][j];
      S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
    }
  }

  cout << dp(1, 1, N, M) << endl;

  ////////////////////////////////
  return 0;
}
