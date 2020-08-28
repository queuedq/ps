#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXK = 30005;
bool prime[MAXK];

int rmv(int p, int x) {
  return p / (10*x) * x + p % x;
}

int score(int p) {
  if (!prime[p]) return 0;
  int ret = 0;
  for (int x = 1; x <= p; x *= 10) {
    ret = max(ret, score(rmv(p, x)));
  }
  return ret + 1;
}

int solve() {
  int a, b; cin >> a >> b;
  int sa = score(a);
  int sb = score(b);
  if (sa > sb) return 1;
  if (sa < sb) return 2;
  return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime, prime+MAXK, true);
  prime[0] = prime[1] = false;
  for (int i=2; i<=30000; i++) {
    if (!prime[i]) continue;
    for (int j=i*2; j<=30000; j+=i) prime[j] = false;
  }

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << endl;
    cout << solve() << endl;
  }

  ////////////////////////////////
  return 0;
}
