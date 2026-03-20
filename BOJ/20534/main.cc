#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
int N, A[MN*2], up[MN*2];
vector<int> pos[MN];
vector<pii> adj[MN*2];

bool dfs(int u, int b) {
  if (up[u] == b) return true;
  if (up[u] == !b) return false;
  up[u] = b;
  bool possible = true;
  for (auto [v, c]: adj[u]) {
    possible &= dfs(v, b^c);
  }
  return possible;
}

bool is_possible() {
  for (int a=1; a<=N; a++) {
    for (int b=1; b<a; b++) {
      int x1 = pos[a][0], x2 = pos[a][1], y1 = pos[b][0], y2 = pos[b][1];
      if (x1 < y1 && y2 < x2) {
        adj[y1].push_back({y2, 0});
        adj[y2].push_back({y1, 0});
      } else if (y1 < x1 && x2 < y2) {
        adj[x1].push_back({x2, 0});
        adj[x2].push_back({x1, 0});
      } else if (x1 < y1 && y1 < x2) {
        adj[y1].push_back({x2, 1});
        adj[x2].push_back({y1, 1});
      } else if (y1 < x1 && x1 < y2) {
        adj[x1].push_back({y2, 1});
        adj[y2].push_back({x1, 1});
      }
    }
  }

  fill(up, up+N*2, -1);
  bool possible = true;
  for (int i=0; i<N*2; i++) {
    if (up[i] == -1) possible &= dfs(i, 0);
  }
  return possible;
}

struct Line { char dir; int len; };
vector<Line> link[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*2; i++) {
    cin >> A[i];
    pos[A[i]].push_back(i);
  }

  if (!is_possible()) { cout << "NO" << endl; return 0; }

  for (int i=0; i<N*2; i++) {
    int a = A[i];
    int x = pos[a][0], y = pos[a][1];
    if (i == x) continue;

    if (up[x] && up[y]) link[a] = {{'U', i}, {'R', y-x}, {'D', i}};
    if (!up[x] && !up[y]) link[a] = {{'D', i}, {'R', y-x}, {'U', i}};
    if (up[x] && !up[y]) link[a] = {{'U', i}, {'L', i+x}, {'D', i*2}, {'R', i+y}, {'U', i}};
    if (!up[x] && up[y]) link[a] = {{'D', i}, {'L', i+x}, {'U', i*2}, {'R', i+y}, {'D', i}};
  }

  cout << "YES" << endl;

  for (int a=1; a<=N; a++) {
    cout << link[a].size() << " ";
    for (Line L: link[a]) cout << L.dir << " " << L.len << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
