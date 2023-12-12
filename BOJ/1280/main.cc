#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
const lld MOD = 1e9+7;
lld N, X[ST], cnt[ST*2], sum[ST*2];

void add(int i, int v) {
  i += ST;
  cnt[i] += 1;
  sum[i] += v;
  for (i/=2; i>0; i/=2) {
    cnt[i] = cnt[i*2] + cnt[i*2+1];
    sum[i] = sum[i*2] + sum[i*2+1];
  }
}

pll qry(int l, int r) {
  lld c = 0, s = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) {
      c += cnt[l];
      s += sum[l];
      l++;
    }
    if (r&1) {
      r--;
      c += cnt[r];
      s += sum[r];
    }
  }
  return {c, s};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> X[i];

  lld ans = 1;
  for (int i=0; i<N; i++) {
    auto [c0, s0] = qry(0, X[i]-1);
    auto [c1, s1] = qry(X[i], ST-1);
    lld cost = ((X[i]*c0 - s0) + (s1 - X[i]*c1)) % MOD;
    if (i > 0) ans = ans*cost % MOD;
    add(X[i], X[i]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
