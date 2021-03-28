#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;
map<vector<int>, int> P;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;

  int ans = 0;
  vector<int> sum(K);
  P[sum] = 0;
  for (int i=1; i<=N; i++) {
    int A; cin >> A;

    int bottom = INT_MAX;
    for (int j=0; j<K; j++) {
      if (A & (1 << j)) sum[j]++;
      bottom = min(bottom, sum[j]);
    }

    for (int j=0; j<K; j++) sum[j] -= bottom;

    if (P.find(sum) == P.end()) P[sum] = i;
    else ans = max(ans, i - P[sum]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
