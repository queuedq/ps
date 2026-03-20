#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

bool is_independent(int s, int N, int M, vector<vector<int>> &adj) {
  for (int i=0; i<N; i++) {
    if ((s>>i & 1) == 0) continue;
    for (int j=i+1; j<N; j++) {
      if ((s>>j & 1) == 0) continue;
      if (adj[i][j]) return false;
    }
  }
  return true;
}

int chromatic_number(int N, int M, vector<vector<int>> &adj) {
  if (M == 0) return 1;

  // find independent sets
  vector<int> I(1<<N);
  for (int s=0; s<1<<N; s++) I[s] = is_independent(s, N, M, adj);

  // zeta transform
  vector<int> zeta(all(I));
  for (int k=0; k<N; k++) {
    for (int s=0; s<1<<N; s++) {
      if (s>>k & 1) zeta[s] += zeta[s ^ (1<<k)];
    }
  }

  // find chromatic number
  vector<lld> conv(all(zeta));
  for (int c=2; c<=4; c++) {
    // or convolution
    for (int s=0; s<1<<N; s++) conv[s] = conv[s] * zeta[s];

    // inclusion-exclusion
    lld colorings = 0; // number of colorings of entire vertex set
    for (int s=0; s<1<<N; s++) {
      int sign = (__builtin_popcount(s) + N) % 2 == 0 ? 1 : -1;
      colorings += sign * conv[s];
    }

    if (colorings > 0) return c;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i=0; i<M; i++) {
      int u, v; cin >> u >> v;
      adj[u][v] = adj[v][u] = 1;
    }

    int c = chromatic_number(N, M, adj);
    if (c == -1) cout << "many" << endl;
    else cout << c << endl;
  }

  ////////////////////////////////
  return 0;
}
