#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 1e9+7;
lld N, M;
lld A[10][10][4];
lld D[2][1 << 20], E[2][1 << 20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int c=0; c<4; c++) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        cin >> A[i][j][c];
      }
    }
  }

  for (int f=0; f < 1 << 2*M; f++) {
    E[0][f] = 1;
    int prev = -1;
    for (int j=0; j<M; j++) {
      int c = f >> 2*j & 3;
      if (c == prev) { D[0][f] = 0; E[0][f] = 0; break; }
      D[0][f] += A[0][j][c];
      prev = c;
    }
  }

  for (int i=1; i<N; i++) {
    for (int j=0; j<M; j++) {
      for (int f=0; f < 1 << 2*M; f++) {
        int c = f >> 2*j & 3;
        if (j > 0 && c == (f >> 2*(j-1) & 3)) continue;

        for (int d=0; d<4; d++) {
          if (c == d) continue;
          int g = f - (c << 2*j) + (d << 2*j);
          int cost = D[0][g] + A[i][j][c];
          if (cost > D[1][f]) {
            D[1][f] = cost;
            E[1][f] = E[0][g];
          } else if (cost == D[1][f]) {
            E[1][f] = (E[1][f] + E[0][g]) % MOD;
          }
        }
      }

      for (int f=0; f < 1 << 2*M; f++) {
        D[0][f] = D[1][f]; D[1][f] = 0;
        E[0][f] = E[1][f]; E[1][f] = 0;
      }
    }
  }

  lld ans = 0, cnt = 0;
  for (int f=0; f < 1 << 2*M; f++) {
    if (D[0][f] > ans) {
      ans = D[0][f];
      cnt = E[0][f];
    } else if (D[0][f] == ans) {
      cnt = (cnt + E[0][f]) % MOD;
    }
  }

  cout << ans << " " << cnt << endl;

  ////////////////////////////////
  return 0;
}
