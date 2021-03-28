#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

////////////////////////////////////////////////////////////////
const int MAX = 1505;
const int INF = 1e9;
int w, h, C[MAX][MAX], D[3][MAX][MAX], P[3][MAX][MAX];
bool A[MAX][MAX];

pii move(pii u, int d) { return {u.first + dy[d], u.second + dx[d]}; }
bool oob(pii u) { return u.first <= 0 || u.first > h || u.second <= 0 || u.second > w; }

void dfs(pii u, int m) {
  if (oob(u)) return;
  if (C[u.first][u.second]) return;
  if (!A[u.first][u.second]) return;
  C[u.first][u.second] = m;
  for (int d=0; d<8; d++) {
    pii v = move(u, d);
    dfs(v, m);
  }
}

void dp(int m) {
  int (*E)[MAX] = D[m];

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      if (C[i][j] & (4|m)) { E[i][j] = 0; continue; }
      if (i==1 || j==1) { E[i][j] = 1; continue; }

      bool adj = false;
      for (int d=0; d<8; d++) {
        pii v = move({i, j}, d);
        if (C[v.first][v.second] & m) { adj = true; break; }
      }
      if (adj) { E[i][j] = 1; continue; }

      int a = E[i-1][j];
      int b = E[i][j-1];
      if (a == b && (C[i-a][j-a] & (4|m))) E[i][j] = a;
      else E[i][j] = min(a, b) + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin>>w>>h;
  for (int i=1; i<=h; i++) {
    string a; cin>>a;
    for (int j=1; j<=w; j++) A[i][j] = (a[j-1] == '#');
  }

  // Mark walls
  for (int i=1; i<=h; i++) dfs({i, 1}, 1);
  for (int j=1; j<=w; j++) dfs({h, j}, 1);
  for (int j=1; j<=w; j++) dfs({1, j}, 2);
  for (int i=1; i<=h; i++) dfs({i, w}, 2);

  for (int i=1; i<=h; i++) C[i][0] = 1;
  for (int j=1; j<=w; j++) C[h+1][j] = 1;
  for (int j=1; j<=w; j++) C[0][j] = 2;
  for (int i=1; i<=h; i++) C[i][w+1] = 2;
  C[1][1] = 4;
  C[h][w] = 4;

  // DP
  dp(1); dp(2);

  // Prefix sum
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      P[0][i][j] = P[0][i-1][j] + P[0][i][j-1] - P[0][i-1][j-1] + A[i][j];
    }
  }

  for (int i=0; i<=h+1; i++) {
    for (int j=0; j<=w+1; j++) {
      if (i==0 && j==0) continue;
      if (j==0) P[1][i][j] = P[1][i-1][j] + !!(C[i][j]&1);
      if (i==0) P[2][i][j] = P[2][i][j-1] + !!(C[i][j]&2);
      P[1][i][j] = P[1][i-1][j] + P[1][i][j-1] - P[1][i-1][j-1] + !!(C[i][j]&1);
      P[2][i][j] = P[2][i-1][j] + P[2][i][j-1] - P[2][i-1][j-1] + !!(C[i][j]&2);
    }
  }

  // Find answer
  int ans = INF, y = 0, x = 0;

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      if ((i==1 && j==1) || (i==h && j==w)) continue;
      int a = D[1][i][j], b = D[2][i][j];
      if (P[1][i+1][j+1] - P[1][i-a-1][j+1] - P[1][i+1][j-a-1] + P[1][i-a-1][j-a-1] == 0) continue;
      if (P[2][i+1][j+1] - P[2][i-b-1][j+1] - P[2][i+1][j-b-1] + P[2][i-b-1][j-b-1] == 0) continue;
      int s = max(a, b);
      assert(s > 0);
      if (P[0][i][j] - P[0][i-s][j] - P[0][i][j-s] + P[0][i-s][j-s] > 0) continue;
      if (s < ans) {
        ans = s;
        y = i-s+1;
        x = j-s+1;
      }
    }
  }

  if (ans == INF) cout << "Impossible" << endl;
  else cout << ans << " " << x << " " << y << endl;

  ////////////////////////////////
  return 0;
}
