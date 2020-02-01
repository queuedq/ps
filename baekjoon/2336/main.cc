#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 5e5 + 5;
const int ST_SIZE = 1 << 19;
int N, A[MAX_N], B[MAX_N], C[MAX_N], tree[ST_SIZE * 2];

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) { cin >> A[i]; }
  for (int i = 1; i <= N; i++) { int t; cin >> t; B[t] = i; }
  for (int i = 1; i <= N; i++) { int t; cin >> t; C[t] = i; }
}

void init() {
  for (int node = 1; node < ST_SIZE * 2; node++) {
    tree[node] = INT_MAX;
  }
}

void update(int i, int v) {
  int node = i + ST_SIZE;
  tree[node] = v;
  node /= 2;
  while (node > 0) {
    tree[node] = min(tree[node*2], tree[node*2+1]);
    node /= 2;
  }
}

int query(int node, int nl, int nr, int l, int r) {
  if (nr <= l || r <= nl) { return INT_MAX; }
  if (l <= nl && nr <= r) { return tree[node]; }
  int mid = (nl + nr) / 2;
  return min(query(node*2, nl, mid, l, r), query(node*2+1, mid, nr, l, r));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  init();

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (C[A[i]] < query(1, 0, ST_SIZE, 1, B[A[i]])) {
      ans++;
    }
    update(B[A[i]], C[A[i]]);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
