#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
bool vst[100][100];

int dfs(int x, int y, int px, int py, int len) {
  if (len > N) return 0;
  if (vst[x][y]) return len == N;
  vst[x][y] = true;

  int ans = 0;

  int xs[3] = {x-1, x+1, x};
  int ys[3] = {y, y, y + ((x+y)%2 ? 1 : -1)};

  for (int i=0; i<3; i++) {
    if (xs[i] == px && ys[i] == py) continue;
    ans += dfs(xs[i], ys[i], x, y, len+1);
  }

  vst[x][y] = false;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  vst[50][50] = true;
  cout << dfs(51, 50, 50, 50, 0) << endl;

  ////////////////////////////////
  return 0;
}
