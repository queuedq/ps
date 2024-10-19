#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;

struct Point {
  int x, y;
  bool operator<(const Point &P) const { return x < P.x; }
};

bool inter(Point A, Point B) { return (A.x < B.x) != (A.y < B.y); }

int N;
Point P[MN];
vector<Point> X, Y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y;
  sort(P, P+N);

  X.push_back(P[0]);
  for (int i=1; i<N; i++) {
    if (X.back().y < P[i].y) X.push_back(P[i]);
    else Y.push_back(P[i]);
  }

  int mx = 0;

  int i = 0, j = 0;
  while (i < sz(X)) {
    while (j < sz(Y) && Y[j].x < X[i].x) j++;
    if (j == sz(Y) || !inter(X[i], Y[j])) { i++; continue; }

    // make chain
    int a, b, cnt; // (a, b): last intersection / cnt: number of inter points

    for (int flag: {1, 0}) {
      // flag = 1: chain X - Y - ...
      // flag = 0: chain Y - X - ...
      a = i, b = j, cnt = 1;

      while (1) {
        if (flag) { // ... - X - Y
          if (a+1 < sz(X) && inter(X[a+1], Y[b])) a++, flag ^= 1, cnt++; // Y - X
          else if (b+1 < sz(Y) && inter(X[a], Y[b+1])) b++; // alter last Y
          else break;
        } else { // ... - Y - X
          if (b+1 < sz(Y) && inter(X[a], Y[b+1])) b++, flag ^= 1, cnt++; // X - Y
          else if (a+1 < sz(X) && inter(X[a+1], Y[b])) a++; // alter last X
          else break;
        }
      }

      mx = max(mx, cnt);
    }

    i = a+1;
  }

  cout << mx + 1 << endl;

  ////////////////////////////////
  return 0;
}
