#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 105;
int N; string S;
int x[MX], y[MX]; // R/B count
bool univ[2][MX][MX]; // current/next round's possible universes (visible R/B count)

void solve() {
  cin >> N >> S;
  for (int k=1; k<=N; k++) {
    x[k] = x[k-1], y[k] = y[k-1];
    if (S[k-1] == 'R') x[k]++;
    else y[k]++;
  }

  vector<bool> ans(N+1);

  memset(univ, 0, sizeof(univ));
  auto &U = univ[0], &V = univ[1];
  U[x[N]][y[N]] = 1;
  int start = N; // starting person who answers this round

  while (1) {
    bool done = 1;

    for (int k=start; k>=0; k--) { // person k can see k hats
      bool ambiguous = U[x[k]+1][y[k]] && U[x[k]][y[k]+1]; // person k can answer if not ambiguous
      if (!ambiguous) ans[k] = 1;

      for (int i=0, j=k; i<=k; i++, j--) {
        if (k == start) {
          V[i][j] = U[i][j];
        } else {
          U[i][j] = U[i+1][j] || U[i][j+1];
          V[i][j] = V[i+1][j] || V[i][j+1];
        }

        bool ambiguous_here = U[i+1][j] && U[i][j+1];
        V[i][j] &= (ambiguous == ambiguous_here); // next universe possible if the answers match
      }

      if (k < start && ambiguous) { // no more answers from people < k (round ends)
        start = k, done = 0;
        break;
      }
    }

    if (done) break;
    swap(U, V);
  }

  for (int k=0; k<N; k++) cout << ans[k];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
