#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 505;
int N, A[2*MAXN];
bool D[2*MAXN][MAXN][MAXN], E[2*MAXN][MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=2*N-1; i++) cin >> A[i];

  D[0][0][0] = true;

  for (int i=1; i<=2*N-1; i++) {
    for (int j=0; j<=N; j++) {
      for (int k=0; k<N; k++) {
        if (j <= i-1 && D[i-1][j][k]) {
          D[i][j][k] = true;
          E[i][j][k] = false;
        } else if (D[i-1][j-1][(k-A[i]+N) % N]) {
          D[i][j][k] = true;
          E[i][j][k] = true;
        }
      }
    }
  }

  if (!D[2*N-1][N][0]) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> rst;
  int i = 2*N-1, j = N, k = 0;
  while (i > 0) {
    if (E[i][j][k]) {
      rst.push_back(i);
      j--;
      k = (k-A[i]+N) % N;
    }
    i--;
  }

  for (auto it = rst.rbegin(); it < rst.rend(); it++) {
    cout << A[*it] << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
