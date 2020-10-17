#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, A[MAXN], H[MAXN];
vector<pii> ans;

bool solve() {
  int row = N;
  int last = 0;
  stack<int> st;
  for (int i=1; i<=N; i++) {
    if (A[i] == 2) {
      H[i] = row--;
      st.push(i);
      ans.push_back({H[i], i});
      last = i;
    }
    if (A[i] == 1) {
      if (st.empty()) {
        H[i] = row--;
        ans.push_back({H[i], i});
        last = i;
      } else {
        H[i] = H[st.top()];
        ans.push_back({H[i], i});
        st.pop();
      }
    }
  }

  if (!st.empty()) return false;

  for (int i=N; i>=1; i--) {
    if (A[i] == 3) {
      if (last < i) return false;
      H[i] = row--;
      ans.push_back({H[i], i});
      ans.push_back({H[i], last});
      last = i;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  if (solve()) {
    cout << ans.size() << endl;
    for (auto [x, y]: ans) {
      cout << x << " " << y << endl;
    }
  } else {
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
