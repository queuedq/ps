#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, D[100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=1; i<=N; i++) {
    D[i] = i;
    for (int j=1; ; j++) {
      if ((1<<j)-1 > i) break;
      int tmp = D[i];
      D[i] = min(D[i], D[i-(1<<j)+1] + j);
      assert(tmp >= D[i]);
    }

    cout << i << " " << D[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
