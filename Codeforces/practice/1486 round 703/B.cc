#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
lld N, X[MN], Y[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> X[i] >> Y[i];
    sort(X, X+N);
    sort(Y, Y+N);
    lld x = X[N/2] - X[(N-1)/2] + 1;
    lld y = Y[N/2] - Y[(N-1)/2] + 1;
    cout << x*y << endl;
  }

  ////////////////////////////////
  return 0;
}
