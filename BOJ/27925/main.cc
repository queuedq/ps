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
const int MN = 5050;
int N, t[MN], D[MN][10][10][10];

int dist(int a, int b) {
  return min(abs(a-b), 10-abs(a-b));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> t[i];

  for (int i=0; i<=N; i++)
    for (int a=0; a<10; a++)
      for (int b=0; b<10; b++)
        for (int c=0; c<10; c++)
          D[i][a][b][c] = INF;
  D[0][0][0][0] = 0;

  for (int i=1; i<=N; i++) {
    for (int a=0; a<10; a++) {
      for (int b=0; b<10; b++) {
        for (int c=0; c<10; c++) {
          if (D[i-1][a][b][c] == INF) continue;
          int d = t[i];
          int da = dist(a, d), db = dist(b, d), dc = dist(c, d);
          D[i][d][b][c] = min(D[i][d][b][c], D[i-1][a][b][c] + da);
          D[i][a][d][c] = min(D[i][a][d][c], D[i-1][a][b][c] + db);
          D[i][a][b][d] = min(D[i][a][b][d], D[i-1][a][b][c] + dc);
        }
      }
    }
  }

  int ans = INF;
  for (int a=0; a<10; a++)
    for (int b=0; b<10; b++)
      for (int c=0; c<10; c++)
        ans = min(ans, D[N][a][b][c]);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
