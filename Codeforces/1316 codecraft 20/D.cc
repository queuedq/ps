#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
char dirs[4] = {'R', 'D', 'L', 'U'};
char revdirs[4] = {'L', 'U', 'R', 'D'};

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int n;
pii dest[MAXN][MAXN];
bool visited[MAXN][MAXN];
char board[MAXN][MAXN];

pii move(pii u, int dir) {
  int y = u.first + dy[dir];
  int x = u.second + dx[dir];
  return {y, x};
}

bool oob(pii u) {
  return u.first<=0 || u.first>n || u.second<=0 || u.second>n;
}

void dfs1(pii u, pii d, int dir) {
  if (oob(u)) return;
  if (dest[u.first][u.second] != d) return;
  if (visited[u.first][u.second]) return;
  visited[u.first][u.second] = true;
  board[u.first][u.second] = dir == -1 ? 'X' : revdirs[dir];

  for (int i=0; i<4; i++) {
    pii v = move(u, i);
    dfs1(v, d, i);
  }
}

bool dfs2(pii u, int dir) {
  if (oob(u)) return false;
  if (dest[u.first][u.second] != pii(-1,-1)) return false;
  if (visited[u.first][u.second]) return false;
  visited[u.first][u.second] = true;
  board[u.first][u.second] = dir == -1 ? 'X' : revdirs[dir];

  for (int i=0; i<4; i++) {
    pii v = move(u, i);
    bool go = dfs2(v, i);
    if ((dir == -1) && go) board[u.first][u.second] = dirs[i];
  }

  return true;
}

bool calc() {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (pii(i,j) == dest[i][j]) {
        dfs1(pii(i,j), dest[i][j], -1);
      } else if (dest[i][j] == pii(-1,-1)) {
        dfs2(pii(i,j), -1);
        if (board[i][j] == 'X') return false;
      }
    }
  }

  // visited all check
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (!visited[i][j]) return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      int x,y; cin>>x>>y;
      dest[i][j] = {x, y};
    }
  }

  if (calc()) {
    cout << "VALID\n";
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (board[i][j] != 0) {
          cout<<board[i][j];
        } else {
          cout<<'?';
        }
      }
      cout<<endl;
    }
  } else {
    cout << "INVALID\n";
  }

  ////////////////////////////////
  return 0;
}
