#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10;
int N, M, D[MN*MN+1][1<<MN][2];
string A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];

  for (int i=N*M-1; i>=0; i--) {
    for (int s=0; s<1<<M; s++) {
      for (int k=0; k<2; k++) {
        int r = i/M, c = i%M;
        if (A[r][c] == '#') { D[i][s][k] = D[i+1][s>>1][0]; continue; }

        D[i][s][k] = MN*MN;
        D[i][s][k] = min(D[i][s][k], D[i+1][s>>1 | 1<<M-1][0] + !(s&1)); // vertical
        D[i][s][k] = min(D[i][s][k], D[i+1][s>>1][1] + !(c!=0 && k)); // horizontal
      }
    }
  }

  cout << D[0][0][0] << endl;

  ////////////////////////////////
  return 0;
}
