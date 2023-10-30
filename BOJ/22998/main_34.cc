#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int T, K;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> T;
  while (T--) {
    cin >> K;
    vector<int> A; // up (1), down (0)
    int lo = 0;

    while (K) {
      if (K%2 == 1) {
        A.push_back(1);
        K /= 2;
      } else {
        A.push_back(0);
        K--, lo++;
      }
    }
    reverse(all(A));

    vector<int> ans;
    int hi = lo+1;
    for (auto a: A) {
      if (a) ans.push_back(hi++);
      else ans.push_back(lo--);
    }

    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
