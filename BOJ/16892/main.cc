#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, A[MN], ans[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  for (int k=0; k<N; k++) {
    if (k >= 2) ans[k] = ans[k-2];
    if ((N-k) % 2 == 0) {
      int s = (N-k)/2, t = (N+k)/2;
      ans[k] = max({ans[k], A[s-1], A[s], A[t-1], A[t]});
    } else {
      int s = (N-k-1)/2, t = (N+k-1)/2;
      if (k == N-1) ans[k] = *max_element(A, A+N);
      else {
        ans[k] = max({
          ans[k],
          min(A[s], max(A[s-1], A[s+1])),
          min(A[t], max(A[t-1], A[t+1])),
        });
      }
    }
  }

  for (int k=0; k<N; k++) cout << ans[k] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
