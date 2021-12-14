#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve() {
  int N, A[101], vst[101];
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  fill(vst, vst+N+1, 0);

  bool parity = 0;
  for (int i=1; i<=N; i++) {
    int j = i, cnt = 0;
    while (!vst[j]) {
      vst[j] = true;
      j = A[j];
      cnt++;
    }
    if (cnt != 0) parity ^= (cnt-1)%2;
  }

  cout << (parity ? "NO" : "YES") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
