#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;

lld mod(lld x) { return (x % MOD + MOD) % MOD; }

struct Matrix {
  lld x[3][3];

  Matrix() { memset(x, 0, sizeof(x)); }
  static Matrix I() {
    Matrix A;
    A.x[0][0] = A.x[1][1] = A.x[2][2] = 1;
    return A;
  }

  Matrix operator* (const Matrix &B) const {
    Matrix C;
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        for (int k=0; k<3; k++) C.x[i][j] += x[i][k] * B.x[k][j];
        C.x[i][j] = mod(C.x[i][j]);
      }
    }
    return C;
  }

  Matrix pow(lld e) const {
    if (e == 0) return I();
    Matrix B = pow(e/2);
    if (e%2 == 0) return B * B;
    return B * B * (*this);
  }
};

Matrix A;

lld f(lld n, lld f0, lld f1, lld f2) { // f0 = f(0, m), f1 = f(1, m), f2 = f(2, m)
  Matrix P = A.pow(n);
  return mod(P.x[0][0] * f0 + P.x[0][1] * f1 + P.x[0][2] * f2);
}

// f(n, m) = (a^n(b^m-c^m) + b^n(c^m-a^m) + c^n(a^m-b^m)) / (a-b)(b-c)(c-a)
// f(n, m) = -f(m, n)

// f(n, 0) = 0, 0, 0, ...
// f(n, 1) = 0, 0, -1, ...
// f(n, 2) = 0, 1, 0, ...

// f(n, m) = s f(n-1, m) - t f(n-2, m) + u f(n-3, m)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  lld n, m, s, t, u; cin >> n >> m >> s >> t >> u;

  A.x[0][1] = A.x[1][2] = 1;
  A.x[2][0] = u, A.x[2][1] = mod(-t), A.x[2][2] = s;

  lld f_n1 = f(n, 0, 0, -1);
  lld f_n2 = f(n, 0, 1, 0);
  lld f_nm = f(m, 0, f_n1, f_n2);
  cout << f_nm << endl;

  ////////////////////////////////
  return 0;
}
