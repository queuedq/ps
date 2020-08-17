#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int T, N;
string A;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    cin >> N >> A;

    int i = 1;
    while (i < N && A[i-1] == A[i]) i++;

    if (i == N) { // all same
      cout << (N-1)/3 + 1 << endl;
      continue;
    }

    int start = i, cnt = 0, ans = 0;

    for (; i<N; i++) {
      if (A[i-1] != A[i]) {
        ans += cnt/3;
        cnt = 1;
      } else {
        cnt++;
      }
    }

    if (A[N-1] != A[0]) ans += start/3 + cnt/3;
    else ans += (start+cnt)/3;
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
