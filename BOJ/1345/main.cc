#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
const double eps = 1e-12;
int N, A, S[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> A;
  for (int i=1; i<=N; i++) cin >> S[i];

  double l = 0, r = 1e9;
  for (int i=1; i<=N; i++) {
    l = max(l, (double)(S[i]-A) / i);
    r = min(r, (double)(S[i]-A+1) / i);
  }

  if (r-l > eps) {
    cout << fixed << setprecision(12) << l << endl;
  } else {
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
