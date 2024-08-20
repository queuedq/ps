#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
lld D[33][2][2]; // match from msb to ith bit, carry info

void solve() {
  cin >> N >> M;
  N--, M--;

  D[32][0][0] = 1;
  for (int i=31; i>=0; i--) {
    int n = N>>i & 1, m = M>>i & 1;
    for (int x: {0, 1}) for (int y: {0, 1}) {
      D[i][x][y] = 0;
      if ((n^x) == (m^y)) { // ith bit match
        for (int a: {0, 1}) for (int b: {0, 1}) {
          D[i][x][y] += D[i+1][x+a>n][y+b>m]; // carry down from i+1-th bit
        }
      }
    }
  }

  cout << D[0][0][0] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
