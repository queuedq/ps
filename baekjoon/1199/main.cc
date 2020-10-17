#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
int adj[MAXN][MAXN];

void euler(int u) {
  for (int v=1; v<=N; v++) {
    if (adj[u][v] == 0) continue;
    adj[u][v]--;
    adj[v][u]--;
    euler(v);
  }
  cout << u << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int deg = 0;
    for (int j=1; j<=N; j++) {
      cin >> adj[i][j];
      deg += adj[i][j];
    }
    if (deg % 2 == 1) { cout << -1 << endl; return 0; }
  }

  euler(1);

  ////////////////////////////////
  return 0;
}
