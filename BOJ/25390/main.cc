#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int XN = 18;
const int XM = 1e5+5;
lld N, M, cost[XM], tot[XN], binary[XM];
lld F[XN][1<<XN], D[1<<XN][XN], E[1<<XN];
vector<int> buy[XN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) { int s; cin >> s; cost[i] -= s; }
  for (int i=1; i<=M; i++) { int t; cin >> t; cost[i] += t; }

  for (int i=0; i<N; i++) {
    int p, q;
    cin >> p;
    for (int j=0; j<p; j++) {
      int a; cin >> a;
      buy[i].push_back(a);
      tot[i] += cost[a];
    }
    cin >> q;
    for (int j=0; j<q; j++) {
      int b; cin >> b;
      binary[b] += (1<<i);
    }
  }

  for (int i=0; i<N; i++) {
    for (int a: buy[i]) F[i][binary[a]] += cost[a];
    for (int j=0; j<N; j++) {
      for (int S=0; S<1<<N; S++) {
        if (S>>j&1) F[i][S] += F[i][S^(1<<j)];
      }
    }
  }

  int mask = (1<<N)-1;
  for (int S=0; S<1<<N; S++) {
    for (int i=0; i<N; i++) {
      if (~S>>i&1) continue;
      D[S][i] = E[S^(1<<i)] + tot[i] - F[i][~S&mask];
      E[S] = max(E[S], D[S][i]);
    }
  }
  cout << E[mask] << endl;

  ////////////////////////////////
  return 0;
}
