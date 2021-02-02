#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1'000'005;
int n, m, p[MN], h[MN], hs[MN], fail[MN];

void update(vector<int> &bit, int i, int x) {
  for (; i < bit.size(); i += i&-i) bit[i] += x;
}

int count(vector<int> &bit, int i) {
  int cnt = 0;
  for (; i > 0; i -= i&-i) cnt += bit[i];
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=0; i<n; i++) { int s; cin >> s; p[s-1] = i+1; }
  for (int i=0; i<m; i++) { cin >> h[i]; hs[i] = h[i]; }

  sort(hs, hs+m);
  for (int i=0; i<m; i++) { h[i] = lower_bound(hs, hs+m, h[i]) - hs + 1; }

  vector<int> L(n+1), R(n+1);

  for (int i=1, j=0; i<n; i++) {
    while (j > 0) {
      int x = count(L, p[j]);
      int y = count(R, p[i]);
      if (x == y) break;

      int f = fail[j-1];
      for (; j > f; j--) {
        update(L, p[j-1], -1);
        update(R, p[i-j], -1);
      }
    }

    update(L, p[j], 1);
    update(R, p[i], 1);
    fail[i] = ++j;
  }

  L.assign(n+1, 0);
  R.assign(m+1, 0);
  vector<int> ans;

  for (int i=0, j=0; i<m; i++) {
    while (j > 0) {
      if (j < n) { // fail otherwise
        int x = count(L, p[j]);
        int y = count(R, h[i]);
        if (x == y) break;
      }

      int f = fail[j-1];
      for (; j > f; j--) {
        update(L, p[j-1], -1);
        update(R, h[i-j], -1);
      }
    }
    
    update(L, p[j], 1);
    update(R, h[i], 1);
    j++;

    if (j == n) ans.push_back(i-n+2);
  }

  cout << ans.size() << endl;
  for (auto a: ans) cout << a << " ";

  ////////////////////////////////
  return 0;
}
