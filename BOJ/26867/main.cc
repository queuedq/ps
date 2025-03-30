#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
const int MN = 1010;
int N;
string A[MN];

int count(int l, int r, int len) {
  if (l == 0 && r == 0) return len + 1;
  if (l == 1 && r == 1) return 0;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  lld ans = 1;

  for (int i=0; i<N; i++) {
    int last = 0, len = 0;
    for (int j=0; j<N; j++) {
      if (A[i][j] == '.') {
        if (len) ans = ans * count(last, 0, len) % MOD;
        last = 0, len = 0;
      } else if (A[i][j] == '#') {
        if (len) ans = ans * count(last, 1, len) % MOD;
        last = 1, len = 0;
      } else {
        len++;
      }
    }
    if (len) ans = ans * count(last, 0, len) % MOD;
  }

  for (int j=0; j<N; j++) {
    int last = 0, len = 0;
    for (int i=0; i<N; i++) {
      if (A[i][j] == '.') {
        if (len) ans = ans * count(last, 0, len) % MOD;
        last = 0, len = 0;
      } else if (A[i][j] == '#') {
        if (len) ans = ans * count(last, 1, len) % MOD;
        last = 1, len = 0;
      } else {
        len++;
      }
    }
    if (len) ans = ans * count(last, 0, len) % MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
