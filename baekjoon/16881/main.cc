#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, M, A[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) cin >> A[i][j];
  }

  int ans = 0;
  for (int i=0; i<N; i++) {
    int g = 0;
    for (int j=M-1; j>=0; j--) {
      if (g == 0) g = A[i][j];
      else if (A[i][j] <= g) g = A[i][j] - 1;
      else g = A[i][j];
    }
    ans ^= g;
  }

  cout << (ans ? "koosaga" : "cubelover") << endl;

  ////////////////////////////////
  return 0;
}
