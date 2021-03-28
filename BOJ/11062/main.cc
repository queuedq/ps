#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, A[MAXN], D[MAXN][MAXN];

void calc() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  for (int s=1; s<=N; s++) {
    for (int i=1; i<=N-s+1; i++) {
      int j = i+s-1;
      if ((N-s) % 2 == 0) {
        D[i][j] = max(D[i+1][j] + A[i], D[i][j-1] + A[j]);
      } else {
        D[i][j] = min(D[i+1][j], D[i][j-1]);
      }
    }
  }

  cout << D[1][N] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
