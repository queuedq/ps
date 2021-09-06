#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string A, B;
const int MN = 1010;
int N, M, D[MN][MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B;
  N = A.size(); M = B.size();

  for (int i=1; i<=N; i++) D[i][0] = i;
  for (int j=1; j<=M; j++) D[0][j] = j;

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      if (A[i-1] == B[j-1]) D[i][j] = D[i-1][j-1];
      else D[i][j] = min({D[i][j-1], D[i-1][j], D[i-1][j-1]}) + 1;
    }
  }

  cout << D[N][M] << endl;

  ////////////////////////////////
  return 0;
}
