#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 100010;
int c[4], d[4];
lld D[MX];

void solve() {
  for (int i=0; i<4; i++) cin >> c[i];
  int Q; cin >> Q;

  fill(D, D+MX, 0);
  D[0] = 1;
  for (int i=0; i<4; i++) {
    for (int v=c[i]; v<MX; v++) D[v] += D[v-c[i]];
  }

  for (int i=0; i<Q; i++) {
    for (int i=0; i<4; i++) cin >> d[i];
    int v; cin >> v;

    lld ans = 0;
    for (int b=0; b<16; b++) {
      int v1 = v;
      for (int i=0; i<4; i++)
        if (b>>i & 1) v1 -= c[i]*(d[i]+1);

      int pop = __builtin_popcount(b);
      if (v1 >= 0) ans += (pop%2 == 0) ? D[v1] : -D[v1];
    }

    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
