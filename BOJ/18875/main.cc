#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M, par[MN], cnt[MN];
vector<int> adj[MN];

int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (find(x) == find(y)) return;

  if (adj[x].size() < adj[y].size()) swap(x, y);
  par[y] = x;

  if (adj[x].size() == 0) return;
  int a = adj[x][0];
  for (auto b: adj[y]) adj[x].push_back(b);
  for (auto b: adj[y]) merge(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  iota(par+1, par+N+1, 1);
  for (int i=0; i<M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  for (int i=1; i<=N; i++) {
    if (adj[i].size() == 0) continue;
    int x = adj[i][0];
    for (auto y: adj[i]) merge(x, y);
  }

  for (int i=1, j=1; i<=N; i++) {
    int x = find(i);
    if (!cnt[x]) cnt[x] = j++;
    cout << cnt[x] << endl;
  }

  ////////////////////////////////
  return 0;
}
