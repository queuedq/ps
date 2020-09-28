#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3e5+5;
int N, A[MAXN], last[MAXN], seg[MAXN], ans[MAXN];

void solve() {
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  fill(last+1, last+N+1, 0);
  fill(seg+1, seg+N+1, 0);

  for (int i=1; i<=N; i++) {
    seg[A[i]] = max(seg[A[i]], i - last[A[i]]);
    last[A[i]] = i;
  }
  for (int i=1; i<=N; i++) {
    seg[i] = max(seg[i], N+1 - last[i]);
  }

  int j = 1;
  for (int i=N; i>=1; i--) {
    while (j <= N && i < seg[j]) j++;
    ans[i] = j <= N ? j : -1;
  }

  for (int i=1; i<=N; i++) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
