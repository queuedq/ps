#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500;
const int INF = 100;
int N, A, B, U[MN], cnt[MN];

bool ok(int n) {
  fill(cnt, cnt+MN, 0);
  cnt[n] = 1;
  for (int i=n; i>=1; i--) {
    cnt[i] = min(cnt[i], INF);
    if (cnt[i] < U[i]) return false;
    if (i > A) cnt[i-A] += cnt[i] - U[i];
    if (i > B) cnt[i-B] += cnt[i] - U[i];
  }
  return true;
}

int solve() {
  fill(U, U+MN, 0);
  cin >> N >> A >> B;
  for (int i=1; i<=N; i++) cin >> U[i];

  for (int i=N; i<MN; i++) {
    if (ok(i)) return i;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    int ans = solve();
    cout << "Case #" << t << ": ";
    if (ans != -1) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
  }

  ////////////////////////////////
  return 0;
}
