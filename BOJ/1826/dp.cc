#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
const int INF = 1e9;
int N, L, P, D[2][MN];

struct Fuel { int d, v; };
Fuel F[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////
  cin >> N;
  for (int i=1; i<=N; i++) {
    int d, v; cin >> d >> v;
    F[i] = {d, v};
  }
  cin >> L >> P;
  sort(F+1, F+N+1, [](Fuel A, Fuel B) { return A.d < B.d; });

  D[0][0] = P; // until i-th fuel, stop j times, max fuel
  for (int i=1; i<=N; i++) {
    int dst = (F[i].d - F[i-1].d);

    for (int j=0; j<=i; j++) {
      D[i&1][j] = -INF;

      if (j <= i-1 && D[(i-1)&1][j] >= dst) { // don't stop
        D[i&1][j] = max(D[i&1][j], D[(i-1)&1][j] - dst);
      }
      if (j-1 >= 0 && D[(i-1)&1][j-1] >= dst) { // stop
        D[i&1][j] = max(D[i&1][j], D[(i-1)&1][j-1] - dst + F[i].v);
      }
    }
  }

  int j = 0;
  for (; j<=N; j++) {
    if (D[N&1][j] >= L - F[N].d) break;
  }
  if (j == N+1) cout << -1 << endl;
  else cout << j << endl;

  ////////////////////////////////
  return 0;
}
