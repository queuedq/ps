#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 25;
int N, D[MN][MN], tot;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      cin >> D[i][j];
      if (i < j) tot += D[i][j];
    }
  }

  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      for (int k=1; k<=N; k++) {
        if (k == i || k == j) continue;
        if (D[i][j] > D[i][k] + D[k][j]) { cout << -1 << endl; return 0; }
        if (D[i][j] == D[i][k] + D[k][j]) { tot -= D[i][j]; break; }
      }
    }
  }

  cout << tot << endl;

  ////////////////////////////////
  return 0;
}
