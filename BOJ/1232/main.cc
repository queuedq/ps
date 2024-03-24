#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int N = 100;

struct Point {
  int x, y;
  bool operator==(const Point &P) const { return tie(x, y) == tie(P.x, P.y); }
  bool operator!=(const Point &P) const { return tie(x, y) != tie(P.x, P.y); }
  bool oob() { return x < 0 || x >= N || y < 0 || y >= N; }
};
Point Q, K1, K2;

bool attack(Point A, Point B) {
  return A.x == B.x || A.y == B.y || A.x+A.y == B.x+B.y || A.x-A.y == B.x-B.y;
}

int black(int turn);
int white(int turn);

int black(int turn) {
  Point _K1 = K1, _K2 = K2;
  int mate = 0;

  for (int d=0; d<8; d++) {
    K1.x += dx[d], K1.y += dy[d];
    if (!K1.oob() && K1 != K2 && K1 != Q) mate = max(mate, white(turn+1));
    K1 = _K1;
  }
  
  for (int d=0; d<8; d++) {
    K2.x += dx[d], K2.y += dy[d];
    if (!K2.oob() && K2 != K1 && K2 != Q) mate = max(mate, white(turn+1));
    K2 = _K2;
  }

  return mate;
}

int white(int turn) {
  if (attack(Q, K1) || attack(Q, K2)) return turn; // check mate
  if (turn == 3) return 4; // always <= 4 using forking move

  Point _Q = Q;
  int mate = 4;

  for (int d=0; d<8; d++) {
    while (1) {
      Q.x += dx[d], Q.y += dy[d];
      if (Q.oob()) break;
      mate = min(mate, black(turn));
    }
    Q = _Q;
  }

  return mate;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> Q.x >> Q.y >> K1.x >> K1.y >> K2.x >> K2.y;
  cout << white(1) << endl;

  ////////////////////////////////
  return 0;
}
