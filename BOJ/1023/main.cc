#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const lld MAX_N = 55;
lld N, K;
lld D[MAX_N][MAX_N]; // length, open

lld pow(lld n) {
  return 1L << n;
}

lld getD(lld i, lld j) {
  if (i < 0 || j < 0) { return 0; }
  return D[i][j];
}

void dp() {
  D[0][0] = 1;
  for (lld i = 1; i <= N; i++) {
    for (lld j = 0; j <= N; j++) {
      D[i][j] = getD(i-1, j-1) + getD(i-1, j+1);
    }
  }
}

string search() {
  if (K >= pow(N) - D[N][0]) { return "-1"; }

  string res = "";
  lld open = 0;
  bool valid = true;
  for (int i = 0; i < N; i++) {
    if (open < 0) valid = false;
    lld skip = pow(N - i - 1);
    if (valid) skip -= D[N - i - 1][open + 1];

    if (K < skip) {
      open++;
      res.append("(");
    } else {
      K -= skip;
      open--;
      res.append(")");
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  dp();
  cout << search() << endl;

  // for (int i = 0; i < 1 << N; i++) {
  //   cout << i << " " << numStr(i) << endl;
  // }

  ////////////////////////////////
  return 0;
}
