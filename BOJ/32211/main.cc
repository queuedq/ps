#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ML = 40*40+5;
int N, idx[ML], perm[ML], vst[ML];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N*N; i++) {
    for (int j=1; j<=N*N; j++) {
      int x; cin >> x;
      if (i == N*N-1) idx[x] = j;
      else if (i == N*N) perm[idx[x]] = j;
    }
  }

  int last = 0; // last cyclc start
  for (int i=1; i<=N*N; i++) {
    if (vst[i]) continue;
    last = i;

    int u = i;
    do {
      vst[u] = 1;
      u = perm[u];
    } while (u != i);
  }

  cout << (N*N) * (N*N - 2) + last << endl;

  ////////////////////////////////
  return 0;
}
