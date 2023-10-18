#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MOD = 1e9+7;
const int MQ = 1010;
lld N, x0, a, b, Q;

struct Query {
  // l: [0, l) cnt < k, r: [0, r) cnt >= k
  int k, l, r, m;
  bool operator<(Query q) { return k < q.k; }
};
Query qry[MQ];
int cnt[MQ]; // [0, m) cnt

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> x0 >> a >> b >> Q;
  for (int i=0; i<Q; i++) {
    int k; cin >> k;
    qry[i] = {k+1, 0, MOD, MOD/2};
  }
  sort(qry, qry+Q);

  // pbs
  for (int t=0; t<32; t++) {
    fill(cnt, cnt+Q+1, 0);

    for (int i=0, X=x0; i<N; i++, X=(X*a+b)%MOD) {
      // find index to add
      int l = -1, r = Q;
      while (l+1 < r) {
        int m = (l+r)/2;
        if (X < qry[m].m) r = m;
        else l = m;
      }

      cnt[r]++; // X in [0, qry[r].m)
    }

    // prefix sum
    for (int i=1; i<Q; i++) cnt[i] += cnt[i-1];

    // narrow down
    for (int i=0; i<Q; i++) {
      if (cnt[i] < qry[i].k) qry[i].l = qry[i].m;
      else qry[i].r = qry[i].m;
      qry[i].m = (qry[i].l + qry[i].r) / 2;
    }
  }

  lld sum = 0;
  for (int i=0; i<Q; i++) sum += qry[i].m;
  cout << sum << endl;

  ////////////////////////////////
  return 0;
}
