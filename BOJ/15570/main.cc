#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1999;

struct Matrix {
  int N;
  vector<vector<int>> v;

  Matrix(int N) : N(N) { v.assign(N, vector<int>(N)); }

  static Matrix id(int N) {
    Matrix A(N);
    for (int i=0; i<N; i++) A.v[i][i] = 1;
    return A;
  }

  Matrix operator*(const Matrix &A) const {
    Matrix B(N);
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++)
        for (int k=0; k<N; k++)
          B.v[i][j] = (B.v[i][j] + v[i][k] * A.v[k][j]) % MOD;
    return B;
  }

  Matrix pow(lld e) const {
    if (e == 0) return id(N);
    if (e == 1) return *this;
    Matrix A = pow(e/2);
    if (e%2) return A * A * (*this);
    return A * A;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  lld N, M; cin >> N >> M;
  Matrix A(N);

  for (int i=0; i<N-1; i++) A.v[0][i] = A.v[i+1][i] = 1;
  int p2 = 1;
  for (int i=0; i<N-1; i++) p2 = p2*2 % MOD;
  A.v[0][N-1] = p2;

  Matrix B = A.pow(M);
  cout << B.v[0][0] << endl;

  ////////////////////////////////
  return 0;
}
