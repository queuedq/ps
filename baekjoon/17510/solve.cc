#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

////////////////////////////////////////////////////////////////
const int MAX_N = 105;
int N, M;

struct Level {
  char level[MAX_N][MAX_N];

  char at(int x, int y) {
    return level[x][y];
  }
} level;

class Point {
public:
  int x, y;
  static const Point boxArea[4];

  bool oob() {
    return x < 0 || x >= N || y < 0 || y >= M;
  }

  Point move(int dir) {
    return {x + dx[dir], y + dy[dir]};
  }

  bool operator ==(const Point p) const { return x == p.x && y == p.y; }
  bool operator <(const Point p) const { return x == p.x ? y < p.y : x < p.x; }
  Point operator +(const Point p) const { return {x + p.x, y + p.y}; }
  Point operator -(const Point p) const { return {x - p.x, y - p.y}; }

  bool isInBox(Point box) {
    return find(boxArea, boxArea + 4, *this - box) - boxArea < 4;
  }

  bool isOnFloor(bool isPlayer) {
    if (isPlayer) {
      Point player = *this;
      if (oob()) return false;
      return level.at(player.x, player.y) != '#';
    } else {
      Point box = *this;
      bool ret = true;
      for (int i = 0; i < 4; i++) {
        Point p = box + boxArea[i];
        if (p.oob()) return false;
        ret = ret && (level.at(p.x, p.y) != '#');
      }
      return ret;
    }
  }
};

const Point Point::boxArea[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
ostream& operator <<(ostream& os, Point p) {
  return os << "{" << p.x << "," << p.y << "}";
}

Point storage = {INT_MAX, INT_MAX};

struct State {
  Point player, box;
  bool valid = true;

  State move(int dir) {
    State s = *this;
    Point newPlayer = s.player.move(dir);
    if (!newPlayer.isOnFloor(true)) { return {{-2, -2}, {-2, -2}, false}; }
    if (newPlayer.isInBox(s.box)) {
      Point newBox = s.box.move(dir);
      if (!newBox.isOnFloor(false)) { return {{-2, -2}, {-2, -2}, false}; }
      return { newPlayer, newBox };
    }
    return { newPlayer, s.box };
  }

  bool isDone() {
    return box == storage;
  }

  bool operator <(const State s) const {
    return player == s.player ? box < s.box : player < s.player;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  State init = {{-1, -1}, {INT_MAX, INT_MAX}};
  for (int i = 0; i < N; i++) {
    cin >> level.level[i];
    for (int j = 0; j < M; j++) {
      if (level.at(i, j) == 'P') {
        init.player = {i, j};
      }
      if (level.at(i, j) == 'B') {
        init.box.x = min(init.box.x, i);
        init.box.y = min(init.box.y, j);
      }
      if (level.at(i, j) == 'S') {
        storage.x = min(storage.x, i);
        storage.y = min(storage.y, j);
      }
    }
  }

  // cout << init.player << " " << init.box << " " << storage << endl;

  queue<pair<State, int>> states;
  map<State, bool> visited;
  states.push({init, 0});
  visited[init] = true;
  while (!states.empty()) {
    State s; int depth;
    tie(s, depth) = states.front(); states.pop();

    if (s.isDone()) {
      cout << depth << endl;
      return 0;
    }

    for (int dir = 0; dir < 4; dir++) {
      State newState = s.move(dir);
      if (!visited[newState] && newState.valid) {
        visited[newState] = true;
        states.push({newState, depth + 1});
      }
    }
  }

  ////////////////////////////////
  return 0;
}
