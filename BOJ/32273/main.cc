#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct Point {
  lld x, y;
  Point operator+(Point Q) { return {x+Q.x, y+Q.y}; }
  Point operator+=(Point Q) { return *this = *this + Q; }
};

Point solve() {
  lld K, A, B, C, D; cin >> K >> A >> B >> C >> D;
  if ((A+B+C+D)*3+1 != 1LL<<(K*2)) return {-1, -1};
  if (abs((A+D)-(B+C)) != 1) return {-1, -1}; // A+D = B+C excluding the last piece

  // start from 4 empty cells at the center
  Point P = {1<<(K-1), 1<<(K-1)};
  lld X = A-D, Y = B-C;

  // recursive jump along diagonals
  lld t = (K-2 >= 0) ? 1<<(K-2) : 0;
  for (; t>0; t/=2) {
    if (abs(X) > abs(Y)) {
      if (X > 0) X -= t*2, P += {t, t};
      else X += t*2, P += {-t, -t};
    } else {
      if (Y > 0) Y -= t*2, P += {t, -t};
      else Y += t*2, P += {-t, t};
    }
  }

  // place last piece
  if (X > 0) X -= 1;
  else if (X < 0) X += 1, P += {-1, -1};
  else if (Y > 0) Y -= 1, P += {0, -1};
  else if (Y < 0) Y += 1, P += {-1, 0};
  else assert(0); // X+Y must be odd (= parity of number of all pieces)

  if (X != 0 || Y != 0) return {-1, -1};
  return P;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    auto [x, y] = solve();
    cout << x << " " << y << endl;
  }

  ////////////////////////////////
  return 0;
}
