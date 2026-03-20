#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5005;
const lld MOD = 1e9+7;
int N, M;
int par[MN], comp;
lld binom[MN][MN], D[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  par[y] = x;
  comp--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  comp = N;
  for (int i=1; i<=N; i++) par[i] = i;

  for (int i=0; i<=N; i++) {
    binom[i][0] = binom[i][i] = 1;
    for (int j=1; j<i; j++) {
      binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
    }
  }

  D[0] = 1;
  for (int i=1; i<=N; i++) {
    for (int j=0; j<=N-1; j++) {
      D[i] = (D[i] + binom[i-1][j] * D[j]) % MOD;
    }
  }

  for (int i=0; i<M; i++) {
    int x, y; cin >> x >> y;
    merge(x, y);
    cout << D[comp] << endl;
  }

  ////////////////////////////////
  return 0;
}
