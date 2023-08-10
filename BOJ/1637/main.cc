#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 20202;
lld N, X[MN], Y[MN], Z[MN];

lld count(lld m) {
  lld sum = 0;
  for (int i=0; i<N; i++) {
    if (m < X[i]) continue;
    lld cnt = (min(m, Y[i]) - X[i]) / Z[i] + 1;
    sum += cnt;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> X[i] >> Y[i] >> Z[i];

  lld l = 0, r = INT_MAX;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (count(m) % 2 == 1) r = m;
    else l = m;
  }

  lld cl = count(l), cr = count(r);
  if (cr % 2 == 0) cout << "NOTHING" << endl;
  else cout << r << " " << (cr - cl) << endl;

  ////////////////////////////////
  return 0;
}
