#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MM = 1e6+5;
lld N, M, S, edge[MM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S;
  
  S -= (N-1)*N/2; // remaining budget
  if (S < 0) { cout << -1 << endl; return 0; }

  // increase edge costs
  for (lld i=N-1; i>=1; i--) {
    // upper bounds:
    // - first edge after completing K_i
    // - make room for later edges
    // - remaining budget S
    lld e = min({i*(i-1)/2 + 1, M-(N-1-i), i+S});

    edge[e] = 1;
    S -= e-i;
  }

  if (S > 0) { cout << -1 << endl; return 0; }

  // MST edge: (1, u) / free edge: (v, w)
  int u = 2, v = 2, w = 3;
  for (int i=1; i<=M; i++) {
    if (edge[i]) { // MST edge
      cout << 1 << " " << u << endl;
      u++;
    } else { // free edge
      cout << v << " " << w << endl;
      if (++v == w) v = 2, w++;
    }
  }

  ////////////////////////////////
  return 0;
}
