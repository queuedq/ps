#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int _N = 1e5+5;
int N, S[_N];

void solve(int test) {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> S[i];
  sort(S+1, S+N+1);

  int mn = N;
  for (int i=1; i<=N; i++) {
    mn = min(mn, S[i] + (N-i));
  }

  cout << "Case #" << test << ": " << mn << endl;
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
