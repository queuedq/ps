#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = -1e9;
const int MAXN = 55;
int N, K, P, A[MAXN][MAXN], D[MAXN][MAXN*MAXN];

void reset() {
  for (int i=1; i<=N; i++) {
    for (int j=0; j<=K; j++) {
      A[i][j] = 0;
    }
  }
  for (int i=1; i<=N; i++) {
    for (int j=0; j<=P; j++) {
      D[i][j] = 0;
    }
  }
}

void calc(int test) {
  cin >> N >> K >> P;
  reset();

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=K; j++) {
      cin >> A[i][j];
      A[i][j] += A[i][j-1];
    }
  }

  for (int i=1; i<=N; i++) {
    for (int j=0; j<=P; j++) {
      for (int k=0; k<=j && k<=K; k++) {
        D[i][j] = max(D[i][j], A[i][k] + D[i-1][j-k]);
      }
    }
  }

  cout << "Case #" << test << ": " << D[N][P] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    calc(t);
  }

  ////////////////////////////////
  return 0;
}
