#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 1e5+5;
const lld INF = 2e9;
lld N, F[_N], P[_N];
vector<lld> costs[_N];

void solve(int test) {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> F[i];
  for (int i=1; i<=N; i++) cin >> P[i];
  for (int i=0; i<=N; i++) costs[i].clear();
  
  lld ans = 0;

  for (int i=N; i>=1; i--) {
    if (costs[i].size() == 0) {
      costs[P[i]].push_back(F[i]);
      continue;
    }
    
    lld mn = INF;
    for (int j=0; j<costs[i].size(); j++) {
      ans += costs[i][j];
      mn = min(mn, costs[i][j]);
    }
    ans -= mn;

    costs[P[i]].push_back(max(mn, F[i]));
  }

  for (int j=0; j<costs[0].size(); j++) ans += costs[0][j];

  cout << "Case #" << test << ": " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
