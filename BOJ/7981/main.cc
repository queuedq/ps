#include <bits/stdc++.h>
#include <queue>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, U[MN], Z[MN], deg[MN];
vector<int> rev[MN];
lld D[MN], E[MN]; // D: optimal, E: weak

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int r; cin >> U[i] >> Z[i] >> r;
    for (int j=0; j<r; j++) {
      int g; cin >> g;
      deg[i]++;
      rev[g].push_back(i);
    }
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (int i=1; i<=N; i++) {
    pq.push({Z[i], i});
    D[i] = Z[i];
    E[i] = U[i];
  }

  while (!pq.empty()) {
    auto [d, i] = pq.top(); pq.pop();
    if (d > D[i]) continue;

    for (auto j: rev[i]) {
      E[j] += d;
      if (--deg[j] == 0 && E[j] < D[j]) {
        D[j] = E[j];
        pq.push({E[j], j});
      }
    }
  }

  cout << D[1] << endl;

  ////////////////////////////////
  return 0;
}
