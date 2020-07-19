#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  lld sum = 0;
  double ans = 0;
  for (int i=0; i<N; i++) {
    sum += A[i];
    ans = max(ans, (double)sum / (i+1));
  }

  sum = 0;
  for (int i=N-1; i>=0; i--) {
    sum += A[i];
    ans = max(ans, (double)sum / (N-i));
  }

  cout << setprecision(12) << fixed << ans << endl;

  ////////////////////////////////
  return 0;
}
