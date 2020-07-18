#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5005;
int D[MAXN]; bool nim[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  D[0] = D[1] = 0;
  for (int i=2; i<=5000; i++) {
    int reset = 0;
    for (int j=0; j<=i-2; j++) {
      int nimber = D[j] ^ D[i-j-2];
      nim[nimber] = true;
      reset = max(reset, nimber);
    }

    for (int j=0; j<=reset+1; j++) {
      if (nim[j] == false) {
        D[i] = j;
        break;
      }
    }

    for (int j=0; j<=reset; j++) {
      nim[j] = false;
    }
  }

  int T; cin >> T;
  for (int i=0; i<T; i++) {
    int N; cin >> N;
    if (D[N] > 0) cout << "First" << endl;
    else cout << "Second" << endl;
  }

  ////////////////////////////////
  return 0;
}
