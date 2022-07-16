#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3e5+5;
int N, P[MN], V[MN], idx[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> P[i];
    for (int i=0; i<N; i++) cin >> V[i];
    iota(idx, idx+N, 0);
    sort(idx, idx+N, [](int a, int b) { return pii(V[a], a) < pii(V[b], b); });

    lld ans = 0;
    for (int i=0; i<N; i++) {
      int j = idx[i];
      ans += abs(P[i] - P[j]);
    }
    cout << "Case #" << t << endl;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
