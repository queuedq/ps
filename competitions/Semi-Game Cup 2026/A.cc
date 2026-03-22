#include <bits/stdc++.h>
using namespace std;

const int MX = 1010;
int N, L[MX], R[MX], D[MX][MX][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=1; i<=N; i++) cin >> L[i] >> R[i];

  for (int j=0; j<MX; j++) D[0][j][0] = D[0][j][1] = 1;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<MX-1; j++) {
      int safe = L[i] <= j && j <= R[i];
      if (safe) {
        D[i][j][0] = D[i-1][j-1][0] | D[i-1][j][0] | D[i-1][j+1][0];
        D[i][j][1] = D[i-1][j-1][1] | D[i-1][j][1] | D[i-1][j+1][1];
      } else {
        D[i][j][1] = D[i-1][j-1][0] | D[i-1][j][0] | D[i-1][j+1][0];
      }
    }

    // for (int j=1; j<=20; j++) {
    //   cout << D[i][j][0] << "," << D[i][j][1] << " ";
    // }
    // cout << endl;
  }

  int ans = 0;
  for (int j=1; j<MX-1; j++) ans |= D[N][j][1];

  if (ans) cout << "World Champion" << endl;
  else cout << "Surrender" << endl;

  return 0;
}
