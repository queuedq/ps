#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, d[MN], g[MN], ans;

struct SlopeTrick {
  priority_queue<lld> L;
  priority_queue<lld, vector<lld>, greater<lld>> R;
  lld x, y, ls, rs; // reference point (x, y), slope addends

  void conv(lld s) {
    if (R.empty() || s < R.top() + rs) {
      L.push(s - ls);
      x++, y += s;
    } else {
      R.push(s - rs);
    }
  }
  
  void balance() {
    while (L.size() > R.size() + 1) {
      lld s = L.top() + ls; L.pop();
      R.push(s - rs);
      x--, y -= s;
    }
    while (L.size() < R.size()) {
      lld s = R.top() + rs; R.pop();
      L.push(s - ls);
      x++, y += s;
    }
  }
};

SlopeTrick D;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N-1; i++) cin >> d[i];
  for (int i=0; i<N; i++) { cin >> g[i]; ans += g[i]; }

  D.conv(g[0]);
  D.conv(g[0]);
  D.balance();

  for (int i=1; i<N; i++) {
    D.ls -= d[i-1];
    D.rs += d[i-1];
    D.conv(g[i]);
    D.conv(g[i]);
    D.balance();
  }

  cout << D.y << endl;

  ////////////////////////////////
  return 0;
}
