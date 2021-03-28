#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 25;
int N;
string A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = INT_MAX;
  for (int i=0; i<(1<<N); i++) {
    int tot = 0;
    for (int j=0; j<N; j++) {
      int cnt = 0;
      for (int k=0; k<N; k++) {
        bool back = A[j][k] == 'T';
        if (i & (1<<k)) back = !back;
        cnt += back;
      }
      tot += min(cnt, N-cnt);
    }
    ans = min(ans, tot);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
