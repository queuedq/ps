#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 1024;
int g[MX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  g[0] = 0;
  for (int i=1; i<MX; i++) {
    vector<int> vst(i*4);
    for (int j=0; 1<<j <= i; j++) {
      if (1<<j & i) {
        for (int k=0; k<=j; k++) {
          int mask = (1<<(j+1)) - (1<<k);
          vst[g[i ^ mask]]++;
        }
      }
    }

    int j = 0;
    for (; j<sz(vst); j++) {
      if (!vst[j]) break;
    }
    g[i] = j;
  }


  for (int i=0; i<MX; i++) {
    cout << bitset<10>(i) << ": " << bitset<10>(g[i]) << endl;
  }

  ////////////////////////////////
  return 0;
}
