#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
const int MAXP = 1<<20;
const int mask = (1<<20)-1;
int N, M, A[MAXN];
bool vst[MAXP];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  for (int m=0; m<M; m++) {
    int q, i, x; cin >> q >> i;
    switch(q) {
      case 1:
        cin >> x; x--;
        A[i] = A[i] | (1 << x);
        break;
      case 2:
        cin >> x; x--;
        A[i] = A[i] & (mask - (1 << x));
        break;
      case 3:
        A[i] = (A[i] << 1) & mask;
        break;
      default:
        A[i] >>= 1;
    }
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    if (vst[A[i]]) continue;
    vst[A[i]] = true;
    ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
