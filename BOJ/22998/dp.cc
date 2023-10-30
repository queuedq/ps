#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 1<<18;
int D[MK];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  D[0] = 0;
  for (int i=1; i<MK; i++) {
    D[i] = D[i-1]+1;
    // add second to the bottom, makes loop condition below into j<11
    // if (i-2>=1) D[i] = min(D[i], D[i-2]+1);

    for (int j=1; j<31; j++) { // add D[j] elems at the top
      if (i%(j+1) == j) D[i] = min(D[i], D[i/(j+1)] + D[j]);
    }
  }

  int mx = 0;
  for (int i=0; i<MK; i++) mx = max(mx, D[i]);
  for (int i=0; i<100; i++) {
    cout << D[i] << " ";
    if (i%10 == 9) cout << endl;
  }
  cout << mx << endl;

  ////////////////////////////////
  return 0;
}
