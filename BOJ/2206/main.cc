#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
#define INF 987654321
#define MAX_N 1005
int N, M;
bool maze[MAX_N][MAX_N];
int dist1[MAX_N][MAX_N], dist2[MAX_N][MAX_N];

pii move(pii current, int dir) {
  int s[] = {0, 1, 0, -1};
  int x = current.first;
  int y = current.second;
  int dx = s[dir];
  int dy = s[(dir + 1) % 4];
  if (!maze[x + dx][y + dy]) return {0, 0};
  return {x + dx, y + dy};
}

void input() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string cells;
    cin >> cells;
    for (int j = 1; j <= M; j++) {
      char cell = cells[j - 1];
      if (cell == '0') {
        maze[i][j] = true;
      }
    }
  }
}

void bfs() {
  for (int i = 0; i <= N + 1; i++) {
    for (int j = 0; j <= M + 1; j++) {
      dist1[i][j] = INF;
      dist2[i][j] = INF;
    }
  }

  queue<pii> toVisit;

  toVisit.push({1, 1});
  dist1[1][1] = 1;
  while (!toVisit.empty()) {
    pii current = toVisit.front();
    toVisit.pop();
    for (int dir = 0; dir < 4; dir++) {
      pii nextCell = move(current, dir);
      if (nextCell == (pii){0, 0}) continue;
      if (dist1[nextCell.first][nextCell.second] == INF) {
        dist1[nextCell.first][nextCell.second] = dist1[current.first][current.second] + 1;
        toVisit.push(nextCell);
      }
    }
  }

  toVisit.push({N, M});
  dist2[N][M] = 1;
  while (!toVisit.empty()) {
    pii current = toVisit.front();
    toVisit.pop();
    for (int dir = 0; dir < 4; dir++) {
      pii nextCell = move(current, dir);
      if (nextCell == (pii){0, 0}) continue;
      if (dist2[nextCell.first][nextCell.second] == INF) {
        dist2[nextCell.first][nextCell.second] = dist2[current.first][current.second] + 1;
        toVisit.push(nextCell);
      }
    }
  }
}

int breakWall() {
  int result = dist1[N][M];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (maze[i][j]) continue;
      int D1 = INF, D2 = INF;
      for (int dir = 0; dir < 4; dir++) {
        pii nextCell = move({i, j}, dir);
        D1 = min(D1, dist1[nextCell.first][nextCell.second]);
        D2 = min(D2, dist2[nextCell.first][nextCell.second]);
      }
      result = min(result, D1 + D2 + 1);
    }
  }

  if (result == INF) return -1;
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  bfs();

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= M; j++) {
  //     cout << setw(12) << dist1[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= M; j++) {
  //     cout << setw(12) << dist2[i][j];
  //   }
  //   cout << endl;
  // }

  cout << breakWall() << endl;

  ////////////////////////////////
  return 0;
}
