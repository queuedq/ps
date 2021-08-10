#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int N = 100;
int D[N+1][N+1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<N+1; i++) fill(D[i], D[i]+N+1, -1);

  for (int n=1; n<=N; n++) {
    for (int m=1; m<=N; m++) {
      vector<int> g(32);
      for (int i=2; i<=n-1; i++) g[D[i-1][m] ^ D[n-i][m]] = 1;
      for (int i=2; i<=m-1; i++) g[D[n][i-1] ^ D[n][m-i]] = 1;
      
      for (int i=0; i<g.size(); i++) {
        if (g[i] == 0) { D[n][m] = i; break; }
      }
    }
  }

  for (int i=1; i<=N; i++) {
    if (i < 10) cout << " ";
    cout << i << " ";
    for (int j=1; j<=N; j++) cout << D[i][j];
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
