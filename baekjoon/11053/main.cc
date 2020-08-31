#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, A[MAXN], D[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int ans = 0;
  for (int i=0; i<N; i++) {
    D[i] = 1;
    for (int j=0; j<i; j++) {
      if (A[j] < A[i]) D[i] = max(D[i], D[j]+1);
    }
    ans = max(ans, D[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
