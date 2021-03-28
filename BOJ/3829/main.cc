#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXH = 55;

int H, W;
char puzzle[MAXH][MAXH];
bool maze[MAXH][MAXH];

enum Dir { U, L, R, D };
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
Dir opposite(Dir d) { return Dir(3-d); }

struct Pos {
  int x, y;

  Pos(): x(-1), y(-1) {}
  Pos(int x, int y): x(x), y(y) {}
  bool operator ==(Pos p) { return pii(x, y) == pii(p.x, p.y); }
  bool oob() { return x < 0 || x >= W || y < 0 || y >= H; }
  Pos move(Dir d) { return Pos(x+dx[d], y+dy[d]); }
  Pos move(vector<Dir> dirs) {
    Pos p(x, y);
    for (auto d: dirs) p = p.move(d);
    return p;
  }

  int dist(Pos dest) {
    if (dest.oob()) return -1;

    int vst[MAXH][MAXH];
    for (int y=0; y<H; y++) fill(vst[y], vst[y]+W, -1);

    queue<Pos> q;
    q.push(*this);
    vst[y][x] = 0;

    while (!q.empty()) {
      Pos u = q.front(); q.pop();
      if (u == dest) return vst[u.y][u.x];
      for (int d = 0; d < 4; d++) {
        Pos v = u.move(Dir(d));
        if (v.oob() || maze[v.y][v.x] || vst[v.y][v.x] != -1) continue;
        q.push(v);
        vst[v.y][v.x] = vst[u.y][u.x] + 1;
      }
    }
    return -1;
  }
};

ostream& operator <<(ostream &os, Pos p) { return os << "{" << p.x << ", " << p.y << "}"; }

int matching(vector<Pos> s, vector<Pos> e) {
  if (s[0].oob() || s[1].oob() || e[0].oob() || e[1].oob()) return -1;
  int dist = 1e9, d[2][2];
  for (int i=0; i<2; i++) for (int j=0; j<2; j++) d[i][j] = s[i].dist(e[j]);
  if (d[0][0] != -1 && d[1][1] != -1) dist = min(dist, d[0][0]+d[1][1]);
  if (d[0][1] != -1 && d[1][0] != -1) dist = min(dist, d[0][1]+d[1][0]);
  return dist == 1e9 ? -1 : dist;
}

struct King {
  Pos pos; Dir empty;

  King(): pos({-1, -1}), empty(U) {}
  King(Pos pos, Dir empty): pos(pos), empty(empty) {}

  vector<Pos> cells() { return {pos, pos.move(R), pos.move(D), pos.move({D, R}) }; }
  vector<Pos> adjCells(Dir d) {
    switch (d) {
      case U: return { pos.move(U), pos.move({U, R}) };
      case L: return { pos.move(L), pos.move({L, D}) };
      case D: return { pos.move({D, D}), pos.move({D, D, R}) };
      case R: return { pos.move({R, R}), pos.move({R, R, D}) };
    }
  }

  pair<int, King> move(Dir d) {
    auto kingCells = cells();

    for (auto c: kingCells) maze[c.y][c.x] = true;
    int dist = matching(adjCells(empty), adjCells(d));
    for (auto c: kingCells) maze[c.y][c.x] = false;

    if (dist == -1) return {-1, *this};
    return {dist + 1, King(pos.move(d), opposite(d))};
  }
};

ostream& operator <<(ostream &os, King king) { return os << "(" << king.pos << ", " << king.empty << ")"; }

int calc() {
  // Input
  vector<Pos> initEmpty;
  King initKing;

  for (int y=0; y<H; y++) {
    cin >> puzzle[y];
    for (int x=0; x<W; x++) {
      maze[y][x] = puzzle[y][x] == '*';
      if (puzzle[y][x] == '.') initEmpty.push_back({x, y});
      if (puzzle[y][x] == 'X') initKing = King({x-1, y-1}, U); // last found: bottom right
    }
  }

  if (initKing.pos == Pos(0, 0)) return 0;

  // Initialize king pos
  vector<pair<int, King>> start;

  auto kingCells = initKing.cells();
  for (auto c: kingCells) maze[c.y][c.x] = true;
  for (Dir dir = Dir(0); dir < Dir(4); dir = Dir(dir+1)) {
    int dist = matching(initEmpty, initKing.adjCells(dir));
    if (dist != -1) {
      start.push_back({dist + 1, King(initKing.pos.move(dir), opposite(dir))});
    }
  }
  for (auto c: kingCells) maze[c.y][c.x] = false;

  // Dijkstra
  int ans = 1e9;

  for (auto [initCost, king]: start) {
    int dist[MAXH][MAXH][4];
    for (int y=0; y<H; y++) for (int x=0; x<W; x++) fill(dist[y][x], dist[y][x]+4, 1e9);

    auto cmp = [](pair<int, King> a, pair<int, King> b) { return a.first > b.first; };
    priority_queue<pair<int, King>, vector<pair<int, King>>, decltype(cmp)> pq(cmp);
    pq.push({initCost, king});

    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();

      if (u.pos == Pos(0, 0)) {
        ans = min(ans, d);
        break;
      }
      if (d >= dist[u.pos.y][u.pos.x][u.empty]) continue;
      dist[u.pos.y][u.pos.x][u.empty] = d;

      for (Dir dir = Dir(0); dir < Dir(4); dir = Dir(dir+1)) {
        auto [w, v] = u.move(dir);
        if (w == -1) continue;
        pq.push({d+w, v});
      }
    }
  }

  return ans == 1e9 ? -1 : ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> H >> W;
    if (H == 0) break;
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
