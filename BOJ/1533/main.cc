#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1'000'003;

struct Matrix {
  lld n;
  vector<vector<lld>> m;

  Matrix(int n): n(n) {
    m.resize(n);
    for (int i=0; i<n; i++) m[i].resize(n);
  }

  static Matrix id(int n) {
    Matrix I(n);
    for (int i=0; i<n; i++) I.m[i][i] = 1;
    return I;
  }

  Matrix operator *(const Matrix &M) const {
    Matrix K(n);
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        for (int k=0; k<n; k++) {
          K.m[i][j] = (K.m[i][j] + m[i][k] * M.m[k][j]) % MOD;
        }
      }
    }
    return K;
  }

  Matrix exp(int e) {
    Matrix K = Matrix::id(n);
    for (int b = 31; b >= 0; b--) {
      K = K * K;
      if (e & (1<<b)) K = K * (*this);
    }
    return K;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, S, E; cin >> N >> S >> E;
  S--; E--;
  lld T; cin >> T;
  
  vector<pii> edges;
  for (int i=0; i<N; i++) {
    for (int r=0; r<4; r++) edges.push_back({i*5 + r, i*5 + r+1});

    string S; cin >> S;
    for (int j=0; j<N; j++) {
      int a = S[j] - '0';
      if (a == 0) continue;
      edges.push_back({i*5 + a-1, j*5});
    }
  }

  Matrix adj(N*5);
  for (auto [i, j]: edges) adj.m[i][j] = 1;

  Matrix exp = adj.exp(T);
  cout << exp.m[S*5][E*5] << endl;

  ////////////////////////////////
  return 0;
}
