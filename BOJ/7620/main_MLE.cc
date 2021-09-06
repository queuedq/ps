#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
string A, B;
const int MN = 17005;
int N, M, D[MN][MN], E[MN][MN]; // 0: add, 1: del, 2: mod, 3: cpy

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B;
  N = A.size(); M = B.size();

  for (int i=1; i<=N; i++) { D[i][0] = i; E[i][0] = 1; }
  for (int j=1; j<=M; j++) { D[0][j] = j; E[0][j] = 0; }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      if (A[i-1] == B[j-1]) {
        D[i][j] = D[i-1][j-1];
        E[i][j] = 3;
      } else {
        D[i][j] = min({D[i][j-1], D[i-1][j], D[i-1][j-1]}) + 1;
        if (D[i][j] == D[i][j-1] + 1) E[i][j] = 0;
        if (D[i][j] == D[i-1][j] + 1) E[i][j] = 1;
        if (D[i][j] == D[i-1][j-1] + 1) E[i][j] = 2;
      }
    }
  }

  vector<pair<char, char>> ans;
  for (int i=N, j=M; pii(i, j) != pii(0, 0);) {
    if (E[i][j] == 0) { ans.push_back({'a', B[j-1]}); j--; }
    if (E[i][j] == 1) { ans.push_back({'d', A[i-1]}); i--; }
    if (E[i][j] == 2) { ans.push_back({'m', B[j-1]}); i--; j--; }
    if (E[i][j] == 3) { ans.push_back({'c', A[i-1]}); i--; j--; }
  }
  reverse(ans.begin(), ans.end());

  for (auto [op, ch]: ans) cout << op << " " << ch << endl;

  ////////////////////////////////
  return 0;
}
