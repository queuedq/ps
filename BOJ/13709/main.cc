#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  for (int i=0; i<N; i++) {
    int k = max_element(A+i, A+N) - A;
    swap(A[i], A[k]);
    if (A[i] == 0) break;
    
    int b = 0;
    while (A[i] >= (1LL<<b)) b++;
    b--;

    for (int j=i+1; j<N; j++) {
      if (A[j]>>b & 1LL) A[j] ^= A[i];
    }
  }

  lld ans = 0;
  for (int i=0; i<N; i++) {
    if (A[i] == 0) break;
    ans = max(ans, ans ^ A[i]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
