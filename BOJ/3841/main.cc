#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, A[MN], psum[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> N;
    if (N == 0) break;

    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i];
    for (int i=N+1; i<=N*2; i++) psum[i] = psum[i-1] + A[i-N];

    vector<int> st;
    for (int i=0; i<N*2; i++) {
      while(!st.empty() && st.back() >= i-N && psum[st.back()] > psum[i]) st.pop_back();
      st.push_back(i);
    }

    int ans = 0;
    for (int i=0; i<st.size(); i++) {
      if (st[i] < N) ans++;
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
