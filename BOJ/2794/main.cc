#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1<<9;
int K, adj[MN][MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K;
  for (int i=0; i<1<<K; i++) {
    for (int j=0; j<1<<K; j++) {
      cin >> adj[i][j];
      D[i][j] = INT_MAX;
    }
  }

  for (int j=0; j<1<<K; j++) D[0][j] = 0;
  for (int i=1; i<1<<K; i++) {
    int lsb = i&-i; // prev group size
    for (int j=0; j<1<<K; j++) {
      for (int b=0; b<lsb; b++) {
        int k = j ^ lsb ^ b; // possible prev group num
        D[i][j] = min(D[i][j], D[i-1][k] + adj[k][j]);
      }
    }
  }

  int ans = INT_MAX;
  for (int j=0; j<1<<K; j++) ans = min(ans, D[(1<<K)-1][j]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
