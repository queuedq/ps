#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 20005;
const int MX = 2020;
const lld INF = 1e12;
lld N, X[MN], Y[MN], H[2][MX], V[2][MX]; // H: y = Y[i], V: x = X[i]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  X[0] = Y[0] = 1000;
  for (int i=1; i<=N; i++) {
    cin >> X[i] >> Y[i];
    X[i] += 1000, Y[i] += 1000;
  }

  fill(H[0], H[0]+MX, INF);
  fill(V[0], V[0]+MX, INF);
  H[0][1000] = V[0][1000] = 0;

  for (int i=0; i<N; i++) {
    int c = i&1, n = !c;

    for (int x=0; x<MX; x++) {
      H[n][x] = H[c][x] + abs(Y[i+1] - Y[i]); // H -> H
      V[n][x] = V[c][x] + abs(X[i+1] - X[i]); // V -> V
    }

    for (int x=0; x<MX; x++) {
      V[n][Y[i]] = min(V[n][Y[i]], H[c][x] + abs(X[i+1] - x)); // H -> V
      H[n][X[i]] = min(H[n][X[i]], V[c][x] + abs(Y[i+1] - x)); // V -> H
    }
  }

  lld ans = INF;
  for (int x=0; x<MX; x++) {
    ans = min(ans, H[N&1][x]);
    ans = min(ans, V[N&1][x]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
