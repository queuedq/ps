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
const int MN = 101010;
int N, K, M;
vector<pii> I; // intervals
int E[MN]; // zero events
vector<int> bush; // possible ninja pos
vector<int> L, R; // ninja range w/ min number of ninjas
set<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K >> M;
  for (int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    if (c) I.push_back({a, b});
    else E[a]++, E[b+1]--;
  }

  // get possible bushes
  for (int i=1, sum=0; i<=N; i++) {
    sum += E[i];
    if (sum == 0) bush.push_back(i);
  }

  // saturated
  if (sz(bush) == K) {
    for (auto i: bush) cout << i << endl;
    return 0;
  }

  // recalc intervals
  for (int i=0; i<sz(I); i++) {
    int l = *lower_bound(all(bush), I[i].first);
    int r = *prev(upper_bound(all(bush), I[i].second));
    I[i] = {l, r};
  }

  // find ninja range
  sort(all(I), [](pii a, pii b) { return a.second < b.second; });
  for (int i=0, last=0; i<sz(I); i++) {
    if (I[i].first <= last) continue;
    last = I[i].second;
    R.push_back(last);
  }

  sort(all(I));
  for (int i=sz(I)-1, last=N+1; i>=0; i--) {
    if (I[i].second >= last) continue;
    last = I[i].first;
    L.push_back(last);
  }
  reverse(all(L));

  assert(sz(L) == sz(R));

  // get ans
  for (auto [l, r]: I) {
    if (l == r) ans.insert(l);
  }

  if (sz(L) == K) { // cannot add more ninjas
    for (int i=0; i<K; i++) {
      if (L[i] == R[i]) ans.insert(L[i]);
    }
  }

  // print
  if (sz(ans) == 0) cout << -1 << endl;
  else {
    for (auto i: ans) cout << i << endl;
  }

  ////////////////////////////////
  return 0;
}
