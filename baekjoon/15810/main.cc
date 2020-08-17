#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MAXN = 1e6+5;
lld N, M, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];

  lld l = 0, r = M*MAXN/N + MAXN;
  while (l+1 < r) {
    lld mid = (l+r)/2, cnt = 0;
    for (int i=0; i<N; i++) {
      cnt += mid / A[i];
    }
    if (cnt >= M) r = mid;
    else l = mid;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
