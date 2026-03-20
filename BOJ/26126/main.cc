#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, K;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    int r; cin >> r;
    A[r].first = i;
  }
  for (int i=1; i<=N; i++) {
    int r; cin >> r;
    A[r].second = i;
  }
  sort(A+1, A+N+1);

  int mx = 0, s = 0, ans = 0;
  for (int i=1; i<=N; i++) {
    mx = max(mx, A[i].second);
    s++;
    if (mx == i && s >= K) {
      s = 0;
      ans++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
