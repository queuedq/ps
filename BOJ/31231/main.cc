#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, S[MN], ans[MN], cnt[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    char c; cin >> c;
    S[i] = c-'0';
    cnt[c-'0']++;
  }

  for (int d=9; d>=1; d--) {
    // fill pairs containing d
    for (int i=0, j=N-1; i<=j; i++, j--) {
      if (ans[i]) continue;

      if (S[i] == d || S[j] == d) {
        ans[i] = ans[j] = d;
        if (S[i] != d) cnt[d]--;
        if (S[j] != d) cnt[d]--;
      }
    }

    // place remaining d's
    for (int i=0, j=N-1; i<=j; i++, j--) {
      if (ans[i]) continue;

      if (i != j) { // place two d's
        if (cnt[d] >= 2) ans[i] = ans[j] = d, cnt[d] -= 2;
      } else { // place one d at the center
        if (cnt[d] >= 1) ans[i] = d, cnt[d]--;
      }
    }
  }

  for (int i=0; i<N; i++) cout << ans[i];
  cout << endl;

  ////////////////////////////////
  return 0;
}
