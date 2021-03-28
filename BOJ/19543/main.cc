#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, M, K;
string line[26], dungeon;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<K; i++) cin >> line[i];
  cin >> dungeon;

  lld s = M-1, e = M-1;
  while (s > 0 && line[dungeon[N-1] - 'A'][s-1] != 'U') s--;

  lld ans = e-s+1;

  for (int i=N-2; i>=0; i--) {
    string &L = line[dungeon[i] - 'A'];
    while (e >= s && L[e] != 'U') e--;
    if (e < s) break;
    while (s > 0 && L[s-1] != 'U') s--;
    ans += e-s+1;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
