#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 15;
const int MM = MK*(MK+1)/2 + 5;
const int O = MM*MK;
int K, M;

struct Tile {
  // [w = 1]  [w = 2]
  // a        a     b
  // b        K+1-a K+1-b
  int w, a, b;
};
Tile T[MM];

// indices: # tiles, # cols, diff
// values: 0 (impossible), 1 (skipped), 2 (placed), 3 (flipped)
int D[MM][MM][O*2];
vector<int> ans[2];

void place_tile(int i, bool f) {
  auto [w, a, b] = T[i];
  if (w == 1) {
    ans[f].push_back(-a);
    ans[!f].push_back(-b);
  } else {
    ans[f].push_back(a);
    ans[f].push_back(b);
    ans[!f].emplace_back(K+1-a);
    ans[!f].push_back(K+1-b);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> K >> M;

  // make tiles
  // (K+1)/2 vertical singles, (K^2-K)/2 horizontal pairs
  int tcnt = 0;
  for (int a=1; a<=K; a++) {
    for (int b=a; b<=K; b++) {
      if (a+b == K+1) T[++tcnt] = {1, a, b};
      else if (a+b <= K) T[++tcnt] = {2, a, b};
    }
  }

  // DP
  D[0][0][O] = 1;
  for (int i=0; i<tcnt; i++) {
    for (int j=0; j<=M; j++) {
      for (int k=-j*(K-1); k<=j*(K-1); k++) {
        if (D[i][j][O+k]) {
          auto [w, a, b] = T[i+1];
          int diff = (w == 1) ? (b-a) : (K+1-a-b)*2;

          D[i+1][j][O+k] = 1;
          D[i+1][j+w][O+k+diff] = 2;
          D[i+1][j+w][O+k-diff] = 3;
        }
      }
    }
  }

  // traceback
  int i = tcnt, j = M, k = 0;

  if (!D[i][j][O+k]) {
    cout << "NO" << endl;
  } else {
    while (i) {
      auto [w, a, b] = T[i];
      int diff = (w == 1) ? (b-a) : (K+1-a-b)*2;
      int dp = D[i][j][O+k];

      if (dp >= 2) place_tile(i, dp == 3);

      i--;
      if (dp == 2) j -= w, k -= diff;
      if (dp == 3) j -= w, k += diff;
    }

    cout << "YES" << endl;
    for (auto x: ans[0]) { cout << x << " "; } cout << endl;
    for (auto x: ans[1]) { cout << x << " "; } cout << endl;
  }

  ////////////////////////////////
  return 0;
}
