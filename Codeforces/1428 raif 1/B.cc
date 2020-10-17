#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

int solve() {
  int N; string S; cin >> N >> S;

  int lcnt = 0, rcnt = 0;
  for (int i=0; i<N; i++) {
    if (S[i] == '<') lcnt++;
    if (S[i] == '>') rcnt++;
  }

  if (lcnt == 0 || rcnt == 0) return N;

  int ans = 0;
  for (int i=0; i<N-1; i++) {
    if (S[i] == '-' || S[i+1] == '-') ans++;
  }
  ans += S[0] == '-' || S[N-1] == '-';
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cout << solve() << endl;
  }

  ////////////////////////////////
  return 0;
}
