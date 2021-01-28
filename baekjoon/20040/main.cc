#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 500'005;
int N, M, par[MN], sz[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;

  for (int i=0; i<N; i++) {
    par[i] = i;
    sz[i] = 1;
  }

  for (int i=1; i<=M; i++) {
    int a, b; cin >> a >> b;
    if (find(a) == find(b)) {
      cout << i << endl;
      return 0;
    }
    merge(a, b);
  }

  cout << 0 << endl;

  ////////////////////////////////
  return 0;
}
