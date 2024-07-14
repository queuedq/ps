#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
map<string, int> dst;

bool oob(int x, int y) {
  return x < 0 || x >= 3 || y < 0 || y >= 3;
}

int bfs(string S, string E) {
  queue<string> Q;
  Q.push(S);
  dst[S] = 0;

  while (!Q.empty()) {
    string U = Q.front(); Q.pop();

    int i = 0;
    while (U[i] != '0') i++;
    int x = i/3, y = i%3;

    for (int r=0; r<4; r++) {
      int xx = x+dx[r], yy = y+dy[r];
      if (oob(xx, yy)) continue;
      string V = U;
      swap(V[x*3+y], V[xx*3+yy]);

      if (!dst.count(V)) {
        dst[V] = dst[U] + 1;
        Q.push(V);
      }
      if (V == E) return dst[V];
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S;
  for (int i=0; i<9; i++) {
    char c; cin >> c;
    S.push_back(c);
  }
  string E = "123456780";

  cout << bfs(S, E) << endl;

  ////////////////////////////////
  return 0;
}
