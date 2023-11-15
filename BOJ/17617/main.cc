#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, R, M, x[MN*2], P[MN*2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> R >> M;
  for (int i=0; i<N; i++) cin >> x[i];
  sort(x, x+N);
  for (int i=0; i<N; i++) x[i+N] = x[i] + M;

  lld mn = 0, L = 0;
  for (int i=1; i<N*2; i++) {
    P[i] = P[i-1] + (x[i]-x[i-1] - R*2);
    L = max(L, P[i] - mn);
    mn = min(mn, P[i]);
  }

  cout << (L+1)/2 << endl;

  ////////////////////////////////
  return 0;
}
