#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  vector<int> A;
  for (int i=1; sz(A)<=100'000; i++) {
    int cnt3 = 0, cnt5 = 0;
    int x = i;
    while (x%3 == 0) cnt3++, x/=3;
    while (x%5 == 0) cnt5++, x/=5;
    if ((cnt3-cnt5) % 3 == 0) A.push_back(i);
  }

  // cout << A.back() << endl; // 172964

  int T; cin >> T;
  while (T--) {
    int i; cin >> i;
    cout << A[i-1] << endl;
  }

  ////////////////////////////////
  return 0;
}
