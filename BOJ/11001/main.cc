#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, D, T[MAXN], V[MAXN], E[MAXN];

void dnco(int s, int e, int l, int r) {
  if (s > e) return;
  int m = (s+e)/2, opt = m;
  E[m] = -1;
  for (int i=max(m, l); i<=r && i<=m+D; i++) {
    if ((i-m) * T[i] + V[m] > E[m]) {
      E[m] = (i-m) * T[i] + V[m];
      opt = i;
    }
  }
  dnco(s, m-1, l, opt);
  dnco(m+1, e, opt, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=0; i<N; i++) cin >> T[i];
  for (int i=0; i<N; i++) cin >> V[i];

  dnco(0, N-1, 0, N-1);

  lld ans = 0;
  for (int i=0; i<N; i++) {
    ans = max(ans, E[i]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
