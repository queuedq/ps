#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 505;
int N, adj[MAXN][MAXN], D[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> adj[i][j];
    }
  }

  for (int l=2; l<=N; l++) {
    for (int i=0; i<N; i++) {
      int j = i+l-1;
      if (j >= N) break;
      for (int k=i; k<j; k++) D[i][j] = max(D[i][j], D[i][k]+D[k+1][j]);
      if (adj[i][j] == 1) D[i][j] = max(D[i][j], D[i+1][j-1]+1);
    }
  }

  cout << D[0][N-1] << endl;

  ////////////////////////////////
  return 0;
}
