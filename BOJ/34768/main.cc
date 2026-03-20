#include <bits/stdc++.h>
using namespace std;

const int MN = 1010;
int N, mat[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i+=2) {
    for (int j=0; j<N; j++) {
      mat[i][j] = i/2*N + j + 1;
      mat[i+1][j] = i/2*N + j + 2;
    }
  }
  mat[N-1][N-1] = 1;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }

  ////////////////////////////////
  return 0;
}
