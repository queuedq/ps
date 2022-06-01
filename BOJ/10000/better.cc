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

  int N; cin >> N;
  vector<pii> A;
  for (int i=0; i<N; i++) {
    int x, r; cin >> x >> r;
    A.push_back({x-r, 1});
    A.push_back({x+r, 0});
  }
  sort(A.begin(), A.end());

  stack<int> S, T; // S: left, T: inner_sum
  T.push(0);
  int ans = N+1;
  for (int i=0; i<N*2; i++) {
    auto [x, b] = A[i];
    if (b) {
      S.push(x);
      T.push(0);
    } else {
      int left = S.top(); S.pop();
      int inner_sum = T.top(); T.pop();
      if (x - left == inner_sum) ans++;
      int sum = T.top(); T.pop();
      T.push(sum + (x - left));
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
