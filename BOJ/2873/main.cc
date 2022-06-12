#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int R, C, A[MN][MN], mn=1e9, r, c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> R >> C;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      cin >> A[i][j];
      if ((i+j)%2 == 0) continue;
      if (A[i][j] < mn) mn = A[i][j], r = i, c = j;
    }
  }

  if (R%2) {
    for (int i=0; i<R; i++) {
      if (i%2 == 0) {
        for (int j=0; j<C-1; j++) cout << 'R';
      } else {
        cout << 'D';
        for (int j=0; j<C-1; j++) cout << 'L';
        cout << 'D';
      }
    }
    return 0;
  }
  
  if (C%2) {
    for (int j=0; j<C; j++) {
      if (j%2 == 0) {
        for (int i=0; i<R-1; i++) cout << 'D';
      } else {
        cout << 'R';
        for (int i=0; i<R-1; i++) cout << 'U';
        cout << 'R';
      }
    }
    return 0;
  }

  bool rf = 0;
  for (int i=0; i<R; i+=2) {
    if (i == r || i+1 == r) {
      int cf = 0;
      for (int j=0; j<C; j+=2) {
        if (j == c) { cout << "RD"; cf = 1; }
        else if (j+1 == c) { cout << "DR"; cf = 1; }
        else if (!cf) cout << "DRUR";
        else cout << "RURD";
      }
      rf = 1;
    } else if (!rf) {
      for (int j=0; j<C-1; j++) cout << 'R';
      cout << 'D';
      for (int j=0; j<C-1; j++) cout << 'L';
      cout << 'D';
    } else {
      cout << 'D';
      for (int j=0; j<C-1; j++) cout << 'L';
      cout << 'D';
      for (int j=0; j<C-1; j++) cout << 'R';
    }
  }

  ////////////////////////////////
  return 0;
}
