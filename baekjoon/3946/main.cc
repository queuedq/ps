#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
double L, R, M;
double D[2][MAXN];

void solve() {
  cin >> N >> L >> R;
  M = 1-L-R;

  D[0][0] = 1;
  D[0][1] = D[0][2] = 0;
  for (int n=1; n<=N; n++) {
    int b = n&1;
    D[b][0] = L * D[!b][1] + L * D[!b][0] + M * D[!b][0];
    for (int i=1; i<=n; i++) {
      D[b][i] = L * D[!b][i+1] + M * D[!b][i] + R * D[!b][i-1];
    }
    D[b][n+1] = D[b][n+2] = 0;
  }

  double ans = 0;
  for (int i=0; i<=N; i++) ans += i * D[N&1][i];

  cout << fixed << setprecision(4) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
