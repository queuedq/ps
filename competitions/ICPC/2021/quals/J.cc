#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

const int MN = 305;
int m, n, p[MN][MN], psum[MN][MN], cnt;

int sum(int x1, int y1, int x2, int y2) {
  return psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n;
  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) cin >> p[i][j];
  }

  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) {
      psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + p[i][j];
    }
  }

  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) {
      int y = n;
      for (int x=i; x<=m; x++) {
        while (j <= y && sum(i, j, x, y) > 10) y--;
        if (sum(i, j, x, y) == 10) cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
