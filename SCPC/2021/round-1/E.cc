#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int par[MN], diff[MN], cf[MN]; // diff[i]: value of i - value of par[i]

pii find(int x) {
  if (x == par[x]) return {x, 0};
  auto [root, d] = find(par[x]);
  par[x] = root;
  diff[x] += d;
  return {root, diff[x]};
}

void merge(int x, int y, int d) {
  auto [xr, xd] = find(x);
  auto [yr, yd] = find(y);
  if (xr == yr) {
    if (d != xd - yd) cf[xr] = true;
    return;
  }
  par[xr] = yr;
  diff[xr] = d + yd - xd;
  cf[yr] = cf[xr] | cf[yr];
}

void solve(int test) {
  int N, K; cin >> N >> K;
  for (int i=1; i<=N; i++) {
    par[i] = i;
    diff[i] = 0;
    cf[i] = false;
  }

  cout << "Case #" << test << endl;
  for (int q=0; q<K; q++) {
    int t; cin >> t;
    if (t == 1) {
      int i, j, d; cin >> i >> j >> d;
      merge(i, j, d);
    } else {
      int i, j; cin >> i >> j;
      auto [x, xd] = find(i);
      auto [y, yd] = find(j);
      if (x != y) {
        cout << "NC" << endl;
      } else if (cf[x]) {
        cout << "CF" << endl;
      } else {
        cout << xd - yd << endl;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
