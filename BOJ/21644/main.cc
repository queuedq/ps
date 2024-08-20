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

struct Item {
  lld w, c, idx;
  bool operator<(const Item &X) const { return c * X.w < X.c * w; }
};

void solve() {
  lld N, W; cin >> N >> W;

  vector<Item> H, L; // heavy, light
  for (int i=1; i<=N; i++) {
    lld w, c; cin >> w >> c;
    if (w > W/2) H.push_back({w, c, i});
    else L.push_back({w, c, i});
  }

  // greedily select light items
  sort(all(L));
  reverse(all(L));
  vector<pll> S(sz(L)+1);
  for (int i=0; i<sz(L); i++) {
    S[i+1] = S[i];
    S[i+1].first += L[i].w;
    S[i+1].second += L[i].c;
  }

  // choose at most one heavy item
  lld best = 0, hi = 0, lcnt = 0; // heavy index, light cnt

  int i = upper_bound(all(S), pll(W*3/2, -INF)) - S.begin() - 1; // no heavy item
  best = S[i].second;
  lcnt = i;

  for (auto [w, c, idx]: H) {
    if (w > W) continue;
    int i = upper_bound(all(S), pll(W*3/2-w, -INF)) - S.begin() - 1;
    if (c + S[i].second > best) {
      best = c + S[i].second;
      hi = idx;
      lcnt = i;
    }
  }

  // print ans
  vector<int> ans;
  if (hi) ans.push_back(hi);
  for (int i=0; i<lcnt; i++) ans.push_back(L[i].idx);

  cout << sz(ans) << endl;
  for (int x: ans) cout << x << " ";
  cout << endl;
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
