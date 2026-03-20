#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
const int MN = 505050;
lld N, Q;

struct Query { lld l, r, c; };
Query qry[MN];
vector<pii> E;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=Q; i++) {
    lld l, r, c; cin >> l >> r >> c;
    qry[i] = {l, r, c};
    E.push_back({l, i});
    E.push_back({r+1, -i});
  }
  sort(all(E));

  lld ans = 0, sum = 0;
  set<lld> S; S.insert(0); S.insert(Q+1);

  for (lld i=1, j=0; i<=N; i++) {
    while (j<E.size() && E[j].first<=i) {
      lld k = E[j].second;
      if (k > 0) {
        auto it = S.lower_bound(k);
        lld l = *prev(it), r = *it;
        sum += qry[k].c * ((r-k) * k % MOD) - qry[l].c * ((r-k) * l % MOD);
        sum = (sum%MOD + MOD) % MOD;
        S.insert(k);
      } else {
        k = -k;
        auto it = S.lower_bound(k);
        lld l = *prev(it), r = *next(it);
        sum -= qry[k].c * ((r-k) * k % MOD) - qry[l].c * ((r-k) * l % MOD);
        sum = (sum%MOD + MOD) % MOD;
        S.erase(it);
      }
      j++;
    }

    ans = (ans + sum * (i*(N-i+1) % MOD)) % MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
