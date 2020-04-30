#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e6+5;
int N, H[MAXN];
int shot[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> H[i];

  int ans = 0;
  for (int i=0; i<N; i++) {
    if (shot[H[i]]) {
      shot[H[i]]--;
      shot[H[i]-1]++;
    } else {
      shot[H[i]-1]++;
      ans++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
