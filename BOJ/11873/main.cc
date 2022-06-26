#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
// B+=B is equiv to A/=2
string op[4] = {"B+=B", "A+=A", "A+=B", "B+=A"};
lld A, B;
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> A >> B;
  while (A%2 == 0 && B%2 == 0) {
    A /= 2;
    B /= 2;
  }
  while (A%2 == 0) { A /= 2; ans.push_back(0); }
  while (B%2 == 0) { B /= 2; ans.push_back(1); }

  while (A != B) {
    while (A > B) {
      A += B; ans.push_back(2);
      while (A % 2 == 0) { A /= 2; ans.push_back(0); }
    }
    while (A < B) {
      B += A; ans.push_back(3);
      while (B % 2 == 0) { B /= 2; ans.push_back(1); }
    }
  }

  cout << ans.size() << endl;
  for (auto i: ans) cout << op[i] << endl;

  ////////////////////////////////
  return 0;
}
