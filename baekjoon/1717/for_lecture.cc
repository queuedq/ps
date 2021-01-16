#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 1'000'005;
int N, M, par[MAX_N], sz[MAX_N];

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

  for (int i=0; i<=N; i++) {
    par[i] = i;
    sz[i] = 1;
  }

  for (int q=0; q<M; q++) {
    int op, a, b; cin >> op >> a >> b;

    if (op == 0) {
      merge(a, b);
    } else {
      if (find(a) == find(b)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
