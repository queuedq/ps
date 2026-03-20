#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
lld N, M;
vector<pll> A;

lld ceil(lld x, lld y) { return x/y + (x%y > 0); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;
  A.resize(N);
  for (int i=0, a; i<N; i++) { cin >> a; A[i].second = a-1; }
  for (int i=0, b; i<N; i++) { cin >> b; A[i].first = b-1; }
  sort(all(A));

  // check same b
  for (int i=0; i<N-1; i++) {
    if (A[i].first == A[i+1].first) { cout << -1 << endl; return 0; }
  }

  // check full
  if (N == M) {
    for (int i=0; i<N; i++) {
      if (A[i].first != A[i].second) { cout << -1 << endl; return 0; }
    }
    cout << 0 << endl; return 0;
  }

  for (auto init: {A[0].second, A[0].second + M}) {
    lld last = init, ans = 0;
    for (auto [s, e]: A) {
      lld k = ceil(max(s, last) - e, M);
      lld goal = e + k*M;
      ans += goal - s;
      last = max(last, goal);
    }
    if (last - init < M) { cout << ans << endl; return 0; }
  }
  
  cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
