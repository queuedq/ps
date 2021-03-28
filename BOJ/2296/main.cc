#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Building {
  int x, y, c;

  bool operator <(Building a) const { return x < a.x; }
};

const int MAXN = 1005;
int N, D[MAXN], E[MAXN];
Building P[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> P[i].x >> P[i].y >> P[i].c;

  sort(P, P+N);

  int ans = 0;
  for (int i=0; i<N; i++) {
    int maxd = 0, maxe = 0;
    for (int j=0; j<i; j++) {
      if (P[j].y < P[i].y) maxd = max(maxd, D[j]);
      if (P[j].y > P[i].y) maxe = max(maxe, E[j]);
    }
    D[i] = maxd + P[i].c;
    E[i] = maxe + P[i].c;
    ans = max(ans, D[i]);
    ans = max(ans, E[i]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
