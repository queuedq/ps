#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, A[MN], B[MN], P[MN], Q[MN];
map<int, int> cnt;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];

  for (int i=1; i<=N; i++) P[i] = P[i-1] + A[i];
  for (int i=1; i<=N; i++) Q[i] = Q[i-1] + B[i];

  lld ans = 0;
  cnt[0]++;
  for (int i=1; i<=N; i++) {
    ans += cnt[P[i] - Q[i]];
    cnt[P[i] - Q[i]]++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
