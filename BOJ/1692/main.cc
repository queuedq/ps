#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50;
int N, M = 16, A[MN][16], D[2][1<<16][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<16; j++) A[i][j] = S[j]-'0';
  }
  
  for (int i=N*M-1; i>=0; i--) {
    for (int s=0; s<1<<M; s++) {
      for (int k=0; k<2; k++) {
        int r = i/M, c = i%M;
        int h = i%16 == 0 || !k;
        int v = !(s&1);
        
        if (!A[r][c]) {
          D[i&1][s][k] = min(
            D[~i&1][s>>1][0],
            D[~i&1][s>>1 | 1<<15][1] + h + v
          );
        } else {
          D[i&1][s][k] = min(
            D[~i&1][s>>1][1] + h,
            D[~i&1][s>>1 | 1<<15][0] + v
          );
        }
      }
    }
  }

  cout << D[0][0][0] << endl;

  ////////////////////////////////
  return 0;
}
