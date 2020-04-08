#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;
string S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> S;

  stack<char> st;
  int cnt = K;
  for (int i=0; i<N; i++) {
    while (st.size() > 0 && cnt > 0 && st.top() < S[i]) {
      st.pop();
      cnt--;
    }
    st.push(S[i]);
  }

  vector<char> ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }

  for (int i=0; i<N-K; i++) cout << ans[ans.size()-i-1];
  cout << endl;

  ////////////////////////////////
  return 0;
}
