#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
int N, L[27], R[27], D[27], E[27];
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> S;
  fill(L, L+27, INF);
  for (int i=0; i<sz(S); i++) {
    int c = S[i] - 'a' + 1;
    L[c] = min(L[c], i);
    R[c] = max(R[c], i);
  }

  D[0] = E[0] = 0;
  int l = 0, r = 0;
  for (int i=1; i<=26; i++) {
    if (L[i] == INF) {
      D[i] = D[i-1];
      E[i] = E[i-1];
    } else {
      D[i] = R[i]-L[i] + min(D[i-1] + abs(R[i] - l), E[i-1] + abs(R[i] - r));
      E[i] = R[i]-L[i] + min(D[i-1] + abs(L[i] - l), E[i-1] + abs(L[i] - r));
      l = L[i];
      r = R[i];
    }
  }
  cout << min(D[26], E[26]) + sz(S) << endl;

  ////////////////////////////////
  return 0;
}
