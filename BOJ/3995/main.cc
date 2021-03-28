#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const string BLOCK = "AaBbCcDdEeFfGgHhIiJjKkLlMmN";
const int dx[] = {1, 0, 0, 0, 0, -1}; // indices of opposite directions sum to 5
const int dy[] = {0, 1, 0, 0, -1, 0};
const int dz[] = {0, 0, 1, -1, 0, 0};

struct Point {
  int x, y, z;
  Point(int x, int y, int z): x(x), y(y), z(z) {}
  Point(int n) { x = n/9; n -= x*9; y = n/3; n -= y*3; z = n; }
  bool oob() { return x < 0 || x >= 3 || y < 0 || y >= 3 || z < 0 || z >= 3; }
  Point displace(int d) { return {x+dx[d], y+dy[d], z+dz[d]}; }
};

ostream& operator <<(ostream &os, const Point &p) {
  return os << "{" << p.x << ", " << p.y << ", " << p.z << "}";
}

bool snake[27]; // true if there is a turn
int cube[3][3][3];

int& cubeAt(Point p) {
  assert(!p.oob());
  return cube[p.x][p.y][p.z];
}

////////////////////////////////

void parse() {
  int puzzle[17][17];
  int dx[] = {1, 0, 0, -1}; // indices of opposite directions sum to 3
  int dy[] = {0, 1, -1, 0};

  for (int i=0; i<17; i++) fill(puzzle[i], puzzle[i]+17, -1);

  for (int i=1; i<=15; i++) {
    string s; cin >> s;
    for (int j=1; j<=15; j++) {
      if (s[j-1] == '.') continue;
      for (int k=0; k<27; k++) {
        if (s[j-1] == BLOCK[k]) puzzle[i][j] = k;
      }
    }
  }

  for (int i=1; i<=15; i++) {
    for (int j=1; j<=15; j++) {
      if (puzzle[i][j] == -1) continue;
      int prv = 0, nxt = 0;
      for (int d=0; d<4; d++) {
        if (puzzle[i+dx[d]][j+dy[d]] == puzzle[i][j] - 1) prv = d;
        if (puzzle[i+dx[d]][j+dy[d]] == puzzle[i][j] + 1) nxt = d;
      }
      snake[puzzle[i][j]] = prv + nxt != 3; // not opposite = turn
    }
  }

  snake[0] = true;
}

bool backtrack(Point p, int len, int dir) {
  // cout << p << " " << len << " " << snake[len] << endl;
  if (len == 27) return true;
  if (p.oob()) return false;
  if (cubeAt(p) != -1) return false;

  cubeAt(p) = len;

  if (snake[len]) {
    for (int d=0; d<6; d++) {
      if (d == dir || d == 5-dir) continue; // same or opposite directions
      if (backtrack(p.displace(d), len+1, d)) return true;
    }
  } else {
    if (backtrack(p.displace(dir), len+1, dir)) return true;
  }

  cubeAt(p) = -1;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i=0; i<27; i++) {
    cubeAt(Point(i)) = -1;
  }

  parse();
  // for (int i=0; i<27; i++) cout << snake[i] << " "; cout << endl;

  for (int i=0; i<27; i++) {
    if (backtrack(Point(i), 0, -1)) break;
  }

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++) {
        assert(0 <= cube[i][j][k] && cube[i][j][k] < 27);
        cout << BLOCK[cube[i][j][k]];
      }
      if (j != 2) cout << " ";
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
