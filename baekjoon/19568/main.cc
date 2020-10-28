#include <bits/stdc++.h>
using namespace std;

int A[30][30];

int main() {
  for (int i=0; i<14; i++) {
    A[14][i] = 1;
    A[i][15] = 15;
    A[15][i+16] = 15*15;
    A[i+16][14] = 15*15*15;
  }

  for (int i=0; i<30; i++) {
    for (int j=0; j<30; j++) cout << A[i][j] << " ";
    cout << endl;
  }

  return 0;
}
