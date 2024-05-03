#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 600921647;
int N, M;
int cnt[10][10]; // genre, len
int adj[10][10];
int ST, ED;

struct Matrix {
  int n;
  vector<vector<lld>> e;

  Matrix(int n): n(n) {
    for (int i=0; i<n; i++) e.push_back(vector<lld>(n, 0));
  }

  static Matrix id(int n) {
    Matrix I(n);
    for (int i=0; i<n; i++) I.e[i][i] = 1;
    return I;
  }

  Matrix operator*(const Matrix& B) const {
    Matrix C(n);
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        for (int k=0; k<n; k++) {
          C.e[i][j] += e[i][k] * B.e[k][j];
          C.e[i][j] %= MOD;
        }
      }
    }
    return C;
  }

  Matrix pow(int e) {
    if (e == 0) return Matrix::id(n);
    Matrix B = pow(e/2);
    if (e&1) return B * B * (*this);
    return B * B;
  }
};

lld calc(Matrix &A, int t) {
  Matrix B = A.pow(t+1);
  return B.e[ST][ED];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a, l; cin >> a >> l;
    cnt[a][l]++;
  }

  cin >> M;
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      char c; cin >> c;
      adj[i][j] = c == 'Y';
    }
  }

  // nodes: (genre, remaining len) + ST + ED
  // transitions: (a, 0) -> (b, len-1) where adj[a][b]
  Matrix A(M*10+2);
  ST = M*10, ED = M*10+1;

  for (int a=0; a<M; a++) {
    for (int l=1; l<10; l++) A.e[ST][a*10+l-1] = cnt[a][l]; // start playing
    for (int l=1; l<10; l++) A.e[a*10+l][a*10+l-1] = 1; // now playing
    A.e[a*10][ED] = 1; // done playing

    for (int b=0; b<M; b++) {
      if (!adj[a][b]) continue;
      for (int l=1; l<10; l++) A.e[a*10][b*10+l-1] = cnt[b][l]; // choose (b, l) next
    }
  }
  A.e[ED][ED] = 1; // keep done cnt

  // print ans
  int s, e; cin >> s >> e;
  lld ans = calc(A, e) - calc(A, s-1);
  ans = (ans+MOD) % MOD;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
