#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
////////////////////////////////
const int MX = 30;
int m, cnt[MX];
char A[MX];
lld ans = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////
  
  cin >> m;
  for (int i=1; i<=m; i++) cin >> A[i] >> cnt[i];
  
  lld moves = 1;
  for (int i=m; i>=1; i--) {
    if (A[i] == 'G' || cnt[i] == 1) {
      ans += cnt[i] * moves;
      moves *= 2;
    } else if (A[i] == 'R') {
      if (moves % 2 == 0) {
        ans += cnt[i] * (moves + 1);
        moves = moves * 2 + 1;
        if (i == 1) ans--;
      } else {
        ans += cnt[i] * moves;
        moves *= 2;
      }
    } else if (A[i] == 'B') {
      if (moves % 2 == 1) {
        ans += cnt[i] * (moves + 1);
        moves = moves * 2 + 1;
        if (i == 1) ans--;
      } else {
        ans += cnt[i] * moves;
        moves *= 2;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
