#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 20005;
vector<int> w[MN];

void solve(int test) {
  int n, m; cin >> n >> m;
  lld sum = 0, sum2 = 0;
  vector<int> ends[2];

  for (int i=0; i<n; i++) {
    int l; cin >> l;

    w[i].resize(l);
    for (int j=0; j<l; j++) cin >> w[i][j];
    sort(w[i].begin(), w[i].end());
    
    if (l%2 == 0) {
      sum += w[i][0] + w[i][1] + w[i][2] + w[i][3];
      sum2 += w[i][0] * 2 + w[i][1] * 2 + w[i][2] + w[i][3];
      ends[0].push_back(w[i][2] + w[i][3]);
    } else {
      sum += w[i][0] * 2 + w[i][1] + w[i][2] + w[i][3];
      sum2 += w[i][0] * 2 + w[i][1] + w[i][2] + w[i][3];
      ends[1].push_back(w[i][2] + w[i][3]);
    }
  }
  sort(ends[0].rbegin(), ends[0].rend());
  sort(ends[1].rbegin(), ends[1].rend());

  cout << "Case #" << test << endl;
  if (ends[1].empty()) { // tc 1
    cout << sum - ends[0][0] - ends[0][1] << endl;
  } else if (ends[0].empty()) { // tc 2
    cout << sum - ends[1][0] - ends[1][1] << endl;
  } else {
    lld ans = LLONG_MAX;
    if (ends[0].size() >= 2) ans = min(ans, sum - ends[0][0] - ends[0][1]);
    ans = min(ans, sum - ends[0][0] - ends[1][0]);
    if (ends[1].size() >= 4) ans = min(ans, sum - ends[1][0] - ends[1][1]);
    ans = min(ans, sum2 - ends[1][0] - ends[1][1]); // even-sized groups are shifted

    cout << ans << endl;
  }
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
