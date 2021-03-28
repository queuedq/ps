#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 10'000 + 5;
int N, W, A[MAX_N][2];
int D[MAX_N][3];

void input() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) { cin >> A[i][0]; }
  for (int i = 0; i < N; i++) { cin >> A[i][1]; }
}

int dp() {
  D[0][0] = 1; D[0][1] = 1;
  D[0][2] = (A[0][0] + A[0][1] <= W) ? 1 : 2;

  for (int i = 1; i < N; i++) {
    D[i][0] = D[i][1] = D[i-1][2] + 1;

    if (A[i-1][0] + A[i][0] <= W) {
      D[i][0] = min(D[i][0], D[i-1][1] + 1);
    }
    if (A[i-1][1] + A[i][1] <= W) {
      D[i][1] = min(D[i][1], D[i-1][0] + 1);
    }

    D[i][2] = min(D[i][0] + 1, D[i][1] + 1);
    D[i][2] = min(D[i][2], D[i-1][2] + (A[i][0] + A[i][1] <= W ? 1 : 2));
    if (A[i-1][0] + A[i][0] <= W && A[i-1][1] + A[i][1] <= W) {
      if (i == 1) { D[i][2] = 2; }
      else { D[i][2] = min(D[i][2], D[i-2][2] + 2); }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   cout << i << ": " << D[i][0] << " " << D[i][1] << " " << D[i][2] << endl;
  // }

  return D[N-1][2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    input();

    int in0 = A[0][0], in1 = A[N-1][0];
    int out0 = A[0][1], out1 = A[N-1][1];

    int ans = dp();
    if (N == 1) {
      cout << ans << endl;
      continue;
    }

    if (in0 + in1 <= W) {
      A[0][0] = W; A[N-1][0] = W;
      ans = min(ans, dp() - 1);
      A[0][0] = in0; A[N-1][0] = in1;
    }
    if (out0 + out1 <= W) {
      A[0][1] = W; A[N-1][1] = W;
      ans = min(ans, dp() - 1);
      A[0][1] = out0; A[N-1][1] = out1;
    }
    if (in0 + in1 <= W && out0 + out1 <= W) {
      A[0][0] = W; A[N-1][0] = W;
      A[0][1] = W; A[N-1][1] = W;
      ans = min(ans, dp() - 2);
      A[0][0] = in0; A[N-1][0] = in1;
      A[0][1] = out0; A[N-1][1] = out1;
    }

    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
