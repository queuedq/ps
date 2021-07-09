#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[101], B[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int t=0; t<N; t++) {
    int a, b; cin >> a >> b;
    A[a]++; B[b]++;

    int j = 100, bcnt = B[100], ans = 0;
    for (int i=1; i<=100; i++) {
      int acnt = A[i];
      while (acnt > 0) {
        if (acnt > bcnt) {
          if (bcnt > 0) ans = max(ans, i+j);
          acnt -= bcnt;
          bcnt = B[--j];
        } else {
          ans = max(ans, i+j);
          bcnt -= acnt;
          acnt = 0;
        }
      }
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
