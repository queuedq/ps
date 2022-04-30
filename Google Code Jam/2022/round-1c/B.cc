#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, K, A[MN];

void solve(int t) {
  cin >> N >> K;
  lld S = 0, T = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    S += A[i];
    T += A[i] * A[i];
  }

  if (S == 0 && T == 0) {
    cout << "Case #" << t << ": " << 0 << endl;
    return;
  }

  if (S != 0 && (T-S*S) % (2*S) == 0) {
    cout << "Case #" << t << ": " << ((T-S*S) / (2*S)) << endl;
    return;
  }

  if (K == 1) {
    cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    return;
  }

  cout << "Case #" << t << ": " << (-S+1) << " " << ((T+S*S)/2 - S) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
