#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N, C, x[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> C;
  for (int i=0; i<N; i++) cin >> x[i];
  sort(x, x+N);

  int l = 0, r = 1e9+1;
  while (l+1 < r) {
    int mid = (l+r)/2;

    int last = x[0], cnt = 1;
    for (int i=1; i<N; i++) {
      if (x[i] - last >= mid) {
        last = x[i];
        cnt++;
      }
    }

    if (cnt >= C) l = mid;
    else r = mid;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
