#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using uint = unsigned int;

////////////////////////////////////////////////////////////////
uint D[31][31][31][31][31];

uint dp(int a, int b, int c, int d, int e) {
  if (!a && !b && !c && !d && !e) return 1;
  if (D[a][b][c][d][e]) return D[a][b][c][d][e];

  uint ans = 0;
  if (a > b) ans += dp(a-1, b, c, d, e);
  if (b > c) ans += dp(a, b-1, c, d, e);
  if (c > d) ans += dp(a, b, c-1, d, e);
  if (d > e) ans += dp(a, b, c, d-1, e);
  if (e > 0) ans += dp(a, b, c, d, e-1);

  return D[a][b][c][d][e] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  dp(30, 30, 30, 30, 30);

  int T; cin >> T;
  for (int i=0; i<T; i++) {
    int k; cin >> k;
    int A[5] = {0, 0, 0, 0, 0};
    for (int i=0; i<k; i++) cin >> A[i];

    cout << D[A[0]][A[1]][A[2]][A[3]][A[4]] << endl;
  }

  ////////////////////////////////
  return 0;
}
