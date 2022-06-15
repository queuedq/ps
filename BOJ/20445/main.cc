#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MN = 105;
lld N, Q, D[MN][MN];
vector<lld> xs;

struct Interval {
  lld s, e;
  inline lld len() { return e-s+1; }
  bool operator <(const Interval &I) const { return e < I.e; }
};
vector<Interval> I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    lld s, e; cin >> s >> e;
    I.push_back({s, e});
    xs.push_back(s);
  }
  sort(all(I));
  sort(all(xs));

  for (int k=0; k<N; k++) {
    fill(D[k], D[k]+N+1, INF);
    lld L = xs[k];
    for (int i=0; i<N; i++) {
      if (I[i].s <= L) { D[k][i] = I[i].len(); continue; }
      for (int j=0; j<i; j++) {
        if (I[j].e < I[i].s) continue;
        D[k][i] = min(D[k][i], D[k][j] + I[i].len());
      }
    }
    for (int i=N-1; i>=0; i--) D[k][i] = min(D[k][i], D[k][i+1]);
  }

  for (int q=0; q<Q; q++) {
    lld a, b; cin >> a >> b;
    int l = upper_bound(all(xs), a) - xs.begin() - 1;
    int r = lower_bound(all(I), (Interval){0, b}) - I.begin();
    if (l < 0 || D[l][r] == INF) cout << -1 << endl;
    else cout << D[l][r] << endl;
  }

  ////////////////////////////////
  return 0;
}
