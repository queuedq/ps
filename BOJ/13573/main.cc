#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, cnt[1<<20], D[2][1<<20][21];
char A[21][101010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
  }
  for (int j=0; j<M; j++) {
    int x = 0;
    for (int i=0; i<N; i++) {
      if (A[i][j] == 'T') x += 1<<i;
    }
    cnt[x]++;
  }

  for (int m=0; m<1<<N; m++) D[0][m][0] = cnt[m];

  for (int i=1; i<=N; i++) {
    for (int m=0; m<1<<N; m++) {
      D[i&1][m][0] = D[~i&1][m][0];
      for (int j=1; j<=N; j++) {
        D[i&1][m][j] = D[~i&1][m][j] + D[~i&1][m^(1<<(i-1))][j-1];
      }
    }
  }

  int ans = N*M;
  for (int m=0; m<1<<N; m++) {
    int tail = 0;
    for (int j=0; j<=N; j++) {
      tail += D[N&1][m][j] * min(j, N-j);
    }
    ans = min(ans, tail);
  }

  cout << ans << endl;  

  ////////////////////////////////
  return 0;
}
