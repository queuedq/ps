#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010101;
string S;
int N, M, z[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;
  N = sz(S);
  reverse(all(S));

  z[0] = N;
  int l = 0, r = 0;
  for (int i=1; i<N; i++) {
    if (i < r) z[i] = min(z[i-l], r-i);
    while (i+z[i] < N && S[z[i]] == S[i+z[i]]) z[i]++;
    if (i+z[i] > r) l = i, r = i+z[i];
  }

  cin >> M;
  for (int j=0; j<M; j++) {
    int i; cin >> i;
    cout << z[N-i] << endl;
  }

  ////////////////////////////////
  return 0;
}
