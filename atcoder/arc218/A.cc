#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
lld N, M;
map<int, vector<lld>> cnts; // key: a, value: number of "A_ij = a" for each i
lld tot, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int a; cin >> a;
      if (cnts.count(a) == 0) cnts[a].resize(N);
      cnts[a][i]++;
    }
  }

  tot = 1;
  for (int i=0; i<N; i++) tot = tot * M % MOD;

  for (auto &[_, cnt]: cnts) {
    sort(all(cnt));
    reverse(all(cnt));

    lld none = 1;
    for (int i: cnt) none = none * (M-i) % MOD;
    ans = (ans + tot - none + MOD) % MOD;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
