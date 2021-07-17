#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
lld N, M, par[MN], diff[MN]; // diff[i]: value of i - value of par[i]

pll find(int x) {
  if (x == par[x]) return {x, 0};
  auto [root, d] = find(par[x]);
  par[x] = root;
  diff[x] += d;
  return {root, diff[x]};
}

void merge(int x, int y, int d) {
  auto [xr, xd] = find(x);
  auto [yr, yd] = find(y);
  if (xr == yr) return;
  par[yr] = xr;
  diff[yr] = d + xd - yd;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  while (true) {
    cin >> N >> M;
    if (N == 0) break;
    iota(par+1, par+N+1, 1);
    fill(diff+1, diff+N+1, 0);

    for (int q=0; q<M; q++) {
      char t; cin >> t;

      if (t == '!') {
        int a, b, w; cin >> a >> b >> w;
        merge(a, b, w);
      } else {
        int a, b; cin >> a >> b;
        auto [x, xd] = find(a);
        auto [y, yd] = find(b);
        if (x != y) cout << "UNKNOWN" << endl;
        else cout << yd - xd << endl;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
