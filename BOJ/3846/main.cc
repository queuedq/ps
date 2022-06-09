#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _M = 81;
const int _N = 5005;
int m, n, mod, f[_M], g[_N][_M], L[_N][_M], R[_N][_M], C[_N][_M];

struct Matrix {
  int n;
  vector<vector<int>> a;

  Matrix(int n): n(n) {
    a.resize(n);
    for (int i=0; i<n; i++) a[i].resize(n);
  }

  static Matrix id(int n) {
    Matrix I(n);
    for (int i=0; i<n; i++) I.a[i][i] = 1;
    return I;
  }

  Matrix operator *(const Matrix &A) const {
    Matrix B(n);
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        for (int k=0; k<n; k++)
          B.a[i][j] = (B.a[i][j] + a[i][k] * A.a[k][j]) % mod;
    return B;
  }

  Matrix pow(int e) {
    if (e == 0) return id(n);
    Matrix B = pow(e/2);
    if (e%2) return B * B * (*this);
    return B * B;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> m;
    if (m == 0) break;
    for (int i=0; i<=m; i++) cin >> f[i];
    cin >> n >> mod;
    
    Matrix A(m);
    for (int i=0; i<m; i++) {
      int s = f[i], e = f[i+1];
      if (s > e) swap(s, e);
      for (int j=s; j<e; j++) A.a[i][j] = 1;
    }
    Matrix B = A.pow(n);

    // handle integer points
    iota(g[0], g[0]+m+1, 0); // f^k
    fill(L[0], L[0]+m+1, 1); // left slope
    fill(R[0], R[0]+m+1, 1); // right slope
    fill(C[0], C[0]+m+1, 1); // slope = +-1 (detect infinity)
    L[0][0] = R[0][m] = C[0][m] = 0;

    for (int k=1; k<=n; k++) {
      fill(L[k], L[k]+m+1, 0);
      fill(R[k], R[k]+m+1, 0);
      fill(C[k], C[k]+m+1, 0);

      for (int i=0; i<=m; i++) {
        g[k][i] = g[k-1][f[i]];

        if (i > 0) {
          if (f[i-1] < f[i]) L[k][i] = L[k-1][f[i]];
          if (f[i-1] > f[i]) L[k][i] = -R[k-1][f[i]];
        }
        if (i < m) {
          if (f[i] < f[i+1]) R[k][i] = R[k-1][f[i]];
          if (f[i] > f[i+1]) R[k][i] = -L[k-1][f[i]];

          if (f[i]+1 == f[i+1]) C[k][i] = C[k-1][f[i]];
          if (f[i]-1 == f[i+1]) C[k][i] = C[k-1][f[i+1]];
        }
      }
    }

    // get ans
    int ans = 0;
    for (int i=0; i<m; i++) ans = (ans + B.a[i][i]) % mod;

    bool inf = false;
    for (int i=0; i<=m; i++) {
      if (g[n][i] == i) {
        if (C[n][i] && R[n][i] == 1) { inf = true; break; }
        if (L[n][i] == 1) ans--;
        if (R[n][i] == 1) ans--;
        ans = (ans+1 + mod) % mod;
      }
    }

    if (inf) cout << "Infinity" << endl;
    else cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
