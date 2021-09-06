#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 10101;
int N, L[MN], R[MN], indeg[MN], mn[MN], mx[MN];

int solve(int u, int st, int d) {
  if (u == -1) return 0;

  int ls = solve(L[u], st, d+1);
  int rs = solve(R[u], st+ls+1, d+1);

  mn[d] = min(mn[d], st+ls);
  mx[d] = max(mx[d], st+ls);

  return ls + 1 + rs;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int u, l, r; cin >> u >> l >> r;
    L[u] = l;
    R[u] = r;
    if (l != -1) indeg[l]++;
    if (r != -1) indeg[r]++;
  }

  int root;
  for (int i=1; i<=N; i++) {
    if (indeg[i] == 0) { root = i; break; }
  }

  fill(mn, mn+MN, 1e9);
  solve(root, 1, 1);

  int ans = 0, idx = 0;
  for (int i=1; i<=N; i++) {
    if (mx[i] == 0) break;
    if (ans < mx[i] - mn[i] + 1) {
      ans = mx[i] - mn[i] + 1;
      idx = i;
    }
  }
  cout << idx << " " << ans << endl;

  ////////////////////////////////
  return 0;
}
