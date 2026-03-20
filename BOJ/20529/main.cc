#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
int N;
string A[MN];

int dist(int i, int j) {
  int res = 0;
  for (int k=0; k<4; k++) {
    res += (A[i][k] != A[j][k]);
  }
  return res;
}

int solve() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  if (N > 32) return 0;

  int ans = INT_MAX;
  for (int k=0; k<N; k++) {
    for (int j=0; j<k; j++) {
      for (int i=0; i<j; i++) {
        ans = min(ans, dist(i, j) + dist(j, k) + dist(k, i));
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
