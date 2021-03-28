#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, B;

struct SquareMatrix {
  int e[5][5];

  SquareMatrix(bool id=true) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) e[i][j] = 0;
      if (id) e[i][i] = 1;
    }
  }

  SquareMatrix multiply(SquareMatrix B) {
    SquareMatrix C(false);
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        for (int k=0; k<N; k++) {
          C.e[i][j] += e[i][k] * B.e[k][j];
        }
        C.e[i][j] %= 1000;
      }
    }
    return C;
  }
};

ostream& operator <<(ostream &os, SquareMatrix A) {
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) os << A.e[i][j] << " ";
    os << endl;
  }
  return os;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> B;
  SquareMatrix A, R;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A.e[i][j];
  }

  lld b;
  for (b = 1; b < B; b *= 2) {}
  for (; b > 0; b /= 2) {
    R = R.multiply(R);
    if (B & b) R = R.multiply(A);
  }

  cout << R;

  ////////////////////////////////
  return 0;
}
