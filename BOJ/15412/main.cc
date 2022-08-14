#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9;
const lld F[9] = {1, 1, 2, 3, 5, 8, 13, 21, 34};
lld N, M;

struct Matrix {
  lld a[1<<8][1<<8];

  Matrix operator *(Matrix &B) {
    Matrix C;
    for (int i=0; i<1<<N; i++)
      for (int j=0; j<1<<N; j++)
        for (int k=0; k<1<<N; k++)
          C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % MOD;
    return C;
  }

  vector<lld> operator *(vector<lld> &x) {
    vector<lld> b(1<<N);
    for (int i=0; i<1<<N; i++)
      for (int j=0; j<1<<N; j++)
        b[i] = (b[i] + a[i][j] * x[j]) % MOD;
    return b;
  }

  Matrix pow(lld e) {
    if (e == 1) return *this;
    Matrix B = pow(e/2);
    if (e%2) return B*B * (*this);
    return B*B;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  Matrix A;
  for (int i=0; i<1<<N; i++) {
    for (int j=0; j<1<<N; j++) {
      if (i&j) continue;
      int m = ((1<<N)-1) ^ i^j, cnt = 0, a = 1;
      for (int k=0; k<N; k++) {
        if (m>>k & 1) cnt++;
        else { a *= F[cnt]; cnt = 0; }
      }
      a *= F[cnt];
      A.a[i][j] = a;
    }
  }

  vector<lld> x(1<<N);
  x[0] = 1;
  cout << (A.pow(M) * x)[0] << endl;

  ////////////////////////////////
  return 0;
}
