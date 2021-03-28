#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e5 + 5;
int N, K;
string directions;

set<pii> D1, D2;
pii frog;

void input() {
  cin >> N >> K;
  cin >> directions;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    D1.insert({x - y, x});
    D2.insert({x + y, x});
    if (i == 0) frog = {x, y};
  }
}

void simulate() {
  for (char dir: directions) {
    int x = frog.first, y = frog.second;
    // cout << x << ", " << y << endl;

    if (dir == 'A') {
      auto pos = next(D1.find({x - y, x}));
      if (pos == D1.end() || pos->first != x - y) continue;

      D1.erase({x - y, x});
      D2.erase({x + y, x});
      frog = {pos->second, pos->second - pos->first};
    } else if (dir == 'D') {
      auto pos = prev(D1.find({x - y, x}));
      if (pos == prev(D1.begin()) || pos->first != x - y) continue;

      D1.erase({x - y, x});
      D2.erase({x + y, x});
      frog = {pos->second, pos->second - pos->first};
    } else if (dir == 'B') {
      auto pos = next(D2.find({x + y, x}));
      if (pos == D2.end() || pos->first != x + y) continue;

      D1.erase({x - y, x});
      D2.erase({x + y, x});
      frog = {pos->second, pos->first - pos->second};
    } else if (dir == 'C') {
      auto pos = prev(D2.find({x + y, x}));
      if (pos == prev(D1.begin()) || pos->first != x + y) continue;

      D1.erase({x - y, x});
      D2.erase({x + y, x});
      frog = {pos->second, pos->first - pos->second};
    }
  }
  cout << frog.first << " " << frog.second << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  simulate();

  ////////////////////////////////
  return 0;
}
