#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 256;
lld N, L;
vector<lld> M[MN];

struct Matrix {
  lld mat[MN][MN];

  vector<lld> mul(vector<lld> vec) {
    vector<lld> res(N);
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) res[i] += mat[i][j] * vec[j];
    }
    return res;
  }
};

bool check(Matrix &A, Matrix &B, Matrix &C) {
  for (int t=0; t<30; t++) {
    vector<lld> r(N);
    for (int i=0; i<N; i++) r[i] = rand()%2;
    if (A.mul(B.mul(r)) != C.mul(r)) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    M[i].resize(L);
    for (int j=0; j<L; j++) cin >> M[i][j];
  }

  int ans = 0;
  for (int i=0; i<L-3*N+1; i++) {
    Matrix A, B, C;
    for (int j=0; j<N; j++) {
      for (int k=0; k<N; k++) {
        A.mat[j][k] = M[j][i+k];
        B.mat[j][k] = M[j][i+N+k];
        C.mat[j][k] = M[j][i+N+N+k];
      }
    }
    if (check(A, B, C)) { ans++; i += N*3-1; }
  }
  cout << ans * N * N * 3 << endl;

  ////////////////////////////////
  return 0;
}
