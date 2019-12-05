#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 51;
const int MAX_H = 5e5 + 5;
int N, H[MAX_N];
int D[MAX_N][MAX_H * 2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  for (int i = 0; i < N; i++) {
    fill(D[i], D[i] + MAX_H * 2, -1);
    if (i == 0) {
      D[i][MAX_H] = 0;
      D[i][MAX_H + H[i]] = H[i];
      D[i][MAX_H - H[i]] = 0;
      continue;
    }

    for (int j = 0; j < MAX_H * 2; j++) {
      if (j + H[i] < MAX_H * 2 && D[i - 1][j] != -1) {
        D[i][j + H[i]] = max(D[i][j + H[i]], D[i - 1][j] + H[i]);
      }
      if (j - H[i] >= 0 && D[i - 1][j] != -1) {
        D[i][j - H[i]] = max(D[i][j - H[i]], D[i - 1][j]);
      }
      D[i][j] = max(D[i][j], D[i - 1][j]);
    }
  }

  if (D[N - 1][MAX_H] > 0) {
    cout << D[N - 1][MAX_H] << endl;
  } else {
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
