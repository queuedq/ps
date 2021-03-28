#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define MAX_N 33
int N, L;
lld I;
int D[MAX_N][MAX_N];
int S[MAX_N][MAX_N];
int bits[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L >> I;
  I -= 1;

  D[0][0] = 1;
  for (int i = 0; i <= N; i++) { S[0][i] = 1; }
  for (int i = 1; i <= N; i++) {
    D[i][0] = D[i - 1][0];
    S[i][0] = D[i][0];
    for (int j = 1; j <= N; j++) {
      D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
      S[i][j] = S[i][j - 1] + D[i][j];
    }
  }

  int pos = N - 1;

  while (pos >= 0) {
    // cout << pos << " " << L << " " << I << " " << S[pos][L] << endl;
    if (S[pos][L] <= I) {
      bits[pos] = 1;
      I -= S[pos][L];
      L -= 1;
    }
    pos--;
  }

  for (int i = N - 1; i >= 0; i--) {
    cout << bits[i];
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
