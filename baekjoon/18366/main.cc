#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int N = 55;
const int M = 4005;
int n, m, cnt[N][N][N], D[M][N][N], E[M][N][N], ans[N];

struct Customer {
  int a, b, c;
  bool operator <(const Customer &C) const { return c < C.c; }
};
Customer A[M];

int dp(int k, int l, int r) {
  if (l > r) return 0;
  int &res = D[k][l][r];
  if (res != -1) return res;

  res = D[k+1][l][r];
  for (int i=l; i<=r; i++) {
    int d = A[k].c * cnt[l][r][i] + dp(k, l, i-1) + dp(k, i+1, r);
    if (d > res) { res = d; E[k][l][r] = i; }
  }

  return D[k][l][r];
}

void trace(int k, int l, int r) {
  if (l > r || k > m) return;
  int i = E[k][l][r];
  if (i == 0) return trace(k+1, l, r);
  ans[i] = A[k].c;
  trace(k, l, i-1);
  trace(k, i+1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int k=1; k<=m; k++) cin >> A[k].a >> A[k].b >> A[k].c;
  sort(A+1, A+m+1);

  for (int k=1; k<=m; k++) {
    for (int l=1; l<=n; l++) fill(D[k][l]+1, D[k][l]+n+1, -1);
  }

  for (int k=m; k>=1; k--) {
    for (int l=1; l<=n; l++) {
      for (int r=l; r<=n; r++) {
        if (A[k].a < l || r < A[k].b) continue;
        for (int i=A[k].a; i<=A[k].b; i++) cnt[l][r][i]++;
      }
    }
    dp(k, 1, n);
  }

  fill(ans+1, ans+n+1, A[m].c);
  trace(1, 1, n);

  cout << D[1][1][n] << endl;
  for (int i=1; i<=n; i++) cout << ans[i] << " ";

  ////////////////////////////////
  return 0;
}
