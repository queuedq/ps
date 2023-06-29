#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int di[4] = {-1, 0, 0, 1};
const int dj[4] = {0, -1, 1, 0};
int Q = 50;

bool query(int i, int j) {
  if (i < 0 || i >= 10 || j < 0 || j >= 10) return 0;
  Q--;
  cout << "? " << i << " " << j << endl;
  bool res; cin >> res;
  return res;
}

void ans(int i0, int j0, int i1, int j1) {
  cout << "! " << i0 << " " << j0 << " " << i1 << " " << j1 << endl;
}

int main() {
  int i, j, found = 0;

  for (i=0; i<10; i++) {
    for (j=0; j<10; j++) {
       // corner case
      if (i == 0 && j == 0) continue;
      if (i == 9 && j == 9) continue;

      if ((i+j)%2 == 0) found = query(i, j);
      if (found) break;
    }
    if (found) break;
  }

  if (!found) { // corner case
    if (query(0, 0)) { // top left
      if (query(0, 1)) ans(0, 0, 0, 1);
      else ans(0, 0, 1, 0);
    } else { // bottom right
      if (query(9, 8)) ans(9, 9, 9, 8);
      else ans(9, 9, 8, 9);
    }
  } else {
    // examine 3 adjacent cells (or 2 if (i, j) at wall)
    int d, r = min(Q, 3);
    for (d=0; d<r; d++) {
      if (query(i+di[d], j+dj[d])) break;
    }
    ans(i, j, i+di[d], j+dj[d]);
  }

  return 0;
}
