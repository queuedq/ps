#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e8+7;
int n, m;

struct Matrix {
  int r, c;
  vector<bitset<805>> mat;
  int rank;

  Matrix(int r, int c): r(r), c(c) { mat.resize(r); }

  void print() {
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) cout << mat[i][j]; cout << endl;
    } cout << endl;
  }

  bool solve() { // returns solvability
    rank = 0;
    for (int i=0; i<c; i++) {
      // find pivot
      bool found = false;
      for (int j=rank; j<r; j++) {
        if (mat[j][i]) {
          swap(mat[rank], mat[j]);
          found = true;
          break;
        }
      }
      if (!found) continue;
      else if (i == c-1) return false; // last column has pivot

      // do row operations
      for (int j=rank+1; j<r; j++) {
        if (mat[j][i]) mat[j] ^= mat[rank];
      }
      rank++;
    }
    return true;
  }
};

int pow2(int e) {
  int res = 1;
  for (int i=0; i<e; i++) res = res * 2 % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  Matrix M(n, m+1);
  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v;
    M.mat[u-1][i] = true;
    M.mat[v-1][i] = true;
  }
  for (int i=0; i<n; i++) M.mat[i][m] = true;

  bool res = M.solve();
  if (!res) cout << 0 << endl;
  else cout << pow2(m - M.rank) << endl;

  ////////////////////////////////
  return 0;
}
