#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
const int MAXN = 705;

int N, M;
bool maze[MAXN][MAXN];
bool vst[MAXN][MAXN], vvst[MAXN][MAXN];
bool seen[MAXN][MAXN][5];

struct Pos { int x, y; } Y, V, T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  queue<Pos> q, vq;

  for (int i=1; i<=N; i++) {
    string s; cin >> s;
    for (int j=1; j<=M; j++) {
      if (s[j-1] != 'I') maze[i][j] = true;
      if (s[j-1] == 'Y') Y = {i, j};
      if (s[j-1] == 'V') V = {i, j};
      if (s[j-1] == 'T') T = {i, j};
    }
  }

  q.push(Y); vst[Y.x][Y.y] = true;
  vq.push(V); vvst[V.x][V.y] = true;

  while (!q.empty()) {
    int sz = vq.size();
    for (int i=0; i<sz; i++) {
      Pos u = vq.front(); vq.pop();

      for (int d=0; d<4; d++) {
        Pos v = {u.x+dx[d], u.y+dy[d]};
        if (!maze[v.x][v.y] || vvst[v.x][v.y]) continue;
        vvst[v.x][v.y] = true;
        vq.push({v.x, v.y});

        for (int d=0; d<4; d++) {
          int k=0;
          while (maze[v.x+dx[d]*k][v.y+dy[d]*k] && !seen[v.x+dx[d]*k][v.y+dy[d]*k][d]) {
            seen[v.x+dx[d]*k][v.y+dy[d]*k][d] = seen[v.x+dx[d]*k][v.y+dy[d]*k][4] = true;
            k++;
          }
        }
      }
    }

    sz = q.size();
    for (int i=0; i<sz; i++) {
      Pos u = q.front(); q.pop();

      for (int d=0; d<4; d++) {
        Pos v = {u.x+dx[d], u.y+dy[d]};
        if (!maze[v.x][v.y] || vst[v.x][v.y] || seen[v.x][v.y][4]) continue;
        vst[v.x][v.y] = true;
        q.push({v.x, v.y});
      }
    }
  }

  if (vst[T.x][T.y]) cout << "YES" << endl;
  else cout << "NO" << endl;

  ////////////////////////////////
  return 0;
}
