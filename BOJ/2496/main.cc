#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MT = 105;
int N, M, T, K;
pii A[MT];
vector<int> xs[2], ys[2]; // [0]: even, [1]: odd

bool in_square(int sx, int sy, int x, int y) {
  return sx<=x && x<=sx+K && sy<=y && y<=sy+K;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> T >> K;
  for (int i=0; i<T; i++) {
    int a, b; cin >> a >> b;
    A[i] = {a+b, a-b};
    int p = (a+b)&1;
    xs[p].push_back(a+b);
    ys[p].push_back(a-b);
    xs[!p].push_back(a+b-1);
    ys[!p].push_back(a-b-1);
  }

  int ans = 0, sx = 0, sy = 0;
  for (int p: {0, 1}) {
    for (int i=0; i<xs[p].size(); i++) {
      for (int j=0; j<ys[p].size(); j++) {
        int cnt = 0;
        for (int k=0; k<T; k++) {
          auto [x, y] = A[k];
          cnt += in_square(xs[p][i], ys[p][j], x, y);
        }

        if (cnt > ans) {
          ans = cnt;
          sx = xs[p][i];
          sy = ys[p][j];
        }
      }
    }
  }

  int cx = (sx+sy)/2 + K/2;
  int cy = (sx-sy)/2;
  cx = min(max(cx, 0), N);
  cy = min(max(cy, 0), M);
  cout << cx << " " << cy << endl << ans << endl;

  ////////////////////////////////
  return 0;
}
