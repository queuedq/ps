#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, f[MN], g[MN], S[MN]; // cyc len -> min num

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> f[i];

  for (int i=1; i<=N; i++) {
    if (g[i]) continue;

    // get cycle len
    int j = i, len = 0;
    do {
      len++;
      j = f[j];
    } while (j != i);

    // find possible g(i)
    g[i] = i;
    for (int d=1; d*d<=len; d++) {
      if (len % d) continue;
      if (S[d]) g[i] = min(g[i], S[d]);
      if (S[len/d]) g[i] = min(g[i], S[len/d]);
    }

    // set g for this cycle
    do {
      g[f[j]] = f[g[j]];
      j = f[j];
    } while (j != i);

    if (!S[len]) S[len] = i;
  }

  // print
  for (int i=1; i<=N; i++) {
    cout << g[i] << ' ';
  }

  ////////////////////////////////
  return 0;
}
