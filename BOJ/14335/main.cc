#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
char S[MN];
lld N, last[256], prv[MN], D[MN];

void solve() {
  cin >> (S+1);
  N = strlen(S+1);

  for (int i=1; i<=N; i++) {
    prv[i] = last[S[i]];
    last[S[i]] = i;
  }

  D[0] = 1;
  for (int i=1; i<=N; i++) {
    D[i] = D[i-1] * 2;
    if (prv[i] > 0) D[i] -= D[prv[i]-1];
  }

  cout << D[N] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
    fill(last, last+256, 0);
    fill(prv, prv+MN, 0);
    fill(D, D+MN, 0);
  }

  ////////////////////////////////
  return 0;
}
