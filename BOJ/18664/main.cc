#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, S, adj[20][20], edg[1<<18], ans[20];
pii D[1<<18][105];

int popcount(int x) { return __builtin_popcount(x); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> S;
  for (int i=0; i<M; i++) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u][v]++, adj[v][u]++;
  }

  for (int m=0; m<1<<N; m++) {
    for (int i=0; i<N; i++) {
      if (~m>>i & 1) continue;
      for (int j=0; j<N; j++) {
        if (~m>>j & 1) continue;
        edg[m] += adj[i][j];
      }
    }
    edg[m] /= 2;
  }

  for (int m=0; m<1<<N; m++) {
    for (int i=0; i<=S; i++) {
      for (int j=0; j<N; j++) {
        if (m>>j & 1) D[m][i] = max(D[m][i], {D[m^1<<j][i].first, j});
      }
      if (i >= popcount(m)) {
        D[m][i] = max(D[m][i], {D[m][i - popcount(m)].first + edg[m], N});
      }
    }
  }

  for (int m=(1<<N)-1, i=S; i>0;) {
    if (D[m][i].second == N) { // put tokens to set m
      for (int j=0; j<N; j++) {
        if (m>>j & 1) ans[j]++;
      }
      i -= popcount(m);
    } else { // added vertex j
      m ^= 1 << D[m][i].second;
    }
  }

  for (int i=0; i<N; i++) cout << ans[i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
