#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 998'244'353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  lld N;
  cin >> N;
  vector<lld> x1(N), y1(N), x2(N), y2(N);
  for (int i=0; i<N; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  sort(all(x1)); sort(all(y1));
  sort(all(x2)); sort(all(y2));

  lld sum = 0, ans = 0;
  for (int i=0, j=0; i<N; i++) {
    while (x2[j] < x1[i]) { sum += x2[j]; j++; }
    ans += x1[i]*j - sum;
    ans %= MOD;
  }

  sum = 0;
  for (int i=0, j=0; i<N; i++) {
    while (y2[j] < y1[i]) { sum += y2[j]; j++; }
    ans += y1[i]*j - sum;
    ans %= MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
