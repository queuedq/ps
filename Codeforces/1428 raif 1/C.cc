#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

void solve() {
  string S; cin >> S;
  stack<char> st;

  for (int i=0; i<S.size(); i++) {
    if (!st.empty() && S[i] == 'B') {
      st.pop();
    } else {
      st.push(S[i]);
    }
  }

  cout << st.size() << endl;
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
