#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, M, R, c[MN], r[MN], rent[MN], sell[MN];

struct Store {
  lld q, p;
  bool operator <(const Store &S) const { return p < S.p; }
};
Store S[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> R;
  for (int i=1; i<=N; i++) cin >> c[i];
  for (int i=1; i<=M; i++) { cin >> S[i].q >> S[i].p; }
  for (int i=1; i<=R; i++) cin >> r[i];

  sort(c+1, c+N+1);
  sort(S+1, S+M+1); reverse(S+1, S+M+1);
  sort(r+1, r+R+1); reverse(r+1, r+R+1);

  for (int i=1; i<=min(N, R); i++) rent[i] = rent[i-1] + r[i];
  
  int k = 1;
  for (int i=N; i>=1; i--) {
    sell[i] = sell[i+1];

    while (k <= M && S[k].q <= c[i]) {
      sell[i] += S[k].q * S[k].p;
      c[i] -= S[k].q;
      k++;
    }
    if (k <= M) {
      sell[i] += c[i] * S[k].p;
      S[k].q -= c[i];
    }
  }

  lld ans = 0;
  for (int i=1; i<=N+1; i++) ans = max(ans, rent[i-1] + sell[i]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
