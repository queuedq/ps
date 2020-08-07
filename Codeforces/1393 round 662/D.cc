#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2005;
int N, M, A[MAXN][MAXN], D[MAXN][MAXN];

bool oob(int i, int j) {
  return i < 0 || j < 0 || i >= N || j >= M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (int j=0; j<M; j++) {
      A[i][j] = s[j] - 'a';
    }
  }

  lld ans = 0;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (
        !oob(i-1, j-1) && !oob(i-1, j+1) &&
        A[i][j] == A[i-1][j] && A[i][j] == A[i-1][j-1] && A[i][j] == A[i-1][j+1]
      ) {
        D[i][j] = min(D[i-1][j-1], D[i-1][j+1]);
        int d = D[i][j];
        if (
          !oob(i-d*2, j) && A[i][j] == A[i-1][j] &&
          A[i][j] == A[i-d*2][j] && A[i][j] == A[i-d*2+1][j]
        ) {
          D[i][j]++;
        }
      } else {
        D[i][j] = 1;
      }
      ans += D[i][j];
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
