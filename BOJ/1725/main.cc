#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
lld N, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];

  lld ans = 0;
  stack<int> S;
  S.push(0);
  for (int i=1; i<=N; i++) {
    while (A[S.top()] > A[i]) {
      lld h = A[S.top()];
      S.pop();
      lld l = S.top();
      ans = max(ans, h * (i-l-1));
    }
    S.push(i);
  }

  while (S.size() > 1) {
    lld h = A[S.top()];
    S.pop();
    lld l = S.top();
    ans = max(ans, h * (N-l));
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
