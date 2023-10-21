#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 305;
int N, D[MN*2][MN*2];
vector<int> xs;

struct Interval {
  int s, e, d;
  bool operator<(Interval I) const { return d < I.d; }
};
Interval I[MN];

void solve() {
  cin >> N;
  for (int i=0; i<N; i++) {
    int s, e, d; cin >> s >> e >> d;
    I[i] = {s, e+1, d};
    xs.push_back(s);
    xs.push_back(e);
  }

  // sort and compress
  sort(I, I+N);
  sort(all(xs));
  for (int i=0; i<N; i++) {
    I[i].s = lower_bound(all(xs), I[i].s) - xs.begin();
    I[i].e = lower_bound(all(xs), I[i].e) - xs.begin();
  }

  // dp
  for (int len=1; len<=N*2; len++) {
    for (int s=0, e=len; e<=N*2; s++, e++) {
      D[s][e] = INT_MAX;

      // find interval in [s, e) with max d
      int k = N-1;
      for (; k>=0; k--)
        if (s <= I[k].s && I[k].e <= e) break;

      if (k == -1) { D[s][e] = 0; continue; }

      // dp
      for (int m=I[k].s; m<I[k].e; m++) {
        D[s][e] = min(D[s][e], D[s][m] + D[m+1][e] + I[k].d);
      }
    }
  }

  cout << D[0][N*2] << endl;

  // reset
  xs.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
