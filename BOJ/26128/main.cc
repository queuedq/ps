#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 300'001;
lld N, M, p[MN], cnt[MN], deg[MN];
lld ans, vst[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> p[i];
    deg[p[i]]++;
  }
  for (int j=1; j<=M; j++) {
    int a; cin >> a;
    cnt[a]++;
  }

  // BFS
  queue<int> Q;
  for (int i=1; i<=N; i++) {
    if (deg[i] == 0) Q.push(i);
  }

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    vst[u] = 1;
    if (cnt[u] == M) { cout << ans << endl; return 0; } // found
    
    // move to next node
    ans += cnt[u];
    cnt[p[u]] += cnt[u];
    cnt[u] = 0;

    // push to queue
    if (--deg[p[u]] == 0) Q.push(p[u]);
  }

  for (int i=1; i<=N; i++) {
    if (!vst[i]) assert(deg[i] == 1);
  }

  // check cycles
  for (int i=1; i<=N; i++) {
    if (vst[i]) continue;

    // visit cycle, get length and total cnt of cycle
    int u = i, len = 0, tot = 0;
    do {
      vst[u] = 1;
      len++;
      tot += cnt[u];
      u = p[u];
    } while (u != i);

    if (tot != M) continue;
    // found full cycle

    // calc initial cost
    lld cost = 0, j = 0;
    do {
      if (j != 0) cost += (len - j) * cnt[u];
      j++;
      u = p[u];
    } while (u != i);

    // calc min cost
    lld best = cost;
    do {
      cost += M - len * cnt[p[u]]; // cost of p[u]
      best = min(best, cost);
      u = p[u];
    } while (u != i);

    cout << ans + best << endl; return 0;
  }

  // full cycle not found
  cout << -1 << endl;

  ////////////////////////////////
  return 0;
}
