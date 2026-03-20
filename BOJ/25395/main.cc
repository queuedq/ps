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
int N, S, x[MN], h[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> S;
  for (int i=1; i<=N; i++) cin >> x[i];
  for (int i=1; i<=N; i++) cin >> h[i];
  
  int l = S, r = S;
  int L = x[S], R = x[S];

  while (1) {
    bool done = 1;
    while (l >= 1 && x[l] >= L) {
      L = min(L, x[l]-h[l]);
      R = max(R, x[l]+h[l]);
      l--;
      done = 0;
    }
    while (r <= N && x[r] <= R) {
      L = min(L, x[r]-h[r]);
      R = max(R, x[r]+h[r]);
      r++;
      done = 0;
    }
    if (done) break;
  }

  for (int i=l+1; i<=r-1; i++) cout << i << ' ';

  ////////////////////////////////
  return 0;
}
