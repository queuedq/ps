#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 202;
int A, B, C, vst[MX][MX][MX];

void dfs(int a, int b, int c) {
  if (vst[a][b][c]) return;
  vst[a][b][c] = 1;
  int x;

  x = min(a, B-b); dfs(a-x, b+x, c);
  x = min(a, C-c); dfs(a-x, b, c+x);
  x = min(b, A-a); dfs(a+x, b-x, c);
  x = min(b, C-c); dfs(a, b-x, c+x);
  x = min(c, A-a); dfs(a+x, b, c-x);
  x = min(c, B-b); dfs(a, b+x, c-x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> A >> B >> C;
  dfs(0, 0, C);
  for (int i=0; i<=C; i++) {
    if (vst[0][C-i][i]) cout << i << " ";
  }

  ////////////////////////////////
  return 0;
}
