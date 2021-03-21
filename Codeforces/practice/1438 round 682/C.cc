#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int n, m, A[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        cin >> A[i][j];
        if ((i+j+A[i][j]) % 2 == 1) A[i][j]++;
      }
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) cout << A[i][j] << " ";
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
