#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_K = 505;
int K, A[MAX_K], S[MAX_K];
lld score[MAX_K][MAX_K];

void reset() {
  for (int i = 0; i < MAX_K; i++) {
    for (int j = 0; j < MAX_K; j++) {
      score[i][j] = 0;
    }
  }
}

void input() {
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }
}

lld dp(int l, int r) {
  if (l + 1 == r) { return 0; }
  if (score[l][r] > 0) { return score[l][r]; }
  lld minScore = LLONG_MAX;
  for (int i = l + 1; i < r; i++) {
    minScore = min(minScore, dp(l, i) + dp(i, r) + S[r] - S[l]);
  }
  score[l][r] = minScore;
  return minScore;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    reset();
    input();
    cout << dp(0, K) << endl;
  }

  ////////////////////////////////
  return 0;
}
