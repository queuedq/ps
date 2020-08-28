#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  sort(A, A+N);
  reverse(A, A+N);

  int ans = 0;
  for (int i=0; i<N; i++) {
    ans = max(ans, A[i] * (i+1));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
