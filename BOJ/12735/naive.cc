#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100;
int N, l[MN], r[MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> l[i] >> r[i];
    r[i]++;
  }

  for (int k=0; k<100; k++) D[0][k] = 1;
  for (int i=1; i<=N; i++) {
    for (int k=l[i]; k<r[i]; k++) {
      for (int j=0; j<i; j++) { // prev used variable
        D[i][k] += D[j][k-1];
      }
    }
    for (int k=1; k<100; k++) D[i][k] += D[i][k-1];

    for (int k=0; k<20; k++) cout << D[i][k] << " "; cout << endl;
  }

  int ans = 0;
  for (int i=1; i<=N; i++) ans += D[i][99];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
