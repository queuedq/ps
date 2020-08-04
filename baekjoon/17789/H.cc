#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int p, v; cin >> p >> v;

  vector<pair<pii, int>> A;
  for (int i=0; i<p; i++) {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    A.push_back({{a, b}, i+1});
  }

  sort(A.begin(), A.end());

  vector<pii> B;
  for (int i=0; i<v; i++) {
    int c; cin >> c;
    B.push_back({c, i+1});
  }

  sort(B.begin(), B.end());

  vector<pii> ans;
  int i = 0;
  for (int j=0; j<v; i++, j++) {
    while (i < p && B[j].first != A[i].first.first && B[j].first != A[i].first.second) i++;
    if (i == p) break;

    ans.push_back({B[j].second, A[i].second});
  }

  if (ans.size() < v) {
    cout << "impossible" << endl;
  } else {
    sort(ans.begin(), ans.end());
    for (int i=0; i<v; i++) {
      cout << ans[i].second << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
