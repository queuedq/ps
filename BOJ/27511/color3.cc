#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

vector<int> nodes, adj[64];
int color[64], deg[64], used[64][4];

int pack(int a, int b, int c) { return a<<4 | b<<2 | c; }

tuple<int, int, int> unpack(int i) {
  int a = i>>4 & 3;
  int b = i>>2 & 3;
  int c = i & 3;
  return {a, b, c};
}

void connect(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

bool color_3() {
  int u = -1, mx = -1;
  for (int v: nodes) {
    if (color[v]) continue;
    if (deg[v] > mx) u = v, mx = deg[v];
  }
  if (u == -1) return 1; // all colored

  for (auto c: {1, 2, 3}) { // color u with c
    if (used[u][c]) continue;
    
    color[u] = c;
    for (auto v: adj[u]) deg[v]++, used[v][c]++;
    
    if (color_3()) return 1;

    color[u] = 0;
    for (auto v: adj[u]) deg[v]--, used[v][c]--;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // node number = (left, self, right)
  for (int a=0; a<4; a++) {
    for (int b=0; b<4; b++) {
      for (int c=0; c<4; c++) {
        if (a == b || b == c) continue;
        int u = pack(a, b, c);
        nodes.push_back(u);

        for (int d=0; d<4; d++) {
          if (c == d) continue;
          int v = pack(b, c, d);
          connect(u, v);
        }
      }
    }
  }

  bool ok = color_3();
  cout << ok << endl;

  for (auto u: nodes) {
    auto [a, b, c] = unpack(u);
    cout << "color";
    cout << "[" << a << "]";
    cout << "[" << b << "]";
    cout << "[" << c << "]";
    cout << " = " << color[u] << ";\n";
  }

  ////////////////////////////////
  return 0;
}
