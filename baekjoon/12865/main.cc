#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 105
#define MAX_K 100005
int N, K;
int W[MAX_N], V[MAX_N];
int value[MAX_N][MAX_K];

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> W[i] >> V[i];
  }
}

int dp() {
  value[0][W[0]] = V[0];
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      if (j - W[i] >= 0) {
        value[i][j] = max(value[i - 1][j], value[i - 1][j - W[i]] + V[i]);
      } else {
        value[i][j] = value[i - 1][j];
      }
    }
  }

  int maxValue = 0;
  for (int i = 0; i <= K; i++) {
    maxValue = max(maxValue, value[N - 1][i]);
  }

  return maxValue;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  cout << dp() << endl;

  ////////////////////////////////
  return 0;
}
