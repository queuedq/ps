#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 100'005;
const int ST = 1<<18;
int n, m, cnt, in[MN], out[MN], seg[ST*2];
vector<int> adj[MN];

void dfs(int u) {
  in[u] = cnt++;
  for (auto v: adj[u]) dfs(v);
  out[u] = cnt++;
}

void update(int i, int v) {
  int n = ST+i;
  for (; n > 0; n /= 2) seg[n] += v;
}

int query(int n, int nl, int nr, int l, int r) {
  if (r < nl || nr < l) return 0;
  if (l <= nl && nr <= r) return seg[n];
  int mid = (nl+nr+1)/2;
  return query(n*2, nl, mid-1, l, r) + query(n*2+1, mid, nr, l, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    int p; cin >> p;
    if (i != 1) adj[p].push_back(i);
  }

  dfs(1);

  for (int q=0; q<m; q++) {
    int t, i, w; cin >> t;
    if (t == 1) {
      cin >> i >> w;
      update(in[i], w);
    } else {
      cin >> i;
      cout << query(1, 0, ST-1, in[i], out[i]) << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
