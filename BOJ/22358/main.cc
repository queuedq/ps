#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, M, K, S, T;
lld D[11][MN];
vector<pll> adj[MN], rev[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K >> S >> T;
  for (int i=0; i<M; i++) {
    int a, b, t; cin >> a >> b >> t;
    adj[a].push_back({b, t});
    rev[b].push_back({a, t});
  }

  for (int k=0; k<=K; k++) fill(D[k]+1, D[k]+N+1, -1);

  D[0][S] = 0;
  for (int i=S; i<=N; i++) {
    for (auto [v, t]: rev[i]) {
      if (D[0][v] != -1) D[0][i] = max(D[0][i], D[0][v] + t);
    }
  }

  for (int k=1; k<=K; k++) {
    for (int i=1; i<=N; i++) {
      for (auto [v, t]: rev[i]) {
        if (D[k][v] != -1) D[k][i] = max(D[k][i], D[k][v] + t);
      }
      for (auto [v, t]: adj[i]) {
        D[k][i] = max(D[k][i], D[k-1][v]);
      }
    }
  }
  
  cout << D[K][T] << endl;

  ////////////////////////////////
  return 0;
}
