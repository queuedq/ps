#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  int ans = -1;
  for (int i=0; i<=N/5; i++) {
    if ((N - i*5) % 3 == 0) ans = i + (N - i*5) / 3;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
