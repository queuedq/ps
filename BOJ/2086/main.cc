#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld MOD = 1e9;

struct Matrix {
  lld a, b, c, d;

  static Matrix id() { return {1, 0, 0, 1}; }

  Matrix operator *(Matrix A) {
    lld aa = (a*A.a + b*A.c) % MOD;
    lld bb = (a*A.b + b*A.d) % MOD;
    lld cc = (c*A.a + d*A.c) % MOD;
    lld dd = (c*A.b + d*A.d) % MOD;
    return {aa, bb, cc, dd};
  }

  Matrix pow(lld n) {
    Matrix A = *this;
    Matrix B = Matrix::id();
    lld e = 1;
    while (e <= n - e) e <<= 1;
    while (e > 0) {
      B = B * B;
      if (e & n) B = B * A;
      e >>= 1;
    }
    return B;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld a, b; cin >> a >> b;

  Matrix A = {0, 1, 1, 1};
  cout << (A.pow(b+2).b - A.pow(a+1).b + MOD) % MOD << endl;

  ////////////////////////////////
  return 0;
}
