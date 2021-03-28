#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pll> incr, decr;

bool check(lld cap, vector<pll> &v) {
  for (auto [a, b]: v) {
    if (cap < a) return false;
    cap += b-a;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  lld diff = 0;
  for (int i=0; i<N; i++) {
    lld a, b; cin >> a >> b;
    if (a <= b) incr.push_back({a, b});
    else decr.push_back({b, a});
    diff += b-a;
  }

  sort(incr.begin(), incr.end());
  sort(decr.begin(), decr.end());

  lld l = 0, r = 1e16;
  while (l+1 < r) {
    lld mid = (l+r) / 2;
    bool b1 = check(mid, incr);
    bool b2 = check(mid+diff, decr);
    if (b1 && b2) r = mid;
    else l = mid;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
