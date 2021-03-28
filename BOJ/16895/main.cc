#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  vector<int> P(N);
  int nim = 0;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    nim ^= P[i];
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < P[i]; j++) {
      if ((nim ^ P[i] ^ j) == 0) ans++;
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
