#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string A, B, C;
const int MN = 101;
int D[MN][MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> A >> B >> C;
  for (int i=1; i<=sz(A); i++) {
    for (int j=1; j<=sz(B); j++) {
      for (int k=1; k<=sz(C); k++) {
        D[i][j][k] = max({D[i-1][j][k], D[i][j-1][k], D[i][j][k-1]});
        if (A[i-1] == B[j-1] && B[j-1] == C[k-1])
          D[i][j][k] = max(D[i][j][k], D[i-1][j-1][k-1]+1);
      }
    }
  }

  cout << D[sz(A)][sz(B)][sz(C)] << endl;

  ////////////////////////////////
  return 0;
}
