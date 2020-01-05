#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, root;
vector<int> a, c;
vector<vector<int>> adj;
vector<bool> avail;

int kth(int k) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (avail[i]) cnt++;
    if (cnt == k) {
      avail[i] = false;
      return i;
    }
  }
}

int dfs1(int node, bool& valid) {
  int size = 0;
  for (int i: adj[node]) {
    size += dfs1(i, valid);
  }
  if (c[node] > size) valid = false;
  return size + 1;
}

void dfs2(int node) {
  a[node] = kth(c[node] + 1);
  for (int i: adj[node]) {
    dfs2(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  a.resize(n+1);
  c.resize(n+1);
  adj.resize(n+1);
  avail.resize(n+1);
  fill(avail.begin(), avail.end(), true);

  for (int i = 1; i <= n; i++) {
    int p; cin >> p >> c[i];
    if (p == 0) root = i;
    else adj[p].push_back(i);
  }

  bool valid = true;
  dfs1(root, valid);
  if (!valid) { cout << "NO" << endl; return 0; }

  dfs2(root);
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }

  ////////////////////////////////
  return 0;
}
