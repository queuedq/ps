#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e9;
const int MN = 1010;
int N, A[MN][MN], S[MN][MN];
int X1[MN*MN], Y1[MN*MN], X2[MN*MN], Y2[MN*MN];
int ok[MN*MN], vis[MN*MN], vcnt;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  fill(X1, X1+N*N+1, INF);
  fill(Y1, Y1+N*N+1, INF);
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      int a; cin >> a;
      A[i][j] = a;
      if (a != 0) {
        vis[a] = 1;
        X1[a] = min(X1[a], i);
        Y1[a] = min(Y1[a], j);
        X2[a] = max(X2[a], i);
        Y2[a] = max(Y2[a], j);
      }
    }
  }

  // cover rects
  for (int a=1; a<=N*N; a++) {
    if (X1[a] != INF) {
      S[X1[a]][Y1[a]]++;
      S[X1[a]][Y2[a]+1]--;
      S[X2[a]+1][Y1[a]]--;
      S[X2[a]+1][Y2[a]+1]++;
    }
  }

  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) S[i][j] += S[i][j-1];
  for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) S[i][j] += S[i-1][j];

  // exclude rects above other ones
  fill(ok, ok+N*N+1, 1);
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (A[i][j] != 0 && S[i][j] > 1) ok[A[i][j]] = 0;
    }
  }

  // if only a single rect is visible, it cannot be the first rect
  for (int a=1; a<=N*N; a++) vcnt += vis[a];
  if (vcnt == 1 && N != 1) { // ...unless N=1
    for (int a=1; a<=N*N; a++) {
      if (vis[a]) ok[a] = 0;
    }
  }

  int ans = 0;
  for (int a=1; a<=N*N; a++) ans += ok[a];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
