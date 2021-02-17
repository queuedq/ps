#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2005;
int N, D[MN], S[2048];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  D[0] = 0;
  for (int i=1; i<=N; i++) {
    fill(S, S+i, 0);
    for (int j=0; j<i; j++) {
      int l = max(0, j-2), r = max(0, i-j-3);
      S[D[l] ^ D[r]] = 1;
    }
    for (int j=0; j<=i; j++) {
      if (!S[j]) { D[i] = j; break; }
    }
  }

  cout << (D[N] ? 1 : 2) << endl;

  ////////////////////////////////
  return 0;
}
