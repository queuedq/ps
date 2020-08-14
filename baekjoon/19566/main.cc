#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
lld N, K, A[MAXN], ans;
unordered_map<lld, lld> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    A[i] -= K;
  }

  lld sum = 0;
  cnt[0] = 1;
  for (int i=1; i<=N; i++) {
    sum += A[i];
    ans += cnt[sum];
    cnt[sum]++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
