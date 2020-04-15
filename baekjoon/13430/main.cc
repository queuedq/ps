#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
const int MAXK = 55;
int K, N;

struct Matrix {
  lld el[MAXK][MAXK];

  Matrix() {
    for (int i=0; i<=K; i++) fill(el[i], el[i]+K+1, 0);
  }

  lld* operator [](int i) { return el[i]; }

  Matrix operator *(Matrix A) {
    Matrix M;
    for (int i=1; i<=K; i++) {
      for (int j=1; j<=K; j++) {
        for (int k=1; k<=K; k++) {
          M[i][j] = (M[i][j] + el[i][k] * A[k][j]) % MOD;
        }
      }
    }
    return M;
  }

  vector<lld> operator *(vector<lld> v) {
    vector<lld> u(K+1);
    for (int i=1; i<=K; i++) {
      for (int j=1; j<=K; j++) {
        u[i] = (u[i] + el[i][j] * v[j]) % MOD;
      }
    }
    return u;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> N;
  K += 2;

  Matrix A;
  for (int i=1; i<=K; i++) {
    for (int j=1; j<=i; j++) A[i][j] = 1;
  }

  Matrix B;
  for (int i=1; i<=K; i++) B[i][i] = 1;
  while (N > 0) {
    if (N & 1) B = B * A;
    N /= 2;
    A = A * A;
  }

  vector<lld> v(K+1);
  v[1] = 1;

  v = B * v;
  cout << v[K] << endl;

  ////////////////////////////////
  return 0;
}
