#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
const int MOD = 1e9+7;
lld N, Q, A[ST], D[ST*2][4][4];

const vector<pll> table[4] = {
  {{0, 0}, {0, 3}, {1, 2}, {2, 1}, {3, 0}},
  {{0, 2}, {2, 0}},
  {{0, 1}, {1, 0}},
  {{0, 0}}
};

void build() {
  for (int y=N; y<ST; y++) A[y] = 3; // Blocked after Nth column

  for (int y=0; y<ST; y++) {
    for (auto [i, j]: table[A[y]]) D[ST+y][i][j] = 1;
  }

  for (int n=ST-1; n>0; n--) {
    for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        D[n][i][j] = 0;

        for (int k=0; k<4; k++) {
          D[n][i][j] += D[n*2][i][k] * D[n*2+1][k][j];
          D[n][i][j] %= MOD;
        }
      }
    }
  }
}

void update(int x, int y) {
  // Set constraints
  A[y] = A[y] ^ (1 << x);

  // Set segtree leaf
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) D[ST+y][i][j] = 0;
  }
  for (auto [i, j]: table[A[y]]) D[ST+y][i][j] = 1;

  // Update segtree
  for (int n = (ST+y)/2; n > 0; n /= 2) {
    for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        D[n][i][j] = 0;

        for (int k=0; k<4; k++) {
          D[n][i][j] += D[n*2][i][k] * D[n*2+1][k][j];
          D[n][i][j] %= MOD;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  build();
  // cout << D[1][0][0] << endl;

  for (int i=0; i<Q; i++) {
    lld q, x, y; cin >> q >> x >> y;
    x--; y--;
    update(x, y);
    cout << D[1][0][0] << endl;
  }

  ////////////////////////////////
  return 0;
}
