#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
int n, val[MAXN];
pii univ[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, p; cin >> p >> d;
    univ[i] = {d, p};
  }

  sort(univ, univ+n);

  for (int i = 0; i < n; i++) {
    auto [d, p] = univ[i];
    int m = 1;
    for (int j = 1; j <= d; j++) {
      if (val[j] < val[m]) m = j;
    }
    if (val[m] < p) val[m] = p;
  }

  int ans = 0;
  for (int i = 1; i < MAXN; i++) {
    ans += val[i];
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
