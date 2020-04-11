#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, m;
struct Point { int x, y; };

Point getPos(int n, int m) {
  if (n == 1) return {0, 0};

  Point p = getPos(n/2, m % (n*n/4));

  if (m < n*n / 4) {
    return {p.y, p.x};
  } else if (m < n*n / 2) {
    return {p.x, p.y + n/2};
  } else if (m < n*n / 4 * 3) {
    return {p.x + n/2, p.y + n/2};
  } else {
    return {n - p.y - 1, n/2 - p.x - 1};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  Point p = getPos(n, m-1);
  cout << p.x + 1 << " " << p.y + 1 << endl;

  ////////////////////////////////
  return 0;
}
