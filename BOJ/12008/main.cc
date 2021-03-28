#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 300'000;
int N, A[MN], len[61][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = 0;
  for (int k=1; k<=60; k++) {
    for (int i=0; i<N; i++) {
      if (A[i] == k) len[k][i] = 1;
      else {
        int j = i + len[k-1][i];
        if (i < j && j < N && len[k-1][j] > 0) {
          len[k][i] = len[k-1][i] + len[k-1][j];
        }
      }

      if (len[k][i] > 0) ans = max(ans, k);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
