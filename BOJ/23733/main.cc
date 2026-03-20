#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, K, D[20][20], p10[18];
string S;

void solve() {
  cin >> N >> K >> S;
  reverse(all(S));
  for (int i=1; i<=N; i++) {
    lld d = S[i-1] - '0';
    D[i][0] = D[i][i] = D[i-1][0] + d * p10[i-1];
    for (int j=1; j<i; j++) {
      D[i][j] = max(D[i-1][j-1] + d * p10[j-1], D[i-1][j] + d * p10[i-j-1]);
    }
  }
  cout << D[N][K] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  p10[0] = 1;
  for (int i=1; i<18; i++) p10[i] = p10[i-1] * 10;

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
