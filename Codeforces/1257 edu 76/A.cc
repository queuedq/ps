#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    cout << min(n - 1, abs(a - b) + x) << endl;
  }

  ////////////////////////////////
  return 0;
}
