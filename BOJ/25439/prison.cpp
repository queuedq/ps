#include "prison.h"
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 6000;
const int base[8] = {0, 2, 3, 3, 3, 3, 3, 3};
int D[8], id[8][3], last, A[21][MN];

void solve(int n, int s, int e, int l, int r, int d) {
  // n: prev group id
  // [s, e): prev coin's range
  // [l, r): current coin's range (contains [s, e), length D[d])
  int bag = A[n][0] = d%2;

  for (int i=l; i<=s; i++) A[n][i] = -1-bag; // fewer
  for (int i=e-1; i<r; i++) A[n][i] = -1-!bag; // more

  // divide [s+1, e-1) into 2 or 3 groups
  for (int j=0; j<base[d]; j++) {
    int m = id[d][j]; // group id
    int gl = s+1 + D[d-1]*j, gr = gl + D[d-1]; // group's range

    for (int i=gl; i<gr; i++) A[n][i] = m; // write group id
    solve(m, gl, gr, s, e, d-1); // next turn
  }
}

vector<vector<int>> devise_strategy(int N) {
  D[0] = 2;
  for (int d=1; d<=7; d++) {
    D[d] = D[d-1] * base[d] + 2;
    for (int j=0; j<base[d]; j++) id[d][j] = ++last;
  }

  solve(0, 1, D[7]+1, 1, D[7]+1, 7);

  vector<vector<int>> ans;
  for (int i=0; i<=20; i++) ans.push_back(vector(A[i], A[i]+N+1));
  return ans;
}
