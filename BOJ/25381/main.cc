#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, vst[MN];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;
  N = sz(S);

  for (int i=0, j=0; i<N; i++) { // BC
    if (S[i] != 'B') continue;
    j = max(j, i+1);
    while (j < N && S[j] != 'C') j++;
    if (j < N) { vst[i] = 1; j++; }
  }

  for (int i=N-1, j=N-1; j>=0; j--) { // AB
    if (S[j] != 'B') continue;
    i = min(i, j-1);
    while (i >= 0 && S[i] != 'A') i--;
    if (i >= 0) { vst[j] = 1; i--; }
  }

  int ans = 0;
  for (int i=0; i<N; i++) ans += vst[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
