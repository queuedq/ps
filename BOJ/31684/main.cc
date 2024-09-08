#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1<<15;
int N, A[MN], B[MN], idx[MN];

void swap_A(int i, int j) {
  if (i == j) return;
  swap(idx[A[i]], idx[A[j]]);
  swap(A[i], A[j]);
}

void update_A(int i, int x) {
  idx[A[i]] = 0;
  idx[x] = i;
  A[i] = x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i], idx[A[i]] = i;
  for (int i=1; i<=N; i++) cin >> B[i];

  vector<pii> ans;
  for (int i=1; i<=N; i++) {
    int j = idx[B[i]];
    if (j) { swap_A(i, j); continue; }

    vector<vector<pii>> ops = {{}};
    int x = A[i];
    for (int p=0; p<15; p++) {
      if ((x>>p & 1) == (B[i]>>p & 1)) continue;
      int y = x^(1<<p);
      ops.back().push_back({x, y});
      if (idx[y]) ops.push_back({});
      x = y;
    }
    update_A(i, x);

    for (int t=sz(ops)-1; t>=0; t--) {
      for (auto op: ops[t]) ans.push_back(op);
    }
  }

  cout << sz(ans) << endl;
  for (auto [x, y]: ans) cout << x << " " << y << endl;

  ////////////////////////////////
  return 0;
}
