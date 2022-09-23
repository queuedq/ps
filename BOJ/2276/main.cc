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
const int MN = 305;
lld N, M, par[MN*MN], s[MN*MN], vst[MN*MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  par[y] = x;
  s[x] += s[y];
}

struct Cell {
  lld h, i, j;
  bool operator <(const Cell &C) const { return h < C.h; }
};
vector<Cell> A;

bool oob(int i, int j) { return i<=0 || i>N || j<=0 || j>M; }
int to_int(int i, int j) { return (i-1)*M + (j-1) + 1; } // reserve 0 as oob

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      lld h; cin >> h;
      A.push_back({h, i, j});
      int u = to_int(i, j);
      par[u] = u, s[u] = 1;
    }
  }
  sort(all(A));

  lld ans = 0, ph = 0, cnt = 0;
  for (auto [h, i, j]: A) {
    ans += (h-ph) * (cnt-s[find(0)]); // s[find(0)]: oob count
    int u = to_int(i, j);
    vst[u] = 1;

    for (int d=0; d<4; d++) {
      int ii = i+dx[d], jj = j+dy[d];
      if (oob(ii, jj)) { merge(0, u); continue; }
      int v = to_int(ii, jj);
      if (vst[v]) merge(u, v);
    }

    ph = h;
    cnt++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
