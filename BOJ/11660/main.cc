#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1025;
int N, M;
lld A[MN][MN], S[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      cin >> A[i][j];
      S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + A[i][j];
    }
  }

  for (int q=0; q<M; q++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1] << '\n';
  }

  ////////////////////////////////
  return 0;
}
