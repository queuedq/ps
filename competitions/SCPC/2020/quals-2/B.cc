#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
lld N, M, A[MAXN];

void solve(int test) {
  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];

  set<lld> S;
  S.insert(0);
  lld psum = 0, ans = 0;
  for (int i=0; i<N; i++) {
    psum += A[i];
    S.insert(psum);
    auto it = S.lower_bound(psum-M);
    ans = max(ans, psum - *it);
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
