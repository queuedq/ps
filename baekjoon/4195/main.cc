#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int F;
string adj[MAXN][2];
map<string, int> name;

struct DSU {
  int parent[MAXN], size[MAXN];

  void reset(int N) {
    for (int i=0; i<N; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }

  int merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return size[x];
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    return size[x];
  }
} dsu;

void calc() {
  cin >> F;
  dsu.reset(F*2);

  int id = 0;
  for (int i=0; i<F; i++) {
    cin >> adj[i][0] >> adj[i][1];
    name[adj[i][0]] = id++;
    name[adj[i][1]] = id++;
  }

  for (int i=0; i<F; i++) {
    cout << dsu.merge(name[adj[i][0]], name[adj[i][1]]) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
