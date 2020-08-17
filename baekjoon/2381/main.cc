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
  int mna = 2e6+5, mxa = -2e6-5, mnb = 2e6+5, mxb = -2e6-5;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    mna = min(mna, x+y);
    mxa = max(mxa, x+y);
    mnb = min(mnb, x-y);
    mxb = max(mxb, x-y);
  }

  cout << max(mxa-mna, mxb-mnb) << endl;

  ////////////////////////////////
  return 0;
}
