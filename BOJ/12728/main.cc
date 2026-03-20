#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
struct Matrix {
  int a, b, c, d;

  static Matrix id() {
    return {1, 0, 0, 1};
  }

  Matrix operator *(Matrix A) {
    int aa = a*A.a + b*A.c;
    int bb = a*A.b + b*A.d;
    int cc = c*A.a + d*A.c;
    int dd = c*A.b + d*A.d;

    aa = aa % 1000; bb = bb % 1000; cc = cc % 1000; dd = dd % 1000;
    return {aa, bb, cc, dd};
  }

  Matrix pow(lld n) {
    Matrix A = *this;
    Matrix B = Matrix::id();
    lld e = 1;
    while (e <= n) e <<= 1;
    while (e > 0) {
      B = B * B;
      if (e & n) B = B * A;
      e >>= 1;
    }
    return B;
  }
};

ostream& operator <<(ostream& os, Matrix A) {
  return os << "[[" << A.a << " " << A.b << "] [" << A.c << " " << A.d << "]]";
};

int calc(lld n) {
  Matrix A = {6, -4, 1, 0};
  Matrix B = A.pow(n);
  return (((B.c * 6 + B.d * 2 - 1) % 1000) + 1000) % 1000;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    lld n; cin >> n;
    cout << "Case #" << i << ": " << setw(3) << setfill('0') << calc(n) << endl;
  }

  ////////////////////////////////
  return 0;
}
