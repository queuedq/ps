#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998244353;
const int MAXN = 2e5+5;
int N, M;
lld d[MAXN], psum[MAXN];

pll egcd(lld a, lld b) {
  lld ax = 1, ay = 0, bx = 0, by = 1;
  while (b > 0) {
    lld q = a / b;
    a -= b * q; ax -= bx * q; ay -= by * q;
    swap(a, b); swap(ax, bx); swap(ay, by);
  }
  return {ax, ay};
}

lld invmod(lld a, lld m) {
  return (egcd(a, m).first + m) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> d[i];
  sort(d+1, d+N+1);
  for (int i=1; i<=N; i++) psum[i] = psum[i-1]+d[i];

  for (int i=0; i<M; i++) {
    lld a, b; cin >> a >> b;
    int p = lower_bound(d+1, d+N+1, b) - d;
    lld cnt = N-p+1;

    if (cnt < a) {
      cout << 0 << endl;
      continue;
    }

    lld strong = (psum[N] - psum[p-1]) % MOD;
    strong = strong*(cnt-a) % MOD;
    strong = strong*invmod(cnt, MOD) % MOD;

    lld weak = psum[p-1] % MOD;
    weak = weak*(cnt-a+1) % MOD;
    weak = weak*invmod(cnt+1, MOD) % MOD;

    cout << (strong+weak) % MOD << endl;
  }

  ////////////////////////////////
  return 0;
}
