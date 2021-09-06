#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, A[MN], D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i] >> A[i+1];

  for (int l=2; l<=N; l++) {
    for (int s=0; s+l-1<N; s++) {
      int e = s+l-1;
      D[s][e] = INT_MAX;
      for (int m=s; m<e; m++) {
        D[s][e] = min(D[s][e], D[s][m] + D[m+1][e] + A[s] * A[m+1] * A[e+1]);
      }
    }
  }

  cout << D[0][N-1] << endl;

  ////////////////////////////////
  return 0;
}
