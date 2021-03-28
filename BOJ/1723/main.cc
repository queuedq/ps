#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
int N, K;
double A[MAXN*2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) A[i+N] = A[i] + 360;
  sort(A, A+N*2);

  int ans = 99999;
  for (int i=0; i<N; i++) {
    int mx = 0, mn = 99999;
    int cnt = 0, k = i;
    for (int j=1; j<=K; j++) {
      while (A[k] < A[i] + 360.0/K * j) {
        cnt++;
        k++;
      }
      mx = max(mx, cnt);
      mn = min(mn, cnt);
      cnt = 0;
    }
    ans = min(ans, mx - mn);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
