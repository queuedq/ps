#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int B = 300;
lld N, ans;
unordered_map<int, unordered_set<int>> L;
vector<int> SL, LL; // short line, long line pos

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // collect short (size <= B) and long (size > B) lines
  // there are at most N/B long lines
  cin >> N;
  for (int i=0; i<N; i++) {
    int x, y; cin >> x >> y;
    L[x].insert(y);
  }
  for (auto [x, line]: L) {
    if (sz(line) <= B) SL.push_back(x);
    else LL.push_back(x);
  }

  // squares with a short line
  // O(N/l * l^2) = O(Nl) = O(NB)
  for (int x: SL) {
    for (int y1: L[x]) {
      for (int y2: L[x]) {
        if (y1 >= y2) continue;
        int d = y2 - y1;
        // (SL, SL) or (LL, SL)
        if (L.count(x-d) && L[x-d].count(y1) && L[x-d].count(y2)) ans++;
        // (SL, LL) only
        if (L.count(x+d) && sz(L[x+d]) > B && L[x+d].count(y1) && L[x+d].count(y2)) ans++;
      }
    }
  }

  // squares with two long lines
  // O((N/l)^2 * l) = O(N^2/l) = O(N^2/B)
  for (auto x1: LL) {
    for (auto x2: LL) {
      if (x1 >= x2) continue;
      int d = x2 - x1;
      for (auto y: L[x1]) {
        if (L[x1].count(y+d) && L[x2].count(y) && L[x2].count(y+d)) ans++;
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
