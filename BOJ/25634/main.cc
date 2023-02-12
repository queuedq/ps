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
int N, A[MN], B[MN], S[MN], ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];
  for (int i=1; i<=N; i++) if (B[i]) ans += A[i];

  for (int i=1; i<=N; i++) {
    if (B[i]) S[i] = S[i-1] - A[i];
    else S[i] = S[i-1] + A[i];
  }

  int L = 0, cost = -1e9;
  for (int i=1; i<=N; i++) {
    cost = max(cost, S[i] - L);
    L = min(L, S[i]);
  }

  ans += cost;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
