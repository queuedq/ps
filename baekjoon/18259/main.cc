#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
const int ML = 1005; 
int N, p[MN], q[MN], inv[MN];
vector<pii> bar[ML];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N-1; i++) {
    for (int j=1;; j++) {
      int d; cin >> d;
      if (d == 0) break;
      bar[d].push_back({i, j});
    }
  }

  for (int i=1; i<=N; i++) p[i] = q[i] = inv[i] = i;
  for (int d=1; d<=1000; d++) {
    for (auto [i, j]: bar[d]) {
      swap(p[i], p[i+1]);
      swap(inv[p[i]], inv[p[i+1]]);
    }
  }

  vector<pii> ans;
  for (int d=1; d<ML; d++) {
    for (auto [i, j]: bar[d]) {
      if (inv[q[i]] > inv[q[i+1]]) {
        ans.push_back({i, j});
        swap(q[i], q[i+1]);
      }
    }
  }

  for (int i=1; i<=N; i++) assert(p[i] == q[i]);

  cout << ans.size() << endl;
  for (auto [i, j]: ans) cout << i << " " << j << endl;

  ////////////////////////////////
  return 0;
}
