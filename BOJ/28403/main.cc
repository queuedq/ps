#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'000'005;
int N, S[MN], ans[MN];
string X;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> X;
  for (int i=1; i<=N; i++) {
    S[i] = S[i-1] + (X[i-1] == 'S');
  }

  for (int k=1; k<=N; k++) {
    int i = 0;
    while (S[i] != k) {
      i += k-S[i];
      if (i > N) break;
      ans[k]++;
    }
  }

  for (int k=1; k<=N; k++) cout << ans[k] << ' ';
  cout << endl;

  ////////////////////////////////
  return 0;
}
