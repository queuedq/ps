#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, cnt[1<<20], D[1<<20];

void solve() {
  fill(cnt, cnt+(1<<20), 0);

  cin >> N;
  for (int i=0; i<N; i++) {
    int A; cin >> A;
    cnt[A]++;
  }

  for (int m=0; m<1<<20; m++) D[m] = cnt[m];
  for (int i=1; i<=20; i++) {
    for (int m=0; m<1<<20; m++) {
      if (m>>(i-1) & 1) D[m] += D[m ^ 1<<(i-1)];
    }
  }

  lld ans = 0;
  for (int m=0; m<1<<20; m++) ans += (lld)cnt[m] * D[m];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
