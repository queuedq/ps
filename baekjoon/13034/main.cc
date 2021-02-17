#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, D[1001], S[1024];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  D[0] = D[1] = 0;

  for (int i=2; i<=N; i++) {
    fill(S, S+i+1, false);
    for (int j=0; j<=i-2; j++) {
      S[D[j] ^ D[i-j-2]] = true;
    }
    for (int j=0; j<=i; j++) {
      if (!S[j]) { D[i] = j; break; }
    }
  }

  cout << (D[N] ? 1 : 2) << endl;

  ////////////////////////////////
  return 0;
}
