#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
char tile[200][200];
vector<pii> ans;

void solve(int n);
void make_vertical(int x, int y);
void rotate_tiles(int x, int y);

void solve(int n) {
  if (n == 0) return;
  make_vertical(n*2-1, N-1);
  solve(n-1);
}

void make_vertical(int x, int y) {
  if (tile[x][y] == 'D') return;
  if (tile[x-1][y] == 'L') return rotate_tiles(x-1, y);

  if (tile[x-1][y] == 'R') make_vertical(x-1, y-1);
  if (tile[x-1][y+1] == 'L') make_vertical(x-1, y+1);
  rotate_tiles(x-2, y);
  rotate_tiles(x-1, y);
}

void rotate_tiles(int x, int y) {
  if (tile[x][y] == 'L') {
    tile[x][y] = tile[x][y+1] = 'U';
    tile[x+1][y] = tile[x+1][y+1] = 'D';
  } else if (tile[x][y] == 'U') {
    tile[x][y] = tile[x+1][y] = 'L';
    tile[x][y+1] = tile[x+1][y+1] = 'R';
  } else {
    assert(false);
  }
  ans.push_back({x, y});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*2; i++) {
    for (int j=0; j<N*2; j++) cin >> tile[i][j];
  }

  solve(N);
  cout << ans.size() << endl;
  for (auto [x, y]: ans) cout << x+1 << " " << y+1 << endl;

  ////////////////////////////////
  return 0;
}
