#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
lld m, n;
pll P[MN], C[MN];
lld D[MN];

lld profit(int i, int j) {
  return (C[j].second-P[i].second) * (C[j].first-P[i].first);
}

void dnco(int s, int e, int l, int r) {
  if (s > e) return;
  int mid = (s+e)/2;
  D[mid] = LLONG_MIN;
  int opt = r;
  for (int i=l; i<=r; i++) {
    if (P[mid].first > C[i].first) continue;
    if (profit(mid, i) > D[mid]) {
      D[mid] = profit(mid, i);
      opt = i;
    }
  }

  dnco(s, mid-1, l, opt);
  dnco(mid+1, e, opt, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> m >> n;
  for (int i=0; i<m; i++) cin >> P[i].second >> P[i].first;
  for (int i=0; i<n; i++) cin >> C[i].second >> C[i].first;
  sort(P, P+m);
  sort(C, C+n);

  int k = 1;
  for (int i=1; i<m; i++) {
    if (P[k-1].second >= P[i].second) P[k++] = P[i];
  }

  dnco(0, k-1, 0, n-1);

  lld ans = 0;
  for (int i=0; i<k; i++) ans = max(ans, D[i]);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
