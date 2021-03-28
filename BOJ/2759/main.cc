#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];

  vector<int> ans;
  for (int i=N; i>2; i--) {
    int p = find(A.begin(), A.end(), i) - A.begin() + 1;
    reverse(A.begin(), A.begin()+p);
    reverse(A.begin(), A.begin()+i);
    ans.push_back(p);
    ans.push_back(i);
  }
  if (A[0] == 2) ans.push_back(2);

  cout << ans.size() << " ";
  for (auto a: ans) cout << a << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
