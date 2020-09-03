#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, A[MAXN];

bool solve(int x, int st, int ed) {
  if (x == 0) return true;
  if (st+1 == ed || st-2 == ed) {
    if (A[x] == st) return solve(x-1, st, 6-st-ed);
    if (A[x] == ed) return solve(x-1, 6-st-ed, ed);
    return false;
  } else {
    if (A[x] == st) return solve(x-1, st, ed);
    if (A[x] == 6-st-ed) return solve(x-1, ed, st);
    if (A[x] == ed) return solve(x-1, st, ed);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    for (int i=1; i<=N; i++) {
      char c; cin >> c;
      A[i] = c-'A'+1;
    }

    bool ans = solve(N, 1, 2);

    cout << "Case #" << t << endl;
    cout << (ans ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
