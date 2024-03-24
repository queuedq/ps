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
const int MN = 1010;
const int MQ = 10101;
int N, M, Q, vst[MN][MN], par[MN*MN];
int comp;
vector<pii> E[MQ];
vector<int> ans;

bool oob(int x, int y) { return x < 0 || y < 0 || x >= N || y >= M; }
int id(int x, int y) { return x*M+y; }
pii coord(int i) { return {i/M, i%M}; }

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=1; i<=Q; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    for (int x=x1; x<=x2; x++) {
      for (int y=y1; y<=y2; y++) {
        if (vst[x][y]) continue;
        vst[x][y] = i;
        E[i].push_back({x, y});
      }
    }
  }

  // initialize
  for (int x=0; x<N; x++) {
    for (int y=0; y<M; y++) {
      int i = id(x, y);
      par[i] = i;
      if (!vst[x][y]) comp++;
    }
  }

  for (int x=0; x<N; x++) {
    for (int y=0; y<M; y++) {
      if (vst[x][y]) continue;
      int i = find(id(x, y));

      for (int d=0; d<4; d++) {
        int xx = x+dx[d], yy = y+dy[d];
        if (oob(xx, yy) || vst[xx][yy]) continue;
        int ii = find(id(xx, yy));

        if (i != ii) {
          par[ii] = i;
          comp--;
        }
      }
    }
  }

  ans.push_back(comp);

  // queries
  for (int q=Q; q>=2; q--) {
    for (auto [x, y]: E[q]) {
      vst[x][y] = 0;
      comp++;
      int i = find(id(x, y));

      for (int d=0; d<4; d++) {
        int xx = x+dx[d], yy = y+dy[d];
        if (oob(xx, yy) || vst[xx][yy]) continue;
        int ii = find(id(xx, yy));

        if (i != ii) {
          par[ii] = i;
          comp--;
        }
      }
    }

    ans.push_back(comp);
  }

  // print
  reverse(all(ans));
  for (auto a: ans) cout << a << endl;

  ////////////////////////////////
  return 0;
}
