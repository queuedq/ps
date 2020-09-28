#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
int N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  lld inv = 0, x = 0;
  for (int b=0; (1<<b) <= 1e9; b++) {
    int m = 1<<b;
    unordered_map<int, int> cnt0, cnt1;
    lld inv0 = 0, inv1 = 0;
    for (int i=0; i<N; i++) {
      if ((A[i] & m) == 0) {
        inv0 += cnt1[A[i]/m/2];
        cnt0[A[i]/m/2]++;
      } else {
        inv1 += cnt0[A[i]/m/2];
        cnt1[A[i]/m/2]++;
      }
    }
    // cout << cnt0[2] << " " << cnt1[2] << " " << inv0 << " " << inv1 << endl;
    if (inv0 <= inv1) {
      inv += inv0;
    } else {
      x += m;
      inv += inv1;
    }
  }

  cout << inv << " " << x << endl;

  ////////////////////////////////
  return 0;
}
