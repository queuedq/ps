#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, d;
vector<pii> A;
list<pii> L;
vector<int> has;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=0; i<n; i++) {
    int h, o; cin >> h >> o;
    A.push_back({h, i});
    A.push_back({o, i});
  }
  cin >> d;
  has.resize(n);

  sort(A.begin(), A.end());

  int cnt = 0, ans = 0;
  for (int i=0; i<A.size(); i++) {
    auto [x, j] = A[i];
    L.push_back(A[i]);
    if (has[j]) cnt++;
    has[j]++;

    while (!L.empty()) {
      auto [y, k] = L.front();
      if (x-y > d) {
        L.pop_front();
        if (has[k] == 2) cnt--;
        has[k]--;
      } else {
        break;
      }
    }

    ans = max(ans, cnt);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
