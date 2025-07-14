#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, H, Q;
map<int, int> E;
vector<int> L;
lld psum[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> H;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    E[a]++;
    E[b+1]--;
  }
  E[H+1]++;

  // sweep to get free interval lengths
  int prv = 1, cnt = 0;
  for (auto [x, d]: E) {
    if (cnt == 0) L.push_back(x - prv);
    cnt += d;
    prv = x;
  }
  sort(all(L));

  // psum
  for (int i=0; i<sz(L); i++) psum[i+1] = psum[i] + L[i];

  // query
  cin >> Q;
  for (int q=0; q<Q; q++) {
    int x; cin >> x;
    int i = lower_bound(all(L), x) - L.begin();
    lld cnt = sz(L) - i;
    lld sum = psum[sz(L)] - psum[i];
    lld ans = sum - cnt * (x-1);
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
