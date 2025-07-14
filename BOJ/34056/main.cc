#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 202020;
lld N, D[MX], Q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> D[i];

  cin >> Q;
  for (int q=0; q<Q; q++) {
    lld t, c, x; cin >> t;

    if (t == 1) {
      cin >> c >> x;

      lld s = x;
      for (int i=c; i>=1 && s > 0; i--) {
        lld dt = min(D[i], s);
        D[i] += dt;
        s -= dt;
      }
      s = x;
      for (int i=c+1; i<=N && s > 0; i++) {
        lld dt = min(D[i], s);
        D[i] += dt;
        s -= dt;
      }

    } else {
      cin >> c;
      cout << D[c] << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
