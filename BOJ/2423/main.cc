#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 505;
const int dx[] = {1, -1, 1, -1};
const int dy[] = {1, -1, -1, 1};

int N, M;
int cells[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

struct Pos {
  int x, y, d;

  bool operator >(const Pos p) const {
    if (d == p.d) return pll(x, y) > pll(p.x, p.y);
    return d > p.d;
  }
};

priority_queue<Pos, vector<Pos>, greater<Pos>> pq;

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string row; cin >> row;
    for (int j = 0; j < M; j++) {
      cells[i][j] = row[j];
    }
  }
}

void init() {
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dist[i][j] = INT_MAX;
    }
  }
}

bool oob(int i, int j) {
  if (i < 0 || i > N) return true;
  if (j < 0 || j > M) return true;
  return false;
}

bool connected(Pos p, int dir) {
  int x = min(p.x, p.x + dx[dir]), y = min(p.y, p.y + dy[dir]);
  if (dir <= 1) {
    return cells[x][y] == '\\';
  } else {
    return cells[x][y] == '/';
  }
}

void dijkstra() {
  pq.push({0, 0, 0});
  dist[0][0] = 0;

  while (!pq.empty()) {
    Pos p;
    do {
      p = pq.top(); pq.pop();
    } while (!pq.empty() && visited[p.x][p.y]);
    if (visited[p.x][p.y]) break;

    visited[p.x][p.y] = true;

    for (int dir = 0; dir < 4; dir++) {
      int x = p.x + dx[dir], y = p.y + dy[dir], d = p.d;
      if (oob(x, y)) continue;
      if (!connected(p, dir)) d++;
      // cout << x << " " << y << endl;
      dist[x][y] = min(dist[x][y], d);
      pq.push({x, y, dist[x][y]});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  if ((N + M) % 2 != 0) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  init();
  dijkstra();

  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j <= M; j++) {
  //     if (dist[i][j] == INT_MAX) { cout << "  "; }
  //     else { cout << dist[i][j] << " "; }
  //   }
  //   cout << endl;
  // }

  cout << dist[N][M] << endl;

  ////////////////////////////////
  return 0;
}
