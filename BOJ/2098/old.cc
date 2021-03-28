#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 17;
const int MAX_POW = 1 << 17;
int N, W[MAX_N][MAX_N], D[MAX_POW][MAX_N];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> W[i][j];
    }
  }
}

void dp() {
  for (int s = 0; s < (1 << N); s++) {
    for (int i = 0; i < N; i++) {
      D[s][i] = INT_MAX;
    }
  }
  D[1][0] = 0;

  for (int s = 0; s < (1 << N); s++) {
    for (int i = 0; i < N; i++) {
      if ((s & (1 << i)) == 0) { continue; }
      int ss = s - (1 << i);

      for (int j = 0; j < N; j++) {
        if ((ss & (1 << j)) == 0) { continue; }
        if (W[j][i] == 0) { continue; }
        if (D[ss][j] == INT_MAX) { continue; }

        D[s][i] = min(D[s][i], D[ss][j] + W[j][i]);
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < N; i++) {
    if (D[(1 << N) - 1][i] == INT_MAX || W[i][0] == 0) { continue; }
    ans = min(ans, D[(1 << N) - 1][i] + W[i][0]);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  dp();

  ////////////////////////////////
  return 0;
}
