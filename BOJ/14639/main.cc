#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _H = 310;
int H, W;
int A[_H][_H], B[_H][_H];

void previous_state(int h, int w) {
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {

      for (int a=1; a>=-1; a--) {
        for (int b=1; b>=-1; b--) {
          B[i+1][j+1] ^= B[i+a][j+b]; // B[i+1][j+1] is reset to 0 in the first iteration
        }
      }
      B[i+1][j+1] ^= A[i][j];
    }
  }
}

pii detect_error(int h, int w) {
  int r = 0, c = 0;
  for (int i=2; i<=h+1; i++) {
    if (B[i][w] || B[i][w+1]) { r = i; break; }
  }
  for (int j=2; j<=w+1; j++) {
    if (B[h][j] || B[h+1][j]) { c = j; break; }
  }
  return {r, c};
}

pii solve(int h, int w) {
  if (h <= 2 || w <= 2) return {h, w};

  // reconstruct previous state
  previous_state(h, w);

  // detect error and flip bit
  auto [x, y] = detect_error(h, w);

  if (x != 0) {
    // flip pattern
    // ##.
    // ##.
    // ...
    for (int i=x; i<=h+1; i++) {
      for (int j=y; j<=w+1; j++) {
        if ((i-x)%3 == 2 || (j-y)%3 == 2) continue;
        B[i][j] ^= 1;
      }
    }
  }

  // detect error again
  auto [xx, yy] = detect_error(h, w);
  if (xx != 0) return {h, w}; // no previous state

  // find bounding box
  int r0 = _H, c0 = _H;
  int r1 = 0, c1 = 0;
  for (int i=2; i<=h+1; i++) {
    for (int j=2; j<=w+1; j++) {
      if (B[i][j]) {
        r0 = min(r0, i), c0 = min(c0, j);
        r1 = max(r1, i), c1 = max(c1, j);
      }
    }
  }

  // copy and recurse
  for (int i=r0; i<=r1; i++) {
    for (int j=c0; j<=c1; j++) {
      A[i-r0+1][j-c0+1] = B[i][j];
    }
  }

  return solve(r1-r0+1, c1-c0+1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> W >> H;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      char c; cin >> c;
      A[i][j] = c == '#';
    }
  }

  auto [h, w] = solve(H, W);

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      cout << (A[i][j] ? '#' : '.');
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
