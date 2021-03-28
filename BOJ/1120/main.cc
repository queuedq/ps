#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string A, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B;

  int ans = B.size();
  for (int i=0; i<=B.size()-A.size(); i++) {
    int diff = 0;
    for (int j=0; j<A.size(); j++) {
      if (A[j] != B[i+j]) diff++;
    }
    ans = min(ans, diff);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
