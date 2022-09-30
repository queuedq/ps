#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 205;
int D[MN][MN];

void solve(int test) {
  string A, B, C;
  cin >> A >> B >> C;
  int N = sz(A), M = sz(B);
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=M; j++) {
      D[i][j] = 0;
      if (i == 0 && j == 0) { D[i][j] = 1; continue; }
      if (i > 0) D[i][j] |= (A[i-1] == C[i+j-1]) && D[i-1][j];
      if (j > 0) D[i][j] |= (B[j-1] == C[i+j-1]) && D[i][j-1];
    }
  }
  cout << "Data set " << test << ": " << (D[N][M] ? "yes" : "no") << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
