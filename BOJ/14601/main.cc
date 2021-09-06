#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, x, y, num = 1, A[1<<7][1<<7];

void solve(int sx, int sy, int n, int x, int y) {
  if (n == 1) return;
  int cx = sx + n/2;
  int cy = sy + n/2;

  for (int a: {0, 1}) {
    for (int b: {0, 1}) {
      if ((x >= cx) == a && (y >= cy) == b) continue;
      A[cx + a-1][cy + b-1] = num;
    }
  }
  num++;

  for (int a: {0, 1}) {
    for (int b: {0, 1}) {
      if ((x >= cx) == a && (y >= cy) == b) {
        solve(a?cx:sx, b?cy:sy, n/2, x, y);
      } else {
        solve(a?cx:sx, b?cy:sy, n/2, cx-1+a, cy-1+b);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> K >> x >> y;
  A[--x][--y] = -1;
  solve(0, 0, 1<<K, x, y);

  for (int y=(1<<K)-1; y>=0; y--) {
    for (int x=0; x<1<<K; x++) cout << A[x][y] << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
