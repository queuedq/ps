#include "secret.h"

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1024;
int N, A[MN], ans[MN][MN];

void dnc(int l, int r) {
  if (l == r) return;
  int m = (l+r)/2;

  ans[m][m] = A[m];
  for (int i=m-1; i>=l; i--) {
    if (ans[i][m] == -1) ans[i][m] = Secret(A[i], ans[i+1][m]);
  }

  ans[m+1][m+1] = A[m+1];
  for (int i=m+2; i<=r; i++) {
    if (ans[m+1][i] == -1) ans[m+1][i] = Secret(ans[m+1][i-1], A[i]);
  }

  dnc(l, m);
  dnc(m+1, r);
}

void Init(int _N, int _A[]) {
  N = _N;
  for (int i=0; i<N; i++) A[i] = _A[i];

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) ans[i][j] = -1;
  }
  dnc(0, N-1);
}

int qry(int s, int e, int L, int R) {
  int m = (s+e)/2;
  if (L <= m && m+1 <= R) return Secret(ans[L][m], ans[m+1][R]);
  if (R <= m) return qry(s, m, L, R);
  if (m+1 <= L) return qry(m+1, e, L, R);
  assert(0);
}

int Query(int L, int R) {
  if (ans[L][R] != -1) return ans[L][R];
  return qry(0, N-1, L, R);
}
