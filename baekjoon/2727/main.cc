#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
vector<pii> ans;

void solve(int N) {
  if (N == 0) return;

  int m3 = 0;
  while (N % 3 == 0) { N /= 3; m3++; }

  int m2 = 30;
  while ((1 << m2) > N) m2--;
  if ((N - (1 << m2)) % 3 != 0) m2--;

  ans.push_back({m2, m3});
  solve(N - (1 << m2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    ans.clear();
    solve(N);

    cout << ans.size() << endl;
    int m3 = 0;
    for (int i=0; i<ans.size(); i++) {
      m3 += ans[i].second;
      cout << ans[i].first << " " << m3 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
