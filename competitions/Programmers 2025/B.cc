#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
using lld = long long;
using pii = pair<int, int>;

////////////////////////////////////////////////////////////////
// 문제를 똑바로 읽자
const int INF = 1e9;
const int _N = 20;
const int _M = 105;
int N, M, K;
vector<int> A[_N], B[_N];
int D[_M][2]; // dropped one cell?

int dp() {
  bool flag = (N%2 == 0) && (M%2 == 0);

  D[0][1] = -INF;

  for (int i=1; i<=M; i++) {
    int sum_A = 0, sum_B = 0;
    int min_A = INF, min_B = INF;
    for (int k=1; k<=N; k++) {
      sum_A += A[k][i];
      sum_B += B[k][i];
      if ((k+i)%2 == 1) {
        min_A = min(min_A, A[k][i]);
        min_B = min(min_B, B[k][i]);
      }
    }
    
    D[i][0] = D[i-1][0] + max(sum_A, sum_B - K);
    D[i][1] = D[i-1][1] + max(sum_A, sum_B - K);
    D[i][1] = max(D[i][1], D[i-1][0] + max(sum_A - min_A, sum_B - min_B - K));

    // cout << i << ": " << sum_A << " " << sum_B << " " << min_A << " " << min_B << endl;
    // cout << i << ": " << D[i][0] << " " << D[i][1] << endl;
  }

  if (flag) return D[M][1];
  else return D[M][0];
}

int solution(vector<vector<int>> _A, vector<vector<int>> _B, int _K) {
  // init
  N = sz(_A), M = sz(_A[0]), K = _K;
  for (int i=1; i<=N; i++) {
    A[i].resize(M+1), B[i].resize(M+1);
    for (int j=1; j<=M; j++) A[i][j] = _A[i-1][j-1], B[i][j] = _B[i-1][j-1];
  }
  
  // dp
  int ans = 0;

  for (int m=0; m<1<<(N+1); m+=2) {
    for (int i=1; i<=N; i++) if (m>>i & 1) swap(A[i], B[i]);

    // for (int i=1; i<=N; i++) { for (int j=1; j<=M; j++) cout << A[i][j] << " "; cout << endl; } cout << endl;
    // for (int i=1; i<=N; i++) { for (int j=1; j<=M; j++) cout << B[i][j] << " "; cout << endl; } cout << endl;
    // cout << dp() << endl;

    int score = dp() - K * __builtin_popcount(m);
    ans = max(ans, score);

    for (int i=1; i<=N; i++) if (m>>i & 1) swap(A[i], B[i]);
  }

  // cout << ans << endl;
  return ans;
}

int main() {
  solution({{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, 5);
}
