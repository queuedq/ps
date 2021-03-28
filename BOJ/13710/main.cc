#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;;
int N, A[MN], psum[30][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  
  lld ans = 0;
  for (int k=0; k<30; k++) {
    for (int i=1; i<=N; i++) psum[k][i] = psum[k][i-1] ^ (A[i]>>k & 1);

    lld ecnt=1, ocnt=0;
    for (int i=1; i<=N; i++) {
      if (psum[k][i]) {
        ans += ecnt << k;
        ocnt++;
      } else {
        ans += ocnt << k;
        ecnt++;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
