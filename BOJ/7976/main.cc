#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, K, A[MN], cnt[MN][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cnt[i%K][A[i]%2]++;

  int ans = 0, p = 0, diff = N;
  for (int i=0; i<K; i++) {
    ans += min(cnt[i][0], cnt[i][1]);
    diff = min(diff, abs(cnt[i][0] - cnt[i][1]));
    if (cnt[i][0] < cnt[i][1]) p = !p;
  }

  if (p) ans += diff; // make sum even
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
