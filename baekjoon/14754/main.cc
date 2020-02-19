#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX = 1005;
int n, m, a[MAX][MAX], b[MAX][MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] > a[i][k]) k = j;
    }
    b[i][k] = a[i][k];
  }

  for (int j = 0; j < m; j++) {
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] > a[k][j]) k = i;
    }
    b[k][j] = a[k][j];
  }

  lld ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += a[i][j] - b[i][j];
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
