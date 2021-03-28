#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
string A, B;
int D[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B;
  int a = A.size(), b = B.size();

  for (int i=1; i<=a; i++) {
    for (int j=1; j<=b; j++) {
      if (A[i-1] == B[j-1]) D[i][j] = D[i-1][j-1] + 1;
      else D[i][j] = max(D[i][j-1], D[i-1][j]);
    }
  }

  cout << D[a][b] << endl;

  vector<char> ans;
  int i = a, j = b;
  while (i > 0 && j > 0) {
    if (A[i-1] == B[j-1]) {
      ans.push_back(A[i-1]);
      i--;
      j--;
    } else {
      if (D[i][j-1] > D[i-1][j]) j--;
      else i--;
    }
  }

  for (int i = ans.size()-1; i >= 0; i--) cout << ans[i];
  cout << endl;

  ////////////////////////////////
  return 0;
}
