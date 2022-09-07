#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
string S, T;
char stk[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S >> T;
  int s = 0;
  for (int i=0; i<sz(S); i++) {
    stk[s++] = S[i];

    if (s >= sz(T)) {
      bool match = 1;
      for (int j=0; j<sz(T); j++) {
        if (stk[s-sz(T)+j] != T[j]) { match = 0; break; }
      }

      if (match) s -= sz(T);
    }
  }

  if (s > 0) {
    for (int i=0; i<s; i++) cout << stk[i];
  } else {
    cout << "FRULA" << endl;
  }

  ////////////////////////////////
  return 0;
}
