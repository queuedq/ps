#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
char A[10][10], B[10][10];

bool oob(int x, int y) {
  return x < 0 || x >= 10 || y < 0 || y >= 10;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int H, W;
  cin >> H >> W;
  for (int x=0; x<H; x++) {
    for (int y=0; y<W; y++) cin >> A[x][y];
  }
  cin >> H >> W;
  for (int x=0; x<H; x++) {
    for (int y=0; y<W; y++) cin >> B[x][y];
  }

  int best = 100;
  for (int dx=-9; dx<=9; dx++) {
    for (int dy=-9; dy<=9; dy++) {
      int cnt = 0;
      for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
          if (A[x][y] == 'O' && (oob(x-dx, y-dy) || B[x-dx][y-dy] != 'O')) cnt++;
        }
      }
      best = min(best, cnt);
    }
  }

  cout << best << endl;

  ////////////////////////////////
  return 0;
}
