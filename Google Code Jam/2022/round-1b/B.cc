#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, P, S[MN], E[MN], D[MN][2];

lld solve() {
  cin >> N >> P;

  D[0][0] = D[0][1] = 0;

  for (int i=1; i<=N; i++) {
    S[i] = 1e9+5; E[i] = 0;
    for (int j=0; j<P; j++) {
      lld X; cin >> X;
      S[i] = min(S[i], X);
      E[i] = max(E[i], X);
    }
    
    D[i][0] = min(
      D[i-1][0] + abs(E[i-1] - S[i]),
      D[i-1][1] + abs(S[i-1] - S[i])
    ) + (E[i] - S[i]);

    D[i][1] = min(
      D[i-1][0] + abs(E[i-1] - E[i]),
      D[i-1][1] + abs(S[i-1] - E[i])
    ) + (E[i] - S[i]);
  }

  return min(D[N][0], D[N][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld answer = solve();
    cout << "Case #" << t << ": " << answer << endl;
  }

  ////////////////////////////////
  return 0;
}
