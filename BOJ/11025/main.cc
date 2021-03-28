#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, K;
  cin >> N >> K;
  int D = 1;
  for (int i=2; i<=N; i++) {
    D = (D+K) % i;
    if (D == 0) D = i;
  }

  cout << D << endl;

  ////////////////////////////////
  return 0;
}
