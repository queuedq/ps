#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 5005;
int k, n;

vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u])
      dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v, int cl) {
  comp[v] = cl;
  for (int u : gt[v]) {
    if (comp[u] == -1)
      dfs2(u, cl);
  }
}

bool solve_2SAT() {
  used.assign(k*2, false);
  for (int i = 0; i < k*2; ++i) {
    if (!used[i])
      dfs1(i);
  }

  comp.assign(k*2, -1);
  for (int i = 0, j = 0; i < k*2; ++i) {
    int v = order[k*2 - i - 1];
    if (comp[v] == -1)
      dfs2(v, j++);
  }

  assignment.assign(k, false);
  for (int i = 0; i < k*2; i += 2) {
    if (comp[i] == comp[i + 1])
      return false;
    assignment[i / 2] = comp[i] > comp[i + 1];
  }
  return true;
}

void construct(int x, int xn, int y, int yn) {
  g[xn].push_back(y); gt[y].push_back(xn);
  g[yn].push_back(x); gt[x].push_back(yn);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> k >> n;
  g.resize(k*2);
  gt.resize(k*2);

  for (int i=0; i<n; i++) {
    int a, b, c;
    char ac, bc, cc;
    cin >> a >> ac >> b >> bc >> c >> cc;
    a--; b--; c--;

    int x = a*2 + (ac!='R');
    int xn = x^1;
    int y = b*2 + (bc!='R');
    int yn = y^1;
    int z = c*2 + (cc!='R');
    int zn = z^1;

    construct(x, xn, y, yn);
    construct(y, yn, z, zn);
    construct(z, zn, x, xn);
  }

  bool ok = solve_2SAT();

  if (ok) {
    for (int i=0; i<k; i++) cout << (assignment[i] ? 'R' : 'B');
    cout << endl;
  } else {
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
