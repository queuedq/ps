#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, D[10005], E[10005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  N = 10000;

  for (int i=1; i<=N; i++) {
    D[i] = i;
    for (int j=1; ; j++) {
      if ((1<<j)-1 > i) break;
      int tmp = D[i];
      D[i] = min(D[i], D[i-(1<<j)+1] + j);
      assert(tmp >= D[i]);
    }
  }

  for (int i=1; i<=N; i++) {
    int x = i;
    for (int j=31; j>0; j--) {
      while ((1<<j)-1 <= x) {
        x -= (1<<j)-1;
        E[i] += j;
      }
    }
  }

  for (int i=1; i<=N; i++) {
    if (D[i] != E[i]) cout << "DIFFERENT " << i << endl;
  }

  ////////////////////////////////
  return 0;
}
