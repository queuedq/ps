#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1005;
const int MAX_K = 15;
int N, M, K;
bool wall[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_K];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Pos {
  int i, j, k;
};
queue<Pos> q;

void input() {
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    string cells; cin >> cells;
    for (int j = 1; j <= M; j++) {
      char cell = cells[j - 1];
      if (cell == '1') {
        wall[i][j] = true;
      }
    }
  }
}

void init() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      for (int k = 0; k <= K; k++) {
        dist[i][j][k] = INT_MAX;
      }
    }
  }
}

bool oob(int i, int j, int k) {
  if (i <= 0 || i > N) return true;
  if (j <= 0 || j > M) return true;
  if (k < 0 || k > K) return true;
  return false;
}

void bfs() {
  q.push({1, 1, 0});
  dist[1][1][0] = 1;

  while (!q.empty()) {
    Pos p = q.front(); q.pop();

    for (int d = 0; d < 4; d++) {
      int i = p.i + dx[d], j = p.j + dy[d], k = p.k;
      if (wall[i][j]) k++;
      if (oob(i, j, k) || dist[i][j][k] != INT_MAX) continue;
      // cout << i << " " << j << " " << k << endl;
      dist[i][j][k] = dist[p.i][p.j][p.k] + 1;
      q.push({i, j, k});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  init();
  bfs();
  int ans = INT_MAX;
  for (int k = 0; k <= K; k++) {
    ans = min(ans, dist[N][M][k]);
  }
  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
