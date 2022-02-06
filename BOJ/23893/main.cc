#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, P, K;
map<int, int> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> P >> K;
  lld ans = 0;
  for (int i=0; i<N; i++) {
    lld A; cin >> A;
    lld x = (A*A % P)*A % P;
    x = (x - A*K) % P;
    x = (x+P) % P;
    ans += cnt[x]++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
