#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int Q;
set<pii> S;
lld ans = 0;

auto merge(set<pii>::iterator it) {
  if (next(it) == S.end()) return it;
  auto [s1, l1] = *it;
  auto [s2, l2] = *next(it);
  if (s1 + l1 == s2) {
    S.erase(next(it));
    S.erase(it);
    it = S.insert({s1, l1 + l2}).first;
    ans += (lld)l1 * l2;
  }
  return it;
}

void split(int x) {
  auto it = S.lower_bound({x+1, 0});
  it--;
  auto [s, l] = *it;
  int l1 = x-s, l2 = l-(x-s)-1;
  S.erase(it);
  if (l1 > 0) S.insert({s, l1});
  if (l2 > 0) S.insert({x+1, l2});
  ans -= (lld)(l1+1) * (l2+1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int q, x; cin >> q >> x;
    if (q == 1) {
      ans++;
      auto [it, _] = S.insert({x, 1});
      it = merge(it);
      if (it != S.begin()) merge(prev(it));
    } else {
      split(x);
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
