#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 1e8;
int n, r[20], c[20], D[1<<20][20];
string name[20];
set<string> names;
int tot;

int dist(int i, int j) {
  return abs(r[i]-r[j]) + abs(c[i]-c[j]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> r[i] >> c[i] >> name[i];
    names.insert(name[i]);
  }

  int ans = INF;

  for (int s=1; s<1<<n; s++) {
    set<string> poke;
    bool dup = false;
    for (int i=0; i<n; i++) {
      if (!(s & (1<<i))) continue;
      D[s][i] = INF;
      if (poke.count(name[i]) != 0) dup = true;
      poke.insert(name[i]);
    }
    if (dup) continue;

    for (int i=0; i<n; i++) {
      if (!(s & (1<<i))) continue;
      int ss = s ^ (1<<i);

      for (int j=0; j<n; j++) {
        if (!(ss & (1<<j))) continue;
        D[s][i] = min(D[s][i], D[ss][j] + dist(i, j));
      }
      if (ss == 0) D[s][i] = abs(r[i]) + abs(c[i]);

      if (poke.size() == names.size()) {
        ans = min(ans, D[s][i] + abs(r[i]) + abs(c[i]));
      }
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
