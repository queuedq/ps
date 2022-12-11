#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
lld N, D[MN][MN]; // consider [1..i], j days
pll A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i].first >> A[i].second;
  sort(A+1, A+N+1);

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=i; j++) {
      D[i][j] = max(D[i-1][j], D[i-1][j-1] + A[i].first * (j-1) + A[i].second);
    }
  }

  for (int j=1; j<=N; j++) {
    cout << D[N][j] << endl;
  }

  ////////////////////////////////
  return 0;
}
