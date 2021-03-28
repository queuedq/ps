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
vector<int> xs, ys;

bool in_square(int sx, int sy, int x, int y) {
  return sx<=x && x<=sx+K && sy<=y && y<=sy+K;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> T >> K;
  for (int i=0; i<T; i++) {
    int x, y; cin >> x >> y;
    A[i] = {x, y};
    xs.push_back(x);
    ys.push_back(y);
  }
  xs.push_back(N-K);
  ys.push_back(M-K);

  int ans = 0, sx = 0, sy = 0;
  for (int i=0; i<xs.size(); i++) {
    if (xs[i]+K > N) continue;
    for (int j=0; j<ys.size(); j++) {
      if (ys[j]+K > M) continue;

      int cnt = 0;
      for (int k=0; k<T; k++) {
        auto [x, y] = A[k];
        cnt += in_square(xs[i], ys[j], x, y);
      }

      if (cnt > ans) {
        ans = cnt;
        sx = xs[i];
        sy = ys[j];
      }
    }
  }

  cout << sx << " " << sy+K << endl << ans << endl;

  ////////////////////////////////
  return 0;
}
