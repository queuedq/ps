#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, A[MAXN], D[MAXN][2];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  D[0][0] = A[0];
  D[1][0] = A[0]+A[1];
  D[0][1] = MAXN;
  D[1][1] = A[0];
  for (int i=2; i<N; i++) {
    D[i][0] = min(D[i-2][1]+A[i-1]+A[i], D[i-1][1]+A[i]);
    D[i][1] = min(D[i-2][0], D[i-1][0]);
  }

  cout << min(D[N-1][0], D[N-1][1]) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
