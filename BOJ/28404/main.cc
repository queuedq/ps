#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MX = 100;
lld F[MX];

lld fibo(lld x) {
  if (x > MX) return INF+1;
  return F[x];
}

lld inv(lld x) { // F[i] <= x count
  lld cnt = 0;
  for (int i=1; i<MX; i++) cnt += F[i] <= x;
  return cnt;
}

lld a(lld n) {
  if (n <= 3) return n;

  lld c = inv(n), dep = 0;
  while (F[c] == n) n = c, c = inv(n), dep++;

  if ((n - c) % 2 == 1) {
    do { n++; } while (F[inv(n)] == n);
    while (dep--) n = fibo(n);
  } else {
    do { n--; } while (F[inv(n)] == n);
    dep++;
    while (dep--) n = fibo(n);
  }
  
  return n;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  F[1] = 1, F[2] = 2;
  for (int i=3; i<MX; i++) F[i] = min(F[i-1] + F[i-2], INF+1);
  
  int T; cin >> T;
  while (T--) {
    lld n; cin >> n;
    lld ans = a(n);
    if (ans > INF) cout << -1 << endl;
    else cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
