#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
const lld MOD = 1e9+7;
int N, M, R, C, cnt[MN];

struct Matrix {
  vector<int> mat[MN*2];
  int rank;

  void normalize() {
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) 
      mat[i][j] = (mat[i][j]%3+3) % 3;
  }

  void row_op(int row, int i, int s) { // mat[i] -= mat[row] * s
    for (int j=0; j<C; j++) {
      mat[i][j] -= mat[row][j] * s;
      mat[i][j] = (mat[i][j]%3+3) % 3;
    }
  }

  bool solve() { // returns solvability
    for (int col=0, row=0; col<C && row<R; col++) {
      // find pivot
      for (int i=row; i<R; i++) {
        if (mat[i][col]) {
          swap(mat[row], mat[i]);
          break;
        }
      }
      if (!mat[row][col]) continue;
      else if (col == C-1) return false; // last column has pivot

      // row operations
      for (int i=row+1; i<R; i++) {
        if (mat[i][col]) row_op(row, i, mat[row][col] == mat[i][col] ? 1 : 2);
      }
      rank = ++row;
    }
    return true;
  }
} mat;

vector<int> tie2(int x, int y) {
  vector<int> row(C);
  row[x] = cnt[x]; row[x+N] = 1;
  row[y] = -cnt[y]; row[y+N] = -1;
  return row;
}

vector<int> win2(int x, int y) {
  vector<int> row = tie2(x, y);
  row[N*2] = 1;
  return row;
}

vector<int> tie3(int x, int y, int z) {
  vector<int> row(C);
  row[x] = cnt[x]; row[x+N] = 1;
  row[y] = cnt[y]; row[y+N] = 1;
  row[z] = cnt[z]; row[z+N] = 1;
  return row;
}

lld pow3(int e) {
  lld res = 1;
  for (int i=0; i<e; i++) res = res * 3 % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  C = N*2+1;

  for (int game=0; game<M; game++) {
    // input
    int a, b, p[3], win[3]; char _;
    cin >> a;
    for (int i=0; i<a; i++) { cin >> p[i]; p[i]--; }
    cin >> _;
    cin >> b;
    fill(win, win+a, 0);
    for (int i=0; i<b; i++) {
      int q; cin >> q; q--;
      for (int j=0; j<a; j++) if (p[j] == q) win[j] = 1;
    }

    // build matrix
    if (b == 0) {
      if (a == 2) mat.mat[R++] = tie2(p[0], p[1]);
      else mat.mat[R++] = tie3(p[0], p[1], p[2]);
    } else {
      for (int i=0; i<a; i++) for (int j=0; j<a; j++)
        if (win[i] && !win[j]) mat.mat[R++] = win2(p[i], p[j]);
    }

    for (int i=0; i<a; i++) cnt[p[i]]++;
  }

  mat.normalize();
  bool res = mat.solve();
  if (res) cout << pow3(N*2 - mat.rank) << endl;
  else cout << 0 << endl;

  ////////////////////////////////
  return 0;
}
