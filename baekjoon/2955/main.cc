#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int A[9][9];

int cross_hatching(int num) {
  bool B[9][9];
  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) B[i][j] = false;
  }

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (A[i][j] == num) {
        int b = i/3*3 + j/3;
        for (int k=0; k<9; k++) {
          int r = b/3*3 + k/3;
          int c = b%3*3 + k%3;
          B[i][k] = true;
          B[k][j] = true;
          B[r][c] = true;
        }
      } else if (A[i][j]) {
        B[i][j] = true;
      }
    }
  }

  int res = 0;
  for (int i=0; i<9; i++) {
    int cnt = 0, sr = 0, sc = 0;
    bool hasnum = false;
    for (int j=0; j<9; j++) {
      int r = i/3*3 + j/3;
      int c = i%3*3 + j%3;
      if (A[r][c] == num) hasnum = true;
      if (!B[r][c]) {
        cnt++;
        sr = r;
        sc = c;
      }
    }
    if (hasnum) continue;
    if (cnt == 0) return 2;
    if (cnt == 1) {
      A[sr][sc] = num;
      res = 1;
    }
  }
  return res;
}

bool is_valid() {
  for (int i=0; i<9; i++) {
    set<int> row, column, box;
    int rc = 0, cc = 0, bc = 0;
    for (int j=0; j<9; j++) {
      if (A[i][j]) { row.insert(A[i][j]); rc++; }
      if (A[j][i]) { column.insert(A[j][i]); cc++; }

      int r = i/3*3 + j/3;
      int c = i%3*3 + j%3;
      if (A[r][c]) { box.insert(A[r][c]); bc++; }
    }
    if (row.size() != rc || column.size() != cc || box.size() != bc) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<9; i++) {
    string s; cin >> s;
    for (int j=0; j<9; j++) {
      if (s[j] == '.') A[i][j] = 0;
      else A[i][j] = s[j] - '0';
    }
  }

  if (!is_valid()) {
    cout << "ERROR" << endl;
    return 0;
  }

  while (true) {
    bool success = false;
    for (int num=1; num<=9; num++) {
      int res = cross_hatching(num);
      if (res == 2) {
        cout << "ERROR" << endl;
        return 0;
      } else if (res == 1) {
        success = true;
      }
    }
    if (!success) break;
  }

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      if (A[i][j]) cout << A[i][j];
      else cout << '.';
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
