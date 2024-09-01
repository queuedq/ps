#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 10;
char A[1<<MK][1<<MK];

void solve(int L, int x, int y, int a, int b) {
  if (L == 2) {
    int color = (x/2 + y/2) % 2 == 0 ? 'b' : 'c';
    for (int i=0; i<2; i++) for (int j=0; j<2; j++) {
      if (!(x+i == a && y+j == b)) A[x+i][y+j] = color;
    }
    return;
  }

  int M = L/2;
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      int na = x + M-1 + i;
      int nb = y + M-1 + j;
      if (a/M - x/M == i && b/M - y/M == j) na = a, nb = b;
      else A[na][nb] = 'a';
      solve(M, x + i*M, y + j*M, na, nb);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T, K; cin >> T >> K;
  while (T--) {
    int a, b; cin >> a >> b;
    a--, b--;
    solve(1<<K, 0, 0, a, b);
    A[a][b] = '@';

    for (int i=0; i<1<<K; i++) {
      for (int j=0; j<1<<K; j++) cout << A[i][j];
      cout << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
